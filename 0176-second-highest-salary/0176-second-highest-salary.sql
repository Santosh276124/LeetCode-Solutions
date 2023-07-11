
# SELECT max(salary) AS SecondHighestSalary FROM Employee
# WHERE salary NOT IN (SELECT max(salary) FROM Employee)


with cte as (
            select salary,
                    dense_rank() over(order by salary desc) as rn
            from employee
)

-- select * from cte

select max(salary) as SecondHighestSalary from cte 
where rn = 2
    

    



