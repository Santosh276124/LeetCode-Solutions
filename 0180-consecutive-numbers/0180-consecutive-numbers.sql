# Write your MySQL query statement below
with cte as 
(
select *,
lag(num,1) over(order by id) as "lag1",
lag(num,2) over(order by id) as "lag2"
from Logs)

select distinct num as ConsecutiveNums from cte
where num = lag1 and num = lag2;

# method 2

# select distinct num as ConsecutiveNums
# from Logs
# where (id+1, num) in (select * from Logs) and (id+2, num) in (select * from Logs)