#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);

    connect(ui->pushButton_sair, SIGNAL(clicked()), this, SLOT(close()));
}

principal::~principal()
{
    delete ui;
}
