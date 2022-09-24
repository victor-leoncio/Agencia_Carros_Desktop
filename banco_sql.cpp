#include "banco_sql.h"

//Função para conectar ao banco
bool conectar_banco (MYSQL * banco)
{
    if(mysql_real_connect(banco, "localhost", "root", "Password123#@!", "agencia_auto", 3306, NULL, 0)){
        puts("\nSucesso ao conectar no Banco!");
        return 1;
    } else {
        puts("\nFalha ao conectar no Banco!");
        return 0;
    }
}

//Imprimi a tabela agencia
MYSQL_RES * agencia(MYSQL * banco)
{
    if(!mysql_query(banco, "select * from agencia;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Erro: Agencia");
    }
    return NULL;
}

//Imprimi a tabela carros
MYSQL_RES * carros(MYSQL * banco)
{
    if(!mysql_query(banco, "select * from carros;"))
    {
        return mysql_store_result(banco);
    }else {
        puts("Error: Carros");
    } 
    return NULL;
}

//Imprimi a tabela clientes
MYSQL_RES * clientes(MYSQL * banco)
{ 
    if(!mysql_query(banco, "select * from clientes;"))
    {
        return mysql_store_result(banco); 
    } else {
        puts("Error: Clientes");
    }
    return NULL;
}

//Imprimi a tabela funcionarios
MYSQL_RES * funcionarios(MYSQL * banco)
{ 
    if(!mysql_query(banco, "select * from funcionarios;"))
    {
        return mysql_store_result(banco); 
    } else {
        puts("Error: Funcionarios");
    }
    return NULL;
}

//Imprimi a tabeça pecas
MYSQL_RES * pecas(MYSQL * banco)
{ 
    if(!mysql_query(banco, "select * from pecas;"))
    {
        return mysql_store_result(banco); 
    } else {
        puts("Error: Pecas");
    }  
    return NULL;
}

//Imprimi a tabela pecas_pagas
MYSQL_RES * pecas_pagas(MYSQL * banco)
{ 
    if(!mysql_query(banco, "select * from pecas_pagas;"))
    {
        return mysql_store_result(banco); 

    } else {
        puts("Error: Pecas_pagas");
    } 
    return NULL;
}

//Imprimi a tabela revisao
MYSQL_RES * revisao(MYSQL * banco)
{ 
    if(!mysql_query(banco, "select * from revisao;"))
    {
        return mysql_store_result(banco); 

    } else {
        puts("Error: Revisao");
    } 
    return NULL;
}

//Imprimi a tabela trocas
MYSQL_RES * trocas(MYSQL * banco)
{ 
    if(!mysql_query(banco, "select * from trocas;"))
    {
        return mysql_store_result(banco); 

    } else {
        puts("Error: Trocas");
    } 
    return NULL;
}

//Imprimi a tabela vendas
MYSQL_RES * vendas(MYSQL * banco)
{ 
    if(!mysql_query(banco, "select * from vendas;"))
    {
        return mysql_store_result(banco); 

    } else {
        puts("Error: Vendas");
    } 
    return NULL;
}

//Imprimi os carros que não foram comprados por algum cliente
MYSQL_RES * carros_n_vendidos(MYSQL * banco)
{
    if(!mysql_query(banco, "select * "
                           "from carros c1 "
                           "where c1.cod_carro not in ("
                           "select c2.cod_carro "
                           "from vendas v2 natural join carros c2);"))
    {
        return mysql_store_result(banco);

    } else {
        puts("Error: Mais_Vendidos");
    }
    return NULL;
}

//Imprimi os carro(s) mais vendidos de todos os tempos
MYSQL_RES * mais_vendidos(MYSQL * banco)
{
    if(!mysql_query(banco, "select * from carros c1 natural join ( "
                           "select c2.cod_carro, count(c2.cod_carro) as qtd_vendidos "
                           "from vendas v1 natural join carros c2 "
                           "group by c2.cod_carro) t1 where qtd_vendidos = ( "
                           "select max(qtd_vendidos) from ( "
                           "select count(c3.cod_carro) as qtd_vendidos "
                           "from vendas v2 natural join carros c3 "
                           "group by c3.cod_carro) t2); "))
    {
        return mysql_store_result(banco);

    } else {
        puts("Error: Mais_Vendidos");
    }
    return NULL;
}

