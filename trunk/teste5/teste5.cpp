#include "teste5.h"
#include "ui_teste5.h"

teste5::teste5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teste5)
{
    ui->setupUi(this);

    ajust = new ajustar();
    connect(ui->actionAbrir, SIGNAL(triggered()), this, SLOT(abrir()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(inverter()));
    connect(ui->actionSalvar, SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionSair, SIGNAL(triggered()), this, SLOT(sair()));
    connect(ui->actionInverter, SIGNAL(triggered()), this, SLOT(inverter()));
    connect(ui->actionBrilho, SIGNAL(triggered()), this, SLOT(abrir_brilho()));
    connect(ui->actionAjustar, SIGNAL(triggered()), this ,SLOT(abrir_ajuste()));



}

teste5::~teste5()
{
    delete ui;
}

void teste5::abrir(){

    QString fn = QFileDialog::getOpenFileName(this, "Abrir Imagem", "C:\\", "Imagem *.jpg *.png", NULL);
    pag.imagem.load(fn);
    imagem2.load(fn);
    imagem_reserva = imagem2;


    if(fn.compare(fn,"")==0){  // Se livrando do bug que quando fecha a janela de selecionar arquivo.

    }
else{

   imagem2 = pag.imagem.scaledToHeight(301); // Dimensionando a imagem para 301 por 271
   imagem2 = pag.imagem.scaledToWidth(271);

   ui->label_imagem1->setPixmap(QPixmap::fromImage(imagem2));

   ui->label_imagem2->hide();
   ui->status->setText("Diretório: "+ fn);
}
}

void teste5::vis_imagem(){

    ui->label_imagem2->show();

    // A imagem2 é apenas para vizualizaçao, o que é salvo é o imagem com o tamanho normal.

    imagem2 = pag.imagem.scaledToHeight(301); // Dimensionando a imagem para 301 por 271
    imagem2 = pag.imagem.scaledToWidth(271);

    ui->label_imagem2->setPixmap(QPixmap::fromImage(imagem2));
}

void teste5::inverter(){



    pag.imagem.invertPixels();
    imagem2.invertPixels(); // apenas para ser motrado invertido

    vis_imagem();

    QMessageBox::information(this, "Informaçao!", "As cores da imagem foram invertidas!");


}

void teste5::salvar(){

    pag.setWindowTitle("Visualizaçao");
    pag.visualizacao();
    pag.show();


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

void teste5::abrir_brilho(){

    br = new brilho();
    br->setWindowTitle("Brilho");

    br->imagem3 = pag.imagem;

    vis_imagem();

    br->show();

    connect(br, SIGNAL(enviar()), this, SLOT(receber_brilho())); // corrigido!

    /* Imagem 3 está em Brilho, recebe a Imagem, depois modifica o brilho, chama o Receber brilho: A imagem3 com
    brilho modificado passa para Imagem (Que é a QImage que vai ser salva) e para a Imagem2(A QImage que visualiza ao usuario)
    */
}
void teste5::receber_brilho(){

    if(br->op==1){
        pag.imagem = imagem_reserva;
        imagem2 = imagem_reserva;
        br->imagem3 = imagem_reserva;

    vis_imagem();
}
    else{
        pag.imagem = br->imagem3;
        imagem2 = br->imagem3;
        vis_imagem();
    }


}

void teste5::abrir_ajuste(){

    ajust = new ajustar();
    ajust->setWindowTitle("Ajustar");
    ajust->imagem4 = pag.imagem;

vis_imagem();

ajust->show();
ajust->visualizar_pixels();

connect(ajust, SIGNAL(ajuste_concluido()), this, SLOT(receber_ajuste()));

}
void teste5::receber_ajuste(){

    if(ajust->op==1){
    pag.imagem = imagem_reserva;
    imagem2 = imagem_reserva;
    ajust->imagem4 = imagem_reserva;
    vis_imagem();

    }
    else{


        imagem2 = ajust->imagem4;
        pag.imagem = ajust->imagem4;
        ajust->imagem4 = imagem_reserva;

        vis_imagem();

}
}




