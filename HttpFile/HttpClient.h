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


class CHttpClient
{
public:
    CHttpClient();
    ~CHttpClient();
    
    /// <summary>
    /// 使用CURL下载文件
    /// </summary>
    /// <param name="strUrl">下载地址，完整URL，需要进行URL转码</param>
    /// <param name="strLocalPath">本地保存路径</param>
    /// <param name="StrName">本地保存的文件名</param>
    /// <param name="ulSize">文件大小，文件大于0时需要校验文件大小，只支持小于4G的文件</param>
    /// <returns>返回是否下载成功</returns>
    bool DownloadFile(const std::wstring& strUrl, const std::wstring& strLocalPath, const std::wstring& StrName,uint32_t ulSize = 0);


};

#endif
