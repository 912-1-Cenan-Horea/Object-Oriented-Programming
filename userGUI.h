//
// Created by admin on 09/05/2021.
//

#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "service.h"
#include "repoCsvHtml.h"
#include <QRadioButton>

class userGUI : public QWidget {
Q_OBJECT
public:
    userGUI(service &s, QWidget *parent = 0);


private:
    service &serv;
    int size;
    int current;
    int total;
    repoCsvHtml *shoppingList;
    repo<Coat> *v;


    void init_gui();

    void get_size();

    void connectSignalsAndSlots();

    QLabel *current_coat;
    QWidget *prompt;
    QPushButton *buy_button;
    QPushButton *skip_button;
    QPushButton *display_button;
    QPushButton *enter_size_button;
    QRadioButton *csv;
    QRadioButton *html;
    QLabel *cost_label;

    QLineEdit *sizeTextBox;

    void size_update();

    void coatBought();

    void coatUpdateSlot();

    void coatSkippedHandler();

signals:

    void coatUpdateSignal();

    void endProgramSignal();

public slots:

    void endProgramSlot();

    void displaySlot();

};


