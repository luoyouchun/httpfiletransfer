/*---------------------------------------------------------------------------------
* Copyright(C),2018
* FileName:  JsonParser.cpp
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


#include "JsonParser.h"
#include "CFileInfo.hpp"


CJsonParser::CJsonParser()
{
}


CJsonParser::~CJsonParser()
{
}

bool CJsonParser::ParserFiles(const std::string& strJson, std::list<CFileInfo>& lstFiles)
{
    bool bResult = false;

    bResult = Parse(strJson);
    if (!bResult)
    {
        return bResult;
    }

    rapidjson::Value& vRoot = m_docJosn["files"];
    if (vRoot.IsArray())
    {
        for (rapidjson::SizeType i = 0; i < vRoot.Size(); i++)
        {
            CFileInfo stFileItem;
            const rapidjson::Value& vItem = vRoot[i];
            stFileItem.m_strName = getString(vItem, "name");
            stFileItem.m_bDir = getBool(vItem, "dir");
            stFileItem.m_bDir = getInt64(vItem, "size");

            lstFiles.emplace_back(std::move(stFileItem));
        }
    }

    bResult = true;

    return bResult;
}

bool CJsonParser::Parse(const std::string& strJson)
{
    m_docJosn.Parse(strJson.c_str());

    return !m_docJosn.HasParseError();
}

std::string CJsonParser::getString(const rapidjson::Value & value, std::string strName)
{
    std::string strValue;

    if (value.HasMember(strName.c_str()) && value[strName.c_str()].IsString())
    {
        strValue = value[strName.c_str()].GetString();
    }

    return std::move(strValue);
}

bool CJsonParser::getBool(const rapidjson::Value& value, std::string strName)
{
    bool bResult = false;

    if (value.HasMember(strName.c_str()) && value[strName.c_str()].IsBool())
    {
        bResult = value[strName.c_str()].GetBool();
    }

    return bResult; 
}

int64_t CJsonParser::getInt64(const rapidjson::Value& value, std::string strName)
{
    int64_t iValue = 0;

    if (value.HasMember(strName.c_str()) && value[strName.c_str()].IsInt64())
    {
        iValue = value[strName.c_str()].GetInt64();
    }

    return iValue;
}
