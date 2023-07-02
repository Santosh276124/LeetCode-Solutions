# Write your MySQL query statement below

SELECT      s.product_id,
            # p.product_name,
            s.year AS first_year,
            s.quantity,
            s.price
FROM        Sales s
INNER JOIN  Product p
ON          s.product_id = p.product_id
WHERE       (s.product_id,s.year) IN (SELECT product_id, MIN(year) FROM Sales GROUP BY product_id)
# GROUP BY    s.product_id
# ORDER BY    s.year 
# LIMIT 1


# SELECT product_id, year FROM Sales
# WHERE  (product_id,year) IN (SELECT product_id, MIN(year) FROM Sales GROUP BY product_id)
