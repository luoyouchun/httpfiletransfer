/**********************************************************************
* Copyright (c) 2013-2014  Red Hat, Inc.
*
* Developed by Daynix Computing LTD.
*
* Authors:
*     Dmitry Fleytman <dmitry@daynix.com>
*     Pavel Gurvich <pavel@daynix.com>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
**********************************************************************/

#include "tstrings.h"
#include <memory>
#include <stdio.h>
#include <locale>
#include <codecvt>
#include "assert.h"


const string __wstring2string(const wstring& src)
{
    std::wstring_convert<std::codecvt<wchar_t, char, std::mbstate_t>>
        cvt_ansi(new std::codecvt<wchar_t, char, std::mbstate_t>("CHS"));
    return cvt_ansi.to_bytes(src);
}


const wstring __string2wstring(const string& src)
{
    std::wstring_convert<std::codecvt<wchar_t, char, std::mbstate_t>>
        cvt_ansi(new std::codecvt<wchar_t, char, std::mbstate_t>("CHS"));
    return cvt_ansi.from_bytes(src);


}
//const string __wstring2string(const wstring& src)
//{
//    std::locale sys_locale("");
//
//    const wchar_t* data_from = src.c_str();
//    const wchar_t* data_from_end = src.c_str() + src.size();
//    const wchar_t* data_from_next = 0;
//
//    int wchar_size = 4;
//    char* data_to = new char[(src.size() + 1) * wchar_size];
//    char* data_to_end = data_to + (src.size() + 1) * wchar_size;
//    char* data_to_next = 0;
//
//    memset(data_to, 0, (src.size() + 1) * wchar_size);
//
//    typedef std::codecvt<wchar_t, char, mbstate_t> convert_facet;
//    mbstate_t out_state = 0;
//    auto result = std::use_facet<convert_facet>(sys_locale).out(
//        out_state, data_from, data_from_end, data_from_next,
//        data_to, data_to_end, data_to_next);
//    if (result == convert_facet::ok)
//    {
//        std::string dst = data_to;
//        delete[] data_to;
//        return dst;
//    }
//    else
//    {
//        //printf("convert error!\n");
//        delete[] data_to;
//        return std::string("");
//    }
//
//}

//const wstring __string2wstring(const string& src)
//{
//    std::locale sys_locale("");
//
//    const char* data_from = src.c_str();
//    const char* data_from_end = src.c_str() + src.size();
//    const char* data_from_next = 0;
//
//    wchar_t* data_to = new wchar_t[src.size() + 1];
//    wchar_t* data_to_end = data_to + src.size() + 1;
//    wchar_t* data_to_next = 0;
//
//    wmemset(data_to, 0, src.size() + 1);
//
//    typedef std::codecvt<wchar_t, char, mbstate_t> convert_facet;
//    mbstate_t in_state = 0;
//    auto result = std::use_facet<convert_facet>(sys_locale).in(
//        in_state, data_from, data_from_end, data_from_next,
//        data_to, data_to_end, data_to_next);
//    if (result == convert_facet::ok)
//    {
//        std::wstring dst = data_to;
//        delete[] data_to;
//        return dst;
//    }
//    else
//    {
//        printf("convert error!\n");
//        delete[] data_to;
//        return std::wstring(L"");
//    }
//}

const std::string ws2utf8(const std::wstring& src)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    return conv.to_bytes(src);
}

const std::wstring utf8_2_ws(const std::string& src)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t> > conv;
    return conv.from_bytes(src);
}

unsigned char ToHex(unsigned char x)
{
    return  x > 9 ? x + 55 : x + 48;
}

unsigned char FromHex(unsigned char x)
{
    unsigned char y;
    if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
    else if (x >= '0' && x <= '9') y = x - '0';
    else assert(0);
    return y;
}

std::string UrlEncode(const std::string& str)
{
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (isalnum((unsigned char)str[i]) ||
            (str[i] == '-') ||
            (str[i] == '_') ||
            (str[i] == '.') ||
            (str[i] == '~'))
            strTemp += str[i];
        else if (str[i] == ' ')
            strTemp += "%20";
        else
        {
            strTemp += '%';
            strTemp += ToHex((unsigned char)str[i] >> 4);
            strTemp += ToHex((unsigned char)str[i] % 16);
        }
    }
    return strTemp;
}

std::string UrlDecode(const std::string& str)
{
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == '+') strTemp += ' ';
        else if (str[i] == '%')
        {
            assert(i + 2 < length);
            unsigned char high = FromHex((unsigned char)str[++i]);
            unsigned char low = FromHex((unsigned char)str[++i]);
            strTemp += high * 16 + low;
        }
        else strTemp += str[i];
    }
    return strTemp;
}