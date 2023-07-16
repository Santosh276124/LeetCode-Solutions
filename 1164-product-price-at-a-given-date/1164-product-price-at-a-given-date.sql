

with cte as
(select     product_id as id,
            # new_price,
            max(change_date) as dt
from        Products
where       change_date <= "2019-08-16"
group by    product_id),

cte2 as
(select      product_id as id,
            # new_price,
            min(change_date) as dt
from        Products
where       (change_date > "2019-08-16")
group by product_id),

cte3 as
(select * from cte),

cte4 as 
(select * from cte2 
where (id) not in (select id from cte))

(select product_id, new_price as price 
from Products where (product_id, change_date) in (select * from cte3))
union
(select product_id, 10 as price 
from Products where (product_id, change_date) in (select * from cte4))







