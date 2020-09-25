package configuration;

use strict;
use warnings;

our %config = (
	"DataBase_Type" => "SQLite",
	"DataBase_SQLite_File" => "database/sqlite.db",
	"DataBase_SQLite_Bin" => "/usr/bin/sqlite3",
	"DataBase_Dumps" => "database/dumps",
	"DataBase_DumpCmd_Prefix" => "sqlite_",
	"PathSeparator_DataBase" => "/",
	"PathSeparator_System" => "/",
	"HashFunction" => "md5_hex",
	"NullFile" => "/dev/null",
);

our %keys = (
	"--config-file" => ["config-file"],
	"--verbose" => ["verbose"],
	"-v" => ["verbose"],
	"--debug" => ["debug", "verbose"],
	"--debug-lib" => ["debug-lib", "debug", "verbose"],
	"--cut" => ["cut"],
);

our %options = (
	"config-file" => "core.conf",
	"verbose" => "no",
	"debug" => "no",
	"debug-lib" => "no",
	"cut" => "no",
);


sub keys_to_options {
	while ( my $arg = shift ) {
		unless ( $arg =~ /^-/ ) {
			unshift @_, $arg;
			last;
		}
		my ($key, $value);
		if ( $arg =~ /^--.+=.+/ ) {
			# long key with value
			($key, $value) = split /=/, $arg, 2;
		} else {
			# short key or key without value
			($key, $value) = ($arg, "yes");
		}
		unless ( defined @{ $keys{$key} } ) {
			die "Unknown key: '$arg'";
		}
		my @options_list = @{ $keys{$key} };
		foreach (@options_list) {
			$options{$_} = $value;
		}
	}
	return @_;
}

sub key_add {
	my $key = shift;
	my @options_list = @_;
	foreach ( @options_list ) {
		if ( ! defined $options{$_} ) {
			die "Unknown option: '$_'";
		}
	}
	@{ $keys{$key} } = @options_list;
}

sub option_add {
	my ($option, $value) = @_;
	$options{$option} = $value;
}

sub config_read {
	my $config_fd;
	open $config_fd, $options{"config-file"}
		or die "Can not open config file '$options{\"config-file\"}': $!"; 
	my $line = 1;
	while ( <$config_fd> ) {
		$_ =~ s/[\n\r]//g;
		if ( ( $_ =~ /^#/ ) or ( $_ =~ /^[\t ]?$/ ) ) {
			# skip comments and empty lines
			next;
		}
		my ($key, $value) = split /=/, $_, 2;
		if ( ! defined $value ) {
			die "Error in config file, line $line: '$_'"
		}
		if ( ! defined $config{$key} ) {
			die "Unknown option in config file, line $line: '$key'";
		}
		$config{$key} = $value;
	} continue {
		$line++;
	}

	close $config_fd;
}

sub config_print {
	foreach ( sort keys %config ) {
		print "$_ => \"$config{$_}\"\n"; 
	}
}

sub options_print {
	foreach (sort keys %options ) {
		print "$_ => \"$options{$_}\"\n";
	}
}

1
