# Static Verificators Testing Framework
![Static Verificators Testing Framework](https://i.ibb.co/ZStfrV8/vulnerability1.jpg)

It's a framework and a huge tests data set to check coverage, false-positives rate, and some other merits of c/c++ static verifiers like 
[CLion](https://www.jetbrains.com/clion/), [ISC](https://software.intel.com/content/www/us/en/develop/tools/inspector.html), [Sonar Cube](https://www.sonarqube.org/), [VS](https://visualstudio.microsoft.com/vs/features/testing-tools/), etc.

# Run
It's a perl scripts set. Libs, SQLLight, etc. all are embedded.

## Core Module

### Commands
- ***run*** — run verifiers through the set of tests. [KEYS] run.
- ***help*** — print this message and exit

### Keys
- ***-v, --verbose*** — verbose mode
- ***--debug*** — additional debug information
- ***--debug-lib*** — additional debug information from libraries
- ***--verifiers=*** — list of verifier's ids to run like '0,2,8'
- ***--description=*** — add description to the testing sessions


## 	Dump Module

###	Commands:
- ***create*** — create a dump of specified type (all dumps if type is ommited). $0 [KEYS] create [TYPE].
-	***restore*** — restore the database from the dump ('tests' dump is default). [KEYS] restore [TYPE].
	
####	Dump types:
- ***core*** — just table schemas
- ***classification*** — dump of classification
- ***tests*** — dump of classification and tests
- ***verifiers*** — dump of classification, tests and verifiers
- ***testing*** — complete dump of the database
- ***all*** — select all dumps (for 'create' command only)
	
###	Keys:
- ***-v, --verbose*** — verbose mode
- ***--debug*** — additional debug information
- ***--debug-lib*** — additional debug information from libraries
		  
		 
## 	Stat Module
	
###	Commands:
- ***info*** — show available testing sessions. $0 info.
- ***stat*** — show statistics for chosen session. $0 [KEYS] stat session_id.
- ***statbyname*** — show statistics for session chosen by name and version of	verifier and testing date. $0 [KEYS] statbyname verif_name verif_version testing_date.
- ***help*** — print this message and exit. $0 help.
	
###	Keys:
- ***-v, --verbose*** — verbose statistics mode
- ***--order=stat_order*** — it is a record in form 'lev1,lev3,lev2..', where lev_i
- ***--cut=needed_values*** — it is a record in form 'values1,values2,values3..'
			
      
## 	Test Module
	
### Commands:
- ***add*** — add tests to the database. $0 [KEYS] add PATH1 [ PATH2 [ PATH3 ... ] ].
- ***classify*** — (re-)classify the test. $0 [KEYS] classify PATH1 [ PATH2 [ PATH3 ... ] ].
- ***remove*** — remove tests from the database(doesn't actually remove the file). $0 [KEYS] remove PATH1 [ PATH2 [ PATH3 ... ] ].
- ***removeid*** — remove tests from the database by their IDs. $0 [KEYS] remove_id TEST_ID1 [ TEST_ID2 [ TEST_ID3 ... ] ].
- ***help*** — print this message and exit. $0 help.
	
 ### Keys:
- ***-v, --verbose*** — verbose mode
- ***--debug*** — additional debug information
- ***--debug-lib*** — additional debug information from libraries
- ***-d, --duplicate*** — allow to add one test multiple times
- ***-s, --skip-checks*** — don't check if file is a readable text file
