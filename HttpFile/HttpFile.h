#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HttpFile.h"
#include "HttpServer.h"

class HttpFile : public QMainWindow
{
    Q_OBJECT

public:
    HttpFile(QWidget *parent = Q_NULLPTR);

private:
    Ui::HttpFileClass ui;

private slots:
    void btnHttpServerStartClick();    // 开启HTTP服务
    void btnStopHttpServer();
    void update();
private:
    CHttpServer m_oHttpServer;
    QTimer *m_pTimer;
};
