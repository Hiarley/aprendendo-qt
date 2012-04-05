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
    int mostrar; // Faltou declarar esse mostrar

public slots:
    void mais();
    void menos();
    
private slots:
    void on_pushButton_3_clicked();

signals:
    void enviar(); // Faltou declarar o sinal

private:
    Ui::brilho *ui;
};

#endif // BRILHO_H
