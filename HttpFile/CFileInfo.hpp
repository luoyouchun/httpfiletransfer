
/*---------------------------------------------------------------------------------
* Copyright(C),2018
* FileName:  JsonParser.h
* Author:    luoyouchun
* Version:   1.0
* Date:      2018-9-24
* Description:  chfs查询目录文件列表结构
                std::string 字符串统一使用UTF-8编码
                std::wstring 转码后的宽字符
*---------------------------------------------------------------------------------
* Modification Histroy
Date    Author      Modification:
*
*---------------------------------------------------------------------------------*/


#ifndef _CFILEINFO_H_
#define _CFILEINFO_H_

#pragma once
#include <string>

// UTF8编码
class CFileInfo
{
public:
    CFileInfo():
        m_strName(""), m_bDir(false), m_nSize(0), m_strModified(""), m_strIcon(""), m_strMask(""), m_strGguestMask("")
    {}

    CFileInfo(std::string strName, bool bDir, int64_t nSize, std::string strModified, std::string strIcon, std::string strMask, std::string strGguestMask) :
        m_strName(strName), m_bDir(bDir), m_nSize(nSize), m_strModified(strModified), m_strIcon(strIcon), m_strMask(strMask), m_strGguestMask(strGguestMask)
    {
    }

    CFileInfo(const CFileInfo& oFileInfo)
    {
        *this = oFileInfo;
    }

    CFileInfo(CFileInfo&& oFileInfo)
    {
        *this = std::move(oFileInfo);
    }
    CFileInfo& operator=(const CFileInfo& oFileInfo)
    {
        m_strName = oFileInfo.m_strName;
        m_bDir = oFileInfo.m_bDir;
        m_nSize = oFileInfo.m_nSize;
        m_strModified = oFileInfo.m_strModified;
        m_strIcon = oFileInfo.m_strIcon;
        m_strMask = oFileInfo.m_strMask;
        m_strGguestMask = oFileInfo.m_strGguestMask;

        return *this;
    }

    CFileInfo& operator=(CFileInfo&& oFileInfo)
    {
        std::swap(m_strName, oFileInfo.m_strName);
        std::swap(m_bDir, oFileInfo.m_bDir);
        std::swap(m_nSize, oFileInfo.m_nSize);
        std::swap(m_strModified, oFileInfo.m_strModified);
        std::swap(m_strIcon, oFileInfo.m_strIcon);
        std::swap(m_strMask, oFileInfo.m_strMask);
        std::swap(m_strGguestMask, oFileInfo.m_strGguestMask);

        return *this;
    }

    ~CFileInfo(){};


    std::string m_strName;       // 文件名
    bool m_bDir;                 // 是否是目录
    int64_t m_nSize;             // 文件大小
    std::string m_strModified;   // 修改时间
    std::string m_strIcon;       // 某些文件的缩略图
    std::string m_strMask;       // 当前用户的访问权限 
    std::string m_strGguestMask; // 匿名用户的访问权限 
};

#endif // 