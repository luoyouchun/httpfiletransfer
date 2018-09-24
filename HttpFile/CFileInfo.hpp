
/*---------------------------------------------------------------------------------
* Copyright(C),2018
* FileName:  JsonParser.h
* Author:    luoyouchun
* Version:   1.0
* Date:      2018-9-24
* Description:  chfs��ѯĿ¼�ļ��б�ṹ
                std::string �ַ���ͳһʹ��UTF-8����
                std::wstring ת���Ŀ��ַ�
*---------------------------------------------------------------------------------
* Modification Histroy
Date    Author      Modification:
*
*---------------------------------------------------------------------------------*/


#ifndef _CFILEINFO_H_
#define _CFILEINFO_H_

#pragma once
#include <string>

// UTF8����
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


    std::string m_strName;       // �ļ���
    bool m_bDir;                 // �Ƿ���Ŀ¼
    int64_t m_nSize;             // �ļ���С
    std::string m_strModified;   // �޸�ʱ��
    std::string m_strIcon;       // ĳЩ�ļ�������ͼ
    std::string m_strMask;       // ��ǰ�û��ķ���Ȩ�� 
    std::string m_strGguestMask; // �����û��ķ���Ȩ�� 
};

#endif // 