//Imprimi os carro(s) menos vendidos de todos os tempos
MYSQL_RES * menos_vendidos(MYSQL * banco)
{
     if(!mysql_query(banco, "select * from carros c1 natural join ( "
                            "select c2.cod_carro, count(c2.cod_carro) as qtd_vendidos "
                            "from vendas v1 natural join carros c2 "
                            "group by c2.cod_carro) t1 where qtd_vendidos = ( "
                            "select min(qtd_vendidos) from ( "
                            "select count(c3.cod_carro) as qtd_vendidos "
                            "from vendas v1 natural join carros c3 "
                            "group by c3.cod_carro) t2); "))
    {
        return mysql_store_result(banco);

    } else {
        puts("Error: Menos_Vendidos");
    }
    return NULL;
}

//Imprimi os carro(s) mais vendidos entre os anos 2015 a 2023
MYSQL_RES * mais_vendidos_cinco(MYSQL * banco)
{
    if(!mysql_query(banco, "select * from carros c1 natural join ( "
                           "select c2.cod_carro, count(c2.cod_carro) as qtd_vendidos "
                           "from vendas v1 natural join carros c2 "
                           "where data_venda > '2015/01/01' and data_venda < '2023/01/01' "
                           "group by c2.cod_carro) t1 where qtd_vendidos = ( "
                           "select max(qtd_vendidos) from ( "
                           "select count(c3.cod_carro) as qtd_vendidos "
                           "from vendas v2 natural join carros c3 "
                           "where data_venda > '2015/01/01' and data_venda < '2023/01/01' "
                           "group by c3.cod_carro) t2);"))
    {
        return mysql_store_result(banco);

    } else {
        puts("Error: Menos_Vendidos_Cinco");
    }
    return NULL;
}

//Imprimi os carro(s) mais vendidos entre os anos 2010 a 2015
MYSQL_RES * mais_vendidos_dez(MYSQL * banco)
{
    if(!mysql_query(banco, "select * from carros c1 natural join ( "
                           "select c2.cod_carro, count(c2.cod_carro) as qtd_vendidos "
                           "from vendas v1 natural join carros c2 "
                           "where data_venda > '2010/01/01' and data_venda < '2015/01/01' "
                           "group by c2.cod_carro) t1 where qtd_vendidos = ( "
                           "select max(qtd_vendidos) from ( "
                           "select count(c3.cod_carro) as qtd_vendidos "
                           "from vendas v2 natural join carros c3 "
                           "where data_venda > '2010/01/01' and data_venda < '2015/01/01' "
                           "group by c3.cod_carro) t2);"))
    {
        return mysql_store_result(banco);

    } else {
        puts("Error: Menos_Vendidos_Dez");
    }
    return NULL;
}

//Imprimi os carro(s) mais vendidos entre os anos 2005 a 2010
MYSQL_RES * mais_vendidos_quinze(MYSQL * banco)
{
     if(!mysql_query(banco, "select * from carros c1 natural join ( "
                            "select c2.cod_carro, count(c2.cod_carro) as qtd_vendidos "
                            "from vendas v1 natural join carros c2 "
                            "where data_venda > '2005/01/01' and data_venda < '2010/01/01' "
                            "group by c2.cod_carro) t1 where qtd_vendidos = ( "
                            "select max(qtd_vendidos) from ( "
                            "select count(c3.cod_carro) as qtd_vendidos "
                            "from vendas v2 natural join carros c3 "
                            "where data_venda > '2005/01/01' and data_venda < '2010/01/01' "
                            "group by c3.cod_carro) t2);"))
    {
        return mysql_store_result(banco);

    } else {
        puts("Error: Menos_Vendidos_Quinze");
    }
    return NULL;

}

