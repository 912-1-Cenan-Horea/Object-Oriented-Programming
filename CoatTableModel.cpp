//
// Created by admin on 17/05/2021.
//
#pragma once
#include <QFont>
#include "CoatTableModel.h"
#include <QBrush>
CoatTableModel::CoatTableModel(service &s, QObject *parent) : QAbstractTableModel(parent), serv(s) {

}

int CoatTableModel::rowCount(const QModelIndex &parent) const {
    int coatNumbers = this->serv.Lenght();
    return coatNumbers + 1;
}

int CoatTableModel::columnCount(const QModelIndex &parent) const {
    return 5;
}

QVariant CoatTableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    repo<Coat> r = this->serv.list();
    if (row == r.Lenght())
    {
        return QVariant();
    }
    Coat c = r[row];
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (column)
        {
            case 0:
                return QString::fromStdString(std::to_string(c.get_size()));
            case 1:
                return QString::fromStdString(c.get_colour());
            case 2:
                return QString::fromStdString(std::to_string(c.get_price()));
            case 3:
                return QString::fromStdString(std::to_string(c.get_quantity()));
            case 4:
                return QString::fromStdString(c.get_link());
            default:
                break;
        }
    }

    if (role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setItalic(false);
        return font;
    }
    if (role == Qt::BackgroundRole)
    {
        if (row % 2 == 1)
        {
            return QBrush{ QColor{0, 250, 154} };
        }
    }

    return QVariant{};

}

QVariant CoatTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
                case 0:
                    return QString{ "Coat size" };
                case 1:
                    return QString{ "Coat colour" };
                case 2:
                    return QString{ "Coat price" };
                case 3:
                    return QString{ "Coat Quantity" };
                case 4:
                    return QString{ "Coat link" };
                default:
                    break;
            }
        }
    }
    if (role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

bool CoatTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    // set the new data to the gene
    int geneIndex = index.row();

    // get the genes
    repo<Coat> r = this->serv.list();

    // Allow adding in the table
    //if the index is >= number of genes => a new gene is added
    if (geneIndex == r.Lenght())
    {
        this->beginInsertRows(QModelIndex{}, geneIndex, geneIndex);

        switch (index.column())
        {
            case 0:
                this->serv.Add(value.toInt(),"",0,0,"");
                break;
            case 1:

                this->serv.Add(0, const_cast<char *>(value.toString().toStdString().c_str()), 0, 0, "");
                break;
            case 2:
                this->serv.Add(0,"",value.toInt(),0,"");
                break;
            case 3:
                this->serv.Add(0,"",0,value.toInt(),"");
                break;
            case 4:
                this->serv.Add(0,"",0,0,const_cast<char *>(value.toString().toStdString().c_str()));
                break;
        }

        this->endInsertRows();
        return true;
    }
    Coat c = r[geneIndex];

    switch (index.column())
    {
        case 0:
            r[geneIndex].set_size(value.toInt());
            break;
        case 1:
            r[geneIndex].set_colour(value.toString().toStdString());
            break;
        case 2:
            r[geneIndex].set_price(value.toInt());
        case 3:
            r[geneIndex].set_quantity(value.toInt());
        case 4:
            r[geneIndex].set_link(value.toString().toStdString());
    }
    char colour[100];
    char link[100];
    char new_colour[100];
    char new_link[100];
    strcpy(colour,c.get_colour().c_str());
    strcpy(link,c.get_link().c_str());
    strcpy(new_colour,r[geneIndex].get_colour().c_str());
    strcpy(new_link,r[geneIndex].get_link().c_str());
    this->serv.Update(c.get_size(), colour, c.get_price(), c.get_quantity(), link, r[geneIndex].get_size(), new_colour, r[geneIndex].get_price(), r[geneIndex].get_quantity(), new_link);


    // emit the dataChanged signal
    emit dataChanged(index, index);

    return true;
}

Qt::ItemFlags CoatTableModel::flags(const QModelIndex &index) const {

    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
};
