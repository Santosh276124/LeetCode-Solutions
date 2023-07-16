
with cte as
(select  tiv_2015
from    Insurance
group by tiv_2015
having count(tiv_2015) > 1),

cte2 as
(
select lat,lon from Insurance
group by lat,lon
having count(lat) = 1)



select round(sum(tiv_2016),2) as tiv_2016
from Insurance 
where tiv_2015 in (select * from cte) and (lat,lon) in (select * from cte2)