

# with cte as
# (select player_id as id, min(event_date) as first_date from Activity group by player_id) 

# select player_id from Activity 
# where 

with cte as
(select player_id, event_date,
        min(event_date) over(partition by player_id order by event_date) as "first"
from Activity)

select round( (count(player_id) / (select count(distinct player_id) from Activity) ), 2)  as fraction
from cte 
where datediff(event_date, first) = 1




