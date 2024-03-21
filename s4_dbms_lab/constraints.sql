-- 1. 
CREATE TABLE department (
    dno VARCHAR(10) PRIMARY KEY CHECK (dno LIKE 'd%'),
    dname VARCHAR(100),
    cnt_emp NUMBER CHECK (cnt_emp < 15),
    dept_hod VARCHAR(100)
);

INSERT INTO department VALUES ('&dno', '&dname', &cnt_emp, '&dept_hod');

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
SELECT ename, salary * 12 AS annual_salary,
       CONCAT('Every year ', ename, ' earns ', salary * 12) AS output_msg
FROM employee;

-- h. 
SELECT COUNT(*) AS Total
FROM employee;

-- i. Display the minimum salary of various categories of employees.
INSERT INTO employee VALUES ('&eno', '&ename', &salary, '&dno', &mngrno, '&doj', '&job', '&address', '&city', &pincode);
/*
ENO ENAME SALARY DNO MNGRNO DOJ       JOB      ADDRESS      CITY          PINCODE
e4  Alice 1500   d10 3      12-FEB-80 sales    123 Main St  New York      10001
e6  Bob   2000   d20 4      14-MAR-85 manager  456 Elm St   Los Angeles   90001
e8  Carol 3000   d30 6      16-APR-90 accounts 789 Oak St   Chicago       60601
e9  David 1200   d10 7      18-MAY-95 sales    101 Pine St  San Francisco 94101
e10 Emily 2500   d20 8      20-JUN-00 manager  202 Maple St Boston        02101
e11 Frank 3500   d30 10     22-JUL-05 accounts 303 Cedar St Philadelphia  19101
*/

SELECT job, MIN(salary)
FROM employee
GROUP BY job;
