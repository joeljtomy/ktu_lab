CREATE TABLE Department (
    Dept_no INT PRIMARY KEY,
    Dept_name VARCHAR(50) NOT NULL,
    Dept_HOD VARCHAR(50) CHECK (Dept_HOD LIKE 'Prof%')
);

CREATE TABLE Student (
    Roll_no INT PRIMARY KEY,
    Stud_name VARCHAR(50) CHECK (Stud_name LIKE 'B%' OR Stud_name LIKE 'S%' OR Stud_name LIKE 'E%' OR Stud_name LIKE 'P%'),
    Marks INT,
    Dept_no INT REFERENCES Department(Dept_no),
    City VARCHAR(50) CHECK(City IN ('cochin', 'Bombay', 'madras', 'delhi')),
    Date_of_joining DATE
);
