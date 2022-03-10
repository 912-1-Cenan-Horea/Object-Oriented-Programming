//
// Created by admin on 09/05/2021.
//
#pragma once

#include "userGUI.h"
#include "repoCsv.h"
#include "repoHtml.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QRadioButton>


userGUI::userGUI(service &s, QWidget *parent) : QWidget(parent), serv(s) {
    this->current = 0;
    this->total = 0;
    this->init_gui();
    this->get_size();
    this->connectSignalsAndSlots();

}

void userGUI::init_gui() {
    QHBoxLayout *layout = new QHBoxLayout{this};
    QFont f{"Verdana", 15};

    this->current_coat = new QLabel{};
    this->current_coat->setFont(f);
    // this->current_coat->setMinimumHeight(600);
    //this->current_coat->setMinimumWidth(600);
    this->current_coat->setWordWrap(true);

    this->current_coat->setStyleSheet(
            "QLabel {border: 10px solid gray;border-radius: 20px;background-color: white;padding: 0px 5px 5px 5px;}");

    layout->addWidget(this->current_coat);

    /// Buttons widget
    QWidget *button_widget = new QWidget{};
    QVBoxLayout *button_layout = new QVBoxLayout{button_widget};

    this->buy_button = new QPushButton{"Buy this coat"};
    this->buy_button->setFont(f);
    button_layout->addWidget(this->buy_button);
    this->skip_button = new QPushButton{"Skip coat"};
    this->skip_button->setFont(f);
    button_layout->addWidget(this->skip_button);
    this->display_button = new QPushButton{"Display shopping list"};
    this->display_button->setFont(f);
    button_layout->addWidget(this->display_button);
    this->cost_label = new QLabel{"Yout current cost is: 0"};
    button_layout->addWidget(this->cost_label);
    layout->addWidget(button_widget);


}

void userGUI::get_size() {
    this->prompt = new QWidget{};
    this->prompt->setWindowTitle("Enter size");
    QVBoxLayout *big_layout = new QVBoxLayout{this->prompt};

    QWidget *form_widget = new QWidget{};
    QHBoxLayout *layout = new QHBoxLayout{form_widget};
    QLabel *label = new QLabel{"Enter size(-1 for all sizes): "};
    layout->addWidget(label);
    this->sizeTextBox = new QLineEdit;
    layout->addWidget(this->sizeTextBox);
    this->enter_size_button = new QPushButton{"I have entered my size"};
    layout->addWidget(this->enter_size_button);
    big_layout->addWidget(form_widget);

    QWidget *radio_button = new QWidget{};
    QHBoxLayout *button_layout = new QHBoxLayout{radio_button};
    this->csv = new QRadioButton{"CSV"};

    this->html = new QRadioButton{"Html"};
    button_layout->addWidget(csv);
    this->csv->setChecked(true);
    button_layout->addWidget(html);

    big_layout->addWidget(radio_button);


    this->hide();
    this->prompt->show();
}

void userGUI::connectSignalsAndSlots() {
    QObject::connect(this->enter_size_button, &QPushButton::clicked, this, [this]() { this->size_update(); });
    QObject::connect(this->buy_button, &QPushButton::clicked, this, [this]() { this->coatBought(); });
    QObject::connect(this, &userGUI::coatUpdateSignal, this, [this]() { this->coatUpdateSlot(); });
    QObject::connect(this->skip_button, &QPushButton::clicked, this, [this]() { this->coatSkippedHandler(); });
    QObject::connect(this, &userGUI::endProgramSignal, this, &userGUI::endProgramSlot);
    QObject::connect(this->display_button, &QPushButton::clicked, this, &userGUI::displaySlot);

}

void userGUI::size_update() {
    this->size == -2;
    if (this->sizeTextBox->text().isEmpty())
        return;
    this->size = this->sizeTextBox->text().toInt();
    if (this->size >= -1) {
        this->prompt->hide();
        if (this->csv->isChecked())
            this->shoppingList = new repoCsv;
        else this->shoppingList = new repoHtml;
        this->show();
    }

    this->v = this->serv.filter_by_size(this->size);
    if (this->v->Lenght() == 0)
            emit endProgramSignal();
    this->current_coat->setText(QString::fromStdString(this->v->operator[](0).to_Str()));

}

void userGUI::coatBought() {
    this->total += this->v->operator[](this->current).get_price();
    this->shoppingList->Add(this->v->operator[](this->current));
    this->v->Delete(this->v->operator[](this->current));
    if (this->current == this->v->Lenght())
        this->current = 0;
    if (this->v->Lenght() == 0)
            emit endProgramSignal();
    else emit coatUpdateSignal();

}

void userGUI::coatUpdateSlot() {
    this->current_coat->setText(QString::fromStdString(this->v->operator[](this->current).to_Str()));
    this->cost_label->setText(QString::fromStdString("The total cost is: " + std::to_string(this->total)));
}

void userGUI::coatSkippedHandler() {
    this->current++;

    if (this->current == this->v->Lenght())
        this->current = 0;
    emit coatUpdateSignal();

}

void userGUI::endProgramSlot() {
    this->shoppingList->open();
    exit(0);

}

void userGUI::displaySlot() {
    this->shoppingList->open();
}





