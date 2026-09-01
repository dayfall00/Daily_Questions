# Write your MySQL query statement below
-- 1) find no of students in each class
-- select class from 
--     (   select distinct class, 
--         count(student) as cnt 
--         from courses 
--         group by class) 
-- as fx
-- where cnt>=5


select class 
from courses
group by class
having count(student) >=5