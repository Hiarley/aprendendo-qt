#ifndef INFORMACAO_H
#define INFORMACAO_H

#include <QDialog>
#include <QString>
#include <QImage>
#include <opencv.hpp>
#include <QFile>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>

namespace Ui {
class informacao;
}

class informacao : public QDialog
{
    Q_OBJECT
    
public:
    explicit informacao(QWidget *parent = 0);
    ~informacao();

    QString n_canais, largura, altura;

public slots:
    void atualizar();
    
private:
    Ui::informacao *ui;
};

#endif // INFORMACAO_H
