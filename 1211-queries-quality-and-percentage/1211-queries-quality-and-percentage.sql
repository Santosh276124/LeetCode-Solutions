

# SELECT query_name, poor_rating FROM temp;

SELECT  query_name,
        ROUND(AVG(rating/position), 2) AS quality,
        ROUND( ( COUNT(CASE WHEN rating < 3 THEN 1 END )  / COUNT(rating) )*100 , 2) AS poor_query_percentage
FROM Queries
GROUP BY query_name

# SELECT query_name, COUNT(CASE WHEN rating < 3 THEN 1 END), COUNT(rating) FROM Queries
# # WHERE rating  < 3
# GROUP BY query_name




