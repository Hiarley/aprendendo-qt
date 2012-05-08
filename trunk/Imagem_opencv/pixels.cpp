#include "pixels.h"
#include "ui_pixels.h"

pixels::pixels(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pixels)
{
    ui->setupUi(this);
}

pixels::~pixels()
{
    delete ui;
}

void pixels::setpixel(){

    px1 = ui->lineEdit_px1->text().toInt();
    px2 = ui->lineEdit_px2->text().toInt();
    px3 = ui->lineEdit_px3->text().toInt();
    px4 = ui->lineEdit_px4->text().toInt();

    if(px1>0 && px2>0 && px3>0 && px4>0 ){  // falta filtrar por altura máxima e largura máxima
        emit sinal_pixel();
        this->close();
    }
    else{
        QMessageBox::information(this,"ERRO","os pixels estão incorretos!");
    }

}

void pixels::on_pushButton_ok_clicked()
{
   setpixel();
}
