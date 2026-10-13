# Write your MySQL query statement below
with slry(salary,rnk) as(
    select salary,
    DENSE_rank() over( order by salary  desc) as rnk
    from employee
)
 SELECT IFNULL((select distinct salary 
from slry 
where rnk=2), NULL) AS SecondHighestSalary