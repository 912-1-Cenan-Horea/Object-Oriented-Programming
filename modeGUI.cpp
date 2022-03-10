//
// Created by admin on 10/05/2021.
//

#include "modeGUI.h"
#include <QHBoxLayout>
#include <QLabel>

modeGUI::modeGUI(QWidget *parent) : QWidget(parent) {
    QHBoxLayout *layout = new QHBoxLayout{this};
    QLabel *prompt = new QLabel{"Select mode:"};

    QFont f{"Verdana", 30};
    prompt->setFont(f);
    layout->addWidget(prompt);

    this->admin_mode = new QPushButton{"Admin"};
    this->user_mode = new QPushButton{"User"};

    this->admin_mode->setFont(f);
    this->user_mode->setFont(f);

    layout->addWidget(this->admin_mode);
    layout->addWidget(this->user_mode);


}
