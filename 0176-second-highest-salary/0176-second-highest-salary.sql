
# SELECT max(salary) AS SecondHighestSalary FROM Employee
# WHERE salary NOT IN (SELECT max(salary) FROM Employee)

select IFNULL(
        (select distinct salary from employee
        order by salary desc
        limit 1 offset 1),
        null
        ) as SecondHighestSalary

    

    



