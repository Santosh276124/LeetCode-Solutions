# Write your MySQL query statement below
# SELECT v.customer_id,  COUNT( v.customer_id) FROM Visits v

# WHERE v.visit_id NOT IN (SELECT visit_id FROM Transactions)
# ORDER BY COUNT(v.customer_id);

SELECT  customer_id,  COUNT(customer_id) AS count_no_trans  FROM Visits
WHERE visit_id NOT IN (SELECT visit_id FROM Transactions)
GROUP BY customer_id
ORDER BY COUNT(customer_id) DESC
