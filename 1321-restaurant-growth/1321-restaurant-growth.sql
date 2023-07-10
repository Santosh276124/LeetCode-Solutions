
with 
    cte as 
    (
    SELECT      visited_on,
                sum(amount) as total
    FROM        Customer
    GROUP BY    visited_on
    ),
    
    cte2 as
    (
    select visited_on, 
    ROUND(SUM(total) over (order by visited_on ROWS between 6 preceding and current row),2) as amount,
    round(AVG(total) over (order by visited_on ROWS between 6 preceding and current row),2) as average_amount
    from cte
    )


select * from cte2
where visited_on >= (select visited_on from cte2 order by visited_on limit 1) + 6





