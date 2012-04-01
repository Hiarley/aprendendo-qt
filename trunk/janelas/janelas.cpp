#include "janelas.h"
#include "ui_janelas.h"

Janelas::Janelas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Janelas)
{
    ui->setupUi(this);
}

Janelas::~Janelas()
{
    delete ui;
}

void Janelas::on_pushButton_clicked()
{
    janelinha = new segundaJanela();

    janelinha->dadosDaPrimeiraJanela = ui->lineEdit->text();
    janelinha->atualizarSegundaJanela();
    connect(janelinha,SIGNAL(enviarDados()),this,SLOT(receberDadosDaSegundaJanela()));

    janelinha->show();
}

void Janelas::receberDadosDaSegundaJanela()
{
    ui->lineEdit_2->setText(janelinha->dadosDaSegundaJanela);
}
