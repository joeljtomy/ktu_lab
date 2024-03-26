-- 1.
-- a.
CREATE TABLE book_details (
    ISBN VARCHAR(30),
    title VARCHAR(100),
    MRP NUMBER,
    publisher_name VARCHAR(30),
    author VARCHAR(30)
);
-- b. 
CREATE TABLE publisher (
    publisher_id VARCHAR(30),
    publisher_name VARCHAR(30),
    city VARCHAR(30),
    state VARCHAR(30),
    country VARCHAR(30)
);

-- 2
INSERT INTO book_details VALUES ('&ISBN', '&title', &MRP, '&publisher_name', '&author');
/*
ISBN              title       MRP   publisher_name author
978-3-16-148410-0 Gatsby      25.99 Penguin        F. Scott Fitzgerald
978-3-16-148411-0 Mockingbird 20.50 Harper         Harper Lee
978-3-16-148412-0 1984        18.75 Vintage        George Orwell
978-3-16-148413-0 Prejudice   22.00 Harper         Jane Austen
978-3-16-148414-0 Catcher     17.99 Penguin        J.D. Salinger

INSERT INTO book_details (ISBN, title, MRP, publisher_name, author) VALUES 
('978-3-16-148410-0', 'The Great Gatsby', 25.99, 'Penguin Books', 'F. Scott Fitzgerald'),
('978-3-16-148411-0', 'To Kill a Mockingbird', 20.50, 'HarperCollins', 'Harper Lee'),
('978-3-16-148412-0', '1984', 18.75, 'Vintage Books', 'George Orwell'),
('978-3-16-148413-0', 'Pride and Prejudice', 22.00, 'Random House', 'Jane Austen'),
('978-3-16-148414-0', 'The Catcher in the Rye', 17.99, 'Little, Brown and Company', 'J.D. Salinger');
*/

INSERT INTO publisher VALUES ('&publisher_id', '&publisher_name', '&city', '&state', '&country');
/*
INSERT INTO publisher (publisher_id, publisher_name, city, state, country) VALUES 
('PUB001', 'Penguin Books', 'London', 'England', 'United Kingdom'),
('PUB002', 'HarperCollins', 'New York City', 'New York', 'United States'),
('PUB003', 'Vintage Books', 'London', 'England', 'United Kingdom'),
('PUB004', 'Random House', 'New York City', 'New York', 'United States'),
('PUB005', 'Little, Brown and Company', 'Boston', 'Massachusetts', 'United States');
*/

-- 3. 
SELECT *
FROM book_details;

-- 4. 
SELECT *
FROM publisher;

-- 5. 
SELECT bd.title, bd.MRP, p.city
FROM book_details bd
JOIN publisher p 
ON bd.publisher_name = p.publisher_name;

-- 6. 
SELECT bd.ISBN, bd.title, bd.MRP, bd.author, p.*
FROM book_details bd
JOIN publisher p 
ON bd.publisher_name = p.publisher_name;

-- 7. List all publishers, details of books published by each publisher.
SELECT bd.*
FROM book_details bd
JOIN publisher p 
ON bd.publisher_name = p.publisher_name;

