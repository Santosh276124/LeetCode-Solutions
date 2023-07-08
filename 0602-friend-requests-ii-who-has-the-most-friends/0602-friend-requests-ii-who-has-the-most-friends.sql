

with temp as (
        (SELECT      requester_id as id, 
                    COUNT(requester_id) as cnt
                    # COUNT(accepter_id)
        FROM        RequestAccepted
       
        GROUP BY    requester_id) 

        UNION ALL

        (SELECT      accepter_id as id,
                    COUNT(accepter_id) as cnt
                    # COUNT(accepter_id)
        FROM        RequestAccepted
       
        GROUP BY    accepter_id) 
    )
    
    SELECT  id, SUM(cnt) as num FROM temp
    GROUP BY id
    ORDER BY num desc
    LIMIT 1
    
