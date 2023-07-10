# Write your MySQL query statement below

# select num,
#         lag(num, 3) over(order by num) as "lag"
# from Logs


select distinct num as ConsecutiveNums
from Logs
where (id+1, num) in (select * from Logs) and (id+2, num) in (select * from Logs)