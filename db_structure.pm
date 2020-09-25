package db_structure;

#our @EXPORT = qw(analisys_insert verifier_insert
#	verifier_getid verifier_getbyid);
#our @ISA = qw(Exporter);

use strict;
use warnings;

use db_interface;
use configuration;
use core_lib;

sub analysis_insert {
	my ($ver_id, $value_id, $keywords) = @_;
	my $sql_query = "INSERT INTO Analysis"
		. " (ver_id, value_id, keywords)"
		. " VALUES (?, ?, ?)";
	db_interface::db_query($sql_query, $ver_id, $value_id, $keywords);
}

sub analysis_select_test_id_and_path_and_keywords_by_ver_id {
	my ($ver_id) = @_;
	my $sql_query = "SELECT Tests.test_id, Tests.path,"
		. " Analysis.keywords"
		. " FROM Tests, Classification, Analysis"
		. " WHERE Tests.test_id = Classification.test_id"
		. " AND Classification.value_id = Analysis.value_id"
		. " AND Analysis.ver_id = ?;";
	return db_interface::db_query($sql_query, $ver_id);
}

sub analysis_delete_by_ver_id {
	my ($ver_id) = @_;
	my $sql_query = "DELETE FROM Analysis WHERE ver_id = ?;";
	db_interface::db_query($sql_query, $ver_id);
}

#sub basictests_select {
#	my $sql_query = "SELECT * FROM BasicTests, Tests, \"Values\""
#	        . " WHERE BasicTests.test_id = Tests.test_id"
#	        . " AND BasicTests.value_id = \"Values\".value_id"
#	        . " ORDER BY value_id ASC, positive DESC;";
#	my $table_basictests = db_interface::db_query($sql_query);
#	return $table_basictests;
#}

sub basictests_select_values_groups {
	my $sql_query = "SELECT BasicTests.value_id, description FROM BasicTests, \"Values\""
		. " WHERE BasicTests.value_id = \"Values\".value_id"
		. " GROUP BY BasicTests.value_id;";
	my $values_groups = db_interface::db_query($sql_query);
	return $values_groups;
}

sub basictests_select_by_value_id_and_positive {
	my ($value_id, $positive) = @_;
	my $sql_query = "SELECT * FROM BasicTests, Tests"
		. " WHERE BasicTests.test_id = Tests.test_id"
		. " AND value_id = ? AND positive = ?;";
	my $table_basictests = db_interface::db_query($sql_query, $value_id, $positive);
	return $table_basictests;
}

sub basictests_insert {
	my ($test_id, $value_id) = @_;
	my $sql_query = "INSERT INTO BasicTests (test_id, value_id)"
		. " VALUES (?, ?);";
	db_interface::db_query($sql_query, $test_id, $value_id);
}

sub basictest_delete_by_test_id {
	my ($test_id) = @_;
	my $sql_query = "DELETE FROM BasicTests WHERE test_id = ?;";
	db_interface::db_query($sql_query, $test_id);
}

sub classification_select_value_id_by_test_id_and_level_id {
	my ($test_id, $level_id) = @_;
	my $sql_query = "SELECT value_id FROM Classification"
		. " WHERE test_id = ? AND level_id = ?;";
	my $table_classification = db_structure::db_query($sql_query,
		$test_id, $level_id);
	if (my $row = $table_classification->fetchrow_hashref()) {
		return $row->{"value_id"};
	}
	return undef;
}

#by Igor
sub classification_select_test_id_by_level_and_value_and_tests {
	my ($level_id, $value_id, @test_ids) = @_;
	my $test_ids_rowref = join (", ", @test_ids);
	my $sql_query = "SELECT test_id FROM Classification"
		. " WHERE level_id = ? AND value_id = ? AND test_id IN (" . $test_ids_rowref . ");";
	my $testids_table = db_structure::db_query($sql_query, $level_id, $value_id);
	return $testids_table;
}	

sub classification_insert {
	my ($test_id, $level_id, $value_id) = @_;
	my $sql_query = "INSERT INTO Classification"
		. " (test_id, level_id, value_id) VALUES (?, ?, ?)";
	db_interface::db_query($sql_query, $test_id, $level_id, $value_id);
}

sub classification_delete_by_test_id {
	my ($test_id) = @_;
	my $sql_query = "DELETE FROM Classification WHERE test_id = ?";
	db_interface::db_query($sql_query, $test_id);
}

sub level_select_by_id {
	my ($level_id) = @_;
	my $sql_query = "SELECT * FROM Levels where level_id = ?;";
	my $table_levels = db_interface::db_query($sql_query, $level_id);
	return $table_levels->fetchrow_hashref();
}

sub levels_select {
	my $sql_query = "SELECT level_id from Levels ORDER BY level_id;";
	my $table_levels = db_interface::db_query($sql_query);
	return $table_levels;
}

