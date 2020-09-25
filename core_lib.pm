package core_lib;

use strict;
use warnings;

use Digest::MD5 qw(md5_hex);

use configuration;

sub hash_function {
	if ($configuration::config{"HashFunction"} eq "md5_hex") {
		return md5_hex($_[0]);
	} else {
		die "Unknown hash function: '" . $configuration::config{"HashFunction"} . "'";
	}
}

sub verifier_call {
	my ($verifier, $test) = @_;
	my $path_separator;
	my $test_path = $test->{"path"};
	my ($executable, $keys) = ($verifier->{"executable"}, $verifier->{"keys"});
	if ( $verifier->{"path_separator"} eq "" ) {
		$path_separator = $configuration::config{"PathSeparator_System"};
	} else {
		$path_separator = $verifier->{"path_separator"};
	}
	$test_path =~ s/$configuration::config{"PathSeparator_DataBase"}/$path_separator/g;
	my $stream;
	if ( $verifier->{"output_stream"} eq "stdout" ) {
		$stream = "2>" . $configuration::config{"NullFile"};
	} elsif ( $verifier->{"output_stream"} eq "stderr" ) {
		$stream = "2>&1 1>" . $configuration::config{"NullFile"};
	} elsif ( $verifier->{"output_stream"} eq "both" ) {
		$stream = "2>&1";
	} else {
		die "Unknown output stream: '" . $verifier->{"output_stream"} . "'";
	}
	messages::debug_lib("'$executable' $keys '$test_path' $stream");
	my $output = `"$executable" $keys "$test_path" $stream`;
	return $output;
}

sub testids_cut {
	my (@ids) = @_;
	my $cut = $configuration::options{"cut"};
	if ($cut eq "no" || $cut eq "yes") {
		my $output_ids = join(",", @ids);
		return $output_ids;
	}
	
	my @cutvals = split (',', $cut);
	foreach my $cutval (@cutvals) { 			#splitting on levels
		my @onelevel_cutvals = split('/', $cutval);
		my @new_ids;
		my $i=0;
		foreach my $onelevel_cutval (@onelevel_cutvals) {			#splitting on values in the given level
			my $val_info = db_structure::value_select_level_id_by_value($onelevel_cutval);
			my $val_level = $val_info->{"level_id"};
			my $val_id = $val_info->{"value_id"};
			if (!defined $val_id) {
				print "There are no such value: ".$cutval." in the database\n";
				return undef;
			}				
			my $new_ids_array = db_structure::classification_select_test_id_by_level_and_value_and_tests($val_level, $val_id, @ids);
			while (my $new_test_id = $new_ids_array->fetchrow_hashref()) {
				$new_ids[$i++] = $new_test_id->{"test_id"};				#we take union of ids corresponding to values in the given level
			}
		}		
		
		if ($i==0) {			#one set is empty <=> intersection is empty  due to nesting of sets
			print "There are no testing results on test cases having such classification values";
			return undef;
		}
		
		@ids = @new_ids;			#we take intersection of ids corresponding to levels
	}
	my $output_ids = join(",", @ids);
	return $output_ids;
}

1
