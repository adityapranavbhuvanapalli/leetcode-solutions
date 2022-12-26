select max(salary) as SecondHighestSalary 
from (
    select salary 
    from employee 
    where salary not in (
        select max(salary) 
        from employee
    )
) tab;