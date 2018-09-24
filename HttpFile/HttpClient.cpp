/*---------------------------------------------------------------------------------
* Copyright(C),2018
* FileName:  httpclient.cpp
* Author:    luoyouchun
* Version:   1.0
* Date:      2018-9-18
* Description:  对curl进行封装，通过调用CURL.exe实现文件上传下载

*---------------------------------------------------------------------------------
* Modification Histroy
Date    Author      Modification:
*
*---------------------------------------------------------------------------------*/


#include "HttpClient.h"
#include "system.h"
#include "fmt/format.h"
#include <memory>

#include "tstrings.h"
#include "boost/filesystem.hpp"

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_io.hpp"
#include "boost/uuid/uuid_generators.hpp"

#include "JsonParser.h"


CHttpClient::CHttpClient()
{
    // 获取本地路径
    m_strCurlFullPath = fmt::format("{}\\curl.exe", __wstring2string(lpp::GetCurrentPath()));
}


CHttpClient::~CHttpClient()
{
}
// 下载 http://127.0.0.1:3128/shared//Readme%20-%20%E5%89%AF%E6%9C%AC.txt
bool CHttpClient::DownloadFile(const std::wstring& strUrl, const std::wstring& strFilePath,
                               const std::wstring& strLocalPath, const std::wstring& StrName, uint32_t ulSize)
{
    bool bResult = false;

    // 尝试用fmt构造
    // 1.构造准备调用的参数

    // 1.2 构造URL
    std::string strCom = fmt::format("{} {}shared//{} -o\"{}\" -w %{{http_code}}",
                                    m_strCurlFullPath, __wstring2string(strUrl),
                                    UrlEncode(ws2utf8(strFilePath)),
                                    __wstring2string(strLocalPath + StrName));

    // 2.同步调用命令行程序完成操作
    // http://127.0.0.1:3128/shared//Readme%20-%20%E5%89%AF%E6%9C%AC.txt
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.如果需要检查下载的文件是否正确，需要获取文件大小进行对比操作
    bResult = CheckSuccess(lstOutput, "200");;
    if (ulSize > 0)
    {
        // 检查文件大小
        uint32_t ulTem = boost::filesystem::file_size(__wstring2string(strLocalPath + StrName));
        if (ulTem != ulSize)
        {
            bResult = false;
        }        
    }

    return bResult;
}

// GET / downloaddir / {dir}
bool CHttpClient::DownloadDir(const std::wstring& strUrl, const std::wstring& strDirPath, const std::wstring& strLocalPath, const std::wstring& StrName)
{
    bool bResult = false;

    // 1.构造参数
    std::string strCom = fmt::format("{} {}downloaddir/{} -o\"{}\" -w %{{http_code}}",
                                    m_strCurlFullPath, __wstring2string(strUrl),
                                    UrlEncode(ws2utf8(strDirPath)),
                                    __wstring2string(strLocalPath + StrName));

    // 2.调用命令重命名
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.解析是否成功 
    bResult = CheckSuccess(lstOutput, "200");

    return bResult;
}

// curl http://192.168.1.11/upload -F "folder=logs" -F "file=@1.txt;filename=1.txt"
bool CHttpClient::UploadFile(const std::wstring& strUrl, const std::wstring& strHttpDir, const std::wstring& strHttpFileName, const std::wstring& strLocalName)
{
    bool bResult = false;

    // 由于中文轮换的支持两端不是很统一，用UUID上传，上传成功后修改名称
    boost::uuids::uuid a_uuid = boost::uuids::random_generator()(); // 这里是两个() ，因为这里是调用的 () 的运算符重载
    const std::string tmp_uuid = boost::uuids::to_string(a_uuid);

    // 1.上传
    // ??? 需要首先检查上传的文件是否存在，如果存在，需要返回错误
    // 1.1构造上传的命令行调用

    std::string strCom = fmt::format("{} {}upload -F \"folder={}\" -F \"file=@{}; filename={}\" -w %{{http_code}}",
                                    m_strCurlFullPath,
                                    __wstring2string(strUrl),
                                    UrlEncode(ws2utf8(strHttpDir)),
                                    __wstring2string(strLocalName),
                                    tmp_uuid);
    // 1.2 上传
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 2. 检查上传是否成功
    bResult = CheckSuccess(lstOutput);

    // 3.修改名称
    if (bResult)
    {
        // 修改名称也成功了，视为成功
        bResult = Rename(strUrl, strHttpDir, __string2wstring(tmp_uuid), strHttpFileName);
    }
    {
        // 改名失败了，还需要删除上传成功的文件
        std::string strDeleteFilePath = fmt::format("{}/{}", UrlEncode(ws2utf8(strHttpDir)), tmp_uuid);
        Delete(strUrl, __string2wstring(strDeleteFilePath));
    }

    return bResult;
}


