/*---------------------------------------------------------------------------------
* Copyright(C),2018
* FileName:  JsonParser.h
* Author:    luoyouchun
* Version:   1.0
* Date:      2018-9-24
* Description:  ����rapidjsonʵ�ֵ�json�ַ�������
                std::string �ַ���ͳһʹ��UTF-8����
                std::wstring ת���Ŀ��ַ�
*---------------------------------------------------------------------------------
* Modification Histroy
Date    Author      Modification:
*
*---------------------------------------------------------------------------------*/

#ifndef _JSON_PARSER_H_
#define _JSON_PARSER_H_

#pragma once

#include <string>
#include <list>
#include "rapidjson/document.h"
#include "CFileInfo.hpp"


/// <summary>
/// ����rapidjson��׼�����ܻ��������࣬Ϊ����������������׼��
/// </summary>
class CJsonParser
{
public:
    CJsonParser();
    ~CJsonParser();

    bool ParserFiles(const std::string& strJson, std::list<CFileInfo>& lstFiles);
private:
    bool Parse(const std::string& strJson);
    rapidjson::Document m_docJosn;           // Json����Dom��

    /// <summary>
    /// ��ȡ��Ӧ�ڵ��Item��ֵ��û�о���ת�룬ͨ����UTF8����
    /// </summary>
    /// <param name="value">��Ҫ��ȡֵ�Ľڵ�</param>
    /// <param name="strName">����ȡ�ڵ������</param>
    /// <returns>�ڵ��ֵ��û���ҵ�������ʧ��ʱ�����ؿ��ַ���</returns>
    std::string getString(const rapidjson::Value& value, std::string strName);
    bool getBool(const rapidjson::Value& value, std::string strName);
    int64_t getInt64(const rapidjson::Value& value, std::string strName);
};


#endif // _JSON_PARSER_H_

