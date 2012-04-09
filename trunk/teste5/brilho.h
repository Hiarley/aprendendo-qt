#ifndef BRILHO_H
#define BRILHO_H

#include <QDialog>
#include <QString>
#include <QImage>
#include <QColor>


namespace Ui {
class brilho;
}

class brilho : public QDialog
{
    Q_OBJECT

public:
    explicit brilho(QWidget *parent = 0);
    ~brilho();

    QImage imagem3;
    int op;

 //op será ativado quando clicar em Normal, a imagem receberá a imagem reserva, assim voltará a imagem original escolhida
 //imagem4 será a imagem que será aplicado o ajuste.


public slots:
    void mais();
    void menos();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_normal_clicked();

signals:
    void enviar();

private:
    Ui::brilho *ui;
};

#endif // BRILHO_H
