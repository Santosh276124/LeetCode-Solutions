# Write your MySQL query statement below

with cte as
(
select      id, student as st,
            lead(student) over() as "Leadd",
            lag(student) over() as "Lagg"
from        Seat
)

# select id, st, Leadd, Lagg from cte
# where id%2=1


select      id, 
            (
                Case
                    when (id%2=1 and Leadd is not null) then Leadd
                    when (id%2=0 and Lagg is not null) then Lagg
                    else st
                end
            ) as student
from        cte