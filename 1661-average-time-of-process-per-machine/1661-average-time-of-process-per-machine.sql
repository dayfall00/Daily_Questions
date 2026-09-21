# Write your MySQL query statement below
WITH p_id as (
    select machine_id, process_id, 
    SUM(IF(activity_type = 'start', -timestamp, timestamp)) AS time
    from Activity group by machine_id,process_id
)
select machine_id,
    round(avg(time),3) as processing_time from p_id group by(machine_id);

-- WITH p_id AS (
--     SELECT 
--         machine_id,
--         process_id, 
--         SUM(IF(activity_type = 'start', -timestamp, timestamp)) AS time
--     FROM Activity
--     GROUP BY machine_id, process_id
-- )
-- SELECT 
--     machine_id,
--     AVG(time) AS processing_time
-- FROM p_id
-- GROUP BY machine_id;