//Imprimi os carro(s) mais vendidos entre os anos 2000 a 2005
MYSQL_RES * mais_vendidos_vinte(MYSQL * banco)
{
     if(!mysql_query(banco, "select * from carros c1 natural join ( "
                            "select c2.cod_carro, count(c2.cod_carro) as qtd_vendidos "
                            "from vendas v1 natural join carros c2 "
                            "where data_venda > '2000/01/01' and data_venda < '2005/01/01' "
                            "group by c2.cod_carro) t1 where qtd_vendidos = ( "
                            "select max(qtd_vendidos) from ( "
                            "select count(c3.cod_carro) as qtd_vendidos "
                            "from vendas v2 natural join carros c3 "
                            "where data_venda > '2000/01/01' and data_venda < '2005/01/01' "
                            "group by c3.cod_carro) t2);"))
    {
        return mysql_store_result(banco);

    } else {
        puts("Error: Menos_Vendidos_Vinte");
    }
    return NULL;
}

//Imprimi o lucro total de vendas de cada agência de todos os tempos
MYSQL_RES * total_vendas(MYSQL * banco)
{
    if(!mysql_query(banco, "select * "
                           "from agencia natural join ( "
                           "select a.cod_setor, sum(valor) as lucro_vendas "
                           "from agencia a join carros c on c.cod_setor = a.cod_setor "
                           "join vendas v on v.cod_carro = c.cod_carro "
                           "group by a.cod_setor) t1;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Total_Vendas");
    }
    return NULL;
}

//Imprimi o lucro total de vendas de cada agência de 2015 em diante
MYSQL_RES * total_vendas_2015(MYSQL * banco)
{
    if(!mysql_query(banco, "select * "
                           "from agencia natural join ( "
                           "select a.cod_setor, sum(valor) as lucro_vendas "
                           "from agencia a join carros c on c.cod_setor = a.cod_setor "
                           "join vendas v on v.cod_carro = c.cod_carro "
                           "where v.data_venda >= '2015/01/01' "
                           "group by a.cod_setor) t1;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Total_Vendas_2015");
    }
    return NULL;

}

//Imprimi o lucro total de vendas de cada agência de 2010 em diante
MYSQL_RES * total_vendas_2010(MYSQL * banco)
{
    if(!mysql_query(banco, "select * "
                           "from agencia natural join ( "
                           "select a.cod_setor, sum(valor) as lucro_vendas "
                           "from agencia a join carros c on c.cod_setor = a.cod_setor "
                           "join vendas v on v.cod_carro = c.cod_carro "
                           "where v.data_venda >= '2010/01/01' "
                           "group by a.cod_setor) t1;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Total_Vendas_2010");
    }
    return NULL;
}

//Imprimi o lucro total de vendas de cada agência de 2005 em diante
MYSQL_RES * total_vendas_2005(MYSQL * banco)
{
    if(!mysql_query(banco, "select * "
                           "from agencia natural join ( "
                           "select a.cod_setor, sum(valor) as lucro_vendas "
                           "from agencia a join carros c on c.cod_setor = a.cod_setor "
                           "join vendas v on v.cod_carro = c.cod_carro "
                           "where v.data_venda >= '2005/01/01' "
                           "group by a.cod_setor) t1;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Total_Vendas_2005");
    }
    return NULL;
}

//Imprimi o lucro total de trocas de cada agência de todos os tempos
MYSQL_RES * total_trocas(MYSQL * banco)
{
    if(!mysql_query(banco,  "select c1.cod_setor, sum(c2.valor - c1.valor) lucro_trocas "
                           "from trocas t join carros c1 on c1.cod_carro = t.cod_carro_antigo "
                           "join carros c2 on c2.cod_carro = t.cod_carro_novo "
                           "where c2.valor > c1.valor "
                           "group by c1.cod_setor;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Total_Trocas");
    }
    return NULL;
}

//Imprimi o lucro total de trocas de cada agência de 2015 em diante
MYSQL_RES * total_trocas_2015(MYSQL * banco)
{
    if(!mysql_query(banco, "select c1.cod_setor, sum(c2.valor - c1.valor) lucro_trocas "
                           "from trocas t join carros c1 on c1.cod_carro = t.cod_carro_antigo "
                           "join carros c2 on c2.cod_carro = t.cod_carro_novo "
                           "where c2.valor > c1.valor and t.data_troca >= '2015/01/01' "
                           "group by c1.cod_setor;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Total_Trocas_2015");
    }
    return NULL;

}

