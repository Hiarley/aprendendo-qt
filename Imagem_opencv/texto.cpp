#include "texto.h"
#include "ui_texto.h"

texto::texto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::texto)
{
    ui->setupUi(this);
}

texto::~texto()
{
    delete ui;
}

void texto::pegar_texto(){

    texto_imagem = ui->lineEdit_texto->text();
    emit sinal_texto();
    this->close();

}

void texto::on_pushButton_ok_clicked()
{
pegar_texto();
}
