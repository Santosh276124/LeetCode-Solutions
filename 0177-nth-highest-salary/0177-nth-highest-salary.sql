CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      
      
       
        # select rn from cte

        select distinct salary from (
                    select salary,
                            dense_rank() over(order by salary desc) as rn
                    from employee
        ) as cte 
        where cte.rn = N
      
     
      
  );
END

