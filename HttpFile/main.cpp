#include "HttpFile.h"
#include <QtWidgets/QApplication>
#include "HttpServer.h"
#include "HttpClient.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //CHttpClient oClient;
    //oClient.DownloadFile(L"http://127.0.0.1:3128/shared//", L"Readme - ¸±±¾.txt", L"C:\\Users\\Eric\\Documents\\", L"1.txt", 11321);
    //CHttpServer oServer(L"\"D:\\WD Software Offline Installers\"", 3128);
    //oServer.Star();

    HttpFile w;
    w.show();
    return a.exec();
}
