#include <QtGui/QApplication>
#include "gnufreecall.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GNUFreeCall w;
    w.show();

    return a.exec();
}
