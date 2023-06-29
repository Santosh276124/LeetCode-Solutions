# Write your MySQL query statement below
SELECT product_name, year, price FROM Sales
inner join Product 
on Product.product_id = Sales.product_id;
