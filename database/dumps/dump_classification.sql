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
CREATE TABLE Tests (
  test_id   integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  path      text,
  positive  text
);
CREATE TABLE Classification (
  test_id   integer NOT NULL,
  level_id  integer NOT NULL,
  value_id  integer,
  PRIMARY KEY (test_id, level_id)
);
CREATE TABLE BasicTests (
  test_id   integer PRIMARY KEY NOT NULL,
  value_id  integer
);
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
