#include "JsonParser.h"
#include "CFileInfo.hpp"


CJsonParser::CJsonParser()
{
}


CJsonParser::~CJsonParser()
{
}

bool CJsonParser::Parse(const std::string& strJson)
{
    m_docJosn.Parse(strJson.c_str());

    return !m_docJosn.HasParseError();
}
