#ifndef JANELAS_H
#define JANELAS_H

#include <QMainWindow>
#include <segundajanela.h>

namespace Ui {
    class Janelas;
}

class Janelas : public QMainWindow
{
    Q_OBJECT

public:
    explicit Janelas(QWidget *parent = 0);
    ~Janelas();

private:
    Ui::Janelas *ui;

public:
    segundaJanela *janelinha;
private slots:
    void on_pushButton_clicked();
    void receberDadosDaSegundaJanela();
};

#endif // JANELAS_H
