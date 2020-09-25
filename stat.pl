#!/usr/bin/perl

use strict;
use warnings;

use configuration;
use db_interface;
use db_structure;

configuration::option_add("order", "no");

configuration::key_add("--order", "order");

@ARGV = configuration::keys_to_options(@ARGV);

configuration::config_read();

db_interface::db_connect();


my $cmd = shift @ARGV;

unless ( defined $cmd) {
	die "Command expected. Try '$0 help' for more info.";
}

if ($cmd eq "info") {
	getinfo();
} elsif ($cmd eq "statbyname") {
	my ($ver_name, $ver_ver, $sess_date) = @ARGV;
	if (!defined $ver_name || !defined $ver_ver || !defined $sess_date){
		die "Not enough arguments. Try '$0 help' for more info.";
	}
	print_by_name ($ver_name, $ver_ver, $sess_date);
} elsif ($cmd eq "stat") {
	my ($sess_id) = @ARGV;
	if (!defined $sess_id) {
		die "Not enough arguments. Try '$0 help' for more info.";
	}
	print_by_id ($sess_id);
} elsif	($cmd eq "help") {
	usage();
} else {
	die "Unknown command: '$cmd'. Try '$0 help' for more info";
}

db_interface::db_disconnect();

sub getinfo {
	my $allverifiers = db_structure::verifiers_smart_select();
	my $verifier = $allverifiers->fetchrow_hashref();
	if (! defined $verifier) {
		print "There are no verifiers";
		return;
	}
	do {
		print ($verifier->{"name"}." ".$verifier->{"version"}."\n");
		my $tsessions = db_structure::testingsession_select_date_and_id_by_ver_id($verifier->{"ver_id"});
		my $session = $tsessions->fetchrow_hashref();
		if (!defined $session) {
			print ("No sessions available");
		}
		else {
			print ("Sessions available: \n");
		}
		do {
			my $test_count = db_structure::testing_count_tests_by_sessid($session->{"session_id"});
			print ("id = ".$session->{"session_id"}.", date = ".$session->{"time_start"}.", tests = ".$test_count);
			if (defined $session->{"description"} && $session->{"description"} ne "") {
				print ", ".$session->{"description"};
			}
			print "\n";
		} while ($session = $tsessions->fetchrow_hashref());
		print "\n";
	} while ($verifier = $allverifiers->fetchrow_hashref());
}

sub print_by_name {
	my ($verifier_name, $verifier_version, $sess_date) = @_;
	my $ver_id = db_structure::verifier_select_id_by_name_and_version($verifier_name, $verifier_version);
	if (!defined $ver_id) {
		print "No such verifier, try '$0 info' to see available verifiers\n";
		return;
	}
	my $sess_id = db_structure::testingsession_select_session_id_by_verifier_and_time($ver_id, $sess_date);
	if (!defined $sess_id) {
		print "No such testing session, try '$0 info' to see available sessions\n";
		return;
	}
	print_by_id ($sess_id);
}

sub print_by_id {
	my ($sess_id) = @_;
	my $order = $configuration::options{"order"};
	
	my $testids = db_structure::testing_select_testid_by_sess_id($sess_id);
	my $i = 0;
	my @ids;
	while (my $test_id = $testids->fetchrow_hashref()) {
		$ids[$i++] = $test_id->{"test_id"};
	}
	if ($i==0) {
		print "Testing session doesn't exist or is empty, try '$0 info' to see available sessions\n";
		return;
	}
	
	#processing 'cut' option
	my $testids_cut = core_lib::testids_cut(@ids);
	if (!defined $testids_cut) {
		return;
	}
	@ids = split(",", $testids_cut);
	
	#checking order correctness
	my @orderarray = undef;
	my $order_rowref = undef;
	if ($order ne "no" && $order ne "yes") {
		(@orderarray) = split(',', $order);
		my @ordernames;
		$i=0;
		foreach my $stat_level(@orderarray) {
			my $levelcheck = db_structure::level_select_by_id($stat_level);
			if (!defined $levelcheck->{"description"}){
				die "No such level: ".$stat_level.", read the classification technical info at http://www.i-lab.nsu.ru/wiki/index.php/StaticVerifier_classification \n";
			}
			$ordernames[$i++] = $levelcheck->{"level_name"};
		}
		#printing header
		print "Printing statistics ordered by: ".$ordernames[0];
		$i=1;
		while (defined $ordernames[$i]) {
			print " -> ".$ordernames[$i++];
		}		
		print "\n";
		
		$i=1;
		$order_rowref = $orderarray[0];
		while (defined $orderarray[$i]) {
			$order_rowref .= ",".$orderarray[$i++];
		}
	} else {
		print "Printing overall statistics: \n";
	}
	
	level_parse($order_rowref, 0, $sess_id, @ids);
}

