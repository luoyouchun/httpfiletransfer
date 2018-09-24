/*---------------------------------------------------------------------------------
* Copyright(C),2018
* FileName:  JsonParser.h
* Author:    luoyouchun
* Version:   1.0
* Date:      2018-9-24
* Description:  基于rapidjson实现的json字符串解析
                std::string 字符串统一使用UTF-8编码
                std::wstring 转码后的宽字符
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
/// 基于rapidjson，准备构架基础解析类，为后续构造基础类库做准备
/// </summary>
class CJsonParser
{
public:
    CJsonParser();
    ~CJsonParser();

    bool ParserFiles(const std::string& strJson, std::list<CFileInfo>& lstFiles);
private:
    bool Parse(const std::string& strJson);
    rapidjson::Document m_docJosn;           // Json解析Dom树

    /// <summary>
    /// 获取对应节点的Item的值，没有经过转码，通常是UTF8编码
    /// </summary>
    /// <param name="value">需要获取值的节点</param>
    /// <param name="strName">待获取节点的名称</param>
    /// <returns>节点的值，没有找到，或者失败时，返回空字符串</returns>
    std::string getString(const rapidjson::Value& value, std::string strName);
    bool getBool(const rapidjson::Value& value, std::string strName);
    int64_t getInt64(const rapidjson::Value& value, std::string strName);
};


#endif // _JSON_PARSER_H_

