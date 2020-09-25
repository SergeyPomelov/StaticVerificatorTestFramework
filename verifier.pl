#!/usr/bin/perl

use strict;
use warnings;

use db_interface;
use db_structure;
use configuration;
use messages;
use core_lib;

configuration::option_add("duplicate", "no");
configuration::key_add("--duplicate", "duplicate");
configuration::key_add("-d", "duplicate");

configuration::option_add("output-stream", "stdout");
configuration::key_add("--output-stream", "output-stream");

configuration::option_add("path-separator", "");
configuration::key_add("--path-separator", "path-separator");

configuration::option_add("run-positive", "no");
configuration::key_add("--run-positive", "run-positive");

@ARGV = configuration::keys_to_options(@ARGV);
configuration::config_read();

db_interface::db_connect();

my $cmd = shift @ARGV;

unless ( defined $cmd ) {
	die "Command expected. Try '$0 help' for more info.";
}

if ( $cmd eq "add" ) {
	if ( $#ARGV + 1 < 3 ) {
		die "Not enough arguments. Try '$0 help' for more info.";
	}
	my $name = shift @ARGV;
	my $version = shift @ARGV;
	my $executable = shift @ARGV;
	my $keys = join(' ', @ARGV);
	verifier_add($name, $version, $executable, $keys);
} elsif ( $cmd eq "tune" ) {
	if ( $#ARGV + 1 < 2) {
		die "Not enough arguments. Try '$0 help' for more info.";
	}
	my ($name, $version) = @ARGV;
	verifier_tune($name, $version);
} elsif ( $cmd eq "tune_id" ) {
	if ( $#ARGV + 1 < 1) {
		die "Not enough arguments. Try '$0 help' for more info.";
	}
	my ($ver_id) = @ARGV;
	verifier_tune_id($ver_id);
} elsif ( $cmd eq "remove" ) {
	if ( $#ARGV + 1 < 2) {
		die "Not enough arguments. Try '$0 help' for more info.";
	}
	my ($name, $version) = @ARGV;
	verifier_remove($name, $version);
	
} elsif ( $cmd eq "remove_id" ) {
	if ( $#ARGV + 1 < 1) {
		die "Not enough arguments. Try '$0 help' for more info.";
	}
	my ($ver_id) = @ARGV;
	verifier_remove_id($ver_id);
} elsif ( $cmd eq "help" ) {
	usage();
}

db_interface::db_disconnect();

sub verifier_add {
	my ($name, $version, $executable, $keys) = @_;
	my $output_stream = $configuration::options{"output-stream"};
	my $path_separator = $configuration::options{"path-separator"};
	unless ( $configuration::options{"duplicate"} eq "yes" ) {
		messages::verbose("Checking if the verifier is already in DB");
		my $id = db_structure::verifier_select_id_by_name_and_version($name, $version);
		if ( defined $id ) {
			die "Verifier '$name : $version' is already in DB.\n";
		}
	}
	messages::verbose("Adding verifier to the DB.");
	my $ver_id = db_structure::verifier_insert($name, $version,
		$executable, $keys, $output_stream, $path_separator);
	verifier_tune_id($ver_id);
}

sub verifier_tune {
	my ($name, $version) = @_;
	my $ver_id = db_structure::verifier_select_id_by_name_and_version($name, $version);
	verifier_tune_id($ver_id);
}

