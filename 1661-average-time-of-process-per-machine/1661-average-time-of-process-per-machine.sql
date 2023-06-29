

SELECT machine_id, ROUND(AVG(end_time - start_time), 3) AS processing_time
FROM (
        SELECT machine_id, process_id, max(timestamp ) AS end_time, min(timestamp) as start_time
        FROM Activity
        GROUP BY machine_id, process_id
    ) AS temp
GROUP BY machine_id;
     
    
    
     



