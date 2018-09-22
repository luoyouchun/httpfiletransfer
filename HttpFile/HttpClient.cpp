#include "HttpClient.h"
#include <windows.h>
#include "system.h"
#include "fmt/format.h"
#include <memory>

#include "tstrings.h"
#include "boost/filesystem.hpp"


CHttpClient::CHttpClient()
{
}


CHttpClient::~CHttpClient()
{
}

bool CHttpClient::DownloadFile(const std::wstring& strUrl, const std::wstring& strUri,
                               const std::wstring& strLocalPath, const std::wstring& StrName, uint32_t ulSize)
{
    bool bResult = false;

    // 尝试用fmt构造
    // 1.构造准备调用的参数
    // 1.1 获取本地路径
    std::wstring strPath = lpp::GetCurrentPath();
    std::wstring strCommand = std::move(strPath);

    // 1.2 构造URL
    std::string strCom = fmt::format("{}\\curl.exe {}{} -o\"{}\"",
                                    __wstring2string(strCommand), __wstring2string(strUrl),
                                    UrlEncode(ws2utf8(strUri)),
                                    __wstring2string(strLocalPath + StrName));

    // 2.同步调用命令行程序完成操作
    // http://127.0.0.1:3128/shared//Readme%20-%20%E5%89%AF%E6%9C%AC.txt
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.如果需要检查下载的文件是否正确，需要获取文件大小进行对比操作
    bResult = true;
    if (ulSize > 0)
    {
        uint32_t ulTem = boost::filesystem::file_size(__wstring2string(strLocalPath + StrName));
        if (ulTem != ulSize)
        {
            bResult = false;
        }
        // 检查文件大小
    }

    return bResult;
}

// 上传 http://127.0.0.1:3128/shared//Readme%20-%20%E5%89%AF%E6%9C%AC.txt
// curl http://192.168.1.11/upload -F "folder=logs" -F "file=@1.txt"

// 获取文件列表
// curl http://192.168.1.11/files?filepath=log"

// 删除
// curl -X DELETE http://192.168.1.11/rmfiles -F"filepath=1.txt"