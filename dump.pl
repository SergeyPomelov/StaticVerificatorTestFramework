#!/usr/bin/perl

use strict;
use warnings;

use configuration;
use messages;

my @all_dumps = qw(core classification tests verifiers testing);
my $default_restore = "tests";

@ARGV = configuration::keys_to_options(@ARGV);
configuration::config_read();

my $dumps = $configuration::config{"DataBase_Dumps"};
my $prefix = $configuration::config{"DataBase_DumpCmd_Prefix"};
my $ps = $configuration::config{"PathSeparator_System"};
my $psl = $configuration::config{"PathSeparator_DataBase"};

my ($cmd, $type) = @ARGV;

if ( ! defined $cmd ) {
	die "Command expected. Try '$0 help' for more info.";
}

if ( $cmd eq "create" ) {
	if ( ! defined $type or $type eq "all" ) {
		messages::verbose("Creating all dumps");
		for ( @all_dumps ) {
			dump_create($_);
		}
	} else {
		dump_create($type);
	}
} elsif ( $cmd eq "restore" ) {
	if ( ! defined $type ) {
		$type = $default_restore;
	}
	dump_restore($type);
} elsif ( $cmd eq "help" ) {
	usage();
} else {
	die "Unknown command: '$cmd'. Try '$0 help' for more info";
}

sub dump_create {
	my ($type) = @_;

	messages::verbose("Creating '$type' dump");

	my $cmd = $dumps . $ps . $prefix . "dump_cmd_" . $type;
	$cmd =~ s/$psl/$ps/g;
	
		if ( ! -e "$cmd" ) {
		die "No such dump cmd file: '$cmd'";
	}

	my $dump = $dumps . $ps . "dump_" . $type . ".sql";
	$dump =~ s/$psl/$ps/g;
	
	if ( ! -e "$dump" ) {
		die "No such dump file: '$dump'";
	}

	if ( $configuration::config{"DataBase_Type"} eq "SQLite" ) {
		my $db = $configuration::config{"DataBase_SQLite_File"};
		$db =~ s/$psl/$ps/g;

		my $bin = $configuration::config{"DataBase_SQLite_Bin"};
		$bin =~ s/$psl/$ps/g;

		messages::debug("'$bin' '$db' < '$cmd' > '$dump'");
		`"$bin" "$db" < "$cmd" > "$dump"`;
	} else {
		die "Unknown database type: '" . $configuration::config{"DataBase_Type"} . "'";
	}
}

sub dump_restore {
	my ($type) = @_;

	messages::verbose("Restoring '$type' dump");

	my $dump = $dumps . $ps . "dump_" . $type . ".sql";
	$dump =~ s/$psl/$ps/g;

	if ( ! -e "$dump" ) {
		die "No such dump file: '$dump'";
	}

	if ( $configuration::config{"DataBase_Type"} eq "SQLite" ) {
		my $db = $configuration::config{"DataBase_SQLite_File"};
		$db =~ s/$psl/$ps/g;
		
		if ( -e "$db" ) {
			unlink($db);
		}

		my $bin = $configuration::config{"DataBase_SQLite_Bin"};
		$bin =~ s/$psl/$ps/g;

		messages::debug("'$bin' '$db' < '$dump'");
		`"$bin" "$db" < "$dump"`;
	} else {
		die "Unknown database type: '" . $configuration::config{"DataBase_Type"} . "'";
	}
	
}

sub usage {
	print "Usage:\n";
	print "  $0 [KEYS] create [TYPE]\n";
	print "  $0 [KEYS] restore [TYPE]\n";
	print "  $0 help\n";
	print "\n";
	print "Commands:\n";
	print "  create          create a dump of specified type (all dumps if type is ommited)\n";
	print "  restore         restore the database from the dump ('tests' dump is default)\n";
	print "\n";
	print "Dump types:\n";
	print "  core            just table schemas\n";
	print "  classification  dump of classification\n";
	print "  tests           dump of classification and tests\n";
	print "  verifiers       dump of classification, tests and verifiers\n";
	print "  testing         complete dump of the database\n";
	print "  all             select all dumps (for 'create' command only)\n";
	print "\n";
	print "Keys:\n";
        print "  -v, --verbose   verbose mode\n";
        print "  --debug         additional debug information\n";
        print "  --debug-lib     additional debug information from libraries\n";
}
