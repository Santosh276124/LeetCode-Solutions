# Write your MySQL query statement below

WITH temp as (
                SELECT num FROM MyNumbers
                GROUP BY num
                HAVING COUNT(num) = 1
                ORDER BY num desc
                LIMIT 1
    )

SELECT IF(COUNT(*)>0, num, null ) AS num FROM temp
