#include <QtGui/QApplication>
#include "principal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    principal w;
    w.show();
    
    return a.exec();
}
