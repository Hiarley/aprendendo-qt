#ifndef TEXTO_H
#define TEXTO_H

#include <QDialog>
#include <QString>

namespace Ui {
class texto;
}

class texto : public QDialog
{
    Q_OBJECT
    
public:
    explicit texto(QWidget *parent = 0);
    ~texto();

public:
    QString texto_imagem;

public slots:
    void pegar_texto();
    
private slots:
    void on_pushButton_ok_clicked();

signals:
    void sinal_texto();

private:
    Ui::texto *ui;
};

#endif // TEXTO_H
