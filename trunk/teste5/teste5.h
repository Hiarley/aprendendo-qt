#ifndef TESTE5_H
#define TESTE5_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QMessageBox>
#include <pag2.h>

namespace Ui {
class teste5;
}

class teste5 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit teste5(QWidget *parent = 0);
    ~teste5();

    QImage imagem2;

public:
    pag2 pag;

public slots:
    void abrir();
    void inverter();
    void salvar();
    void sair();


private:
    Ui::teste5 *ui;
};




#endif // TESTE5_H
