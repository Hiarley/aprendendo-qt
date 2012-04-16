#include "produto.h"
#include "ui_produto.h"

produto::produto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produto)
{
    ui->setupUi(this);


}

produto::~produto()
{
    delete ui;
}

void produto::on_pushButton_cad_produto_clicked(){



}

void produto::visualizacao_produtos(){

    ui->tableView_produtos->setModel(model);

}
