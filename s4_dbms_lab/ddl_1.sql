CREATE TABLE student (
    roll_no NUMBER PRIMARY KEY,
    name VARCHAR(50),
    address VARCHAR(100),
    phone_no VARCHAR(15),
    gender VARCHAR(10),
    branch VARCHAR(50),
    mark1 NUMBER,
    mark2 NUMBER
);

DESC student;

ALTER TABLE student
ADD total_marks NUMBER;

ALTER TABLE student
MODIFY address VARCHAR(20);

ALTER TABLE student
DROP COLUMN gender,
DROP COLUMN branch;

ALTER TABLE student
RENAME COLUMN mark1 TO m1;

ALTER TABLE student
RENAME TO student1;

DROP TABLE student1;