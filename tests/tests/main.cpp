#include "tests.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tests w;
    w.show();
    return a.exec();
}
