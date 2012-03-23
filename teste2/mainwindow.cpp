#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString resultado, tipo;
   double num1, num2, res;
   int check;

   num1 = ui->Edit_num1->text().toDouble();
   num2 = ui->Edit_num2->text().toDouble();

   tipo = ui->tipo->currentText();

  check = ui->percent->checkState();

   if(tipo.compare("+")==0){
       if(check > 0){
           double num3;

       num2 = num2 * 0.01;
       num3 = num1 * num2;
       res = num1 + num3;
       }
       else{
   res = num1 + num2;
}
   resultado.setNum(res);

   ui->Resultado->setText(resultado);
}
   else if(tipo.compare("-")==0){

       if(check > 0){
           double num3;

       num2 = num2 * 0.01;
       num3 = num1 * num2;
       res = num1 - num3;
       }
     else{
   res = num1 - num2;
}
   resultado.setNum(res);

   ui->Resultado->setText(resultado);
}
   else if(tipo.compare("*")==0){
       if(check > 0){

       num2 = num2 * 0.01;
       res = num1 * num2;
       }
       else{
   res = num1 * num2;
}
   resultado.setNum(res);

   ui->Resultado->setText(resultado);
}
   else if(tipo.compare("/")==0){

       if(check > 0){
           ui->Resultado->setText("<b>Operaçao Incorreta</b>");
       }
       else{
   res = num1 / num2;
   resultado.setNum(res);
   ui->Resultado->setText(resultado);
}


}
   else{
       ui->Resultado->setText("<b>Operaçao Incorreta</b>");

   }

   }


void MainWindow::on_pushButton_2_clicked()
{
    ui->Edit_num1->setText("");
    ui->Edit_num2->setText("");
    ui->Resultado->setText("");
}


void MainWindow::on_percent_stateChanged(int arg1)
{
    if(arg1>0){
        ui->Resultado->setText("");
        ui->label_2->setText("%");


    }
    else if(arg1==0){
    ui->Resultado->setText("");
    ui->label_2->setText("");
    }
}
