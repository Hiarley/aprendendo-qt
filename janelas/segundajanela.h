#ifndef SEGUNDAJANELA_H
#define SEGUNDAJANELA_H

#include <QDialog>

namespace Ui {
    class segundaJanela;
}

class segundaJanela : public QDialog
{
    Q_OBJECT

public:
    explicit segundaJanela(QWidget *parent = 0);
    ~segundaJanela();

    QString dadosDaPrimeiraJanela;
    QString dadosDaSegundaJanela;

private:
    Ui::segundaJanela *ui;

signals:
    void enviarDados();

public slots:
    void on_pushButton_segundaJanela_clicked();
    void atualizarSegundaJanela();
};

#endif // SEGUNDAJANELA_H
