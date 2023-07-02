# Write your MySQL query statement below

SELECT  class
FROM    Courses
GROUP BY class
HAVIng  COUNT(student) >= 5
