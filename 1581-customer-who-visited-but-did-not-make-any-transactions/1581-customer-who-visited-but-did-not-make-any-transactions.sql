# Write your MySQL query statement below
-- 1) find those visit ids those who have made transactions
-- 2) get those customers who havent made any transactions
-- 3) group by customer_id then count        
select customer_id
    , count(visit_id) as count_no_trans
    from(    select *
        from visits
        where visit_id not in   (
                    select  distinct visit_id
                    from transactions   )
    )as customer_no_trans
group by customer_id