sub verifier_tune_id {
	my ($ver_id) = @_;

	my $verifier = db_structure::verifier_select_by_id($ver_id);
	unless ( defined $verifier ) {
		die "No such verifier in DB.\n";
	}
	messages::verbose("$verifier->{name} : $verifier->{version}");
	
	messages::verbose("Removing old analysis info if any");

	db_structure::analysis_delete_by_ver_id($ver_id);
	
	messages::verbose("Selecting basic tests");
	my $keywords;
	my $values_groups = db_structure::basictests_select_values_groups();

	while ( my $value = $values_groups->fetchrow_hashref ) {
		my $value_id = $value->{"value_id"};
		print "\nWe are going to tune our verifier"
			. " on a group of tests called '"
			. $value->{"description"} . "'\n";
		if ( $configuration::options{"run-positive"} eq "yes" ) {
			print "At first we'll show you an output of"
				. " this verifier on positive tests, h.e."
				, " tests which are definitely correct.\n";
			print "Please keep in mind these error reports to"
				. " distinguish useful and useless output"
				. " in the future.\n";
			wait_enter();

			my $positive_tests =
				db_structure::basictests_select_by_value_id_and_positive($value_id, "p");
			while ( my $test = $positive_tests->fetchrow_hashref() ) {
				test_run($test, $verifier);
				wait_enter();
			}
		}
		print "\nNow we are going to show you an output"
			. " of this verifier on negative tests, h.e."
			. " tests which definitely contain errors.\n";
		print "You are supposed to analyse it and select"
			. " some keywords (e.g. 'out-of-bounds' or"
			. " 'memory leak') which are characteristic"
			. " for this kind of error.\n";

		wait_enter();
		
		my $keywords = "";

		my $negative_tests =
			db_structure::basictests_select_by_value_id_and_positive($value_id, "n");
		while (my $test = $negative_tests->fetchrow_hashref()) {
			test_run($test, $verifier);
			print "Current test group is $value->{description}.\n";
			print "Did verifier catch this error or not? [y/n] ";
			my $answer;
			while ( $answer = <STDIN> ) {
				$answer =~ s/[\r\n\t ]//g;
				if ( ( $answer eq "y" )
					or ( $answer eq "n" )) {
					last;
				}
				print "'y' or 'n' please ";
			}
			if ( $answer eq "n" ) {
				print "OK\n";
				next;
			}
			print "Please type phrases which you believe"
				. " are special for this kind of"
				. " error. Separate them with '&'"
				. " character. E.g. 'memory leak &"
				. " pointer' or 'out-of-bounds'.\n";
			print "> ";
			my $line = <STDIN>;
			$line =~ s/[\r\n]//g;
			$line =~ s/\s+/ /g;
			$line =~ s/^ *//g;
			$line =~ s/ *$//g;
			messages::verbose("Cutted to '$line'");
			if ( $keywords ne "" ) {
				$keywords .= " | ";
			}
			$keywords .= $line;
		}
		if ( $keywords eq "" ) {
			if ( $configuration::options{"verbose"} eq "yes" ) {
				print "It seems that verifier didn't actually"
				. " pass any test from the group. We"
				. " consider that it doesn't catch"
				. " this kind of errors.\n";
			}
			next;
		}
		messages::verbose("Preparing report for the DB");
		db_structure::analysis_insert($ver_id, $value_id, $keywords);
	}
}

sub verifier_remove {
	my ($name, $version) = @_;
	my $ver_id = db_structure::verifier_select_id_by_name_and_version($name, $version);
	if ( ! defined $ver_id) {
		die "No such verifier.";
	}
	verifier_remove_id($ver_id);
}

sub verifier_remove_id {
	my ($ver_id) = @_;
	my $verifier = db_structure::verifier_select_by_id($ver_id);
	if ( ! defined $verifier) {
		die "No such verifier.";
	}
	db_structure::analysis_delete_by_ver_id($ver_id);
	db_structure::verifier_delete_by_id($ver_id);
}

sub test_run {
	my ($test, $verifier) = @_;
	print "---- Test #$test->{test_id}: '$test->{path}' ----\n";
	my $output = core_lib::verifier_call($verifier, $test);
	$output =~ s/([^\r\n]{50,70} )/$1\r\n/gm;
	$output =~ s/^/\t/gm;
	print "OUTPUT {\n";
	print "$output";
	print "\n}\n";
}

sub wait_enter {
	print "Press 'Enter' when you are ready.\n";
	<STDIN>;
}

sub usage {
	print "Usage:\n";
	print "$0 [KEYS] add NAME VERSION EXECUTABLE KEYS\n";
	print "$0 [KEYS] tune NAME VERSION\n";
	print "$0 [KEYS] tune_id VER_ID\n";
	print "$0 [KEYS] remove NAME VERSION\n";
	print "$0 [KEYS] remove_id VER_ID\n";
	print "$0 help\n";
	print "\n";
	print "Commands:\n";
	print "add                 add verifier to the database\n";
	print "tune                rerun the verifier through the basic tests\n";
	print "tune_id             like tune but take the verifier's id\n";
	print "remove              remove the verifier from the database\n";
	print "remove_id           remove the verifier by it's id\n";
	print "help                print this message and exit\n";
	print "\n";
	print "Keys:\n";
	print "-v, --verbose       verbose mode\n";
	print "--debug             additional debug information\n";
	print "--debug-lib         additional debug information from libraries\n";
	print "-d, --duplicate     allow to add one verifier+version multiple times\n";
	print "--output-stream=    select the verifier's output stream:\n";
	print "                    'stdout', 'stderr' or 'both', default: 'stdout'\n";
	print "--path-separator=   path separator which verifier uses to find a test:\n";
	print "                    '/', '\\' or whatever you want. Default is in the config.\n";
	print "--run-positive      run verifier through the positive tests\n";
}
