#include "HttpFile.h"
#include <QtWidgets/QApplication>
#include "HttpServer.h"
#include "HttpClient.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::string strFiles;
    CHttpClient oClient;

    //oClient.DownloadFile(L"http://127.0.0.1:3128/", L"Readme - 副本.txt", L"C:\\Users\\Eric\\Documents\\", L"1.txt", 11321);
    //oClient.DownloadDir(L"http://127.0.0.1:3128/", L"test", L"C:\\Users\\Eric\\Documents\\", L"1.zip");
    //oClient.FileExist(L"http://127.0.0.1:3128/", L"Test/云桌面驱动开发.pdf");
    //oClient.FileExist(L"http://127.0.0.1:3128/", L"test/中国");
    // oClient.CreateTxt(L"http://127.0.0.1:3128/", L"中国/中国", L"中国.txt", "123456");
    // oClient.CreateDie(L"http://127.0.0.1:3128/", L"中国/中国");
    //oClient.GetFileList(L"http://127.0.0.1:3128/", L"Test", strFiles);
    // oClient.Delete(L"http://127.0.0.1:3128/", L"/Test/云桌面驱动开发.pdf");
    //oClient.Rename(L"http://127.0.0.1:3128/", L"/Test", L"1.pdf", L"2.pdf");
    //oClient.UploadFile(L"http://127.0.0.1:3128/", L"/Test", L"云桌面驱动开发.pdf", L"D:\\云桌面驱动开发.pdf");
    //CHttpServer oServer(L"\"D:\\WD Software Offline Installers\"", 3128);
    //oServer.Star();




            // 测试解析
    //CJsonParser oJsonParser;
    //std::list<CFileInfo> lstFiles;
    //oJsonParser.ParserFiles(strFilesFind, lstFiles);



    HttpFile w;
    w.show();
    return a.exec();
}
