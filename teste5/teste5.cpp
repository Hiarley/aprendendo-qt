#include "teste5.h"
#include "ui_teste5.h"

teste5::teste5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teste5)
{
    ui->setupUi(this);

    connect(ui->actionAbrir, SIGNAL(triggered()), this, SLOT(abrir()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(inverter()));
    connect(ui->actionSalvar, SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionSair, SIGNAL(triggered()), this, SLOT(sair()));
}

teste5::~teste5()
{
    delete ui;
}

void teste5::abrir(){

    QString fn = QFileDialog::getOpenFileName(this, "Abrir Imagem", "C:\\", "Imagem *.jpg *.png", NULL);
    imagem.load(fn);
    imagem2.load(fn);

    if(fn.compare(fn,"")==0){  // Se livrando do bug que quando fecha a janela de selecionar arquivo.

    }
else{

   imagem2 = imagem.scaledToHeight(301); // Dimensionando a imagem para 301 por 271
   imagem2 = imagem.scaledToWidth(271);

   ui->label_imagem1->setPixmap(QPixmap::fromImage(imagem2));

   ui->label_imagem2->hide();
   ui->status->setText("Diretório: "+ fn);
}
}

void teste5::inverter(){

    ui->label_imagem2->show();

    // A imagem2 é apenas para vizualizaçao, o que é salvo é o imagem com o tamanho normal.

    imagem2 = imagem.scaledToHeight(301); // Dimensionando a imagem para 301 por 271
    imagem2 = imagem.scaledToWidth(271);

    imagem.invertPixels();
    imagem2.invertPixels(); // apenas para ser motrado invertido


    ui->label_imagem2->setPixmap(QPixmap::fromImage(imagem2));

    QMessageBox::information(this, "Informaçao!", "As cores da imagem foram invertidas!");


}

void teste5::salvar(){

    QString file = QFileDialog::getSaveFileName(this, "Salvar Imagem", "C://","JPG (*.jpg)", NULL);

    if(file.compare(file,"")==0){

    }
    else{
    imagem.save(file);
     QMessageBox::information(this, "Salvar", "A imagem foi salva com sucesso");
}

    }

void teste5::sair(){

    QMessageBox msg;
    msg.setText("Deseja Salvar antes de sair?");
    msg.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Save);
    int op = msg.exec();

    switch(op){
    case QMessageBox::Save:
        this->salvar();
    break;

    case QMessageBox::Discard:
        this->close();
       break;
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }


}




