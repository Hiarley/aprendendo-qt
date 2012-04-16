#include "banco.h"
#include "ui_banco.h"

Banco::Banco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Banco)
{
    ui->setupUi(this);
}

Banco::~Banco()
{
    delete ui;
}

void Banco::Connection(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ManagerDB.db");


    if (!db.open()) {
    QMessageBox::critical(0, qApp->tr("Não pode abrir o Banco de Dados"),
    qApp->tr("Conexão não estabelecida.\n"
    "Este programa precisa suportar SQLite. "
    "Click Cancel para sair."), QMessageBox::Cancel);
    }
        QSqlQuery query;
        query.prepare( "CREATE TABLE IF NOT EXISTS produto (id_produto INTEGER UNIQUE PRIMARY KEY, nome_produto VARCHAR(40), tipo VARCHAR(30), preco VARCHAR(10))" );
       if( !query.exec() )
           qDebug() << query.lastError();
         else
           qDebug() << "Tabela PRODUTO Criada!";

       query.prepare( "CREATE TABLE IF NOT EXISTS compra (id_compra INTEGER UNIQUE PRIMARY KEY, id_produto INT, nome_cliente VARCHAR(50), CPF VARCHAR(10))" );
      if( !query.exec() )
          qDebug() << query.lastError();
        else
          qDebug() << "Tabela COMPRA Criada!";


}

void Banco::cadastrar_produto(){

int num=0;
QString num2;

QSqlQuery query;
    query.exec("select * from produto");
    while(query.next()){
        num  = num+1;

}
num++;
    num2.setNum(num);

    query.prepare( "INSERT INTO produto (id_produto, nome_produto, tipo, preco) VALUES ( "+num2+" , '" + nome_produto +"' , '"+ tipo + "' , '"+ preco + "' )" );
        if( !query.exec() )
          qDebug() << query.lastError();
        else
            qDebug( "Inserido em PRODUTO !" );

}

void Banco::atualizar_produto(){


    QSqlQuery query;
    query.exec("select * from produto WHERE nome_produto LIKE '"+select_produto+"%'");
    while(query.next()){
        select_id = query.value(0).toString();

    emit enviar_String();


}

}


