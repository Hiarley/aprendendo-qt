#ifndef PAG2_H
#define PAG2_H

#include <QDialog>
#include <QImage>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class pag2;
}

class pag2 : public QDialog
{
    Q_OBJECT
    
public:
    explicit pag2(QWidget *parent = 0);
    ~pag2();

QImage imagem;

public slots:
    void visualizacao();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::pag2 *ui;
};


#endif // PAG2_H
