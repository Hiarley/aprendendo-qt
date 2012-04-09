#ifndef AJUSTAR_H
#define AJUSTAR_H

#include <QDialog>
#include <QString>
#include <QImage>
#include <QColor>
#include <QMessageBox>

namespace Ui {
class ajustar;
}

class ajustar : public QDialog
{
    Q_OBJECT
    
public:
    explicit ajustar(QWidget *parent = 0);
    ~ajustar();

    QImage imagem4;
    int op;

 //op será ativado quando clicar em Normal, a imagem receberá a imagem reserva, assim voltará a imagem original escolhida
 //imagem4 será a imagem que será aplicado o ajuste.


public slots:
    void visualizar_pixels();

    
private slots:
    void on_pushButton_efeito1_clicked();


    void on_pushButton_normal_clicked();

    void on_pushButton_efeito2_clicked();

    void on_pushButton_aplicar_clicked();

    void on_pushButton_ok_clicked();

signals:
    void ajuste_concluido();

private:
    Ui::ajustar *ui;
};

#endif // AJUSTAR_H