sub level_parse {
	my ($order_rowref, $depth, $sess_id, @ids) = @_;
	if (!defined $order_rowref) {
		statify($depth, $sess_id, @ids);
		return;
	}
	my @orderarray = split(',', $order_rowref);
	my $level = shift @orderarray;
	
	my $i=1;
	$order_rowref = $orderarray[0];
	while (defined $orderarray[$i]) {
		$order_rowref .= ",".$orderarray[$i++];
	}
	
	my $val_table = db_structure::value_select_by_level_id($level);
	my @pos_vals;
	$i=0;
	while (my $val_row = $val_table->fetchrow_hashref()) {
		$pos_vals[$i++] = $val_row->{"value"};
	}
	
	foreach my $pos_val (@pos_vals) {
		#restriction of test_ids
		my $val_id = db_structure::value_select_id($level, $pos_val);
		my $new_ids_array = db_structure::classification_select_test_id_by_level_and_value_and_tests($level, $val_id, @ids);
		$i = 0;
		my @new_ids;
		while (my $new_test_id = $new_ids_array->fetchrow_hashref()) {
			$new_ids[$i++] = $new_test_id->{"test_id"};
		}
		if (defined $new_ids[0]) {
			print "    "x$depth.$pos_val.":\n";
			level_parse($order_rowref, $depth+1, $sess_id, @new_ids);
		}
	}
}

#printing statistics for given set of test_ids
sub statify {
	my ($depth, $sess_id, @ids) = @_;
	my $verbose = $configuration::options{"verbose"};	
	
	if ($verbose eq "yes") {			#processing verbose mode
		my $resvalues = db_structure::testing_select_resultvalues_by_sess_id_and_testids($sess_id, @ids);
		print "    "x$depth."Tests: ".($#ids+1)."\n";
		while (my $value = $resvalues->fetchrow_hashref()) {
			my $fix_result_count = db_structure::testing_count_resultvalues_by_sess_id_and_testids($sess_id, $value->{"result"}, @ids);
			print "    "x$depth.$value->{"result"}.": ". sprintf("%.0f",($fix_result_count*100/($#ids+1))). "%\n";
		}
		return;
	}
	
	my (@pos_ids, @neg_ids);			#dividing ids into two groups
	foreach my $id (@ids) {
		my $val = db_structure::test_select_by_id($id);
		$val = $val->{"positive"};
		if ($val eq "p") {
			$pos_ids[$#pos_ids+1] = $id;
		} 
		elsif ($val eq "n") {
			$neg_ids[$#neg_ids+1] = $id;
		}
	}
	
	my $passrate = 0;
	foreach my $id (@pos_ids) {			#processing positive ids
		my $result = db_structure::testing_select_result_by_testid_and_sessid($sess_id, $id);
		if ($result eq "nothing" || $result eq "something") {
			$passrate++;
		}
	}
	foreach my $id (@neg_ids) {			#processing negative ids
		my $result = db_structure::testing_select_result_by_testid_and_sessid($sess_id, $id);
		if ($result eq "exact") {
			$passrate++;
		}
	}
	print "    "x$depth."Tests: ".($#ids+1)."\n";
	print "    "x$depth."Pass-rate is ". sprintf("%.0f",($passrate*100/($#ids+1))). "%\n";	
}

sub usage {
	print "Usage:\n";
	print "  $0 info\n";
	print "  $0 [KEYS] stat session_id\n";
	print "  $0 [KEYS] statbyname verif_name verif_version testing_date\n";
	print "  $0 help\n";
	print "\n";
	print "Commands:\n";
	print "  info		show available testing sessions\n";
	print "  stat	 	show statistics for chosen session\n";
	print "  statbyname	show statistics for session chosen by name and version of"
			."			verifier and testing date\n";	
	print "  help		print this message and exit\n";
	print "\n";
	print "Keys:\n";
	print "  -v, --verbose		verbose statistics mode\n";
	print "  --order=stat_order,	it is a record in form 'lev1,lev3,lev2..', where lev_i"
			."				is an ID of classification level. This option allows"
			."				to display statistics in tree-like form specified by"
			."				the given order\n";
	print "  --cut=needed_values,	it is a record in form 'values1,values2,values3..',"
			."				where values_i is a set of values corresponding to"
			."				certain classification level, separated by '/' symbol."
			."				This option allows to display section of overall"
			."				statistics containing tests with given classification"
			."				values\n";
}
