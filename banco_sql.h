#ifndef BANCO_SQL 
#define BANCO_SQL 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <mysql/mysql.h>

bool conectar_banco(MYSQL * banco);
MYSQL_RES * agencia(MYSQL * banco);
MYSQL_RES * carros(MYSQL * banco);
MYSQL_RES * clientes(MYSQL * banco);
MYSQL_RES * funcionarios(MYSQL * banco);
MYSQL_RES * pecas(MYSQL * banco);
MYSQL_RES * pecas_pagas(MYSQL * banco);
MYSQL_RES * revisao(MYSQL * banco);
MYSQL_RES * trocas(MYSQL * banco);
MYSQL_RES * vendas(MYSQL * banco);
MYSQL_RES * carros_n_vendidos(MYSQL * banco);
MYSQL_RES * mais_vendidos(MYSQL * banco);
MYSQL_RES * menos_vendidos(MYSQL * banco);
MYSQL_RES * mais_vendidos_cinco(MYSQL * banco);
MYSQL_RES * mais_vendidos_dez(MYSQL * banco);
MYSQL_RES * mais_vendidos_quinze(MYSQL * banco);
MYSQL_RES * mais_vendidos_vinte(MYSQL * banco);
MYSQL_RES * total_vendas(MYSQL * banco);
MYSQL_RES * total_vendas_2015(MYSQL * banco);
MYSQL_RES * total_vendas_2010(MYSQL * banco);
MYSQL_RES * total_vendas_2005(MYSQL * banco);
MYSQL_RES * total_trocas(MYSQL * banco);
MYSQL_RES * total_trocas_2015(MYSQL * banco);
MYSQL_RES * total_trocas_2010(MYSQL * banco);
MYSQL_RES * total_trocas_2005(MYSQL * banco);
MYSQL_RES * quantidade_compras(MYSQL * banco);
MYSQL_RES * quantidade_trocas(MYSQL * banco);
MYSQL_RES * folha_pagamento(MYSQL * banco);
MYSQL_RES * qtd_funcionarios(MYSQL * banco);
MYSQL_RES * revisao_atrasada(MYSQL * banco);
MYSQL_RES * gasto_compras(MYSQL * banco);
MYSQL_RES * gasto_trocas(MYSQL * banco);
MYSQL_RES * gasto_manutencao(MYSQL * banco);
MYSQL_RES * qtd_carros(MYSQL * banco);
MYSQL_RES * carros_antigos(MYSQL * banco);
MYSQL_RES * mais_eficientes(MYSQL * banco);
MYSQL_RES * menos_eficientes(MYSQL * banco);

#endif
