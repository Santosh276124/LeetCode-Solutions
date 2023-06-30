

SELECT r.contest_id, 
ROUND( (COUNT(r.user_id) / (SELECT COUNT(DISTINCT user_id ) FROM Users))*100, 2 ) AS percentage
FROM  Register r 
LEFT JOIN  Users u
ON r.user_id = u.user_id
GROUP BY r.contest_id
ORDER BY percentage desc, contest_id asc


# 