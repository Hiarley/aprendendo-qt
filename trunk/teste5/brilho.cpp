#include "brilho.h"
#include "ui_brilho.h"

brilho::brilho(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::brilho)
{
    ui->setupUi(this);

    connect(ui->ma, SIGNAL(clicked()), this, SLOT(mais()));
    connect(ui->me, SIGNAL(clicked()), this, SLOT(menos()));


    int mostrar = 0;

}

brilho::~brilho()
{
    delete ui;
}

void brilho::mais(){
    int h, w;

    QString mostra2;
    h = imagem3.height();
    w = imagem3.width();

    for (int y = 0; y < h; ++y){
          for (int x = 0; x < w; ++x){
            QColor d;

             int r = QColor(imagem3.pixel(x,y)).red();
             int g = QColor(imagem3.pixel(x,y)).green();
             int b = QColor(imagem3.pixel(x,y)).blue();

            r = r + 50;
            g = g + 50;
            b = b + 50;

            if(r>255){
            r = 254;
            }
            if(g>255){
            g = 254;
            }
            if(b>255){
            b = 254;
            }

            d.setRed(r);
            d.setGreen(g);
            d.setBlue(b);


            imagem3.setPixel(x, y, d.rgb());

          }
        }

    mostrar = mostrar + 10;
    mostra2.setNum(mostrar);
    ui->result->setText(mostra2);

    emit enviar();

    //Mostrar é apenas o valor que vai ser mostrado ao usuario.

}
void brilho::menos(){

    int h, w;

    QString mostra2;
    h = imagem3.height();
    w = imagem3.width();

    for (int y = 0; y < h; ++y){
          for (int x = 0; x < w; ++x){
            QColor d;

             int r = QColor(imagem3.pixel(x,y)).red();
             int g = QColor(imagem3.pixel(x,y)).green();
             int b = QColor(imagem3.pixel(x,y)).blue();

            r = r - 50;
            g = g - 50;
            b = b - 50;

            if(r < 0){
            r = 1;
            }
            if(g < 0){
            g = 1;
            }
            if(b < 0){
            b = 1;
            }

            d.setRed(r);
            d.setGreen(g);
            d.setBlue(b);


            imagem3.setPixel(x, y, d.rgb());

          }
        }

    mostrar = mostrar - 10;
    mostra2.setNum(mostrar);
    ui->result->setText(mostra2);

    emit enviar();

}

void brilho::on_pushButton_3_clicked()
{
    this->close();
}