//Imprimi o lucro total de trocas de cada agência de 2010 em diante
MYSQL_RES * total_trocas_2010(MYSQL * banco)
{
    if(!mysql_query(banco, "select c1.cod_setor, sum(c2.valor - c1.valor) lucro_trocas "
                           "from trocas t join carros c1 on c1.cod_carro = t.cod_carro_antigo "
                           "join carros c2 on c2.cod_carro = t.cod_carro_novo "
                           "where c2.valor > c1.valor and t.data_troca >= '2010/01/01' "
                           "group by c1.cod_setor;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Total_Vendas_2010");
    }
    return NULL;
}

//Imprimi o lucro total de trocas de cada agência de 2005 em diante
MYSQL_RES * total_trocas_2005(MYSQL * banco)
{
    if(!mysql_query(banco, "select c1.cod_setor, sum(c2.valor - c1.valor) lucro_trocas "
                           "from trocas t join carros c1 on c1.cod_carro = t.cod_carro_antigo "
                           "join carros c2 on c2.cod_carro = t.cod_carro_novo "
                           "where c2.valor > c1.valor and t.data_troca >= '2005/01/01' "
                           "group by c1.cod_setor;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Total_Trocas_2005");
    }
    return NULL;
}

//Imprimi a quantidade de compras de veículos realizada por cada cliente
MYSQL_RES * quantidade_compras(MYSQL * banco)
{
    if(!mysql_query(banco, "select v.CPF_cliente, count(v.CPF_cliente) compras "
                           "from vendas v group by v.CPF_cliente;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Quantidade_Compras");
    }
    return NULL;
}

//Imprimi a quantidade de trocas de veículos realizada por cada cliente
MYSQL_RES * quantidade_trocas(MYSQL * banco)
{
    if(!mysql_query(banco, "select t.CPF_cliente, count(t.CPF_cliente) trocas "
                           "from trocas t group by t.CPF_cliente;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Quantidade_Trocas");
    }
    return NULL;
}

//Imprimi a folha de pagamento mensal de cada agência
MYSQL_RES * folha_pagamento(MYSQL * banco)
{
    if(!mysql_query(banco, "select a.cod_setor, a.nome, sum(salario) folha_pagamento "
                           "from agencia a join funcionarios f on a.cod_setor = f.cod_setor "
                           "group by a.cod_setor;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Folha_Pagamento");
    }
    return NULL;
}

//Imprimi a quantidade de funcionarios que cada agência possue + a folha de pagamento
MYSQL_RES * qtd_funcionarios(MYSQL * banco)
{
    if(!mysql_query(banco, "select a.cod_setor, a.nome, count(f.CPF_funcionario) funcionarios, "
                           "sum(f.salario) folha_pagamento "
                           "from agencia a join funcionarios f on a.cod_setor = f.cod_setor "
                           "group by a.cod_setor;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Qtd_Funcionario");
    }
    return NULL;
}

