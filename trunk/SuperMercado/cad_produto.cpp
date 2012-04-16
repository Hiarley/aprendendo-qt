#include "cad_produto.h"
#include "ui_cad_produto.h"

cad_produto::cad_produto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cad_produto)
{
    ui->setupUi(this);
}

cad_produto::~cad_produto()
{
    delete ui;
}

void cad_produto::on_pushButton_cadastrar_clicked()
{
dados = new Banco();

dados->nome_produto = ui->lineEdit_nome->text();
dados->tipo = ui->lineEdit_tipo->text();
dados->preco = ui->lineEdit_preco->text();

dados->cadastrar_produto();

}

void cad_produto::on_pushButton_limpar_clicked()
{

}
