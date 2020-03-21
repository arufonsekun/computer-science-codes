CREATE TABLE curso (
    codc INTEGER, 
    nome VARCHAR(30) NOT NULL, 
    PRIMARY KEY(codc)
);

CREATE TABLE aluno (
    mat INTEGER, nome VARCHAR(30), 
    cpf INTEGER, ender VARCHAR(30), 
    email VARCHAR(30), PRIMARY KEY (mat),
    codc INTEGER REFERENCES curso(codc)
);

CREATE TABLE ccr (
    codccr INTEGER, 
    sigla VARCHAR(6), 
    nome VARCHAR(20), 
    cred INTEGER, 
    PRIMARY KEY(codccr), 
    codc INTEGER REFERENCES curso(codc)
);

CREATE TABLE historico (
    matr INTEGER REFERENCES aluno(mat), 
    codccr INTEGER REFERENCES ccr(codccr) unique NOT NULL, 
    semestre INTEGER unique NOT NULL, 
    ppres FLOAT, 
    media FLOAT, 
    PRIMARY KEY (matr)
);