/*---------------------------------------------------------------------------------
* Copyright(C),2018
* FileName:  httpserver.h定义
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


#ifndef _CHTTP_SERVER_H_
#define _CHTTP_SERVER_H_

#pragma once
#include "utils.h"
#include <string>
#include <atomic>
#include <windows.h>

#include <functional>
#include <thread>
#include <future>

class CHttpServer
{
public:
    CHttpServer();
    CHttpServer(const std::wstring& strPath, uint16_t nPort);
    ~CHttpServer();

    void SetPara(const std::wstring& strPath, uint16_t nPort);

    /// <summary>
    /// 启动HTTP服务，相关参数需要在构造或者调用设置函数设置
    /// </summary>
    /// <returns></returns>
    bool Star();

    bool Stop();

    /// <summary>
    /// 将结果
    /// </summary>
    /// <returns></returns>
    std::string GetOutputText();

    /// <summary>
    /// chfs运行后，用于捕获程序运行的输出
    /// </summary>
    void run();

private:
    HandleHolder<HANDLE> m_hPipeRead;

    std::wstring m_strPath;      // 提供HTTP服务的本地路径
    uint16_t m_nPort;            // 监控的端口

    std::atomic<bool> m_bStart;
    HANDLE  m_hProcess;          // 保存打开的进程的句柄    

    std::mutex m_mutex;         // 输出结果获取信息
    std::string m_strOutput;    // 程序运行后的输出
    std::future<void> m_exit_future;   // 用于等待获取输出结果的异步线程能够正常退出   
};

#endif