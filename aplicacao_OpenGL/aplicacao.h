#ifndef APLICACAO_H
#define APLICACAO_H

#include <QMainWindow>

namespace Ui {
class aplicacao;
}

class aplicacao : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit aplicacao(QWidget *parent = 0);
    ~aplicacao();
    
private:
    Ui::aplicacao *ui;
};

#endif // APLICACAO_H
