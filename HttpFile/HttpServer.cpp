/*---------------------------------------------------------------------------------
* Copyright(C),2018
* FileName:  httpserver.cpp实现
* Author:    luoyouchun
* Version:   1.0
* Date:      2018-9-15
* Description:  对chfs进行封装，启动后启动chfs服务，由chfs来提供服务
                对chfs整个生命周期进行管理
*---------------------------------------------------------------------------------
* Modification Histroy
Date    Author      Modification:
*
*---------------------------------------------------------------------------------*/


#include "HttpServer.h"
#include "utils.h"
#include "system.h"

#define  PIPE_INPUT_BUFFER_SIZE    4096


CHttpServer::CHttpServer(const std::wstring& strPath, uint16_t nPort)
    :m_strPath(strPath), m_nPort(nPort), m_bStart(false), m_hProcess(NULL), m_hPipeRead(nullptr)
{

}


CHttpServer::CHttpServer(): m_strPath(L""), m_nPort(0), m_bStart(false), m_hProcess(NULL), m_hPipeRead(nullptr)
{

}

CHttpServer::~CHttpServer()
{
    if (m_bStart)
    {
        Stop();
    }
}

void CHttpServer::SetPara(const std::wstring& strPath, uint16_t nPort)
{
    m_strPath = strPath;
    m_nPort = nPort;
}

bool CHttpServer::Star()
{
    if (m_bStart)
    {
        Stop();
    }

    // 检查参数
    if (m_strPath.length() == 0)
    {
        m_strPath = lpp::GetCurrentPath();
    }

    if (0 == m_nPort)
    {
        m_nPort = 3129;
    }

    bool bRtn = false;
    m_strOutput = "";

    // 准备参数
    std::wstring strCommond;
    strCommond = lpp::GetCurrentPath();
    strCommond += L"\\chfs.exe";

    strCommond += L" --path=";
    strCommond += m_strPath;

    strCommond += L" --port=";
    strCommond += std::to_wstring(m_nPort);

    // 创建匿名管道
    SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
    
    HANDLE hWrite = INVALID_HANDLE_VALUE;
    HANDLE hRead = INVALID_HANDLE_VALUE;

    if (!CreatePipe(&hRead, &hWrite, &sa, 0))
    {
        return bRtn;
    }
    else
    {
        m_hPipeRead.setValue(hRead);
    }

    // 设置命令行进程启动信息(以隐藏方式启动命令并定位其输出到hWrite
    STARTUPINFO si = { sizeof(STARTUPINFOA) };
    PROCESS_INFORMATION pi;
    GetStartupInfo(&si);
    si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
    si.wShowWindow = SW_HIDE;
    si.hStdError = hWrite;
    si.hStdOutput = hWrite;

    // 启动命令行        
    if (CreateProcess(NULL, (LPTSTR)strCommond.c_str(), NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
    {
        // 等待调用完成，释放句柄       
        HandleHolder<HANDLE> hThread(pi.hThread);
        HandleHolder<HANDLE> hPipeWrite(hWrite);

        // 等待执行完成
        DWORD dwCode = WaitForSingleObject(pi.hProcess, 1000);
        if (dwCode == WAIT_TIMEOUT)
        {
            // 超时了，说明了程序已跑起来了
            m_hProcess = (void *)pi.hProcess;
            m_bStart = true;
            bRtn = true;
        }
        else
        {
            CloseHandle(pi.hProcess);
            m_bStart = false;
        }

        // 启动一个异步的线程，用于读取进程输出
        m_exit_future = std::move(std::async(std::launch::async, [this]
        {
            this->run();
        }));
    }

    return bRtn;
}


bool CHttpServer::Stop()
{
    if (m_hProcess)
    {
        TerminateProcess(m_hProcess, 0);
        CloseHandle(m_hProcess);
    }

    m_hProcess = NULL;
    m_bStart = false;

    if (m_exit_future.valid())
    {
        m_exit_future.get();
    }

    return true;
}

std::string CHttpServer::GetOutputText()
{
    std::lock_guard<std::mutex> lk(m_mutex);
    return std::move(m_strOutput);
}

void CHttpServer::run()
{
    char szBuffer[PIPE_INPUT_BUFFER_SIZE + 1] = { 0 };
    DWORD dwBytesRead = 0;
    DWORD dwAllBytesRead = 0;

    while (ReadFile(this->m_hPipeRead.get(), szBuffer, PIPE_INPUT_BUFFER_SIZE, &dwBytesRead, NULL))
    {
        if (dwBytesRead > 0)
        {
            std::lock_guard<std::mutex> lk(m_mutex);
            m_strOutput += szBuffer;
            dwAllBytesRead += dwBytesRead;
        }
        else
        {
            break;
        }

        memset(szBuffer, 0, PIPE_INPUT_BUFFER_SIZE + 1);
    }
}
