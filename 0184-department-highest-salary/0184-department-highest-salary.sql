# Write your MySQL query statement below

with cte as
(SELECT         d.name as Department,
                e.name as Employee,
                e.salary as Salary
FROM            Employee e
LEFT JOIN       Department d
ON              e.departmentId = d.id),

# select * from cte

cte2 as
(select d.name, Max(e.salary) from Department d
left join Employee e on d.id = e.departmentId
group by d.name)

select Department,Employee,Salary from cte where (Department,Salary) in (select * from cte2)




