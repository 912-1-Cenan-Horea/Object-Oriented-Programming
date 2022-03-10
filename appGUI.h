//
// Created by admin on 16/05/2021.
//
#pragma once
#include <QObject>
#include <QWidget>
#include "modeGUI.h"
#include "adminGUI.h"
#include "userGUI.h"
#include "service.h"
class appGUI : public QWidget {
Q_OBJECT
public:
    appGUI(service& s);
    void connectSignalsAndSlots();

    void adminModeHandler();
    void userModeHandler();

private:
    modeGUI* mode;
    QWidget* main_window;
    service& serv;

};


