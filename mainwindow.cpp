#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "banco_sql.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    banco = mysql_init(NULL);
    conectar_banco(banco);
}

MainWindow::~MainWindow()
{
    delete ui;
    mysql_close(banco);
}

//Abaixo, funções responsáveis por fazer a integração com a tabela

void MainWindow::tabela()
{
    int cnt = 0;
    int tam_col = mysql_num_fields(query);
    campo = mysql_fetch_fields(query);

    remover_tabela();
    ui->table->setColumnCount(tam_col);

    while ((linhas = mysql_fetch_row(query))) {
        ui->table->insertRow(cnt);
        for(int i = 0; i < tam_col; ++i){
            ui->table->setHorizontalHeaderItem(i, new QTableWidgetItem(campo[i].name));
            ui->table->setItem(cnt, i, new QTableWidgetItem(linhas[i]));
            ui->table->setColumnWidth(i, 120);
        }
        ++cnt;
    }

    mysql_free_result(query);
}

void MainWindow::remover_tabela()
{
    int num_row = ui->table->rowCount();
    int num_col = ui->table->columnCount();

    for (int i = num_row; i >= 0; --i) {
        ui->table->removeRow(i);
    }

    for (int i = num_col; i >= 0; --i) {
        ui->table->removeColumn(i);
    }
}

//Abaixo, apenas a chamadas das funções em SQL para cada botão

void MainWindow::on_imprimir_agencia_clicked()
{
    query = agencia(banco);
    tabela();
}

void MainWindow::on_imprimir_carros_clicked()
{
    query = carros(banco);
    tabela();
}

void MainWindow::on_imprimir_pecas_clicked()
{
    query = pecas(banco);
    tabela();
}

void MainWindow::on_imprimir_funcionarios_clicked()
{
    query = funcionarios(banco);
    tabela();
}

void MainWindow::on_imprimir_clientes_clicked()
{
    query = clientes(banco);
    tabela();
}

void MainWindow::on_imprimir_vendas_clicked()
{
    query = vendas(banco);
    tabela();
}

void MainWindow::on_imprimir_trocas_clicked()
{
    query = trocas(banco);
    tabela();
}

void MainWindow::on_imprimir_revisao_clicked()
{
    query = revisao(banco);
    tabela();
}

void MainWindow::on_pecas_pagas_clicked()
{
    query = pecas_pagas(banco);
    tabela();
}

void MainWindow::on_nao_vendidos_clicked()
{
    query = carros_n_vendidos(banco);
    tabela();
}

void MainWindow::on_mais_vendido_clicked()
{
    query = mais_vendidos(banco);
    tabela();
}

void MainWindow::on_menos_vendidos_clicked()
{
    query = menos_vendidos(banco);
    tabela();
}

void MainWindow:: on_carros_vendas_2015_2023_clicked()
{
    query = mais_vendidos_cinco(banco);
    tabela();
}

void MainWindow::on_carros_vendas_2010_2015_clicked()
{
    query = mais_vendidos_dez(banco);
    tabela();
}

void MainWindow::on_carros_vendas_2005_2010_clicked()
{
    query = mais_vendidos_quinze(banco);
    tabela();
}

void MainWindow::on_carros_vendas_2000_2005_clicked()
{
    query = mais_vendidos_vinte(banco);
    tabela();
}

void MainWindow::on_total_vendas_clicked()
{
    query = total_vendas(banco);
    tabela();
}

void MainWindow::on_vendas_2015_clicked()
{
    query = total_vendas_2015(banco);
    tabela();
}

void MainWindow::on_vendas_2010_clicked()
{
    query = total_vendas_2010(banco);
    tabela();
}

void MainWindow::on_vendas_2005_clicked()
{
    query = total_vendas_2005(banco);
    tabela();
}

void MainWindow::on_total_trocas_clicked()
{
    query = total_trocas(banco);
    tabela();
}

void MainWindow::on_trocas_2015_clicked()
{
    query = total_trocas_2015(banco);
    tabela();
}

void MainWindow::on_trocas_2010_clicked()
{
    query = total_trocas_2010(banco);
    tabela();
}

void MainWindow::on_trocas_2005_clicked()
{
    query = total_trocas_2005(banco);
    tabela();
}

void MainWindow::on_maior_quantidade_compras_clicked()
{
    query = quantidade_compras(banco);
    tabela();
}

void MainWindow::on_maior_quantidade_trocas_clicked()
{
    query = quantidade_trocas(banco);
    tabela();
}

void MainWindow::on_folha_pagamento_clicked()
{
    query = folha_pagamento(banco);
    tabela();
}

void MainWindow::on_qtd_funcionarios_clicked()
{
    query = qtd_funcionarios(banco);
    tabela();
}

void MainWindow::on_revisao_atrasada_clicked()
{
    query = revisao_atrasada(banco);
    tabela();
}

void MainWindow::on_gasto_compras_clicked()
{
    query = gasto_compras(banco);
    tabela();
}

void MainWindow::on_gasto_trocas_clicked()
{
    query = gasto_trocas(banco);
    tabela();
}

void MainWindow::on_gasto_manutencao_clicked()
{
    query = gasto_manutencao(banco);
    tabela();
}

void MainWindow::on_qtd_carros_clicked()
{
    query = qtd_carros(banco);
    tabela();
}

void MainWindow::on_carros_antigo_clicked()
{
    query = carros_antigos(banco);
    tabela();
}

void MainWindow::on_mais_eficientes_clicked()
{
    query = mais_eficientes(banco);
    tabela();
}

void MainWindow::on_menos_eficientes_clicked()
{
    query = menos_eficientes(banco);
    tabela();
}
