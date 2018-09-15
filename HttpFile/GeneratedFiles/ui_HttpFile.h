/********************************************************************************
** Form generated from reading UI file 'HttpFile.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HTTPFILE_H
#define UI_HTTPFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HttpFileClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HttpFileClass)
    {
        if (HttpFileClass->objectName().isEmpty())
            HttpFileClass->setObjectName(QStringLiteral("HttpFileClass"));
        HttpFileClass->resize(600, 400);
        menuBar = new QMenuBar(HttpFileClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        HttpFileClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HttpFileClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HttpFileClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(HttpFileClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        HttpFileClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HttpFileClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HttpFileClass->setStatusBar(statusBar);

        retranslateUi(HttpFileClass);

        QMetaObject::connectSlotsByName(HttpFileClass);
    } // setupUi

    void retranslateUi(QMainWindow *HttpFileClass)
    {
        HttpFileClass->setWindowTitle(QApplication::translate("HttpFileClass", "HttpFile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HttpFileClass: public Ui_HttpFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HTTPFILE_H
