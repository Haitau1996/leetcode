# Write your MySQL query statement below
SELECT product_name, year, price
FROM Product, Sales
WHERE Product.product_id = Sales.product_id;