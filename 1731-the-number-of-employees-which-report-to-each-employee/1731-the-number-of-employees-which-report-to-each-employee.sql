# Write your MySQL query statement below


# SELECT      employee_id,
#             name,
#             reports_to
# FROM        Employees
# WHERE       reports_to IS NOT NULL


# SELECT      employee_id, name, COUNT(reports_to) FROM Employees
# WHERE       employee_id IN (SELECT reports_to FROM Employees WHERE reports_to IS NOT NULL)


SELECT      e1.employee_id,
            e1.name, 
            COUNT(e2.reports_to) as reports_count ,
            ROUND(AVG(e2.age)) AS average_age
FROM        Employees e1, Employees e2
WHERE       e2.reports_to IS NOT NULL AND e1.employee_id = e2.reports_to
GROUP BY    e1.employee_id
ORDER BY    e1.employee_id