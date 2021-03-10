--- Nome: Junior Vitor Ramisch 
--- Matrícula: 1811100034
--- Atividade Triggers

-- 2.1 Se o produto em estoque chegar ao valor 0
-- (não tem mais o produto) então o mesmo deve ser
-- removido das tabelas Product e Stock.

CREATE OR REPLACE FUNCTION drop_product() RETURNS TRIGGER AS $$
    BEGIN
        IF NEW.quantity - OLD.quantity = 0 THEN
            DELETE FROM Stock WHERE NEW.eid = eid;
            DELETE FROM Product WHERE NEW.eid = eid;
        END IF;
        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER drop_product_if_out_of_supply 
    AFTER UPDATE
ON stock
    FOR EACH ROW EXECUTE PROCEDURE drop_product();

-- Remove as funções e o trigger
-- drop trigger if exists drop_product_if_out_of_supply() on stock CASCADE;
-- drop function drop_product() CASCADE;