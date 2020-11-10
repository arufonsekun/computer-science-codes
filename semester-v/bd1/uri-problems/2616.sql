select
    customers.id, customers.name
from
    customers
where
    id not in
    (
        select
            customers.id
        from
            customers inner join locations
            on customers.id=locations.id_customers
    );
