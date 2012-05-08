#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);

    connect(ui->actionAbrir, SIGNAL(triggered()), this, SLOT(abrir()));
    connect(ui->actionSalvar, SIGNAL(triggered()), this, SLOT(salvar()));
    connect(ui->actionSair, SIGNAL(triggered()), this, SLOT(sair()));

}

principal::~principal()
{
    delete ui;
}


void principal::abrir(){

    fn = QFileDialog::getOpenFileName(this, "Abrir Imagem", "C:\\", "Imagem *.jpg *.png", NULL);
    qimagem.load(fn);
    imagem = cvLoadImage(fn.toAscii().constData());

    if(fn.compare(fn,"")==0){  // Se livrando do bug que quando fecha a janela de selecionar arquivo.

    }
else{
   ui->label_imagem->setPixmap(QPixmap::fromImage(qimagem));

    }


}

void principal::abrir_informacao(){
    info = new informacao();
    info->setWindowTitle("Informação");

    if(fn.compare(fn,"")==0){

        QMessageBox::information(this,"ERRO","Precisa carregar a imagem primeiro");
    }
    else{
        int nch, w, h;
        nch= imagem->nChannels;
        w = imagem->width;
        h = imagem->height;

    info->n_canais.setNum(nch);
    info->largura.setNum(w);
    info->altura.setNum(h);

    info->atualizar();
    info->show();
    }

}

void principal::visualizacao(){

    if(fn.compare(fn,"")==0){

        QMessageBox::information(this,"ERRO","Precisa carregar a imagem primeiro");
    }
    else{
        cvNamedWindow("Visualização");

        cvShowImage("Visualização", imagem);

    }

}

void principal::salvar(){

    QString file = QFileDialog::getSaveFileName(this, "Salvar Imagem", "C://","JPG (*.jpg)", NULL);
    if(file.compare(file,"")==0){

    }
    else{

    cvSaveImage(file.toAscii().constData(), imagem);
}
}

void principal::transformar(){

    int h = imagem->height;
    int w = imagem->width;
    int channels = imagem->nChannels;
    QImage *qimg = new QImage(w, h, QImage::Format_ARGB32);
    char *data = imagem->imageData;

    for (int y = 0; y < h; y++, data += imagem->widthStep)
    {
        for (int x = 0; x < w; x++)
        {
            char r, g, b, a = 0;
            if (channels == 1){
                r = data[x * channels];
                g = data[x * channels];
                b = data[x * channels];
            }
            else if (channels == 3 || channels == 4){
                r = data[x * channels + 2];
                g = data[x * channels + 1];
                b = data[x * channels];
            }

            if (channels == 4){
                a = data[x * channels + 3];
                qimg->setPixel(x, y, qRgba(r, g, b, a));
            }
            else{
                qimg->setPixel(x, y, qRgb(r, g, b));
            }
        }
    }
 qimagem = *qimg;

}

void principal::modo_monocromatico(){
    if(fn.compare(fn,"")==0){

        QMessageBox::information(this,"ERRO","Precisa carregar a imagem primeiro");
    }
    else{
    imagem = cvLoadImage(fn.toAscii().constData(), CV_LOAD_IMAGE_GRAYSCALE);
    transformar();
    ui->label_imagem->setPixmap(QPixmap::fromImage(qimagem));
}

}

void principal::modo_normal(){
    if(fn.compare(fn,"")==0){

        QMessageBox::information(this,"ERRO","Precisa carregar a imagem primeiro");
    }
    else{
    imagem = cvLoadImage(fn.toAscii().constData(), CV_LOAD_IMAGE_COLOR);
    transformar();
    ui->label_imagem->setPixmap(QPixmap::fromImage(qimagem));
}
}

void principal::caixa(){

    if(fn.compare(fn,"")==0){

        QMessageBox::information(this,"ERRO","Precisa carregar a imagem primeiro");
    }
    else{

    px = new pixels();

    px->show();

    connect(px, SIGNAL(sinal_pixel()), this, SLOT(caixa_2()));

}
}

void principal::caixa_2(){


    cvRectangle(imagem, cvPoint(px->px1,px->px2), cvPoint(px->px3,px->px4), cvScalar(255,0,0), 1);
    transformar();
    ui->label_imagem->setPixmap(QPixmap::fromImage(qimagem));

}

void principal::circulo(){
    if(fn.compare(fn,"")==0){

        QMessageBox::information(this,"ERRO","Precisa carregar a imagem primeiro");
    }
    else{
// Raio de 50px
    cvCircle(imagem, cvPoint(100,100), 50, cvScalar(0,255,0), 1);
    transformar();
    ui->label_imagem->setPixmap(QPixmap::fromImage(qimagem));
}

}

void principal::texto_img(){

    if(fn.compare(fn,"")==0){

        QMessageBox::information(this,"ERRO","Precisa carregar a imagem primeiro");
    }
    else{
    tx = new texto();

    tx->setWindowTitle("Texto");
    tx->show();
    connect(tx,SIGNAL(sinal_texto()), this, SLOT(texto_img_2()));
}


}

void principal::texto_img_2(){

    QString texto2;
    texto2 = tx->texto_imagem;
    CvFont font;
    double hScale=1.0;
    double vScale=1.0;
    int    lineWidth=2; // Grossura do texto
    cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,lineWidth);

    cvPutText (imagem, texto2.toAscii().constData() ,cvPoint(50,50), &font, cvScalar(255,255,0));
    // cvScalar(255,255,0) é a cor

    transformar();
    ui->label_imagem->setPixmap(QPixmap::fromImage(qimagem));

}

void principal::sair(){

cvReleaseImage(&imagem); //desalocando a imagem alocada
this->close();
}




void principal::on_pushButton_informacoes_clicked()
{
    abrir_informacao();
}


void principal::on_pushButton_vis_clicked()
{
   visualizacao();
}

void principal::on_pushButton_Salvar_clicked()
{
    salvar();
}

void principal::on_pushButton_Mono_clicked()
{
    modo_monocromatico();
}

void principal::on_pushButton_normal_clicked()
{
    modo_normal();
}

void principal::on_pushButton_clicked()
{
    caixa();
}

void principal::on_pushButton_circulo_clicked()
{
    circulo();
}

void principal::on_pushButton_texto_clicked()
{
    texto_img();
}

