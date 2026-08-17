# Write your MySQL query statement below
select sell_date,
    count(distinct(product)) as num_sold
    , group_concat(Distinct product Order by product asc separator ',') as products
from Activities
Group by sell_date
order by sell_date asc;
