#include "ajustar.h"
#include "ui_ajustar.h"

ajustar::ajustar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajustar)
{
    ui->setupUi(this);


}

ajustar::~ajustar()
{
    delete ui;
}


void ajustar::visualizar_pixels(){

    int h, w;
    QString wt, ht;
    h = imagem4.width();
    w = imagem4.width();

    wt.setNum(w);
    ht.setNum(h);

    ui->h1->setText("0");
    ui->w1->setText("0");
    ui->w2->setText(wt);
    ui->h2->setText(ht);


}




void ajustar::on_pushButton_efeito1_clicked()
{
    int h, w;
    op=0;

    h = imagem4.height();
    w = imagem4.width();

    for (int y = 0; y<h; ++y) {
          for (int x = 0; x<w; ++x) {

            QColor d;

            int r = QColor(imagem4.pixel(x,y)).red();
            int g = QColor(imagem4.pixel(x,y)).green();
            int b = QColor(imagem4.pixel(x,y)).blue();

            r = r - 20;
            g = g - 20;
            b = b - 20;

            if(r >180){
            r = r + 25;
            }
            if(r < 80){
            r = r - 25;
            }
            if(g >180){
            g = g + 25;
            }
            if(g < 80){
            g = g - 25;
            }
            if(b >180){
            b = b + 25;
            }
            if(b < 80){
            b = b - 25;
            }

            // ------------------------
            if(r < 0){
            r = 1;
            }
            if(g < 0){
            g = 1;
            }
            if(b < 0){
            b = 1;
            }
            // -----------------------

            if(r>255){
            r = 254;
            }
            if(g>255){
            g = 254;
            }
            if(b>255){
            b = 254;
            }

            //------------------------



            d.setRed(r);
            d.setGreen(g);
            d.setBlue(b);

            imagem4.setPixel(x, y, d.rgb());


          }
        }

    emit ajuste_concluido();
}

void ajustar::on_pushButton_normal_clicked()
{

    op=1;
    emit ajuste_concluido();
}

void ajustar::on_pushButton_efeito2_clicked()
{
    int h, w;
    op=0;

    h = imagem4.height();
    w = imagem4.width();

    for (int y = 0; y < h; ++y) {
          for (int x = 0; x < w; ++x) {

            QColor d;

            int r = QColor(imagem4.pixel(x,y)).red();
            int g = QColor(imagem4.pixel(x,y)).green();
            int b = QColor(imagem4.pixel(x,y)).blue();

            r = r - 10;
            g = g - 10;
            b = b - 10;

            if(r >180){
            r = r + 15;
            }
            if(r < 80){
            r = r + 30;
            }
            if(g >180){
            g = g + 15;
            }
            if(g < 80){
            g = g + 15;
            }
            if(b >100){
            b = b +10;
            }
            if(b < 80){
            b = b + 30;
            }

            // ------------------------
            if(r < 0){
            r = 1;
            }
            if(g < 0){
            g = 1;
            }
            if(b < 0){
            b = 1;
            }
            // -----------------------

            if(r>255){
            r = 254;
            }
            if(g>255){
            g = 254;
            }
            if(b>255){
            b = 254;
            }

            //------------------------



            d.setRed(r);
            d.setGreen(g);
            d.setBlue(b);

            imagem4.setPixel(x, y, d.rgb());

          }
        }

    emit ajuste_concluido();
}

void ajustar::on_pushButton_aplicar_clicked()
{
    int hi, wi, h1, w1, h2, w2;
    int checkR, checkG, checkB;
    op=0;


    hi = imagem4.height();
    wi = imagem4.width();

    h1 = ui->h1->text().toInt();
    w1 = ui->w1->text().toInt();
    h2 = ui->h2->text().toInt();
    w2 = ui->w2->text().toInt();

    if(h2>hi || w2>wi){
        QString wiText, hiText;
        wiText.setNum(wi);
        hiText.setNum(hi);

        QMessageBox::information(this, "Informaçao!", "Tamanho de Pixel maior que a imagem.");
        ui->w2->setText(wiText);
        ui->h2->setText(hiText);

    }
    else if(h1<0 || w1<0){
    QMessageBox::information(this, "Informaçao!", "Tamanho de Pixel Impossível");
    }
    else{
        checkR = ui->checkBox_R->checkState();
        checkG = ui->checkBox_G->checkState();
        checkB = ui->checkBox_B->checkState();


            for (int x = h1 ; x < h2; ++x) {
                  for (int y = w1 ; y < w2; ++y) {

                       QColor d;

                      int r = QColor(imagem4.pixel(x,y)).red();
                      int g = QColor(imagem4.pixel(x,y)).green();
                      int b = QColor(imagem4.pixel(x,y)).blue();

                      if(checkR == 0){
                      r = 0;
                  }
                      if(checkG == 0){
                      g = 0;
                  }
                      if(checkB == 0){
                      b = 0;
                  }

                      d.setRed(r);
                      d.setGreen(g);
                      d.setBlue(b);

                      imagem4.setPixel(x , y, d.rgb());

        }

        }

                emit ajuste_concluido();

    }




}

void ajustar::on_pushButton_ok_clicked()
{
     this->close();
}
