# Write your MySQL query statement below

with cte as (
select income,
        (case
            when income < 20000 then "Low Salary"
            when income >= 20000 and income <= 50000 then "Average Salary"
            when income > 50000 then "High Salary"
            
        end) as category
from Accounts
)

(select "Low Salary" as category, count(category) as accounts_count from cte
where category = "Low Salary")
union
(select "Average Salary" as category, count(category) as accounts_count from cte
where category = "Average Salary")
union
(select "High Salary" as category, count(category) as accounts_count from cte
where category = "High Salary")