// curl http://192.168.1.11/rename -F "old=\Test\aaaaa.pdf" -F "new=1.pdf"
bool CHttpClient::Rename(const std::wstring& strUrl, const std::wstring& strHttpDir, const std::wstring& strOldName, const std::wstring& strNewName)
{
    bool bResult = false;

    // 1.构造参数
    std::string strFullOldName = fmt::format("{}/{}", UrlEncode(ws2utf8(strHttpDir)), UrlEncode(ws2utf8(strOldName)));

    std::string strCom = fmt::format("{} {}rename -F \"old={}\" -F \"new={}\" -w %{{http_code}}",
                                    m_strCurlFullPath,
                                    __wstring2string(strUrl),
                                    strFullOldName, UrlEncode(ws2utf8(strNewName)));

    // 2.调用命令重命名
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.解析是否成功 
    bResult = CheckSuccess(lstOutput);

    return bResult;
}

// DELETE  /rmfiles
// curl -X DELETE http://192.168.1.11/rmfiles -F"filepath=1.txt"
bool CHttpClient::Delete(const std::wstring & strUrl, const std::wstring & strFilePath)
{
    bool bResult = false;

    // 1.构造参数
    std::string strCom = fmt::format("{} -X DELETE {}rmfiles -F \"filepath={}\" -w %{{http_code}}",
                                     m_strCurlFullPath,
                                     __wstring2string(strUrl),
                                     UrlEncode(ws2utf8(strFilePath)));

    // 2.调用命令重命名
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.解析是否成功 
    bResult = CheckSuccess(lstOutput, "204");

    return bResult;
}

// 获取文件列表
// curl http://192.168.1.11/files?filepath=log"
bool CHttpClient::GetFileList(const std::wstring& strUrl, const std::wstring& strFilePath, std::string& strFilesFind)
{
    bool bResult = false;

    // 1.构造参数
    std::string strCom = fmt::format("{} {}files?filepath={} -w %{{http_code}}",
                                     m_strCurlFullPath,
                                     __wstring2string(strUrl),
                                     UrlEncode(ws2utf8(strFilePath)));

    // 2.调用命令重命名
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.解析是否成功 
    auto itor = lstOutput.rbegin();
    if (itor != lstOutput.rend())
    {
        std::string strFiles = std::move(*itor);
        std::size_t nfind = strFiles.find_last_of("200");
        if (nfind != std::string::npos && nfind == strFiles.length() - 1)
        {
            // 成功了，可以解析了符串
            bResult = true;

            // 擦除后面http_code
            strFiles.erase(strFiles.size() - 3, 3);
            strFilesFind.swap(strFiles);
        }
    }

    return bResult;
}

// POST  /newdir
// formData filepath=要创建的目录
bool CHttpClient::CreateDie(const std::wstring& strUrl, const std::wstring& strDirPath)
{
    bool bResult = false;

    // 1.构造参数
    std::string strCom = fmt::format("{} {}newdir -F \"filepath={}\" -w %{{http_code}}",
                                      m_strCurlFullPath,
                                      __wstring2string(strUrl),
                                      UrlEncode(ws2utf8(strDirPath)));

    // 2.调用命令重命名
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.解析是否成功 
    bResult = CheckSuccess(lstOutput, "201");

    return bResult;
}

// POST  /newtext
bool CHttpClient::CreateTxt(const std::wstring& strUrl, const std::wstring& strDirPath, const std::wstring& strTitle, const std::string& strText)
{
    bool bResult = false;

    // 1.构造参数
    std::string strCom = fmt::format("{} {}newtext -F \"filepath={}\" -F \"title={}\" -F \"text={}\" -w %{{http_code}}",
                                      m_strCurlFullPath,
                                      __wstring2string(strUrl),
                                      UrlEncode(ws2utf8(strDirPath)),
                                      ws2utf8(strTitle),
                                      strText);

    // 2.调用命令重命名
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.解析是否成功 
    bResult = CheckSuccess(lstOutput, "201");

    return bResult;
}

// GET / exist
bool CHttpClient::FileExist(const std::wstring & strUrl, const std::wstring & strPath)
{
    bool bResult = false;

    // 1.构造参数
    std::string strCom = fmt::format("{} {}exist?file={} -w %{{http_code}}",
                                    m_strCurlFullPath,
                                    __wstring2string(strUrl),
                                    UrlEncode(ws2utf8(strPath)));

    // 2.调用命令重命名
    std::list<std::string> lstOutput;
    lpp::CCmdoutput::GetCmdOutput(strCom, lstOutput);

    // 3.解析是否成功 
    bResult = CheckSuccess(lstOutput, "201");

    return bResult;
}

bool CHttpClient::CheckSuccess(const std::list<std::string>& lstOutput, const std::string& strHttpCodeSuccess)
{
    bool bResult = false;
    auto itor = std::find(lstOutput.begin(), lstOutput.end(), strHttpCodeSuccess);
    if (itor != lstOutput.end())
    {
        bResult = true;
    }
    else
    {
        // ??? 记录错误的日志
    }

    return bResult;
}
