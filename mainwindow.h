#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <mysql/mysql.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void tabela();
    void remover_tabela();
    void on_imprimir_agencia_clicked();
    void on_imprimir_carros_clicked();
    void on_imprimir_pecas_clicked();
    void on_imprimir_funcionarios_clicked();
    void on_imprimir_clientes_clicked();
    void on_imprimir_vendas_clicked();
    void on_imprimir_trocas_clicked();
    void on_imprimir_revisao_clicked();
    void on_pecas_pagas_clicked();
    void on_nao_vendidos_clicked();
    void on_mais_vendido_clicked();
    void on_menos_vendidos_clicked();
    void on_carros_vendas_2015_2023_clicked();
    void on_carros_vendas_2010_2015_clicked();
    void on_carros_vendas_2005_2010_clicked();
    void on_carros_vendas_2000_2005_clicked();
    void on_total_vendas_clicked();
    void on_vendas_2015_clicked();
    void on_vendas_2010_clicked();
    void on_vendas_2005_clicked();
    void on_total_trocas_clicked();
    void on_trocas_2015_clicked();
    void on_trocas_2010_clicked();
    void on_trocas_2005_clicked();
    void on_maior_quantidade_compras_clicked();
    void on_maior_quantidade_trocas_clicked();
    void on_folha_pagamento_clicked();
    void on_qtd_funcionarios_clicked();
    void on_revisao_atrasada_clicked();
    void on_gasto_compras_clicked();
    void on_gasto_trocas_clicked();
    void on_gasto_manutencao_clicked();
    void on_qtd_carros_clicked();
    void on_carros_antigo_clicked();
    void on_mais_eficientes_clicked();
    void on_menos_eficientes_clicked();

private:
    //Inicialização das variáveis fundamentais para manipular o banco de dados
    MYSQL_RES   *  query;
    MYSQL_ROW    linhas;
    MYSQL_FIELD * campo;
    MYSQL * banco;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
