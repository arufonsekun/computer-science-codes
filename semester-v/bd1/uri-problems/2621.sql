select products.name from providers inner join products on providers.id=products.id_providers where products.amount > 10 and products.amount < 20 and substring(providers.name for 1) = 'P';
