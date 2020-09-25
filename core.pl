#!/usr/bin/perl

use strict;
use warnings;

use configuration;
use db_interface;
use db_structure;
use messages;
use core_lib;

configuration::option_add("verifiers", "");
configuration::option_add("description", "");

configuration::key_add("--verifiers", "verifiers");
configuration::key_add("--description", "description");


@ARGV = configuration::keys_to_options(@ARGV);
configuration::config_read();

db_interface::db_connect();

my $cmd = shift @ARGV;

if ( ! defined $cmd ) {
	die "Command expected. Try '$0 help' for more info";
}

if ( $cmd eq "run" ) {
	main_func();
} elsif ( $cmd eq "help" ) {
	usage();
} else {
	die "Unknown command: '$cmd'. Try '$0 help' for more info";
}



db_interface::db_disconnect();

sub main_func {
	my $table_verifiers;
	if ( $configuration::options{"verifiers"} eq "" ) {
		$table_verifiers = db_structure::verifiers_select();
	} else {
		my @ver_ids = split ",", $configuration::options{"verifiers"};
		$table_verifiers = db_structure::verifiers_select_by_ver_ids(@ver_ids);
	}
	
	while (my $verifier = $table_verifiers->fetchrow_hashref()) {

		# creating a new testing session
		my ($sec, $min, $hour, $mday, $mon, $year) =  localtime(time);
		my $time_start = sprintf("%4d-%02d-%02d %02d:%02d:%02d", 
			$year+1900, $mon+1, $mday, $hour, $min, $sec);

		my $session_id = db_structure::testingsession_insert(
			$verifier->{"ver_id"}, $time_start, $configuration::options{"description"});

		my $table_tests
			= db_structure::analysis_select_test_id_and_path_and_keywords_by_ver_id(
			$verifier->{"ver_id"});

		while (my $test = $table_tests->fetchrow_hashref()) {
			run_verifier($verifier, $test, $session_id);
		}

		# updating time_end in TestingSessions table
		($sec, $min, $hour, $mday, $mon, $year) =  localtime(time);
		my $time_end = sprintf("%4d-%02d-%02d %02d:%02d:%02d", 
			$year+1900, $mon+1, $mday, $hour, $min, $sec);
		db_structure::testingsession_update_time_end($session_id, $time_end);
	}
}

sub run_verifier {
	my ($verifier, $test, $session_id) = @_;

	# running $verifier on a $test
	my $output = core_lib::verifier_call($verifier, $test);
	
	my $output_id = db_structure::output_insert_or_select_id($output);	

	# interpreting the output
	my $interpretation;

	$output =~ s/[\s\r\n]+/ /g;

	my @keywords = split / \| /, $test->{"keywords"};
	
	my $catch = "false";
	while ( my $or_keywords = shift @keywords ) {
		my $flag = "true";
		my @and_keywords = split / \& /, $or_keywords;
		while ( my $keyword = shift @and_keywords ) {
			unless ( $output =~ /$keyword/ ) {
				$flag = "false";
				last;
			}
		}
		if ( $flag eq "true" ) {
			$catch = "true";
			last;
		}
	}
	if ( $catch eq "true" ) {
		$interpretation = "exact";
	} else {
		if ($output =~ /warning/) {
			$interpretation = "something";
		} else {
			$interpretation = "nothing";
		}
	}
	messages::verbose("$verifier->{name}, $verifier->{version}"
			. "\tTest #$test->{test_id}, '$test->{path}'\tResult: $interpretation");
	# creating the report
	db_structure::testing_insert($test->{"test_id"},
			$session_id, $output_id, $interpretation);
}

sub usage {
	print "Usage:\n";
	print "$0 [KEYS] run\n";
	print "$0 help\n";
	print "\n";
	print "Commands:\n";
	print "run        run verifiers through the set of tests\n";
	print "help       print this message and exit\n";
	print "\n";
	print "Keys:\n";
	print "-v, --verbose         verbose mode\n";
	print "--debug               additional debug information\n";
	print "--debug-lib           additional debug information from libraries\n";
	print "--verifiers=          list of verifier's ids to run like '0,2,8'\n";
	print "--description=        add description to the testing sessions\n";
}
