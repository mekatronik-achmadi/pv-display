#include "testsim.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testsim w;
    w.show();

    return a.exec();
}
