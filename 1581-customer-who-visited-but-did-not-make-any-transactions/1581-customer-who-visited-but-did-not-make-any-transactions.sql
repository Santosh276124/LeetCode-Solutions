# Write your MySQL query statement below
# SELECT v.customer_id,  COUNT( v.customer_id) FROM Visits v

# WHERE v.visit_id NOT IN (SELECT visit_id FROM Transactions)
# ORDER BY COUNT(v.customer_id);

SELECT  v.customer_id,  COUNT(v.visit_id) AS count_no_trans  FROM Visits v
LEFT JOIN Transactions t
ON t.visit_id = v.visit_id
WHERE t.visit_id IS NULL
GROUP BY v.customer_id;
