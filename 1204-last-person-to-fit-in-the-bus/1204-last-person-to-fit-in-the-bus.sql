# Write your MySQL query statement below

SELECT      
            # q1.person_id,
            q1.person_name
            # q1.weight,
            # SUM(q2.weight) AS total_wt
FROM        Queue q1, Queue q2
WHERE       q2.turn <= q1.turn
GROUP BY    q1.person_name
HAVING      SUM(q2.weight) <= 1000
ORDER BY    SUM(q2.weight) desc
LIMIT 1



