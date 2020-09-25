#!/usr/bin/perl

use strict;
use warnings;

use configuration;
use messages;
use db_interface;
use db_structure;

configuration::option_add("duplicate", "no");
configuration::option_add("skip-checks", "no");

configuration::key_add("--duplicate", "duplicate");
configuration::key_add("-d", "duplicate");
configuration::key_add("--skip-checks", "skip-checks");
configuration::key_add("-s", "skip-checks");

@ARGV = configuration::keys_to_options(@ARGV);

configuration::config_read();

db_interface::db_connect();

my $cmd = shift @ARGV;

unless ( defined $cmd) {
	die "Command expected. Try '$0 help' for more info.";
}

if ($cmd eq "add") {
	while (my $path = shift @ARGV) {
		test_add($path);
	}	
} elsif	($cmd eq "classify") {
	while (my $path = shift @ARGV) {
		test_classify($path);
	}	
} elsif	($cmd eq "remove") {
	while (my $path = shift @ARGV) {
		test_remove($path);
	}	
} elsif	($cmd eq "remove_id") {
	while (my $test_id = shift @ARGV) {
		test_remove_id($test_id);
	}
} elsif	($cmd eq "help") {
	usage();
} else {
	die "Unknown command: '$cmd'. Try '$0 help' for more info";
}

db_interface::db_disconnect();

sub test_add {
	my ($path) = @_;
	my $msg_prefix = "'$path':";

	unless ($configuration::options{"skip-checks"} eq "yes") {
		check_file($path);
	}
	
	# checking if there is already such test
	my $sql_query;
	unless ($configuration::options{"duplicate"} eq "yes") {
		messages::debug("$msg_prefix Checking if the test is already in DB");
		my $test_id = db_structure::test_select_id_by_path($path);
		if (defined $test_id) {
			die "$msg_prefix Test is already in DB, test_id: $test_id";
		}
	}
	
	# adding test to the Tests table
        messages::debug("$msg_prefix Adding test to the DB");
	
	my $test_id = db_structure::test_insert($path);
	
	messages::debug("$msg_prefix test_id = $test_id");

	my $classification = get_classification_line($path);
	
	test_classify_id($test_id, $classification);
	messages::verbose("A #$test_id\t$path\t$classification");
}

sub test_classify {
	my ($path) = @_;
	my $msg_prefix = "'$path':";

	messages::debug("$msg_prefix Getting the test_id");

	my $test_id = db_structure::test_select_id_by_path($path);
	
	if ( ! defined $test_id ) {
		die "$msg_prefix There is no such test."
	}

	messages::debug("$msg_prefix test_id = $test_id");

	my $classification = get_classification_line($path);

	test_classify_id($test_id, $classification);
}

sub test_classify_id {
	my ($test_id, $classification) = @_;
	my $msg_prefix = "#$test_id:";

	messages::debug("$msg_prefix Classifying test. Checking if the test_id is not corect");

	my $test = db_structure::test_select_by_id($test_id);

	if ( ! defined $test ) {
		die "$msg_prefix There is no such test";
	}

	messages::debug("$msg_prefix Deleting old classification if any");
	
	db_structure::classification_delete_by_test_id($test_id);

	# parsing classification line according to the Levels table
	messages::debug("$msg_prefix Parsing the classification line");

	my %values;
	my @values_list = split /\//, $classification;
	my $table_levels = db_structure::levels_select();
	while (my $level = $table_levels->fetchrow_hashref()) {
		if ($#values_list < 0) {
			die "$msg_prefix Incorrect classification: '$classification'";
		}
		$values{$level->{level_id}} = shift(@values_list);
	}

	# writing the classification
	messages::debug("$msg_prefix Writing the classification");

	$table_levels = db_structure::levels_select();
	while (my $level = $table_levels->fetchrow_hashref()) {
		my $level_id = $level->{level_id};
		my $value_id = db_structure::value_insert_or_select_id($level_id,
			$values{$level_id});
		# adding line to the Classification table
		db_structure::classification_insert($test_id,
			$level_id, $value_id);
	}

	messages::debug("$msg_prefix Updating the 'Tests.positive' field");

	db_structure::test_update_positive_by_id($test_id, $values{"0"});
}

sub test_remove_id {
	my ($test_id) = @_;
	my $msg_prefix = "#$test_id:";

	messages::debug("$msg_prefix Checking if there is no such test");

	my $test = db_structure::test_select_by_id($test_id);
	if ( ! defined $test ) {
		die "$msg_prefix There is no such test: $test_id\n";
	}

	messages::debug("$msg_prefix Deleting the classification");

	db_structure::classification_delete_by_test_id($test_id);

	messages::debug("$msg_prefix Deleting the testing info");

	db_structure::testing_delete_by_test_id($test_id);

	messages::debug("$msg_prefix Deleting the basic test links");

	db_structure::basictest_delete_by_test_id($test_id);

	messages::debug("$msg_prefix Deleting the test");

	db_structure::test_delete_by_id($test_id);
}

sub test_remove {
	my ($path) = @_;
	my $msg_prefix = "'$path':";
	messages::debug("$msg_prefix Getting the test_id");

	my $test_id = db_structure::test_select_id_by_path($path);
	if ( ! defined $test_id ) {
		die "$msg_prefix There is no such test: '$path'";
	}

	messages::debug("$msg_prefix test_id = $test_id");
	test_remove_id($test_id);
}

sub get_classification_line {
	my ($path) = @_;
	
	my $msg_prefix = "'$path':";
	messages::debug("$msg_prefix Getting the classification line");

	my $fd;
	open $fd, $path or die "$msg_prefix Can not open file '$path': $!";
	my $first_line = <$fd>;
	close $fd;

	$first_line =~ s/[\r\n]//g;
	$first_line =~ s/^\/\/\s*//;
	$first_line =~ s/\s*$//;
	my $classification = $first_line;
	return $classification;
}

sub check_file {
	my ($path) = @_;
	my $msg_prefix = "'$path':";
	# check if file exists, is readable and is a regular text file
	
	messages::debug("$msg_prefix Checking file");

	if ( ! -e $path ) {
		die "$msg_prefix File does not exist";
	}
	
	if ( ! -r $path ) {
		die "$msg_prefix File is not readable";
	}
	
	if ( ! -T $path ) {
		die "$msg_prefix File is not a text file";
	}
}

sub usage {
	print "Usage:\n";
	print "  $0 [KEYS] add PATH1 [ PATH2 [ PATH3 ... ] ]\n";
	print "  $0 [KEYS] classify PATH1 [ PATH2 [ PATH3 ... ] ]\n";
	print "  $0 [KEYS] remove PATH1 [ PATH2 [ PATH3 ... ] ]\n";
	print "  $0 [KEYS] remove_id TEST_ID1 [ TEST_ID2 [ TEST_ID3 ... ] ]\n";
	print "  $0 help\n";
	print "\n";
	print "Commands:\n";
	print "  add		add tests to the database\n";
	print "  classify	(re-)classify the test\n";
	print "  remove		remove tests from the database\n"
	    . "  		(doesn't actually remove the file)\n";
	print "  removeid	remove tests from the database by their IDs\n";
	print "  help		print this message and exit\n";
	print "\n";
	print "Keys:\n";
	print "  -v, --verbose		verbose mode\n";
	print "  --debug		additional debug information\n";
	print "  --debug-lib		additional debug information from libraries\n";
	print "  -d, --duplicate	allow to add one test multiple times\n";
	print "  -s, --skip-checks	don't check if file is a readable text file\n";
}
