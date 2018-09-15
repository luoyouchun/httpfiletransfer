#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HttpFile.h"

class HttpFile : public QMainWindow
{
    Q_OBJECT

public:
    HttpFile(QWidget *parent = Q_NULLPTR);

private:
    Ui::HttpFileClass ui;
};
