# Write your MySQL query statement below
select majdoor.name as employee from Employee majdoor
inner join employee malik on
majdoor.managerId=malik.id
where majdoor.salary>malik.salary