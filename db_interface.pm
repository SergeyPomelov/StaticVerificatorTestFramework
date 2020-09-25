package db_interface;

our @EXPORT = qw(db_connect db_disconnect db_query db_last_insert_id);
our @ISA = qw(Exporter);

use strict;
use warnings;
use messages;

use DBI;

use configuration;

my $dbh;	# a database interface

sub db_connect {
	if ($configuration::config{"DataBase_Type"} eq "SQLite") {
		$dbh = DBI->connect("dbi:SQLite:dbname="
			. $configuration::config{"DataBase_SQLite_File"},
			"", "") or die "$DBI::errstr";
	} else {
		die "Unknown database type: '"
			. $configuration::config{"DataBaseType"} . "'";
	}
}

sub db_disconnect {
	$dbh->disconnect();
}

sub db_query {
	my $sql_query = shift @_;
	my @substitute = @_;
	my $sub_text = join("', '", @substitute);
	$sub_text = "'$sub_text'";
	messages::debug_lib("SQL Query: '$sql_query', $sub_text");
	my $query = $dbh->prepare($sql_query) or die "$DBI::errstr";
	$query->execute(@substitute) or die "$DBI::errstr";
	return $query;
}

sub db_last_insert_id {
	my ($table) = @_;
	my $id = $dbh->last_insert_id(undef, undef, $table, undef)
		or die "$DBI::errstr";
	return $id;
}

1
