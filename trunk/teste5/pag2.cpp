#include "pag2.h"
#include "ui_pag2.h"

pag2::pag2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pag2)
{
    ui->setupUi(this);
}

pag2::~pag2()
{
    delete ui;
}

void pag2::visualizacao(){

    int w, h, h2;
    QString wd, hg;

    w = imagem.width();
    h = imagem.height();

    h2 = h + 35;

    this->setFixedHeight(h2);
    this->setFixedWidth(w);

    ui->vis->setFixedHeight(h);
    ui->vis->setFixedWidth(w);
    ui->vis->setPixmap(QPixmap::fromImage(imagem));

    wd.setNum(w);
    hg.setNum(h);
    ui->inf->setText("Tamanho: "+ wd +" X "+ hg);

}

void pag2::on_pushButton_clicked()
{
    QString file = QFileDialog::getSaveFileName(this, "Salvar Imagem", "C://","JPG (*.jpg)", NULL);

    if(file.compare(file,"")==0){

    }
    else{
    imagem.save(file);
     QMessageBox::information(this, "Salvar", "A imagem foi salva com sucesso");
}

    this->close();
}
