#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <QMainWindow>
#include <QMessageBox>
#include <QComboBox>
#include <QString>
#include <QDebug>
#include <QtSql>
#include <QSqlTableModel>
#include <QModelIndex>
#include <banco.h>
#include <cad_produto.h>
#include <produto.h>



namespace Ui {
class SuperMercado;
}

class SuperMercado : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SuperMercado(QWidget *parent = 0);
    ~SuperMercado();

public:
    Banco *dados;
    cad_produto *cad_pro;
    produto *pro;

public slots:
    void mostrar_produto();
    void atualizar_produto();
    void atualizar_produto_2();
    void sair();
    

private:
    Ui::SuperMercado *ui;
};

#endif // SUPERMERCADO_H
