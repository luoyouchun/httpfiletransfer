#include "HttpClient.h"
#include <windows.h>
#include "system.h"
#include "fmt/format.h"
#include <memory>
#include "strCoding.h"
#include "tstrings.h"

CHttpClient::CHttpClient()
{
}


CHttpClient::~CHttpClient()
{
}
//string urldecode(string &str_source)
//{
//    char const *in_str = str_source.c_str();
//    int in_str_len = strlen(in_str);
//    int out_str_len = 0;
//    string out_str;
//    char *str;
//
//    str = _strdup(in_str);
//    char *dest = str;
//    char *data = str;
//
//    while (in_str_len--) {
//        if (*data == '+') {
//            *dest = ' ';
//        }
//        else if (*data == '%' && in_str_len >= 2 && isxdigit((int) *(data + 1))
//            && isxdigit((int) *(data + 2))) {
//            *dest = (char)php_htoi(data + 1);
//            data += 2;
//            in_str_len -= 2;
//        }
//        else {
//            *dest = *data;
//        }
//        data++;
//        dest++;
//    }
//    *dest = '\0';
//    out_str_len = dest - str;
//    out_str = str;
//    free(str);
//    return out_str;
//}
string urlencode(string &str_source)
{
    char const *in_str = str_source.c_str();
    int in_str_len = strlen(in_str);
    int out_str_len = 0;
    string out_str;
    register unsigned char c;
    unsigned char *to, *start;
    unsigned char const *from, *end;
    unsigned char hexchars[] = "0123456789ABCDEF";

    from = (unsigned char *)in_str;
    end = (unsigned char *)in_str + in_str_len;
    start = to = (unsigned char *)malloc(3 * in_str_len + 1);

    while (from < end) {
        c = *from++;

        if (c == ' ') {
            *to++ = '+';
        }
        else if ((c < '0' && c != '-' && c != '.') ||
            (c < 'A' && c > '9') ||
            (c > 'Z' && c < 'a' && c != '_') ||
            (c > 'z')) {
            to[0] = '%';
            to[1] = hexchars[c >> 4];
            to[2] = hexchars[c & 15];
            to += 3;
        }
        else {
            *to++ = c;
        }
    }
    *to = 0;

    out_str_len = to - start;
    out_str = (char *)start;
    free(start);
    return out_str;
}

// GET  /shared/{filepath}
// curl http://192.168.1.11/share/1.txt -o "c:\1.txt"

bool CHttpClient::DownloadFile(const std::wstring& strUrl, const std::wstring& strUri,
                               const std::wstring& strLocalPath, const std::wstring& StrName, uint32_t ulSize)
{
    // 尝试用fmt构造
    // 1.构造准备调用的参数
    // 1.1 获取本地路径
    std::wstring strPath = lpp::GetCurrentPath();
    std::wstring strCommand = std::move(strPath);

    // 1.2 构造URL
    std::string strCom = fmt::format("{}\\curl.exe {}{} -o\"{}\"",
        __wstring2string(strCommand), strUrl
        urlencode(strUri),
        __wstring2string(strLocalPath + StrName));

    // 2.同步调用命令行程序完成操作
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.如果需要检查下载的文件是否正确，需要获取文件大小进行对比操作
    return false;
}

// 上传 http://127.0.0.1:3128/shared//Readme%20-%20%E5%89%AF%E6%9C%AC.txt
// curl http://192.168.1.11/upload -F "folder=logs" -F "file=@1.txt"

// 获取文件列表
// curl http://192.168.1.11/files?filepath=log"

// 删除
// curl -X DELETE http://192.168.1.11/rmfiles -F"filepath=1.txt"