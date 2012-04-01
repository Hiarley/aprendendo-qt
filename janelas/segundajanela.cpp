#include "segundajanela.h"
#include "ui_segundajanela.h"

segundaJanela::segundaJanela(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::segundaJanela)
{
    ui->setupUi(this);
}

segundaJanela::~segundaJanela()
{
    delete ui;
}

void segundaJanela::atualizarSegundaJanela()
{
    ui->label_vazio->setText(dadosDaPrimeiraJanela);
}

void segundaJanela::on_pushButton_segundaJanela_clicked()
{
    dadosDaSegundaJanela = ui->lineEdit_segundaJanela->text();

    emit enviarDados();
    this->close();
}
