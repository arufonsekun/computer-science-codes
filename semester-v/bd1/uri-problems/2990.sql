select
    empregados.cpf,
    empregados.enome,
    departamentos.dnome
from
    empregados join departamentos on empregados.dnumero = departamentos.dnumero 
where
    empregados.cpf not in (select distinct empregados.cpf from empregados join trabalha on empregados.cpf=trabalha.cpf_emp)
order by empregados.cpf;
