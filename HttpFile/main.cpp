#include "HttpFile.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HttpFile w;
    w.show();
    return a.exec();
}
