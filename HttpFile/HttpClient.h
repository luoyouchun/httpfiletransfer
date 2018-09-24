/*---------------------------------------------------------------------------------
* Copyright(C),2018
* FileName:  httpclient.h
* Author:    luoyouchun
* Version:   1.0
* Date:      2018-9-18
* Description:  对curl进行封装，通过调用CURL.exe实现文件上传下载

*---------------------------------------------------------------------------------
* Modification Histroy
Date    Author      Modification:
*
*---------------------------------------------------------------------------------*/


#ifndef _CHTTP_CLIENT_H_
#define _CHTTP_CLIENT_H_

#pragma once

#include <string>
#include <list>

/// <summary>
/// 基于curl实现对接chfs的HTTP文件管理API
/// </summary>
class CHttpClient
{
public:
    CHttpClient();
    ~CHttpClient();
    
    /// <summary>
    /// 使用CURL下载文件
    /// GET  /shared/{filepath}
    /// curl http://192.168.1.11/share/1.txt -o "c:\1.txt"
    /// </summary>
    /// <param name="strUrl">下载URL</param>
    /// <param name="strUri">下载文件相对地址，完整URI，需要进行URL转码</param>
    /// <param name="strLocalPath">本地保存路径</param>
    /// <param name="StrName">本地保存的文件名</param>
    /// <param name="ulSize">文件大小，文件大于0时需要校验文件大小，只支持小于4G的文件</param>
    /// <returns>返回是否下载成功</returns>
    bool DownloadFile(const std::wstring& strUrl, const std::wstring& strFilePath, const std::wstring& strLocalPath, const std::wstring& StrName, uint32_t ulSize = 0);

    /// <summary>
    /// 使用CURL打包下载整个文件夹
    /// </summary>
    /// <param name="strUrl"></param>
    /// <param name="strDirPath"></param>
    /// <param name="strLocalPath"></param>
    /// <param name="StrName"></param>
    /// <returns></returns>
    bool DownloadDir(const std::wstring& strUrl, const std::wstring& strDirPath, const std::wstring& strLocalPath, const std::wstring& StrName);

    /// <summary>
    /// 上传一个指定的文件到服务器
    /// </summary>
    /// <param name="strUrl">上传的地址</param>
    /// <param name="strHttpDir">上传的文件路径</param>
    /// <param name="strHttpFileName">上传的文件名</param>
    /// <param name="strLocalName">本地路径</param>
    /// <returns>是不成功</returns>
    bool UploadFile(const std::wstring& strUrl, const std::wstring& strHttpDir, const std::wstring& strHttpFileName,
                    const std::wstring& strLocalName);


    /// <summary>
    /// 基于CURL，配合chfs实现重命名
    /// </summary>
    /// <param name="strUrl">重命名的URL</param>
    /// <param name="strHttpDir">文件路径</param>
    /// <param name="strOldName">旧的名称</param>
    /// <param name="strNewName">新的名称</param>
    /// <returns>是否成功 </returns>
    bool Rename(const std::wstring& strUrl, const std::wstring& strHttpDir, const std::wstring& strOldName, const std::wstring& strNewName);

    /// <summary>
    /// 删除一个文件
    /// </summary>
    /// <param name="strUrl">删除文件的URL</param>
    /// <param name="strFilePath">要删除的文件或目录</param>
    /// <returns>是否成功</returns>
    bool Delete(const std::wstring& strUrl, const std::wstring& strFilePath);

    /// <summary>
    /// 获取指定目录下的文件
    /// </summary>
    /// <param name="strUrl">URL</param>
    /// <param name="strFilePath">路径</param>
    /// <param name="strFiles">返回的文件列表，json字符串,utf8编码</param>
    /// <returns>是否成功</returns>
    bool GetFileList(const std::wstring& strUrl, const std::wstring& strFilePath, std::string& strFilesFind);

    /// <summary>
    /// 创建一个目录
    /// </summary>
    /// <param name="strUrl">创建目录的URL</param>
    /// <param name="strDirPath">要创建的目录，需要UTF8编码</param>
    /// <returns></returns>
    bool CreateDie(const std::wstring& strUrl, const std::wstring& strDirPath);

    /// <summary>
    /// 快速共享文本，比如网址。 创建成功后会新增一个文本文件
    /// </summary>
    /// <param name="strUrl">创建文本文件网址</param>
    /// <param name="strDirPath">当前共享的目录</param>
    /// <param name="strTitle">标题</param>
    /// <param name="strText">文件</param>
    /// <returns>创建结果</returns>
    bool CreateTxt(const std::wstring& strUrl, const std::wstring& strDirPath, const std::wstring& strTitle, const std::string& strText);

    /// <summary>
    /// 判断文件是否存在
    /// </summary>
    /// <param name="strUrl">判断文件是否存在的URL</param>
    /// <param name="strPath">要查询的文件</param>
    /// <returns>文件是否存在</returns>
    bool FileExist(const std::wstring& strUrl, const std::wstring& strPath);

 private:
     /// <summary>
     /// 通过检查http_code判断是否返回成功
     /// </summary>
     /// <param name="lstOutput">调用命令行解析的列表</param>
     /// <param name="strHttpCodeSuccess">成功的编码</param>
     /// <returns></returns>
    bool CheckSuccess(const std::list<std::string>& lstOutput, const std::string& strHttpCodeSuccess = "201");

    std::string m_strCurlFullPath;              // CURL的所在的全路径
};

#endif
