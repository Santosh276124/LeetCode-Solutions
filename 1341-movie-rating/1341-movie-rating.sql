# Write your MySQL query statement below

(SELECT         
                u.name as results
                # COUNT(mr.rating)
FROM            MovieRating mr
INNER JOIN      Users u
ON              mr.user_id = u.user_id
GROUP BY        mr.user_id, u.name   
ORDER BY        COUNT(mr.rating) desc, name
limit 1)

UNION ALL

(SELECT          
                m.title as results
                # AVG(mr.rating)
FROM            MovieRating mr
INNER JOIN      Movies m
ON              mr.movie_id = m.movie_id
WHERE           DATE_FORMAT(mr.created_at, '%Y-%m') = "2020-02"
GROUP BY        mr.movie_id, m.movie_id   
ORDER BY        AVG(mr.rating) desc, m.title
limit 1)

# SELECT DATE_FORMAT("2020-02-12", '%Y-%m');
