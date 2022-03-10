//
// Created by admin on 05/05/2021.
//

#pragma once

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include "adminGUI.h"
#include "CoatTableModel.h"

adminGUI::adminGUI(service &_serv, QWidget *parent) : QWidget(parent), serv(_serv) {
    this->initGUI();
    this->connectSignalsAndSlots();
    this->populate_list();
}

void adminGUI::initGUI() {
    QHBoxLayout *layout = new QHBoxLayout{this};
    layout->setAlignment(Qt::AlignCenter);
    QFont f{"Verdana", 15};
    this->coatList = new QListWidget{};
    //this->coatList = new CoatTableModel{this->serv};

    /// List of coats

    this->coatList->setSelectionMode(QAbstractItemView::SingleSelection);
    this->coatList->setBatchSize(1);


    QWidget *coatDetailsWidget = new QWidget{};
    /// Form with QLineEdit


    QFormLayout *formLayout = new QFormLayout{coatDetailsWidget};


    QLabel *size = new QLabel{"&Size:"};
    size->setFont(f);
    this->textBoxSize = new QLineEdit{};
    size->setBuddy(textBoxSize);
    formLayout->addRow(size, textBoxSize);


    QLabel *colour = new QLabel{"&Colour:"};
    colour->setFont(f);
    this->textBoxColour = new QLineEdit{};
    colour->setBuddy(textBoxColour);
    formLayout->addRow(colour, textBoxColour);

    QLabel *price = new QLabel{"&Price:"};
    this->textBoxPrice = new QLineEdit{};
    price->setFont(f);
    price->setBuddy(textBoxPrice);
    formLayout->addRow(price, textBoxPrice);

    QLabel *quantity = new QLabel{"&Quantity:"};
    this->textBoxQuantity = new QLineEdit{};
    quantity->setBuddy(textBoxQuantity);
    quantity->setFont(f);
    formLayout->addRow(quantity, textBoxQuantity);

    QLabel *link = new QLabel{"&Link:"};
    this->textBoxLink = new QLineEdit{};
    link->setFont(f);
    quantity->setBuddy(textBoxLink);
    formLayout->addRow(link, textBoxLink);
    formLayout->setAlignment(Qt::AlignCenter);


    QWidget *buttonsWidget = new QWidget{};
    ///buttons


    QVBoxLayout *vLayout = new QVBoxLayout{buttonsWidget};
    this->add_coat = new QPushButton{"Add coat"};
    this->add_coat->setFont(f);
    this->delete_coat = new QPushButton{"Delete coat"};
    this->delete_coat->setFont(f);
    this->update_coat = new QPushButton{"Update coat"};
    this->update_coat->setFont(f);
    vLayout->addWidget(this->add_coat);
    vLayout->addWidget(this->delete_coat);
    vLayout->addWidget(this->update_coat);
    vLayout->setAlignment(Qt::AlignCenter);


    layout->addWidget(this->coatList);
    layout->addWidget(coatDetailsWidget);
    layout->addWidget(buttonsWidget);
}

void adminGUI::populate_list() {
    if (this->coatList->count() > 0)
        this->coatList->clear();
    for (auto c : this->serv.list()) {
        QString itemInList = QString::fromStdString(c.to_Str());
        QFont f{"Verdana", 15};
        QListWidgetItem *item = new QListWidgetItem{itemInList};
        item->setFont(f);
        this->coatList->addItem(item);
    }

}

int adminGUI::getSelectedIndex() {
    if (this->coatList->count() == 0)
        return -1;

    // get selected index
    QModelIndexList index = this->coatList->selectionModel()->selectedIndexes();
    if (index.size() == 0) {
        this->textBoxSize->clear();
        this->textBoxColour->clear();
        this->textBoxQuantity->clear();
        this->textBoxPrice->clear();
        this->textBoxLink->clear();
        return -1;
    }

    int idx = index.at(0).row();
    return idx;
}

void adminGUI::connectSignalsAndSlots() {
    QObject::connect(this, &adminGUI::coatUpdatedSignal, this, [this]() { this->populate_list(); });
    QObject::connect(this->coatList, &QListWidget::itemSelectionChanged, this, [this]() { this->listItemChanged(); });

    ///Add button connection
    QObject::connect(this->add_coat,&QPushButton::clicked,this,[this](){this->AddCoatButtonHandler();});
    QObject::connect(this->delete_coat,&QPushButton::clicked,this,[this](){this->DeleteCoatButtonHandler();});
    QObject::connect(this->update_coat,&QPushButton::clicked,this,[this](){this->UpdateCoatButtonHandler();});


}

void adminGUI::listItemChanged() {
    int idx = this->getSelectedIndex();
    if (idx == -1)
        return;

    // get the coat at the selected index
    if (idx >= this->serv.Lenght())
        return;
    Coat c = this->serv.list()[idx];
    this->textBoxSize->setText(QString::fromStdString(std::to_string(c.get_size())));
    this->textBoxPrice->setText(QString::fromStdString(std::to_string(c.get_price())));
    this->textBoxQuantity->setText(QString::fromStdString(std::to_string(c.get_quantity())));
    this->textBoxLink->setText(QString::fromStdString(c.get_link()));
    this->textBoxColour->setText(QString::fromStdString(c.get_colour()));

}

void adminGUI::AddCoatButtonHandler() {
    int size=-1;
    size = this->textBoxSize->text().toInt();
    int price=-1;
    price= this->textBoxPrice->text().toInt();
    char* link = new char[100];
    char* co = new char[100];
    int quantity=-1;
    quantity=this->textBoxQuantity->text().toInt();
    strcpy(link,this->textBoxLink->text().toStdString().c_str());
    strcpy(co,this->textBoxColour->text().toStdString().c_str());
    this->serv.Add(size,co,price,quantity,link);
    emit coatUpdatedSignal();
}

void adminGUI::DeleteCoatButtonHandler() {
    int size=-1;
    size = this->textBoxSize->text().toInt();
    int price=-1;
    price= this->textBoxPrice->text().toInt();
    char* link = new char[100];
    char* co = new char[100];
    int quantity=-1;
    quantity=this->textBoxQuantity->text().toInt();
    strcpy(link,this->textBoxLink->text().toStdString().c_str());
    strcpy(co,this->textBoxColour->text().toStdString().c_str());
    this->serv.Delete(size,co);
    emit coatUpdatedSignal();
}

void adminGUI::UpdateCoatButtonHandler() {
    int size=-1;
    size = this->textBoxSize->text().toInt();
    int price=-1;
    price= this->textBoxPrice->text().toInt();
    char* link = new char[100];
    char* co = new char[100];
    int quantity=-1;
    quantity=this->textBoxQuantity->text().toInt();
    strcpy(link,this->textBoxLink->text().toStdString().c_str());
    strcpy(co,this->textBoxColour->text().toStdString().c_str());

    this->serv.Update(size,co,price,quantity,link,size,co,price,quantity,link);
    emit coatUpdatedSignal();
}


