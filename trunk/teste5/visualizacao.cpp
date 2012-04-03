#include "visualizacao.h"
#include "ui_visualizacao.h"

visualizacao::visualizacao(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visualizacao)
{
    ui->setupUi(this);
}

visualizacao::~visualizacao()
{
    delete ui;
}

void visualizacao::verif(){

/*
    int w, h;
    QString wd, hg;

    w = jan->imagem.width();
    h = jan->imagem.height();

    this->setFixedHeight(h);
    this->setFixedWidth(w);

    ui->vis->setFixedHeight(h);
    ui->vis->setFixedWidth(w);
    ui->vis->setPixmap(QPixmap::fromImage(jan->imagem));

    wd.setNum(w);
    hg.setNum(h);
    ui->inf->setText("Tamanho: "+ wd +" X "+ hg);
*/


}
