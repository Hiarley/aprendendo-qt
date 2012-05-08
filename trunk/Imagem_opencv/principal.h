#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QString>
#include <QImage>
#include <opencv.hpp>
#include <QFile>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <informacao.h>
#include <pixels.h>
#include <texto.h>

namespace Ui {
class principal;
}

class principal : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit principal(QWidget *parent = 0);
    ~principal();
    IplImage *imagem;
    QImage qimagem;
    QString fn;

public:
    informacao *info;
public:
    pixels *px;
public:
    texto *tx;


public slots:
    void abrir();
    void abrir_informacao();
    void visualizacao();
    void salvar();
    void transformar(); //Transformar Iplimage para QImage
    void modo_monocromatico();
    void modo_normal();
    void caixa();
    void caixa_2();
    void circulo();
    void texto_img();
    void texto_img_2();
    void sair();



    
private slots:
    void on_pushButton_informacoes_clicked();

    void on_pushButton_vis_clicked();

    void on_pushButton_Salvar_clicked();

    void on_pushButton_Mono_clicked();

    void on_pushButton_normal_clicked();

    void on_pushButton_clicked();

    void on_pushButton_circulo_clicked();

    void on_pushButton_texto_clicked();

private:
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
