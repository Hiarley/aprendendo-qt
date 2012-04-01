#include <QtGui/QApplication>
#include "janelas.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Janelas w;
    w.show();

    return a.exec();
}
