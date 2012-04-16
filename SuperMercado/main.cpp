#include <QtGui/QApplication>
#include "supermercado.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SuperMercado w;
    w.show();
    
    return a.exec();
}
