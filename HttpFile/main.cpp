#include "HttpFile.h"
#include <QtWidgets/QApplication>
#include "HttpServer.h"
#include "HttpClient.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    CHttpClient oClient;
    oClient.Delete(L"http://127.0.0.1:3128/", L"/Test/云桌面驱动开发.pdf");
    //oClient.Rename(L"http://127.0.0.1:3128/", L"/Test", L"1.pdf", L"2.pdf");
    //oClient.UploadFile(L"http://127.0.0.1:3128/", L"/Test", L"云桌面驱动开发.pdf", L"D:\\云桌面驱动开发.pdf");
    //oClient.DownloadFile(L"http://127.0.0.1:3128/shared//", L"Readme - 副本.txt", L"C:\\Users\\Eric\\Documents\\", L"1.txt", 11321);
    //CHttpServer oServer(L"\"D:\\WD Software Offline Installers\"", 3128);
    //oServer.Star();

    HttpFile w;
    w.show();
    return a.exec();
}
