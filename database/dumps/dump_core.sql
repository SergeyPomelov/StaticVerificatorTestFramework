CREATE TABLE Levels (
  level_id     integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  level_name   text,
  description  text
);
CREATE TABLE "Values" (
  value_id     integer PRIMARY KEY AUTOINCREMENT NOT NULL,
  level_id     integer,
  value        text,
  description  text
);
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
