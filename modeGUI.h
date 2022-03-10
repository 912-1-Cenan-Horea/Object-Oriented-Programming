//
// Created by admin on 10/05/2021.
//

#pragma once
#include <QPushButton>
class modeGUI : public QWidget{
public:
    explicit modeGUI(QWidget *parent=0);

public:
    QPushButton* admin_mode;
    QPushButton* user_mode;
};



