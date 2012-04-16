#ifndef BANCO_H
#define BANCO_H

#include <QDialog>
#include <QMessageBox>
#include <QComboBox>
#include <QString>
#include <QDebug>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlRecord>


namespace Ui {
class Banco;
}

class Banco : public QDialog
{
    Q_OBJECT
    
public:
    explicit Banco(QWidget *parent = 0);
    ~Banco();

public:
    QSqlDatabase db;
    QString id_produto, nome_produto, tipo, preco; // PRODUTO
    QString select_produto, select_id; //Atualizar produto


public slots:
    void Connection(); // Conexão
    void cadastrar_produto(); //insert novo produto
    void atualizar_produto(); //select produto


signals:
    void enviar_String(); // no banco para atualizar produto
    
private:
    Ui::Banco *ui;
};

#endif // BANCO_H
