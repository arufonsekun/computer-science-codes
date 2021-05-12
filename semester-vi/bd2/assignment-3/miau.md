## Último trabalho bosta

- Consulta:
    ```sql
        select
            p.description, s.quantity
        from product p, stock s
        where p.eid=s.eid and
              s.quantity > 500 and
              s.quantity < 1500;
    ```

- Explain da consulta sem índices:
```
                           QUERY PLAN                             
-------------------------------------------------------------------
 Hash Join  (cost=1.30..2.55 rows=1 width=62)
   Hash Cond: (p.eid = s.eid)
   ->  Seq Scan on product p  (cost=0.00..1.19 rows=19 width=62)
   ->  Hash  (cost=1.28..1.28 rows=1 width=8)
         ->  Seq Scan on stock s  (cost=0.00..1.28 rows=1 width=8)
               Filter: ((quantity > 500) AND (quantity < 1500))
```


- Índices criados:
```sql
create index stock_quantity on stock(quantity);
```

- Explain da consulta com índices:

```
                            QUERY PLAN                             
-------------------------------------------------------------------
 Hash Join  (cost=1.30..2.55 rows=1 width=62)
   Hash Cond: (p.eid = s.eid)
   ->  Seq Scan on product p  (cost=0.00..1.19 rows=19 width=62)
   ->  Hash  (cost=1.28..1.28 rows=1 width=8)
         ->  Seq Scan on stock s  (cost=0.00..1.28 rows=1 width=8)
               Filter: ((quantity > 500) AND (quantity < 1500))
```

- O custo de execução com e sem o índice é o mesmo.

- A consulta está acionando o índice? Não.

- O scan completo da tabela é mais viável do que utilizar o índice.

- Qual algoritmos foi usado para realizar o Join? Hash.

- [Funcionamento do Hash join](https://youtu.be/uX6PmZhS2zU?t=410)