sub output_insert_or_select_id {
	my ($output) = @_;

	my $output_id = output_select_id($output);

	if ( defined $output_id) {
		return $output_id;
	}

	# there is no such output in db
	my $output_hash = core_lib::hash_function($output);
	my $sql_query = "INSERT INTO Output (output_text, hash) values (?, ?);";
	my $table_output = db_interface::db_query($sql_query, $output, $output_hash);
	$output_id = db_interface::db_last_insert_id("Output");
	return $output_id;

}

sub output_select_id {
	my ($output) = @_;
	# trying to determine whether $output is already in DB or not
	my $output_hash = core_lib::hash_function($output);
	my $sql_query = "SELECT * FROM Output WHERE hash = ?;";
	my $table_output = db_interface::db_query($sql_query, $output_hash);
	my $output_id;
	while (my $row_output = $table_output->fetchrow_hashref()) {
		if ($row_output->{"output_text"} eq $output) {
			$output_id = $row_output->{"output_id"};
		}
	}
	return $output_id;
}

sub testingsession_insert {
	my ($ver_id, $time_start, $description) = @_;
	my $sql_query = "INSERT INTO TestingSessions (ver_id, time_start, description) VALUES (?, ?, ?)";
	my $table_testingsessions = db_interface::db_query($sql_query, $ver_id, $time_start, $description);
	my $session_id = db_interface::db_last_insert_id("TestingSessions");
	return $session_id;
}

sub testingsession_update_time_end {
	my ($session_id, $time_end) = @_;
	my $sql_query = "UPDATE TestingSessions SET time_end = ? WHERE session_id = ?;";
	my $table_testingsessions = db_interface::db_query($sql_query, $time_end, $session_id);
}

#by Igor
sub testingsession_select_date_and_id_by_ver_id {
	my ($ver_id) = @_;
	my $sql_query = "SELECT time_start, session_id, description FROM TestingSessions WHERE ver_id = ? ORDER BY session_id;";
	my $table_testingsessions = db_interface::db_query($sql_query, $ver_id);
	return $table_testingsessions;
}

#by Igor
sub testingsession_select_session_id_by_verifier_and_time {
	my ($ver_id, $testing_time) = @_;
	my $sql_query = "SELECT session_id FROM TestingSessions WHERE ver_id = ? AND time_start = ?;";
	my $sess_id_row = db_interface::db_query($sql_query, $ver_id, $testing_time);
	my $sess_id = $sess_id_row->fetchrow_hashref();
	return $sess_id->{"session_id"};
}

sub test_select_by_id {
	my ($test_id) = @_;
	my $sql_query = "SELECT * FROM Tests WHERE test_id = ?";
	my $table_tests = db_interface::db_query($sql_query, $test_id);
	return $table_tests->fetchrow_hashref();
}

sub test_select_id_by_path {
	my ($path) = @_;
	my $sql_query = "SELECT * FROM Tests WHERE path = ?";
	my $table_tests = db_interface::db_query($sql_query, $path);
	if ( my $test = $table_tests->fetchrow_hashref() ) {
		return $test->{"test_id"};
	}
	return undef;
}

sub test_delete_by_id {
	my ($test_id) = @_;
	my $sql_query = "DELETE FROM Tests WHERE test_id = ?;";
	db_interface::db_query($sql_query, $test_id);
}

sub test_insert {
        my ($path) = @_;
	my $sql_query = "INSERT INTO Tests (path) VALUES (?);";
	my $insert_test = db_interface::db_query($sql_query, $path);
	my $test_id = db_interface::db_last_insert_id("Tests");
	return $test_id;
}

sub test_update_positive_by_id {
	my ($test_id, $positive) = @_;
	my $sql_query = "UPDATE Tests SET positive = ? WHERE test_id = ?";
	db_interface::db_query($sql_query, $positive, $test_id);
}

sub testing_insert {
	my $sql_query = "INSERT INTO Testing" .
		" (test_id, session_id, output_id, result)"
		. "values (?, ?, ?, ?);";
	db_interface::db_query($sql_query, @_);
}

sub testing_delete_by_test_id {
	my ($test_id) = @_;
	my $sql_query = "DELETE FROM Testing WHERE test_id = ?;";
	db_interface::db_query($sql_query, $test_id);
}

sub tests_select {
	return db_interface::db_query("SELECT * FROM Tests;")
}

#by Igor
sub testing_select_testid_by_sess_id {
	my ($sess_id) = @_;
	my $sql_query = "SELECT test_id FROM Testing WHERE session_id = ?;";
	my $testids_table = db_interface::db_query($sql_query, $sess_id);
	return $testids_table;
}

#by Igor
sub testing_select_resultvalues_by_sess_id_and_testids {
	my ($sess_id, @test_ids) = @_;
	my $test_ids_rowref = join (", ", @test_ids);
	my $sql_query = "SELECT DISTINCT result FROM Testing"
		. " WHERE session_id = ? AND test_id IN (".$test_ids_rowref.");";
	my $resvalues = db_interface::db_query($sql_query, $sess_id);
	return $resvalues;
}

