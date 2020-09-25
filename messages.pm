package messages;

use strict;
use warnings;

use configuration;

sub verbose {
	if ( $configuration::options{"verbose"} eq "yes" ) {
		print "$_[0]\n";
	}
}

sub debug {
	if ( $configuration::options{"debug"} eq "yes" ) {
		print "$_[0]\n";
	}
}

sub debug_lib {
	if ( $configuration::options{"debug-lib"} eq "yes" ) {
		print "$_[0]\n";
	}
}

1
