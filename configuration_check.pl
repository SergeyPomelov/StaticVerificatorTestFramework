#!/usr/bin/perl

use strict;
use warnings;

use configuration;

configuration::option_add("test_option1", "test_value1");
configuration::option_add("test_option2", "test_value2");
configuration::key_add("--test-key", "test_option1", "test_option2");

configuration::keys_to_options(@ARGV);
configuration::config_read();

print "Options:\n";
configuration::options_print();
print "\nConfig:\n";
configuration::config_print();
