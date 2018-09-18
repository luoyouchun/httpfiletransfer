#include "HttpFile.h"
#include <QtWidgets/QApplication>
#include "HttpServer.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //CHttpServer oServer(L"\"D:\\WD Software Offline Installers\"", 3128);
    //oServer.Star();

    HttpFile w;
    w.show();
    return a.exec();
}
