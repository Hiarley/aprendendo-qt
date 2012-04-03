#ifndef VISUALIZACAO_H
#define VISUALIZACAO_H

#include <QDialog>
#include <teste5.h>

namespace Ui {
class visualizacao;
}

class visualizacao : public QDialog
{
    Q_OBJECT
    
public:
    explicit visualizacao(QWidget *parent = 0);
    ~visualizacao();

public slots:
    void verif();
    
private:
    Ui::visualizacao *ui;
};

#endif // VISUALIZACAO_H
