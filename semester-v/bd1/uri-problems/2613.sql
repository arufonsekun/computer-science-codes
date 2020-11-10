select
    movies.id, name
from
    movies inner join prices
    on movies.id_prices=prices.id
where  
    value < 2.00;
