-- Crie uma tabela com a assinatura 
-- “employee (id int, name varchar(50), bithData int, salary float)”. 
-- Insira 5 tuplas

CREATE TABLE employee(id INT, name VARCHAR(50), birthDate DATE, salary FLOAT);

INSERT INTO employee (id, name, birthDate, salary) VALUES 
(1, 'Fausto Silva', '1950-05-02', 1200),
(2, 'Ian J. Goodfellow', '1986-10-15', 1500),
(3, 'Guido van Rossum', '1956-01-31', 1800),
(4, 'Linus Benedict Torvalds', '1969-12-28', 1550),
(5, 'Edgar Frank Codd', '1923-08-23', 1400);

select * from employee;

-- A) Faça uma função capaz de aplicar um aumento de 10% em todos os funcionários;
CREATE OR REPLACE FUNCTION increase_salary() RETURNS VOID AS $$
	BEGIN
		RAISE NOTICE 'Aumento de 10% para todos os empregados', '%';
		UPDATE employee 
		set salary = employee_.salary + employee_.salary / 10
		WHERE id = employee_.id;
		RETURN;
	END;
$$ LANGUAGE plpgsql;
-- Remova o comentário para testar o exercício A
-- select increase_salary();
-- select * from employee;


-- B) Faça uma função capaz de aplicar um aumento de X% nos funcionários com id
-- maior que N. Importante: X e N serão passados por argumento. 
CREATE OR REPLACE FUNCTION increase_salary_conditionally(X INT, N INT) RETURNS VOID AS $$
	BEGIN
		RAISE NOTICE 'Aumento de % para funcionários com id maior que %', concat(X, '%'), N;

		UPDATE employee
		set salary = employee_.salary + employee_.salary * X / 100
		WHERE id = employee_.id and employee_.id > N;
	END;
$$ LANGUAGE plpgsql;
-- Remova o comentário para testar o exercício B
-- select increase_salary_conditionally(5, 3);
-- select * from employee;


-- C) Faça uma função capaz de remover os funcionários com salário acima da média.
CREATE OR REPLACE FUNCTION drop_over_payed_employee() RETURNS VOID AS $$
	BEGIN
		SELECT AVG(salary) INTO avg_salary from employee;
		RAISE NOTICE 'A média dos salários é %', concat('R$', avg_salary);
        DELETE FROM employee WHERE id = employee_.id and employee_.salary > avg_salary;
	END;
$$ LANGUAGE plpgsql;
-- Remova o comentário para testar o exercício C
-- select drop_over_payed_employee();
-- select * from employee;


-- D) Crie uma função que armazene o usuário corrente e a data atual ao adicionar
-- uma nova tupla na tabela. Ex: insereDados( 10,’joao’,’xx’, ‘j’,’1’)
-- *current_user- varchar()
-- *current_date - date
-- *ALTER TABLE table_name ADD column_name datatype;

CREATE OR REPLACE FUNCTION insert_data(id int, name VARCHAR(50), birthDate DATE, salary FLOAT) RETURNS VOID AS $$
	DECLARE
		current_u VARCHAR;
		current_d DATE;
	BEGIN 
		SELECT current_user INTO current_u;
		SELECT current_date INTO current_d;

		ALTER TABLE employee ADD COLUMN current_usr VARCHAR(50), ADD COLUMN current_d DATE;

		INSERT INTO employee (id, name, birthDate, salary, current_usr, current_d) VALUES
		(id, name, birthDate, salary, current_u, current_d);

		RETURN;
	END;
$$ LANGUAGE plpgsql;
-- Remova o comentário para testar o exercício D
-- select insert_data(6, 'Alan Turing', '1912-06-23', 1700);
-- select * from employee;

drop table employee;
drop function increase_salary();
drop function increase_salary_conditionally(INT, INT);
drop function drop_over_payed_employee();
drop function insert_data(int, VARCHAR(50), DATE, FLOAT);
