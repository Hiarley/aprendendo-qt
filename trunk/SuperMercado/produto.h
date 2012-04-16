#ifndef PRODUTO_H
#define PRODUTO_H

#include <QDialog>
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
#include <supermercado.h>


namespace Ui {
class produto;
}

class produto : public QDialog
{
    Q_OBJECT
    
public:
    explicit produto(QWidget *parent = 0);
    ~produto();


public:
    QSqlTableModel *model;


public slots:
    void visualizacao_produtos();
    
private slots:
    void on_pushButton_cad_produto_clicked();



private:
    Ui::produto *ui;
};

#endif // PRODUTO_H
