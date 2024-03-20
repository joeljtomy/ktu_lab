-- 1. Table department
--    dno primary key check(dno like 'd%'), dname, cnt_emp check(cnt_emp<15), dept_hod
CREATE TABLE department (
    dno VARCHAR(10) PRIMARY KEY CHECK (dno LIKE 'd%'),
    dname VARCHAR(100),
    cnt_emp INT CHECK (cnt_emp < 15),
    dept_hod VARCHAR(100)
);

INSERT INTO department VALUES ('&dno', '&dname', &cnt_emp, '&dept_hod');

-- 2. Table employee
--    eno primary key check(eno like 'e%'), ename, salary, dno references department(dno), 
--    mngrno, doj date, job , address, city check(city in('cochin','bombay','madras','delhi')), 
--    pincode.
CREATE TABLE employee (
    eno VARCHAR(10) PRIMARY KEY CHECK (eno LIKE 'e%'),
    ename VARCHAR(100),
    salary NUMBER(10, 2),
    dno VARCHAR(10) REFERENCES department(dno),
    mngrno NUMBER(10),
    doj DATE,
    job VARCHAR(100),
    address VARCHAR(255),
    city VARCHAR(100) CHECK (city IN ('cochin', 'bombay', 'madras', 'delhi')),
    pincode NUMBER(10)
);

INSERT INTO employee VALUES ('&eno', '&ename', &salary, '&dno', &mngrno, '&doj', '&job', '&address', '&city', &pincode);

-- a. List the name of Employees joined after 1- 1- 1998 and working in department 
--    number d10.
SELECT ename
FROM employee
WHERE doj > TO_DATE('1998-01-01', 'YYYY-MM-DD') AND dno = 'd10';

-- b. List all employees working in department other than department number d30.
SELECT ename
FROM employee
WHERE dno <> 'd30';

-- c. List the name of employees working in department sales.
SELECT ename
FROM employee
WHERE dno = (
    SELECT dno
    FROM department
    WHERE dname = 'Sales'
)

-- d. List the name of employees who is not a manager.
SELECT ename
FROM employee
WHERE job != 'manager';

-- e. List the employees whose names starts with ‘J’ and ‘N’ as third character.
SELECT ename
FROM employee
WHERE ename LIKE 'J_N%';

-- f. List all the employees joined during the year 2000.
SELECT ename
FROM employee
WHERE EXTRACT(YEAR FROM doj) = 2000;

-- g. List the name of employees along with their annual salary, and also for 
--    each record, get the output, Every year <ename> earns <amount>
SELECT ename, salary * 12 AS annual_salary,
       CONCAT('Every year ', ename, ' earns ', salary * 12) AS output_msg
FROM employee;

-- h. Find the total number of employees in employee table.
SELECT COUNT(*)
FROM employee;

-- i. Display the minimum salary of various categories of employees.
