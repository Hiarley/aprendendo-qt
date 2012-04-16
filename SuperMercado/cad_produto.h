#ifndef CAD_PRODUTO_H
#define CAD_PRODUTO_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QtSql>
#include <QSqlTableModel>
#include <banco.h>
#include <produto.h>


namespace Ui {
class cad_produto;
}

class cad_produto : public QDialog
{
    Q_OBJECT
    
public:
    explicit cad_produto(QWidget *parent = 0);
    ~cad_produto();

public:
    Banco *dados;

    
private slots:
    void on_pushButton_cadastrar_clicked();

    void on_pushButton_limpar_clicked();

private:
    Ui::cad_produto *ui;
};

#endif // CAD_PRODUTO_H
