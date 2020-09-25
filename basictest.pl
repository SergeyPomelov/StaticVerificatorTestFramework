#!/usr/bin/perl

use strict;
use warnings;

use configuration;
use db_interface;
use db_structure;
use messages;

@ARGV = configuration::keys_to_options(@ARGV);
configuration::config_read();

db_interface::db_connect();

my $cmd = shift @ARGV;

unless ( defined $cmd) {
	die "Command expected. Try '$0 help' for more info.";
}

if ($cmd eq "add") {
	my ($path, $level_id) = @ARGV;
	if ( ! defined $path || ! defined $level_id) {
		die "Not enough arguments. Try '$0 help' for more info."
	}
	basictest_add($path, $level_id);
} elsif ($cmd eq "add_id") {
	my ($test_id, $level_id) = @ARGV;
	if ( ! defined $test_id || ! defined $level_id ) {
		die "Not enough arguments. Try '$0 help' for more info."
	}
	basictest_add_id($test_id, $level_id);
} elsif	($cmd eq "remove") {
	my ($path) = @ARGV;
	if ( ! defined $path ) {
		die "Not enough arguments. Try '$0 help' for more info."
	}
	basictest_remove($path);
} elsif	($cmd eq "remove_id") {
	my ($test_id) = @ARGV;
	if ( ! defined $test_id ) {
		die "Not enough arguments. Try '$0 help' for more info."
	}
	basictest_remove_id($test_id);
} elsif	($cmd eq "help") {
	usage();
} else {
	die "Unknown command: '$cmd'. Try '$0 help' for more info";
}

db_interface::db_disconnect();

sub basictest_add {
	my ($path, $level_id) = @_;
	my $msg_prefix = "'$path':";
	my $test_id = db_structure::test_select_id_by_path($path);
	if ( ! defined $test_id ) {
		die "$msg_prefix No such test.";
	}
	basictest_add_id($test_id, $level_id);
}

sub basictest_add_id {
	my ($test_id, $level_id) = @_;
	my $msg_prefix = "#$test_id:";
	if ( ! defined db_structure::test_select_by_id($test_id) ) {
		die "$msg_prefix No such level.";
	}
	if ( ! defined db_structure::level_select_by_id($level_id) ) {
		die "$msg_prefix No such level.";
	}
	my $value_id = db_structure::classification_select_value_id_by_test_id_and_level_id($test_id, $level_id);
	if ( ! defined $value_id ) {
		die "$msg_prefix Test classification is incomplete.";
	}
	db_structure::basictests_insert($test_id, $value_id);
}

sub basictest_remove {
	my ($path) = @_;
	my $msg_prefix = "'$path':";
	my $test_id = db_structure::test_select_id_by_path($path);
	if ( ! defined $test_id ) {
		die "$msg_prefix No such test.";
	}
	basictest_remove_id($test_id);
}

sub basictest_remove_id {
	my ($test_id) = @_;
	my $msg_prefix = "#$test_id:";
	db_structure::basictest_delete_by_test_id($test_id);
}

sub usage {
	print "Usage:\n";
	print "  $0 [KEYS] add PATH LEVEL_ID\n";
	print "  $0 [KEYS] add_id TEST_ID LEVEL_ID\n";
	print "  $0 [KEYS] remove PATH\n";
	print "  $0 [KEYS] remove_id TEST_ID\n";
	print "  $0 help\n";
	print "\n";
	print "Commands:\n";
	print "  add		add test to the BasicTests table\n";
	print "  add_id		add test to the BasicTests table by it's ID\n";
	print "  remove		remove test from BasicTests table\n"
	    . "			(keeps test in Tests table)\n";
	print "  remove_id	remove test by it's ID\n"
	    . "			(keeps test in Tests table)\n";
	print "  help		print this message and exit\n";
	print "\n";
	print "Keys:\n";
	print "  -v, --verbose	verbose mode\n";
}
