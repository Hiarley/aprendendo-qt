#include <QtGui/QApplication>
#include "aplicacao.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    aplicacao w;
    w.show();
    
    return a.exec();
}
