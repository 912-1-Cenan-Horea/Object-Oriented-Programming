//
// Created by admin on 16/05/2021.
//

#include "appGUI.h"

appGUI::appGUI(service &s) : serv(s) {
    this->hide();
    this->mode = new modeGUI{};
    this->mode->show();
    connectSignalsAndSlots();


}

void appGUI::connectSignalsAndSlots() {
    QObject::connect(this->mode->user_mode, &QPushButton::clicked, this, [this]() { this->userModeHandler(); });
    QObject::connect(this->mode->admin_mode, &QPushButton::clicked, this, [this]() { this->adminModeHandler(); });
}

void appGUI::adminModeHandler() {
    this->main_window = new adminGUI{serv};
    this->main_window->show();
    this->mode->close();
}

void appGUI::userModeHandler() {
    this->main_window = new userGUI{serv};
   // this->main_window->show();
    this->mode->close();
}
