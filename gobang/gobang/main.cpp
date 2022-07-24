#include "ckernel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    checkerboard c;
    //c.show();
    //w.show();
    Ckernel kernel;

    return a.exec();
}
