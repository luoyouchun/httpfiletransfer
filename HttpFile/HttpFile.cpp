#include <QTimer>
#include "HttpFile.h"

HttpFile::HttpFile(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(update()));

    connect(ui.btnStartHttpServer, SIGNAL(clicked()), this, SLOT(btnHttpServerStartClick()));
    connect(ui.btnStopHttpServer, SIGNAL(clicked()), this, SLOT(btnStopHttpServer()));
}

void HttpFile::btnHttpServerStartClick()
{
    m_oHttpServer.SetPara(L"\"D:\\WD Software Offline Installers\"", 3128);
    bool bStart = m_oHttpServer.Star();

    m_pTimer->start(1000);
}

void HttpFile::btnStopHttpServer()
{
    m_pTimer->stop();
    m_oHttpServer.Stop();
}

void HttpFile::update()
{
    std::string strOutput;
    strOutput = m_oHttpServer.GetOutputText();

    if (strOutput.length())
    {
        ui.txtServerOutput->append(QString::fromStdString(strOutput));
    }
}