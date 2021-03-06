--- Nome: Junior Vitor Ramisch 
--- Matrícula: 1811100034
--- Atividade Triggers

-- 2.1 Se o produto em estoque chegar ao valor 0
-- (não tem mais o produto) então o mesmo deve ser
-- removido das tabelas Product e Stock.

-- INSERT INTO product (eid, description) VALUES (1, 'Banana');
-- INSERT INTO product (eid, description) VALUES (2, 'Apple');
-- INSERT INTO product (eid, description) VALUES (3, 'Orange');
-- INSERT INTO product (eid, description) VALUES (4, 'Mango');

--INSERT INTO stock (eid, quantity) VALUES (1, 100);
--INSERT INTO stock (eid, quantity) VALUES (2, 150);
--INSERT INTO stock (eid, quantity) VALUES (3, 200);
--INSERT INTO stock (eid, quantity) VALUES (4, 60);

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
    FOR EACH ROW EXECUTE PROCEDURE drop_product()

-- DROP FUNCTION drop_product() CASCADE;
-- update stock set quantity=0 where eid=3;
-- update stock set quantity=0 where eid=1;


-- 2.2- Para evitar problemas com uso indevido de medicamentos
-- controlados, crie uma tabela auxiliar de  controle para verificar
-- quem está requisitando cada medicamento com a data e hora. Ou seja,
-- usuário que solicitou (logou no sistema), hora, medicamento_id.

CREATE TABLE medicine_request_log(
    id SERIAL,
    did INTEGER NOT NULL,
    date_request timestamp,
    medicine_id INTEGER NOT NULL,
    CONSTRAINT pk_medicine_request_log PRIMARY KEY (id)
);

CREATE OR REPLACE FUNCTION log_medicine_requests() RETURNS TRIGGER AS $$
    BEGIN
        INSERT INTO medicine_request_log (did, date_request, medicine_id) VALUES
        (NEW.did, current_timestamp, NEW.)
    END;
$$ LANGUAGE plpgsql;