//Imprimi quais clientes estão com revisão atrasada
//o "not in" serve para desconsiderar carros trocados
MYSQL_RES * revisao_atrasada(MYSQL * banco)
{
    if(!mysql_query(banco, "select * from revisao r where (r.CPF_cliente, r.cod_carro) "
                           "not in (select t.CPF_cliente, t.cod_carro_antigo cod_carro from trocas t) "
                           "and data_revisao < '2022/01/01';"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Revisao_Atrasada");
    }
    return NULL;
}

//Imprimi o gasto total de compras de cada cliente
MYSQL_RES * gasto_compras(MYSQL * banco)
{
    if(!mysql_query(banco, "select v.CPF_cliente, sum(c1.valor) gasto_trocas "
                           "from vendas v natural join carros c1 join clientes c2 "
                           "on v.CPF_cliente = c2.CPF_cliente group by v.CPF_cliente;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Gasto_Compras");
    }
    return NULL;
}

//Imprimi o gasto total de trocas de cada cliente
MYSQL_RES * gasto_trocas(MYSQL * banco)
{
    if(!mysql_query(banco, "select t.CPF_cliente, sum(c2.valor - c1.valor) gasto_trocas "
                           "from trocas t join carros c1 on c1.cod_carro = t.cod_carro_antigo "
                           "join carros c2 on c2.cod_carro = t.cod_carro_novo "
                           "where c2.valor > c1.valor group by t.CPF_cliente;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Gasto_Trocas");
    }
    return NULL;
}

//Imprimi o gasto total de manutencao de cada cliente
MYSQL_RES * gasto_manutencao(MYSQL * banco)
{
    if(!mysql_query(banco, "select CPF_cliente, sum(valor) gasto_manutencao "
                           "from revisao r natural join pecas_pagas pp natural "
                           "join pecas p group by r.CPF_cliente;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Gasto_Manutencao");
    }
    return NULL;
}

//Imprimi a quantidade de carros de cada agência
MYSQL_RES * qtd_carros(MYSQL * banco)
{
    if(!mysql_query(banco, "select a.cod_setor, a.nome, c.ano, count(c.cod_carro) qtd_carros, "
                           "sum(c.valor) valor_total from carros c join agencia a on "
                           "a.cod_setor = c.cod_setor group by c.ano, a.cod_setor;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Qtd_Carros");
    }
    return NULL;
}

//Imprimi os clientes que possue carros ano de fabricação superior ou igual a 10 anos
//o "not in" serve para desconsiderar carros trocados
MYSQL_RES * carros_antigos(MYSQL * banco)
{
    if(!mysql_query(banco, "select v.id, v.CPF_cliente, v.cod_carro, c.ano from vendas v, carros c "
                           "where (v.CPF_cliente, v.cod_carro) not in "
                           "(select t.CPF_cliente, t.cod_carro_antigo cod_carro from trocas t) "
                           "and c.cod_carro = v.cod_carro and c.ano <= 2013;"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Carros_Antigos");
    }
    return NULL;
}

//Imprimi os funcionarios que venderam mais carros
MYSQL_RES * mais_eficientes(MYSQL * banco)
{
    if(!mysql_query(banco, "select f.CPF_funcionario, f.nome, qtd_vendas "
                           "from funcionarios f natural join ( "
                           "select f.CPF_funcionario, count(c.CPF_cliente) qtd_vendas "
                           "from funcionarios f join clientes c on f.CPF_funcionario = c.CPF_funcionario "
                           "join vendas v on c.CPF_cliente = v.CPF_cliente group by f.CPF_funcionario) t1 "
                           "where qtd_vendas = (select max(qtd_vendas) max from ( "
                           "select f.CPF_funcionario, count(c.CPF_cliente) qtd_vendas "
                           "from funcionarios f join clientes c on f.CPF_funcionario = c.CPF_funcionario "
                           "join vendas v on c.CPF_cliente = v.CPF_cliente group by f.CPF_funcionario) t2);"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Mais_Eficientes");
    }
    return NULL;
}

//Imprimi os funcionarios que venderam menos carros
MYSQL_RES * menos_eficientes(MYSQL * banco)
{
    if(!mysql_query(banco, "select f.CPF_funcionario, f.nome, qtd_vendas "
                           "from funcionarios f natural join ( "
                           "select f.CPF_funcionario, count(c.CPF_cliente) qtd_vendas "
                           "from funcionarios f join clientes c on f.CPF_funcionario = c.CPF_funcionario "
                           "join vendas v on c.CPF_cliente = v.CPF_cliente group by f.CPF_funcionario) t1 "
                           "where qtd_vendas = (select min(qtd_vendas) min from ( "
                           "select f.CPF_funcionario, count(c.CPF_cliente) qtd_vendas "
                           "from funcionarios f join clientes c on f.CPF_funcionario = c.CPF_funcionario "
                           "join vendas v on c.CPF_cliente = v.CPF_cliente group by f.CPF_funcionario) t2);"))
    {
        return mysql_store_result(banco);
    } else {
        puts("Error: Menos_Eficientes");
    }
    return NULL;
}
