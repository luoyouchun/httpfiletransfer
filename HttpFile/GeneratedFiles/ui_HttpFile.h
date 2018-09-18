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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HttpFileClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labFilePath_2;
    QLineEdit *editHttpPath;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *editServerPort;
    QPushButton *btnStartHttpServer;
    QPushButton *btnStopHttpServer;
    QTextEdit *txtServerOutput;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labFilePath_3;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QLineEdit *lineEdit_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QTextEdit *textEdit;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *HttpFileClass)
    {
        if (HttpFileClass->objectName().isEmpty())
            HttpFileClass->setObjectName(QStringLiteral("HttpFileClass"));
        HttpFileClass->resize(581, 586);
        centralWidget = new QWidget(HttpFileClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 551, 573));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labFilePath_2 = new QLabel(groupBox);
        labFilePath_2->setObjectName(QStringLiteral("labFilePath_2"));
        labFilePath_2->setMinimumSize(QSize(70, 0));

        horizontalLayout_4->addWidget(labFilePath_2);

        editHttpPath = new QLineEdit(groupBox);
        editHttpPath->setObjectName(QStringLiteral("editHttpPath"));

        horizontalLayout_4->addWidget(editHttpPath);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(70, 0));

        horizontalLayout_5->addWidget(label_2);

        editServerPort = new QLineEdit(groupBox);
        editServerPort->setObjectName(QStringLiteral("editServerPort"));

        horizontalLayout_5->addWidget(editServerPort);

        btnStartHttpServer = new QPushButton(groupBox);
        btnStartHttpServer->setObjectName(QStringLiteral("btnStartHttpServer"));

        horizontalLayout_5->addWidget(btnStartHttpServer);

        btnStopHttpServer = new QPushButton(groupBox);
        btnStopHttpServer->setObjectName(QStringLiteral("btnStopHttpServer"));

        horizontalLayout_5->addWidget(btnStopHttpServer);


        verticalLayout->addLayout(horizontalLayout_5);

        txtServerOutput = new QTextEdit(groupBox);
        txtServerOutput->setObjectName(QStringLiteral("txtServerOutput"));
        txtServerOutput->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txtServerOutput->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        txtServerOutput->setLineWrapMode(QTextEdit::NoWrap);
        txtServerOutput->setReadOnly(true);

        verticalLayout->addWidget(txtServerOutput);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        horizontalLayout->addWidget(pushButton_8);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labFilePath_3 = new QLabel(groupBox_2);
        labFilePath_3->setObjectName(QStringLiteral("labFilePath_3"));
        labFilePath_3->setMinimumSize(QSize(70, 0));

        horizontalLayout_6->addWidget(labFilePath_3);

        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        horizontalLayout_6->addWidget(lineEdit_5);

        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMaximumSize(QSize(30, 30));

        horizontalLayout_6->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(70, 0));

        horizontalLayout_7->addWidget(label_3);

        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        horizontalLayout_7->addWidget(lineEdit_6);

        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_7->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_7->addWidget(pushButton_6);


        verticalLayout_2->addLayout(horizontalLayout_7);

        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout_3->addWidget(groupBox_2);

        HttpFileClass->setCentralWidget(centralWidget);

        retranslateUi(HttpFileClass);

        QMetaObject::connectSlotsByName(HttpFileClass);
    } // setupUi

    void retranslateUi(QMainWindow *HttpFileClass)
    {
        HttpFileClass->setWindowTitle(QApplication::translate("HttpFileClass", "HttpFile", nullptr));
        groupBox->setTitle(QApplication::translate("HttpFileClass", "Http File Server\350\256\276\347\275\256", nullptr));
        labFilePath_2->setText(QApplication::translate("HttpFileClass", "\345\205\261\344\272\253\350\267\257\345\276\204\357\274\232", nullptr));
        pushButton_2->setText(QApplication::translate("HttpFileClass", "...", nullptr));
        label_2->setText(QApplication::translate("HttpFileClass", "\347\253\257\345\217\243\357\274\232", nullptr));
        btnStartHttpServer->setText(QApplication::translate("HttpFileClass", "\345\220\257\345\212\250", nullptr));
        btnStopHttpServer->setText(QApplication::translate("HttpFileClass", "\345\201\234\346\255\242", nullptr));
        groupBox_2->setTitle(QApplication::translate("HttpFileClass", "HTTP \345\256\242\346\210\267\347\253\257", nullptr));
        pushButton_7->setText(QApplication::translate("HttpFileClass", "\350\277\236\346\216\245", nullptr));
        pushButton_8->setText(QApplication::translate("HttpFileClass", "\346\226\255\345\274\200", nullptr));
        labFilePath_3->setText(QApplication::translate("HttpFileClass", "\344\270\213\350\275\275\357\274\232", nullptr));
        pushButton_4->setText(QApplication::translate("HttpFileClass", "...", nullptr));
        label_3->setText(QApplication::translate("HttpFileClass", "\344\270\212\344\274\240\357\274\232", nullptr));
        pushButton_5->setText(QApplication::translate("HttpFileClass", "PushButton", nullptr));
        pushButton_6->setText(QApplication::translate("HttpFileClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HttpFileClass: public Ui_HttpFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HTTPFILE_H
