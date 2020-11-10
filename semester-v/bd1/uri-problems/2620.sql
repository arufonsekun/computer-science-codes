select 
    customers.name,
    orders.id
from
    customers join orders on
    customers.id=orders.id_customers
where orders.orders_date < '2016-07-01';
