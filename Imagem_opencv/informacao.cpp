#include "informacao.h"
#include "ui_informacao.h"

informacao::informacao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::informacao)
{
    ui->setupUi(this);
}

informacao::~informacao()
{
    delete ui;
}

void informacao::atualizar(){

ui->label_canal->setText(n_canais);
ui->label_dimensao->setText(largura+" X "+altura);



}
