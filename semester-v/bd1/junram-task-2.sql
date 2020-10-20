-- Matricula: 1811100034
-- Nome:      Junior Vitor Ramisch
-- Email:     junior.ramisch@gmail.com

-- DDL statements
CREATE TABLE cliente(
    cpf   INTEGER NOT NULL,
    nome  VARCHAR NOT NULL,
    email VARCHAR NOT NULL,
    ntel  VARCHAR NOT NULL,
    CONSTRAINT pk_cliente PRIMARY KEY (cpf)
);

CREATE TABLE raca(
    cod   INTEGER NOT NULL,
    descr VARCHAR NOT NULL,
    CONSTRAINT pk_raca PRIMARY KEY (cod)
);

CREATE TABLE pet(
    codpet INTEGER NOT NULL,
    nome   VARCHAR NOT NULL,
    draca  INTEGER NOT NULL,
    dono   INTEGER NOT NULL,
    coment VARCHAR,
    CONSTRAINT pk_pet PRIMARY KEY (codpet),
    CONSTRAINT fk_raca FOREIGN KEY (draca) REFERENCES raca(cod),
    CONSTRAINT fk_cliente FOREIGN KEY (dono) REFERENCES cliente(cpf)
);

CREATE TABLE historico(
    idhist   INTEGER NOT NULL,
    codpet   INTEGER NOT NULL,
    datahist DATE NOT NULL,
    medida   VARCHAR(11) NOT NULL,
    valor    NUMERIC(4,2) NOT NULL,
    unid     VARCHAR(2) NOT NULL,
    CONSTRAINT pk_historico PRIMARY KEY (idhist),
    CONSTRAINT fk_pet FOREIGN KEY (codpet) REFERENCES pet(codpet)
);

-- DML statements
INSERT INTO cliente (cpf, nome, email, ntel) VALUES 
    (11111, 'Cruela de Vil', 'cruela@dalmata.com', '11 99932323'),
    (44444, 'Roger Dearly', 'roger@dalmata.com', '11 98761111'),
    (55555, 'Lee Duncan', 'lee@rinty', '21 34512222'),
    (66666, 'Anita Campbell', 'anita@dalmata.com', '11 87679988');

INSERT INTO raca (cod, descr) VALUES
    (1, 'Dalmata'),
    (2, 'Pastor Alemão'),
    (3, 'Yorkshire');

INSERT INTO pet (codpet, nome, draca, dono) VALUES
    (1, 'Pongo', 1, 44444),
    (4, 'Benji', 3, 11111);

INSERT INTO pet (codpet, nome, draca, dono, coment) VALUES
    (2, 'Rin tin tin', 2, 55555, 'Muito dócil'),
    (3, 'Perdy', 1, 66666, 'Alérgica a sabão')
    (5, 'Boris', 2, 66666, 'Inimigo de banhos');

INSERT INTO historico (idhist, codpet, datahist, medida, valor, unid) VALUES
    (1, 1, '10/05/2018', 'peso', 10.5, 'KG'),
    (2, 1, '10/05/2018', 'altura', 98, 'CM'),
    (3, 1, '10/05/2018', 'comprimento', 1.23, 'M'),
    (4, 2, '05/06/1975', 'peso', 14.56, 'KG'),
    (5, 2, '05/06/1975', 'altura', 1.2, 'M'),
    (6, 3, '12/08/2018', 'peso', 9.8, 'KG'),
    (7, 1, '14/08/2018', 'peso', 11.2, 'KG'),
    (8, 5, '11/11/2011', 'altura', 89, 'CM'),
    (9, 3, '10/10/2020', 'peso', 3.4, 'KG');