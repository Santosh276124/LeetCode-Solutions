
# SELECT      c.customer_id,
#             p.product_key
# FROM        Customer c
# RIGHT JOIN  Product p  
# ON          p.product_key = c.product_key
# WHERE       p.product_key = c.product_key


SELECT      customer_id 
FROm Customer
GROUP BY customer_id
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product)