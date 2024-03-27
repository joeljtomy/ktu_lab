-- 1. 
CREATE TABLE department (
    dno VARCHAR(10) PRIMARY KEY CHECK (dno LIKE 'd%'),
    dname VARCHAR(100),
    cnt_emp NUMBER CHECK (cnt_emp < 15),
    dept_hod VARCHAR(100)
);

INSERT INTO department VALUES ('&dno', '&dname', &cnt_emp, '&dept_hod');

/*
DNO DNAME       CNT_EMP DEPT_HOD
d10 Production  1       John Doe
d11 Sales       2       Peter Parker
d12 Exporting   3       Paul Wesley
d20 Maintenance 3       Zuck
d30 Repair      8       Tim Payn

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
ENO ENAME SALARY DNO MNGRNO DOJ       JOB      ADDRESS   CITY   PINCODE
e1  Don   1000   d10 1      18-JAN-65 sales    220 CB    cochin 65
e2  Donny 5000   d20 2      17-JAN-95 manager  Rosevila  delhi  35
e3  Jobin 9000   d30 5      17-JAN-45 accounts 22CB      bombay 72
e5  robin 900    d10        03-JAN-98 intern   22 CB     madras 45
e7  Jane  7500   d11 9      01-MAR-00 clerk    poovathil delhi  12

INSERT INTO employee (ENO, ENAME, SALARY, DNO, MNGRNO, DOJ, JOB, ADDRESS, CITY, PINCODE) VALUES 
('e1', 'Don', 1000, 'd10', 1, '18-JAN-65', 'sales', '220 CB', 'cochin', 65),
('e2', 'Donny', 5000, 'd20', 2, '17-JAN-95', 'manager', 'Rosevila', 'delhi', 35),
('e3', 'Jobin', 9000, 'd30', 5, '17-JAN-45', 'accounts', '22CB', 'bombay', 72),
('e5', 'robin', 900, 'd10', NULL, '03-JAN-98', 'intern', '22 CB', 'madras', 45),
('e7', 'Jane', 7500, 'd11', 9, '01-MAR-00', 'clerk', 'poovathil', 'delhi', 12);
*/

-- a. 
SELECT ename
FROM employee
WHERE doj > '1-1-1998'
AND dno = 'd10';

-- b. 
SELECT ename
FROM employee
WHERE NOT dno = 'd30';

-- c. 
SELECT e.ename
FROM employee e
JOIN department d
ON e.dno = d.dno
WHERE dname = 'Sales';

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
SELECT ename, salary * 12 AS Annual_salary, CONCAT('Every year ', ename, ' earns ', salary * 12) AS output_msg
FROM employee;

-- h. 
SELECT COUNT(*) AS Total_Employees
FROM employee;

-- i. 
INSERT INTO employee VALUES ('&eno', '&ename', &salary, '&dno', &mngrno, '&doj', '&job', '&address', '&city', &pincode);
/*
ENO ENAME SALARY DNO MNGRNO DOJ       JOB      ADDRESS    CITY   PINCODE
e4  Alice 8000   d12 1      12-FEB-80 clerk    220A CB    bombay 15
e6  Bob   5500   d11 2      14-JUN-85 manager  Rosewood   madras 40
e8  Carol 9500   d12 5      16-APR-90 accounts 22A CB     cochin 60
e9  David 1200   d30 9      18-MAY-95 sales    220B CB    delhi  32
e10 Frank 1200   d11 1      20-JUL-05 intern   Rosegarden madras 20
e11 John  7300   d20 2      29-AUG-80 clerk    22B CB     cochin 25
e12 Liam  6000   d10 5      21-SEP-85 manager  220C CB    bombay 30
e13 Maya  8500   d20 9      17-OCT-90 accounts Rosehill   cochin 42
e14 Alex  1000   d12 1      15-NOV-95 sales    22C CB     bombay 50
e15 Sofia 1000   d30 2      24-DEC-05 intern   220D CB    madras 52

INSERT INTO employee (ENO, ENAME, SALARY, DNO, MNGRNO, DOJ, JOB, ADDRESS, CITY, PINCODE) VALUES 
('e4', 'Alice', 8000, 'd12', 1, '12-FEB-80', 'clerk', '220A CB', 'bombay', 15),
('e6', 'Bob', 5500, 'd11', 2, '14-MAR-85', 'manager', 'Rosewood', 'madras', 40),
('e8', 'Carol', 9500, 'd12', 5, '16-APR-90', 'accounts', '22A CB', 'cochin', 60),
('e9', 'David', 1200, 'd30', 9, '18-MAY-95', 'sales', '220B CB', 'delhi', 32),
('e10', 'Frank', 1200, 'd11', 1, '22-JUL-05', 'intern', 'Rosegarden', 'madras', 20),
('e11', 'John', 7300, 'd20', 2, '29-AUG-80', 'clerk', '22B CB', 'cochin', 25),
('e12', 'Liam', 6000, 'd10', 5, '21-SEP-85', 'manager', '220C CB', 'bombay', 30),
('e13', 'Maya', 8500, 'd20', 9, '17-OCT-90', 'accounts', 'Rosehill', 'cochin', 42),
('e14', 'Alex', 1000, 'd12', 1, '15-NOV-95', 'sales', '22C CB', 'bombay', 50),
('e15', 'Sofia', 1000, 'd30', 2, '22-DEC-05', 'intern', '220D CB', 'madras', 52);
*/

SELECT job, MIN(salary) AS Min_Salary
FROM employee
GROUP BY job;

-- j.
SELECT job, dno, MIN(salary) AS Min_Salary
FROM employee
GROUP BY job, dno
HAVING MIN(salary) > 7000;

-- k. 
SELECT dno, MIN(salary) AS Min_Manager_Salary
FROM employee
WHERE job = 'manager'
GROUP BY dno;

-- l. 
SELECT e.ename, d.dname
FROM employee e
JOIN department d 
ON e.dno = d.dno
WHERE e.job = 'clerk';

-- m. 
SELECT ename, TO_CHAR(doj, 'DD-MM-YYYY') AS doj_formated
FROM employee;

-- n. 
SELECT e.ename, e.dno
FROM employee e
JOIN department d
ON e.dno = d.dno

-- o. 
SELECT ename, dno
FROM employee
WHERE job IN (
    SELECT dname
    FROM department
);
-- new rows required to work. question unclear. revise the query.

-- p.
SELECT dname, dno
FROM department
WHERE dno IN (
    SELECT dno
    FROM employee
);