BEGIN TRANSACTION;
CREATE TABLE Levels (
  level_id     integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  level_name   text,
  description  text
);
INSERT INTO "Levels" VALUES(0,'Positive','Shows whether test is positive or negative');
INSERT INTO "Levels" VALUES(1,'ErrorType','Type of the error like "out-of-bounds" or "memory leak"');
INSERT INTO "Levels" VALUES(2,'MemoryType','Type of the memory used in the test');
INSERT INTO "Levels" VALUES(3,'ComputationComplexity','Describes expression which caused the error');
INSERT INTO "Levels" VALUES(4,'Context','Context the error appeared in like');
INSERT INTO "Levels" VALUES(5,'CodeComplexity','Complexity of code in the test');
COMMIT;
BEGIN TRANSACTION;
CREATE TABLE "Values" (
  value_id     integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  level_id     integer,
  value        text,
  description  text
);
INSERT INTO "Values" VALUES(1,0,'n','negative test');
INSERT INTO "Values" VALUES(2,0,'p','positive test');
INSERT INTO "Values" VALUES(3,1,'UI','UnInitialized variable');
INSERT INTO "Values" VALUES(4,1,'ZD','Zero Division');
INSERT INTO "Values" VALUES(5,1,'OOB','Out Of Bounds');
INSERT INTO "Values" VALUES(6,1,'DAM','DeAllocated Memory');
INSERT INTO "Values" VALUES(7,1,'IP','Invalid Pointer');
INSERT INTO "Values" VALUES(8,1,'ML','Memory Leak');
INSERT INTO "Values" VALUES(9,1,'DC','Dead Code');
INSERT INTO "Values" VALUES(10,2,'aS','Automatic+Single');
INSERT INTO "Values" VALUES(11,2,'aS+aS','Automatic+Single + Automatic+Single');
INSERT INTO "Values" VALUES(12,3,'v','Variable');
INSERT INTO "Values" VALUES(13,3,'A(v,c)','Arithmetic(Variable, Const)');
INSERT INTO "Values" VALUES(14,3,'A(D(v,c))','Arithmetic(Dereferencing(var, const))');
INSERT INTO "Values" VALUES(15,4,'lc','local context');
INSERT INTO "Values" VALUES(16,4,'fp','function parameter');
INSERT INTO "Values" VALUES(17,4,'fr','function return');
INSERT INTO "Values" VALUES(18,4,'rc','recursion');
INSERT INTO "Values" VALUES(19,5,'ln','linear code');
INSERT INTO "Values" VALUES(20,5,'cd','condition');
INSERT INTO "Values" VALUES(21,5,'rp','repeat');
INSERT INTO "Values" VALUES(22,3,'D(v)',NULL);
INSERT INTO "Values" VALUES(23,3,'A(D(v))',NULL);
INSERT INTO "Values" VALUES(24,4,'fp+fr',NULL);
INSERT INTO "Values" VALUES(25,2,'aA',NULL);
INSERT INTO "Values" VALUES(26,2,'aS+aA',NULL);
INSERT INTO "Values" VALUES(27,3,'D(A(c,v))',NULL);
INSERT INTO "Values" VALUES(28,3,'c',NULL);
INSERT INTO "Values" VALUES(29,3,'a(v,c)',NULL);
INSERT INTO "Values" VALUES(30,3,'A(v))',NULL);
INSERT INTO "Values" VALUES(31,3,'A(D(v),c))',NULL);
INSERT INTO "Values" VALUES(32,3,'D(A(v,c))',NULL);
INSERT INTO "Values" VALUES(33,3,'A(D(v),c)',NULL);
INSERT INTO "Values" VALUES(34,3,'A(c,v)',NULL);
INSERT INTO "Values" VALUES(35,2,'aS+dA',NULL);
INSERT INTO "Values" VALUES(36,3,'A(v)',NULL);
INSERT INTO "Values" VALUES(37,2,'sS',NULL);
COMMIT;
BEGIN TRANSACTION;
CREATE TABLE Tests (
  test_id   integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  path      text,
  positive  text
);
INSERT INTO "Tests" VALUES(24,'tests/33-n-DAM-aS-D(v)-lc-ln.c','n');
INSERT INTO "Tests" VALUES(25,'tests/27-n-DAM-aS+aS-v-lc-ln.c','n');
INSERT INTO "Tests" VALUES(26,'tests/7-n-ZD-aS+aS-A(D(v))-lc-ln.c','n');
INSERT INTO "Tests" VALUES(27,'tests/ui/ui_positive.c','p');
INSERT INTO "Tests" VALUES(28,'tests/ui/ui_negative.c','n');
INSERT INTO "Tests" VALUES(29,'tests/40-p-DAM-aS-D(v)-fp+fr-ln.c','p');
INSERT INTO "Tests" VALUES(30,'tests/3-n-ZD-aS-v-lc-ln.c','n');
INSERT INTO "Tests" VALUES(31,'tests/28-p-DAM-aS+aS-v-lc-ln.c','p');
INSERT INTO "Tests" VALUES(32,'tests/13-n-ZD-aA-A(D(v))-lc-ln.c','n');
INSERT INTO "Tests" VALUES(33,'tests/38-n-UI-aS-v-lc-cd.c','n');
INSERT INTO "Tests" VALUES(34,'tests/30-p-DAM-aS+aS-v-lc-ln.c','p');
INSERT INTO "Tests" VALUES(35,'tests/20-p-ZD-aS+aA-D(A(c,v))-lc-ln.c','p');
INSERT INTO "Tests" VALUES(36,'tests/12-p-ZD-aS+aS-A(D(v))-lc-ln.c','p');
INSERT INTO "Tests" VALUES(37,'tests/24-p-ZD-aS-c-lc-cd.c','p');
INSERT INTO "Tests" VALUES(38,'tests/37-n-UI-aS-v-lc-ln.c','n');
INSERT INTO "Tests" VALUES(39,'tests/oob/oob_positive.c','p');
INSERT INTO "Tests" VALUES(40,'tests/oob/oob_negative.c','n');
INSERT INTO "Tests" VALUES(41,'tests/11-n-ZD-aS+aS-A(D(v))-lc-ln.c','n');
INSERT INTO "Tests" VALUES(42,'tests/10-p-ZD-aS-A(v)-lc-ln.c','p');
INSERT INTO "Tests" VALUES(43,'tests/29-n-DAM-aS+aS-v-lc-ln.c','n');
INSERT INTO "Tests" VALUES(44,'tests/2-p-ZD-aS-c-lc-ln.c','p');
INSERT INTO "Tests" VALUES(45,'tests/31-n-ZD-aS+aS-A(D(v),c))-lc-ln.c','n');
INSERT INTO "Tests" VALUES(46,'tests/39-n-DAM-aS-D(v)-fp+fr-ln.c','n');
INSERT INTO "Tests" VALUES(47,'tests/15-n-ZD-aA-D(A(v,c))-lc-ln .c','n');
INSERT INTO "Tests" VALUES(48,'tests/32-p-ZD-aS+aS-A(D(v),c))-lc-ln.c','p');
INSERT INTO "Tests" VALUES(49,'tests/6-p-ZD-aS-A(c,v)-lc-ln.c','p');
INSERT INTO "Tests" VALUES(50,'tests/dam/dam_auto_negative.c','n');
INSERT INTO "Tests" VALUES(51,'tests/dam/dam_dynamic_positive.c','p');
INSERT INTO "Tests" VALUES(52,'tests/dam/dam_auto_positive.c','p');
INSERT INTO "Tests" VALUES(53,'tests/dam/dam_dynamic_negative.c','n');
INSERT INTO "Tests" VALUES(54,'tests/zd/zd_positive.c','p');
INSERT INTO "Tests" VALUES(55,'tests/zd/zd_negative.c','n');
INSERT INTO "Tests" VALUES(56,'tests/19-n-ZD-aS+aA-D(A(c,v))-lc-ln.c','n');
INSERT INTO "Tests" VALUES(57,'tests/14-p-ZD-aA-A(D(v))-lc-ln.c','p');
INSERT INTO "Tests" VALUES(58,'tests/ip/ip_negative.c','n');
INSERT INTO "Tests" VALUES(59,'tests/ip/ip_dynamic_negative.c','n');
INSERT INTO "Tests" VALUES(60,'tests/ip/ip_zero_negative.c','n');
INSERT INTO "Tests" VALUES(61,'tests/ip/ip_positive.c','p');
INSERT INTO "Tests" VALUES(62,'tests/ip/ip_zero_positive.c','p');
INSERT INTO "Tests" VALUES(63,'tests/ip/ip_dynamic_positive.c','p');
INSERT INTO "Tests" VALUES(64,'tests/4-p-ZD-aS-v-lc-ln.c','p');
INSERT INTO "Tests" VALUES(65,'tests/21-n-ZD-aS-v-lc-cd.c','n');
INSERT INTO "Tests" VALUES(66,'tests/5-n-ZD-aS-A(c,v)-lc-ln.c','n');
INSERT INTO "Tests" VALUES(67,'tests/8-p-ZD-aS+aS-A(D(v))-lc-ln.c','p');
INSERT INTO "Tests" VALUES(68,'tests/1-n-ZD-aS-c-lc-ln.c','n');
INSERT INTO "Tests" VALUES(69,'tests/34-p-DAM-aS-D(v)-lc-ln.c','p');
INSERT INTO "Tests" VALUES(70,'tests/9-n-ZD-aS-A(v)-lc-ln.c','n');
INSERT INTO "Tests" VALUES(71,'tests/17-n-ZD-sS-v-lc-ln.c','n');
INSERT INTO "Tests" VALUES(72,'tests/22-p-ZD-aS-v-lc-cd.c','p');
INSERT INTO "Tests" VALUES(73,'tests/18-p-ZD-sS-v-lc-ln.c','p');
INSERT INTO "Tests" VALUES(74,'tests/23-n-ZD-aS-c-lc-cd.c','n');
INSERT INTO "Tests" VALUES(75,'tests/16-p-ZD-aA-D(A(v,c))-lc-ln .c','p');
COMMIT;
BEGIN TRANSACTION;
CREATE TABLE Classification (
  test_id   integer NOT NULL,
  level_id  integer NOT NULL,
  value_id  integer,
  PRIMARY KEY (test_id, level_id)
);
INSERT INTO "Classification" VALUES(24,0,1);
INSERT INTO "Classification" VALUES(24,1,6);
INSERT INTO "Classification" VALUES(24,2,10);
INSERT INTO "Classification" VALUES(24,3,22);
INSERT INTO "Classification" VALUES(24,4,15);
INSERT INTO "Classification" VALUES(24,5,19);
INSERT INTO "Classification" VALUES(25,0,1);
INSERT INTO "Classification" VALUES(25,1,6);
INSERT INTO "Classification" VALUES(25,2,11);
INSERT INTO "Classification" VALUES(25,3,12);
INSERT INTO "Classification" VALUES(25,4,15);
INSERT INTO "Classification" VALUES(25,5,19);
INSERT INTO "Classification" VALUES(26,0,1);
INSERT INTO "Classification" VALUES(26,1,4);
INSERT INTO "Classification" VALUES(26,2,11);
INSERT INTO "Classification" VALUES(26,3,23);
INSERT INTO "Classification" VALUES(26,4,15);
INSERT INTO "Classification" VALUES(26,5,19);
INSERT INTO "Classification" VALUES(27,0,2);
INSERT INTO "Classification" VALUES(27,1,3);
INSERT INTO "Classification" VALUES(27,2,10);
INSERT INTO "Classification" VALUES(27,3,12);
INSERT INTO "Classification" VALUES(27,4,15);
INSERT INTO "Classification" VALUES(27,5,19);
INSERT INTO "Classification" VALUES(28,0,1);
INSERT INTO "Classification" VALUES(28,1,3);
INSERT INTO "Classification" VALUES(28,2,10);
INSERT INTO "Classification" VALUES(28,3,12);
INSERT INTO "Classification" VALUES(28,4,15);
INSERT INTO "Classification" VALUES(28,5,19);
INSERT INTO "Classification" VALUES(29,0,2);
INSERT INTO "Classification" VALUES(29,1,6);
INSERT INTO "Classification" VALUES(29,2,10);
INSERT INTO "Classification" VALUES(29,3,22);
INSERT INTO "Classification" VALUES(29,4,24);
INSERT INTO "Classification" VALUES(29,5,19);
INSERT INTO "Classification" VALUES(30,0,1);
INSERT INTO "Classification" VALUES(30,1,4);
INSERT INTO "Classification" VALUES(30,2,10);
INSERT INTO "Classification" VALUES(30,3,12);
INSERT INTO "Classification" VALUES(30,4,15);
INSERT INTO "Classification" VALUES(30,5,19);
INSERT INTO "Classification" VALUES(31,0,2);
INSERT INTO "Classification" VALUES(31,1,6);
INSERT INTO "Classification" VALUES(31,2,11);
INSERT INTO "Classification" VALUES(31,3,12);
INSERT INTO "Classification" VALUES(31,4,15);
INSERT INTO "Classification" VALUES(31,5,19);
INSERT INTO "Classification" VALUES(32,0,1);
INSERT INTO "Classification" VALUES(32,1,4);
INSERT INTO "Classification" VALUES(32,2,25);
INSERT INTO "Classification" VALUES(32,3,23);
INSERT INTO "Classification" VALUES(32,4,15);
INSERT INTO "Classification" VALUES(32,5,19);
INSERT INTO "Classification" VALUES(33,0,1);
INSERT INTO "Classification" VALUES(33,1,3);
INSERT INTO "Classification" VALUES(33,2,10);
INSERT INTO "Classification" VALUES(33,3,12);
INSERT INTO "Classification" VALUES(33,4,15);
INSERT INTO "Classification" VALUES(33,5,20);
INSERT INTO "Classification" VALUES(34,0,2);
INSERT INTO "Classification" VALUES(34,1,6);
INSERT INTO "Classification" VALUES(34,2,11);
INSERT INTO "Classification" VALUES(34,3,12);
INSERT INTO "Classification" VALUES(34,4,15);
INSERT INTO "Classification" VALUES(34,5,19);
INSERT INTO "Classification" VALUES(35,0,2);
INSERT INTO "Classification" VALUES(35,1,4);
INSERT INTO "Classification" VALUES(35,2,26);
INSERT INTO "Classification" VALUES(35,3,27);
INSERT INTO "Classification" VALUES(35,4,15);
INSERT INTO "Classification" VALUES(35,5,19);
INSERT INTO "Classification" VALUES(36,0,2);
INSERT INTO "Classification" VALUES(36,1,4);
INSERT INTO "Classification" VALUES(36,2,11);
INSERT INTO "Classification" VALUES(36,3,23);
INSERT INTO "Classification" VALUES(36,4,15);
INSERT INTO "Classification" VALUES(36,5,19);
INSERT INTO "Classification" VALUES(37,0,2);
INSERT INTO "Classification" VALUES(37,1,4);
INSERT INTO "Classification" VALUES(37,2,10);
INSERT INTO "Classification" VALUES(37,3,28);
INSERT INTO "Classification" VALUES(37,4,15);
INSERT INTO "Classification" VALUES(37,5,20);
INSERT INTO "Classification" VALUES(38,0,1);
INSERT INTO "Classification" VALUES(38,1,3);
INSERT INTO "Classification" VALUES(38,2,10);
INSERT INTO "Classification" VALUES(38,3,12);
INSERT INTO "Classification" VALUES(38,4,15);
INSERT INTO "Classification" VALUES(38,5,20);
INSERT INTO "Classification" VALUES(39,0,2);
INSERT INTO "Classification" VALUES(39,1,5);
INSERT INTO "Classification" VALUES(39,2,26);
INSERT INTO "Classification" VALUES(39,3,29);
INSERT INTO "Classification" VALUES(39,4,15);
INSERT INTO "Classification" VALUES(39,5,19);
INSERT INTO "Classification" VALUES(40,0,1);
INSERT INTO "Classification" VALUES(40,1,5);
INSERT INTO "Classification" VALUES(40,2,26);
INSERT INTO "Classification" VALUES(40,3,29);
INSERT INTO "Classification" VALUES(40,4,15);
INSERT INTO "Classification" VALUES(40,5,19);
INSERT INTO "Classification" VALUES(41,0,1);
INSERT INTO "Classification" VALUES(41,1,4);
INSERT INTO "Classification" VALUES(41,2,11);
INSERT INTO "Classification" VALUES(41,3,23);
INSERT INTO "Classification" VALUES(41,4,15);
INSERT INTO "Classification" VALUES(41,5,19);
INSERT INTO "Classification" VALUES(42,0,2);
INSERT INTO "Classification" VALUES(42,1,4);
INSERT INTO "Classification" VALUES(42,2,10);
INSERT INTO "Classification" VALUES(42,3,30);
INSERT INTO "Classification" VALUES(42,4,15);
INSERT INTO "Classification" VALUES(42,5,19);
INSERT INTO "Classification" VALUES(43,0,1);
INSERT INTO "Classification" VALUES(43,1,6);
INSERT INTO "Classification" VALUES(43,2,11);
INSERT INTO "Classification" VALUES(43,3,12);
INSERT INTO "Classification" VALUES(43,4,15);
INSERT INTO "Classification" VALUES(43,5,19);
INSERT INTO "Classification" VALUES(44,0,2);
INSERT INTO "Classification" VALUES(44,1,4);
INSERT INTO "Classification" VALUES(44,2,10);
INSERT INTO "Classification" VALUES(44,3,28);
INSERT INTO "Classification" VALUES(44,4,15);
INSERT INTO "Classification" VALUES(44,5,19);
INSERT INTO "Classification" VALUES(45,0,1);
INSERT INTO "Classification" VALUES(45,1,4);
INSERT INTO "Classification" VALUES(45,2,11);
INSERT INTO "Classification" VALUES(45,3,31);
INSERT INTO "Classification" VALUES(45,4,15);
INSERT INTO "Classification" VALUES(45,5,19);
INSERT INTO "Classification" VALUES(46,0,1);
INSERT INTO "Classification" VALUES(46,1,6);
INSERT INTO "Classification" VALUES(46,2,10);
INSERT INTO "Classification" VALUES(46,3,22);
INSERT INTO "Classification" VALUES(46,4,24);
INSERT INTO "Classification" VALUES(46,5,19);
INSERT INTO "Classification" VALUES(47,0,1);
INSERT INTO "Classification" VALUES(47,1,4);
INSERT INTO "Classification" VALUES(47,2,25);
INSERT INTO "Classification" VALUES(47,3,32);
INSERT INTO "Classification" VALUES(47,4,15);
INSERT INTO "Classification" VALUES(47,5,19);
INSERT INTO "Classification" VALUES(48,0,2);
INSERT INTO "Classification" VALUES(48,1,4);
INSERT INTO "Classification" VALUES(48,2,11);
INSERT INTO "Classification" VALUES(48,3,33);
INSERT INTO "Classification" VALUES(48,4,15);
INSERT INTO "Classification" VALUES(48,5,19);
INSERT INTO "Classification" VALUES(49,0,2);
INSERT INTO "Classification" VALUES(49,1,4);
INSERT INTO "Classification" VALUES(49,2,10);
INSERT INTO "Classification" VALUES(49,3,34);
INSERT INTO "Classification" VALUES(49,4,15);
INSERT INTO "Classification" VALUES(49,5,19);
INSERT INTO "Classification" VALUES(50,0,1);
INSERT INTO "Classification" VALUES(50,1,6);
INSERT INTO "Classification" VALUES(50,2,11);
INSERT INTO "Classification" VALUES(50,3,12);
INSERT INTO "Classification" VALUES(50,4,15);
INSERT INTO "Classification" VALUES(50,5,19);
INSERT INTO "Classification" VALUES(51,0,2);
INSERT INTO "Classification" VALUES(51,1,6);
INSERT INTO "Classification" VALUES(51,2,35);
INSERT INTO "Classification" VALUES(51,3,29);
INSERT INTO "Classification" VALUES(51,4,15);
INSERT INTO "Classification" VALUES(51,5,19);
INSERT INTO "Classification" VALUES(52,0,2);
INSERT INTO "Classification" VALUES(52,1,6);
INSERT INTO "Classification" VALUES(52,2,11);
INSERT INTO "Classification" VALUES(52,3,12);
INSERT INTO "Classification" VALUES(52,4,15);
INSERT INTO "Classification" VALUES(52,5,19);
INSERT INTO "Classification" VALUES(53,0,1);
INSERT INTO "Classification" VALUES(53,1,6);
INSERT INTO "Classification" VALUES(53,2,35);
INSERT INTO "Classification" VALUES(53,3,29);
INSERT INTO "Classification" VALUES(53,4,15);
INSERT INTO "Classification" VALUES(53,5,19);
INSERT INTO "Classification" VALUES(54,0,2);
INSERT INTO "Classification" VALUES(54,1,4);
INSERT INTO "Classification" VALUES(54,2,10);
INSERT INTO "Classification" VALUES(54,3,28);
INSERT INTO "Classification" VALUES(54,4,15);
INSERT INTO "Classification" VALUES(54,5,19);
INSERT INTO "Classification" VALUES(55,0,1);
INSERT INTO "Classification" VALUES(55,1,4);
INSERT INTO "Classification" VALUES(55,2,10);
INSERT INTO "Classification" VALUES(55,3,28);
INSERT INTO "Classification" VALUES(55,4,15);
INSERT INTO "Classification" VALUES(55,5,19);
INSERT INTO "Classification" VALUES(56,0,1);
INSERT INTO "Classification" VALUES(56,1,4);
INSERT INTO "Classification" VALUES(56,2,26);
INSERT INTO "Classification" VALUES(56,3,27);
INSERT INTO "Classification" VALUES(56,4,15);
INSERT INTO "Classification" VALUES(56,5,19);
INSERT INTO "Classification" VALUES(57,0,2);
INSERT INTO "Classification" VALUES(57,1,4);
INSERT INTO "Classification" VALUES(57,2,25);
INSERT INTO "Classification" VALUES(57,3,23);
INSERT INTO "Classification" VALUES(57,4,15);
INSERT INTO "Classification" VALUES(57,5,19);
INSERT INTO "Classification" VALUES(58,0,1);
INSERT INTO "Classification" VALUES(58,1,7);
INSERT INTO "Classification" VALUES(58,2,10);
INSERT INTO "Classification" VALUES(58,3,12);
INSERT INTO "Classification" VALUES(58,4,15);
INSERT INTO "Classification" VALUES(58,5,19);
INSERT INTO "Classification" VALUES(59,0,1);
INSERT INTO "Classification" VALUES(59,1,7);
INSERT INTO "Classification" VALUES(59,2,35);
INSERT INTO "Classification" VALUES(59,3,29);
INSERT INTO "Classification" VALUES(59,4,15);
INSERT INTO "Classification" VALUES(59,5,19);
INSERT INTO "Classification" VALUES(60,0,1);
INSERT INTO "Classification" VALUES(60,1,7);
INSERT INTO "Classification" VALUES(60,2,10);
INSERT INTO "Classification" VALUES(60,3,12);
INSERT INTO "Classification" VALUES(60,4,15);
INSERT INTO "Classification" VALUES(60,5,19);
INSERT INTO "Classification" VALUES(61,0,2);
INSERT INTO "Classification" VALUES(61,1,7);
INSERT INTO "Classification" VALUES(61,2,10);
INSERT INTO "Classification" VALUES(61,3,12);
INSERT INTO "Classification" VALUES(61,4,15);
INSERT INTO "Classification" VALUES(61,5,19);
INSERT INTO "Classification" VALUES(62,0,2);
INSERT INTO "Classification" VALUES(62,1,7);
INSERT INTO "Classification" VALUES(62,2,10);
INSERT INTO "Classification" VALUES(62,3,12);
INSERT INTO "Classification" VALUES(62,4,15);
INSERT INTO "Classification" VALUES(62,5,19);
INSERT INTO "Classification" VALUES(63,0,2);
INSERT INTO "Classification" VALUES(63,1,7);
INSERT INTO "Classification" VALUES(63,2,35);
INSERT INTO "Classification" VALUES(63,3,29);
INSERT INTO "Classification" VALUES(63,4,15);
INSERT INTO "Classification" VALUES(63,5,20);
INSERT INTO "Classification" VALUES(64,0,2);
INSERT INTO "Classification" VALUES(64,1,4);
INSERT INTO "Classification" VALUES(64,2,10);
INSERT INTO "Classification" VALUES(64,3,12);
INSERT INTO "Classification" VALUES(64,4,15);
INSERT INTO "Classification" VALUES(64,5,19);
INSERT INTO "Classification" VALUES(65,0,1);
INSERT INTO "Classification" VALUES(65,1,4);
INSERT INTO "Classification" VALUES(65,2,10);
INSERT INTO "Classification" VALUES(65,3,12);
INSERT INTO "Classification" VALUES(65,4,15);
INSERT INTO "Classification" VALUES(65,5,20);
INSERT INTO "Classification" VALUES(66,0,1);
INSERT INTO "Classification" VALUES(66,1,4);
INSERT INTO "Classification" VALUES(66,2,10);
INSERT INTO "Classification" VALUES(66,3,34);
INSERT INTO "Classification" VALUES(66,4,15);
INSERT INTO "Classification" VALUES(66,5,19);
INSERT INTO "Classification" VALUES(67,0,2);
INSERT INTO "Classification" VALUES(67,1,4);
INSERT INTO "Classification" VALUES(67,2,11);
INSERT INTO "Classification" VALUES(67,3,23);
INSERT INTO "Classification" VALUES(67,4,15);
INSERT INTO "Classification" VALUES(67,5,19);
INSERT INTO "Classification" VALUES(68,0,1);
INSERT INTO "Classification" VALUES(68,1,4);
INSERT INTO "Classification" VALUES(68,2,10);
INSERT INTO "Classification" VALUES(68,3,28);
INSERT INTO "Classification" VALUES(68,4,15);
INSERT INTO "Classification" VALUES(68,5,19);
INSERT INTO "Classification" VALUES(69,0,2);
INSERT INTO "Classification" VALUES(69,1,6);
INSERT INTO "Classification" VALUES(69,2,10);
INSERT INTO "Classification" VALUES(69,3,22);
INSERT INTO "Classification" VALUES(69,4,15);
INSERT INTO "Classification" VALUES(69,5,19);
INSERT INTO "Classification" VALUES(70,0,1);
INSERT INTO "Classification" VALUES(70,1,4);
INSERT INTO "Classification" VALUES(70,2,10);
INSERT INTO "Classification" VALUES(70,3,36);
INSERT INTO "Classification" VALUES(70,4,15);
INSERT INTO "Classification" VALUES(70,5,19);
INSERT INTO "Classification" VALUES(71,0,1);
INSERT INTO "Classification" VALUES(71,1,4);
INSERT INTO "Classification" VALUES(71,2,37);
INSERT INTO "Classification" VALUES(71,3,12);
INSERT INTO "Classification" VALUES(71,4,15);
INSERT INTO "Classification" VALUES(71,5,19);
INSERT INTO "Classification" VALUES(72,0,2);
INSERT INTO "Classification" VALUES(72,1,4);
INSERT INTO "Classification" VALUES(72,2,10);
INSERT INTO "Classification" VALUES(72,3,12);
INSERT INTO "Classification" VALUES(72,4,15);
INSERT INTO "Classification" VALUES(72,5,20);
INSERT INTO "Classification" VALUES(73,0,2);
INSERT INTO "Classification" VALUES(73,1,4);
INSERT INTO "Classification" VALUES(73,2,37);
INSERT INTO "Classification" VALUES(73,3,12);
INSERT INTO "Classification" VALUES(73,4,15);
INSERT INTO "Classification" VALUES(73,5,19);
INSERT INTO "Classification" VALUES(74,0,1);
INSERT INTO "Classification" VALUES(74,1,4);
INSERT INTO "Classification" VALUES(74,2,10);
INSERT INTO "Classification" VALUES(74,3,28);
INSERT INTO "Classification" VALUES(74,4,15);
INSERT INTO "Classification" VALUES(74,5,20);
INSERT INTO "Classification" VALUES(75,0,2);
INSERT INTO "Classification" VALUES(75,1,4);
INSERT INTO "Classification" VALUES(75,2,25);
INSERT INTO "Classification" VALUES(75,3,32);
INSERT INTO "Classification" VALUES(75,4,15);
INSERT INTO "Classification" VALUES(75,5,19);
COMMIT;
BEGIN TRANSACTION;
CREATE TABLE BasicTests (
  test_id   integer PRIMARY KEY NOT NULL,
  value_id  integer
);
INSERT INTO "BasicTests" VALUES(27,3);
INSERT INTO "BasicTests" VALUES(28,3);
INSERT INTO "BasicTests" VALUES(39,5);
INSERT INTO "BasicTests" VALUES(40,5);
INSERT INTO "BasicTests" VALUES(50,6);
INSERT INTO "BasicTests" VALUES(51,6);
INSERT INTO "BasicTests" VALUES(52,6);
INSERT INTO "BasicTests" VALUES(53,6);
INSERT INTO "BasicTests" VALUES(54,4);
INSERT INTO "BasicTests" VALUES(55,4);
INSERT INTO "BasicTests" VALUES(58,7);
INSERT INTO "BasicTests" VALUES(59,7);
INSERT INTO "BasicTests" VALUES(60,7);
INSERT INTO "BasicTests" VALUES(61,7);
INSERT INTO "BasicTests" VALUES(62,7);
INSERT INTO "BasicTests" VALUES(63,7);
COMMIT;
CREATE TABLE Verifiers (
  ver_id       integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  name         text,
  version      text,
  executable text,
  keys text,
  output_stream text,
  path_separator text
);
CREATE TABLE Analysis (
  ver_id    integer NOT NULL,
  value_id  integer NOT NULL,
  keywords  text,
  PRIMARY KEY (ver_id, value_id)
);
CREATE TABLE TestingSessions (
  session_id    integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  ver_id        integer NOT NULL,
  time_start    timestamp NOT NULL,
  time_end      timestamp,
  description   text
);
CREATE TABLE Output (
  output_id  integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  output_text     text,
  hash       text
);
CREATE TABLE Testing (
  test_id       integer NOT NULL,
  session_id    integer NOT NULL,
  output_id     integer,
  result        text,
  PRIMARY KEY (test_id, session_id)
);
