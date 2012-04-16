#include "supermercado.h"
#include "ui_supermercado.h"

SuperMercado::SuperMercado(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SuperMercado)
{
    ui->setupUi(this);

    dados = new Banco();


dados->Connection();
atualizar_produto();



connect(ui->action_Produto, SIGNAL(triggered()), this, SLOT(mostrar_produto()));
    connect(ui->lineEdit_produto, SIGNAL(textEdited(QString)), this, SLOT(atualizar_produto()));
    connect(ui->actionSair,SIGNAL(triggered()),this,SLOT(sair()));
    connect(ui->actionCadastrar_Produtos, SIGNAL(triggered()), cad_pro, SLOT(show()));


}

SuperMercado::~SuperMercado()
{
  delete ui;
}

void SuperMercado::mostrar_produto(){
pro = new produto();

pro->setWindowTitle("Produtos");

pro->model = new QSqlTableModel(this, dados->db);
pro->model->clear();

pro->model->setTable("produto");
pro->model->setEditStrategy(QSqlTableModel::OnFieldChange);

pro->model->select();

pro->model->setHeaderData(0, Qt::Horizontal, tr("ID"));
pro->model->setHeaderData(1, Qt::Horizontal, tr("Produto"));

pro->show();
pro->visualizacao_produtos();

}

void SuperMercado::atualizar_produto(){

    dados->select_produto = ui->lineEdit_produto->text();
    QString tipo = ui->comboBox_tipo->currentText();

    if(dados->select_produto.compare("")==0){

    }
    else{

        QSqlTableModel *model = new QSqlTableModel(this, dados->db);
        model->clear();

        model->setTable("produto");
        model->setEditStrategy(QSqlTableModel::OnFieldChange);


        if(tipo.compare("ID")==0){
            int verificando_id=0;
            verificando_id = dados->select_produto.toInt();

            if(verificando_id > 0){

    model->setFilter(QString("id_produto=%1").arg(dados->select_produto));
    model->select();
            }
            else{
                QMessageBox::information(this,"ERRO","Erro ao digitar o ID do produto!");
            }
}
        else if(tipo.compare("Nome")==0){

            dados->atualizar_produto();
            connect(dados,SIGNAL(enviar_String()),this,SLOT(atualizar_produto_2()));

            model->setFilter(QString("id_produto=%1").arg(dados->select_id));
            model->select();

        }
        else{
            QMessageBox::information(this,"Erro","Ocorreu um erro ao escolher o tipo");
        }

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Produto"));
    model->removeColumns(2,2);

    ui->tableView_produto->setModel(model);
}



}

void SuperMercado::atualizar_produto_2(){

    QSqlTableModel *model = new QSqlTableModel(this, dados->db);
    model->clear();

    model->setTable("produto");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    model->setFilter(QString("id_produto=%1").arg(dados->select_id));
    model->select();

    model->setHeaderData(0, Qt::Horizontal, tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, tr("Produto"));
    model->removeColumns(2,2);

    ui->tableView_produto->setModel(model);


}


void SuperMercado::sair(){
dados->db.close();
this->close();

}


