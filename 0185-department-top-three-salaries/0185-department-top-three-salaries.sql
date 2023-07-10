

with temp as (
SELECT e.id, e.name, e.salary, e.departmentId, d.name as dept,
dense_rank() over(partition by e.departmentId order by e.salary desc) as 'dense_rank'
from employee e left join department d
on d.id = e.departmentId
)

# select * from temp;

select dept as Department, name as Employee, salary as Salary
from temp 
where temp.dense_rank <= 3



