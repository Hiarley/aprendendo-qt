#ifndef PIXELS_H
#define PIXELS_H

#include <QDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class pixels;
}

class pixels : public QDialog
{
    Q_OBJECT
    
public:
    explicit pixels(QWidget *parent = 0);
    ~pixels();

public:
    int px1, px2, px3, px4;
    
private slots:
    void on_pushButton_ok_clicked();

signals:
    void sinal_pixel();

public slots:
    void setpixel();


private:
    Ui::pixels *ui;
};

#endif // PIXELS_H
