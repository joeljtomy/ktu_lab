-- 1. 
CREATE TABLE department (
    dno VARCHAR(10) PRIMARY KEY CHECK (dno LIKE 'd%'),
    dname VARCHAR(100),
    cnt_emp NUMBER CHECK (cnt_emp < 15),
    dept_hod VARCHAR(100)
);

INSERT INTO department VALUES ('&dno', '&dname', &cnt_emp, '&dept_hod');

/*
INSERT INTO department (dno, dname, cnt_emp, dept_hod) VALUES 
('d10', 'Production', 1, 'John Doe'),
('d11', 'Sales', 2, 'Peter Parker'),
('d12', 'Exporting', 3, 'Paul Wesley'),
('d20', 'Maintenance', 3, 'Zuck'),
('d30', 'Repair', 8, 'Tim Payn');
*/

-- 2. 
CREATE TABLE employee (
    eno VARCHAR(10) PRIMARY KEY CHECK (eno LIKE 'e%'),
    ename VARCHAR(100),
    salary NUMBER(10),
    dno VARCHAR(10) REFERENCES department(dno),
    mngrno NUMBER(10),
    doj DATE,
    job VARCHAR(100),
    address VARCHAR(255),
    city VARCHAR(100) CHECK (city IN ('cochin', 'bombay', 'madras', 'delhi')),
    pincode NUMBER(10)
);

INSERT INTO employee VALUES ('&eno', '&ename', &salary, '&dno', &mngrno, '&doj', '&job', '&address', '&city', &pincode);

/*
INSERT INTO employee (ENO, ENAME, SALARY, DNO, MNGRNO, DOJ, JOB, ADDRESS, CITY, PINCODE) VALUES 
('e1', 'Don', 1000, 'd10', 1, '1965-01-18', 'sales', '220 CB', 'cochin', 65),
('e2', 'Donny', 5000, 'd20', 2, '1995-01-17', 'manager', 'Rosevila', 'delhi', 35),
('e3', 'Jobin', 9000, 'd30', 5, '1945-01-17', 'accounts', '22CB', 'bombay', 72),
('e5', 'robin', 900, 'd10', NULL, '1998-01-03', 'intern', '22 CB', 'madras', 45),
('e7', 'Jane', 7500, 'd11', 9, '2000-03-01', 'clerk', 'poovathil', 'delhi', 12);
*/

-- a. 
SELECT ename
FROM employee
WHERE doj > TO_DATE('1998-01-01', 'YYYY-MM-DD') 
AND dno = 'd10';

-- b. 
SELECT ename
FROM employee
WHERE dno != 'd30';

-- c. 
SELECT ename
FROM employee
WHERE dno = (
    SELECT dno
    FROM department
    WHERE dname = 'Sales'
)

-- d. 
SELECT ename
FROM employee
WHERE job != 'manager';

-- e. 
SELECT ename
FROM employee
WHERE ename LIKE 'J_N%';

-- f. 
SELECT ename
FROM employee
WHERE EXTRACT(YEAR FROM doj) = 2000;

-- g. 
SELECT ename, salary * 12 AS Annual_salary,
       CONCAT('Every year ', ename, ' earns ', salary * 12) AS output_msg
FROM employee;

-- h. 
SELECT COUNT(*) AS Total_Employees
FROM employee;

-- i. Display the minimum salary of various categories of employees.
INSERT INTO employee VALUES ('&eno', '&ename', &salary, '&dno', &mngrno, '&doj', '&job', '&address', '&city', &pincode);
/*
ENO ENAME SALARY DNO MNGRNO DOJ       JOB      ADDRESS      CITY          PINCODE
e4  Alice 1500   d11 3      12-FEB-80 sales    123 Main St  New York      10
e6  Bob   2000   d21 4      14-MAR-85 manager  456 Elm St   Los Angeles   90
e8  Carol 3000   d30 6      16-APR-90 accounts 789 Oak St   Chicago       60
e9  David 1200   d20 7      18-MAY-95 sales    101 Pine St  San Francisco 94
e10 Emily 2500   d12 8      20-JUN-00 manager  202 Maple St Boston        02
e11 Frank 3500   d12 10     22-JUL-05 accounts 303 Cedar St Philadelphia  19

INSERT INTO employee (ENO, ENAME, SALARY, DNO, MNGRNO, DOJ, JOB, ADDRESS, CITY, PINCODE) VALUES 
('e4', 'Alice', 1500, 'd11', 3, '1980-02-12', 'clerk', '123 Main St', 'bombay', 10),
('e6', 'Bob', 2000, 'd21', 4, '1985-03-14', 'manager', '456 Elm St', 'cochin', 90),
('e8', 'Carol', 3000, 'd30', 6, '1990-04-16', 'accounts', '789 Oak St', 'madras', 60),
('e9', 'David', 1200, 'd20', 7, '1995-05-18', 'sales', '101 Pine St', 'bombay', 94),
('e10', 'Emily', 2500, 'd12', 8, '2000-06-20', 'manager', '202 Maple St', 'cochin', 02),
('e11', 'Frank', 3500, 'd12', 10, '2005-07-22', 'intern', '303 Cedar St', 'madras', 19);
*/

SELECT job, MIN(salary) AS Min_Salary
FROM employee
GROUP BY job;

-- j. List the minimum salary of various categories of employees in various departments having minimum salary greater than 7,000.
SELECT dno, job, MIN(salary) AS Min_Salary
FROM employee
GROUP BY dno, job
HAVING MIN(salary) > 7000;

-- k. Find the minimum salary of manager in various departments.
SELECT dno, MIN(salary) AS Min_Manager_Salary
FROM employee
WHERE job = 'manager'
GROUP BY dno;

-- l. List the names of all clerks along with the names of departments.
SELECT e.ename, d.dname
FROM employee e
JOIN department d ON e.dno = d.dno
WHERE e.job = 'clerk';

-- m. List the employee names and their date of joining in format dd/mm/yy.
SELECT ename, TO_CHAR(doj, 'DD-MM-YYYY') AS doj_formated
FROM employee;

-- n. Display ename, DNO of employees whose department is in department table
SELECT ename, dno
FROM employee
WHERE dno IN (
    SELECT dno
    FROM department
);

-- o. Display ename, DNO of employees whose job is in department table
SELECT ename, dno
FROM employee
WHERE job IN (
    SELECT dname
    FROM department
);

-- p. Display dname, DNO of department where departmentno is in employee table
SELECT dname, dno
FROM department
WHERE dno IN (
    SELECT dno
    FROM employee
);