-- 1. Create a Student table with the following fields Name, Roll no, Age, Branch
CREATE TABLE Student (
    Name VARCHAR(100),
    Roll_no INT PRIMARY KEY,
    Age INT,
    Branch VARCHAR(50)
);

INSERT INTO Student VALUES ('&Name', &Roll_no, &Age, '&Branch');

-- 2. Create table called ‘Distributor’ with columns Dcode, Codename, Amount, Limit
CREATE TABLE Distributor (
    Dcode INT PRIMARY KEY,
    Codename VARCHAR(50),
    Amount INT(20),
    Limit INT(20)
);

INSERT INTO Distributor VALUES (&Dcode, '&Codename', &Amount, &Limit);

-- 3. Create a table called ‘Agencies’ with columns Agcode, Agname, Amount, Aglimit 
CREATE TABLE Agencies (
    Agcode INT PRIMARY KEY,
    Agname VARCHAR(50),
    Amount INT(20),
    Aglimit INT(20)
);
-- 4. 
INSERT INTO Agencies VALUES (&Agcode, '&Agname', &Amount, &Aglimit);

-- 5. Alter the structure of table student by adding a column called Totmarks
--    and insert values into the added field.
ALTER TABLE student
ADD Totmarks INT;

INSERT INTO Student VALUES &Totmarks;

-- 6. Update the ‘Agencies table, set amount field to 5000 corresponding to 
--    Agcode = 403.
UPDATE Agencies
SET Amount = 5000
WHERE Agcode = 403;

-- 7. Delete records from distributor table, whose amount is less than 70,000.
DELETE FROM Distributor
WHERE Amount < 70000;

-- 8. Display the Agcode and Agname from table Agencies in reverse order of 
--    their amount.
SELECT Agcode, Agname
FROM Agencies
ORDER BY Amount DESC;

-- 9. Display all Agency names for amount less than 4000 from table ‘Agencies’.
SELECT Agname
FROM Agencies
WHERE Amount < 4000;

-- 10. Display the student info from student table renaming the fields 
--     name as studentname, roll no as student_rollno.
SELECT Name AS studentname, Roll_no AS student_rollno, Age, Branch, Totmarks
FROM student;

-- 11. Display the student info only in CS Branch.
SELECT * 
FROM Student
WHERE Branch = 'CS';

-- 12. Update the limit field and amount field of distributor table 
--     to 1, 50,000 and 10,000 respectively whose limit is 1,00,000.
UPDATE Distributor
SET Limit = 150000,
    Amount = 10000
WHERE Limit = 100000;

-- 13. Display the average of total marks of the student.
SELECT AVG(Totmarks)
FROM Student;