#by Igor
sub testing_count_resultvalues_by_sess_id_and_testids {
	my ($sess_id, $value, @test_ids) = @_;
	my $test_ids_rowref = join (", ", @test_ids);
	my $sql_query = "SELECT COUNT(test_id) FROM Testing"
			. " WHERE session_id = ? AND result = ? AND test_id IN (".$test_ids_rowref.");";
	my $resvalues = db_interface::db_query($sql_query, $sess_id, $value);
	my $result =  $resvalues->fetchrow_hashref();
	return $result->{"COUNT(test_id)"};
}

#by Igor
sub testing_select_result_by_testid_and_sessid {
	my ($sess_id, $test_id) = @_;
	my $sql_query = "SELECT result FROM Testing WHERE session_id = ? AND test_id = ?;";
	my $resrow = db_interface::db_query($sql_query, $sess_id, $test_id);
	my $result = $resrow->fetchrow_hashref();
	return $result->{"result"};
}

#by Igor
sub testing_count_tests_by_sessid {
	my ($sess_id) = @_;
	my $sql_query = "SELECT COUNT(test_id) FROM Testing WHERE session_id = ?;";
	my $resrow = db_interface::db_query($sql_query, $sess_id);
	my $result = $resrow->fetchrow_hashref();
	return $result->{"COUNT(test_id)"};
}

sub value_select_id {
	my ($level_id, $value) = @_;
	my $sql_query = "SELECT value_id FROM \"Values\" WHERE level_id = ? AND value = ?";
	my $table_values = db_interface::db_query($sql_query, $level_id, $value);
	if (my $row_value = $table_values->fetchrow_hashref()) {
		return $row_value->{"value_id"};
	}
	return undef;
}

sub value_insert_or_select_id {
	my ($level_id, $value) = @_;
	# checking if current value is in the Values table
	my $value_id = value_select_id($level_id, $value);
	if ( defined $value_id ) {
		return $value_id;
	}
	# there is no such value, adding it
	my $sql_query = "INSERT INTO \"Values\" (level_id, value) VALUES (?, ?);";
	my $insert_value = db_interface::db_query($sql_query, $level_id, $value);
	$value_id = db_interface::db_last_insert_id("Values");
	return $value_id;
}

#by Igor
sub value_select_by_level_id {
	my ($level_id) = @_;
	my $sql_query = "SELECT * FROM \"Values\" WHERE level_id = ?;";
	my $value_table = db_interface::db_query($sql_query, $level_id);
	return $value_table;
}

#by Igor
sub value_select_level_id_by_value {
	my ($value) = @_;
	my $sql_query = "SELECT level_id, value_id FROM \"Values\" WHERE value = ?;";
	my $val_table = db_interface::db_query($sql_query, $value);
	my $val_row = $val_table->fetchrow_hashref();
	return $val_row;
}

sub verifier_insert {
	my ($name, $version, $executable, $keys, $output_stream, $path_separator) = @_;
	my $sql_query = "INSERT INTO Verifiers" 
		. " (name, version, executable, keys, output_stream, path_separator)"
		. " VALUES (?, ?, ?, ?, ?, ?)";
	db_interface::db_query($sql_query, @_);
	my $ver_id = db_interface::db_last_insert_id("Verifiers");
	return $ver_id;
}

sub verifier_select_id_by_name_and_version {
	my ($name, $version) = @_;
	my $sql_query = "SELECT * FROM Verifiers"
		. " WHERE name = ? AND version = ?;";
	my $table_verifiers = db_interface::db_query($sql_query, $name, $version);
	if ( my $verifier = $table_verifiers->fetchrow_hashref() ) {
		return $verifier->{"ver_id"};
	}
	return undef;
}

sub verifier_select_by_id {
	my ($ver_id) = @_;
	my $sql_query = "SELECT * FROM Verifiers WHERE ver_id = $ver_id;";
	my $table_verifiers = db_interface::db_query($sql_query);
	return $table_verifiers->fetchrow_hashref(); 
}

sub verifier_delete_by_id {
	my ($ver_id) = @_;
	my $sql_query = "DELETE FROM Verifiers WHERE ver_id = ?;";
	db_interface::db_query($sql_query, $ver_id);
}

sub verifiers_select {
	return db_interface::db_query("SELECT * FROM Verifiers;");
}

sub verifiers_select_by_ver_ids {
	my $ver_ids = join ', ', @_; 
	return db_interface::db_query("SELECT * FROM Verifiers WHERE ver_id IN (" . $ver_ids . ");");
}

#by Igor
sub verifiers_smart_select {
	return db_interface::db_query("SELECT name, version, ver_id FROM Verifiers ORDER BY name, version;");
}

1
