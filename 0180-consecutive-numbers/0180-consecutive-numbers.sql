

with cte as (select      
            num,
            lead(num) over(order by id) as "Leadd",
            lag(num) over(order by id) as "Lagg"
        
from Logs)

select num as ConsecutiveNums from cte 
where  num = Leadd and num = Lagg
group by num

# select * from cte
