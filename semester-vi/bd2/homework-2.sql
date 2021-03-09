--- Nome: Junior Vitor Ramisch 
--- Matrícula: 1811100034
--- Atividade Triggers

-- 2.1 Se o produto em estoque chegar ao valor 0
-- (não tem mais o produto) então o mesmo deve ser
-- removido das tabelas Product e Stock.

CREATE OR REPLACE FUNCTION populate_product_and_stock() RETURNS VOID AS $$
    BEGIN
        INSERT INTO product (eid, description) VALUES (1, 'Amoxicillin');
        INSERT INTO product (eid, description) VALUES (2, 'Azithromycin');
        INSERT INTO product (eid, description) VALUES (3, 'Clonazepam');
        INSERT INTO product (eid, description) VALUES (4, 'Ibuprofen');
        INSERT INTO product (eid, description) VALUES (5, 'Relaxon');

        INSERT INTO stock (eid, quantity) VALUES (1, 100);
        INSERT INTO stock (eid, quantity) VALUES (2, 150);
        INSERT INTO stock (eid, quantity) VALUES (3, 200);
        INSERT INTO stock (eid, quantity) VALUES (4, 90);
        INSERT INTO stock (eid, quantity) VALUES (5, 160);
    END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION drop_product() RETURNS TRIGGER AS $$
    BEGIN
        IF NEW.quantity = 0 THEN
            DELETE FROM Stock WHERE NEW.eid = eid;
            DELETE FROM Product WHERE NEW.eid = eid;
        END IF;
        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER drop_product_if_out_of_supply 
    AFTER UPDATE
ON Stock
    FOR EACH ROW EXECUTE PROCEDURE drop_product();

select populate_product_and_stock();

update stock set quantity=0 where eid=3;
update stock set quantity=0 where eid=1;

select * from stock;

drop function populate_product_and_stock();
drop function drop_product() CASCADE;


-- 2.2- Para evitar problemas com uso indevido de medicamentos
-- controlados, crie uma tabela auxiliar de  controle para verificar
-- quem está requisitando cada medicamento com a data e hora. Ou seja,
-- usuário que solicitou (logou no sistema), hora, medicamento_id.
CREATE TABLE medicine_request_log(
    id SERIAL,
    current_usr varchar(20),
    date_request timestamp,
    medicine_id INTEGER NOT NULL,
    CONSTRAINT pk_medicine_request_log PRIMARY KEY (id)
);

CREATE OR REPLACE FUNCTION log_medicine_requests() RETURNS TRIGGER AS $$
    BEGIN
        INSERT INTO medicine_request_log (current_usr, date_request, medicine_id) VALUES
        (current_user, current_timestamp, NEW.eid);
        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER log_medicine_access
    BEFORE UPDATE
ON Stock
    FOR EACH ROW EXECUTE PROCEDURE log_medicine_requests();