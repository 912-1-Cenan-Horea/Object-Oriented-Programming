//
// Created by admin on 05/05/2021.
//

#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include "adminGUI.h"
#include "service.h"
#include "CoatTableModel.h"

class adminGUI : public QWidget {
Q_OBJECT
public:
    explicit adminGUI(service &s, QWidget *parent = 0);

    ~adminGUI() {};

private:
    void initGUI();

    void populate_list();

    void connectSignalsAndSlots();

    int getSelectedIndex();

    void listItemChanged();

    void AddCoatButtonHandler();

    void DeleteCoatButtonHandler();

    void UpdateCoatButtonHandler();

    QListWidget *coatList;

    QLineEdit *textBoxSize;
    QLineEdit *textBoxColour;
    QLineEdit *textBoxPrice;
    QLineEdit *textBoxQuantity;
    QLineEdit *textBoxLink;

    QPushButton *add_coat;
    QPushButton *delete_coat;
    QPushButton *update_coat;
    service& serv;
signals:
    void coatUpdatedSignal();



};


