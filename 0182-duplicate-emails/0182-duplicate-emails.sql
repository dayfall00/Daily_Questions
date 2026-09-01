# Write your MySQL query statement below
-- select email from 
-- Person
-- group by email
-- having count(id)>1


select email
from(
    select email, count(id) as cnt
    from Person
    group by email
) as fx
where cnt>1