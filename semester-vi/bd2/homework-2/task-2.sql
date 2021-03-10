--- Nome: Junior Vitor Ramisch 
--- Matrícula: 1811100034
--- Atividade Triggers

-- 2.2 Para evitar problemas com uso indevido de medicamentos
-- controlados, crie uma tabela auxiliar de  controle para verificar
-- quem está requisitando cada medicamento com a data e hora. Ou seja,
-- usuário que solicitou (logou no sistema), hora, medicamento_id.

CREATE TABLE medicine_request_log(
    id SERIAL,
    current_usr varchar(20),
    requested_at timestamp,
    eid INTEGER NOT NULL,
    CONSTRAINT pk_medicine_request_log PRIMARY KEY (id)
);

CREATE OR REPLACE FUNCTION log_medicine_requests() RETURNS TRIGGER AS $$
    BEGIN
        -- NEW.quantity < OLD.quantity significa que 
        -- está sendo retirado medicamentos do estoque,
        -- então o acesso será registrado (insert).
        -- O contrário significa que o estoque estará
        -- sendo reposto.
        IF NEW.quantity < OLD.quantity THEN
            INSERT INTO medicine_request_log (current_usr, requested_at, eid) VALUES
            (current_user, current_timestamp, NEW.eid);
        END IF;
        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER log_medicine_access
    BEFORE UPDATE
ON stock
    FOR EACH ROW EXECUTE PROCEDURE log_medicine_requests();

-- Cria o evento que aciona o trigger, 
-- nesses exemplos o estoque está sendo
-- consumido.
update stock set quantity=100 where eid=2;
update stock set quantity=110 where eid=5;

-- Exemplo de acesso que não necessita de log
-- pois nessa situação o estoque estará sendo
-- reposto e não consumido.
update stock set quantity=110 where eid=1;

-- drop trigger if exists log_medicine_access on stock CASCADE;
-- drop function log_medicine_requests() CASCADE;
-- drop table medicine_request_log;
