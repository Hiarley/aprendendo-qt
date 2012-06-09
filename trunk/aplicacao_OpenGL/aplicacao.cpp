#include "aplicacao.h"
#include "ui_aplicacao.h"

aplicacao::aplicacao(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aplicacao)
{
    ui->setupUi(this);

    connect(ui->pushButton_Sair, SIGNAL(clicked()), this, SLOT(close()));
}

aplicacao::~aplicacao()
{
    delete ui;
}
