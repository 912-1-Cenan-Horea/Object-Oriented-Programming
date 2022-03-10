//
// Created by cenan on 3/20/2021.
//
#pragma once

#include <string>
#include "domain.h"
#include <cstring>
#include <utility>
#include <vector>
#include <sstream>

Coat::Coat(int size, char *colour, int price, int quantity, char *link) {
    this->link = std::string(link);
    this->colour = std::string(colour);
    this->size = size;
    this->price = price;
    this->quantity = quantity;

}

std::string Coat::to_Str() const {
    std::string str;
    str += "Size: ";
    str += std::to_string(this->size) + "\n";
    str += "Colour: ";
    str += this->colour;
    str += "\nPrice: " + std::to_string(this->price) + "\nQuantity: " + std::to_string(this->quantity) + "\n";
    str += this->link;
    str += "\n";

    return str;
}


void Coat::set_size(int new_size) {
    if (new_size < 0)
        throw "Size cant be negative";
    this->size = new_size;
}

bool Coat::operator==(Coat other) {
    if (this->size != other.get_size() || this->colour != other.get_colour())
        return false;
    return true;
}

std::string Coat::get_colour() const {
    return this->colour;
}

void Coat::set_colour(std::string new_colour) {
    this->colour = std::move(new_colour);
}

void Coat::set_link(std::string new_link) {
    // if (strcmp(new_link, "") == 0)
    //    throw "Link cant be null!\n";

    this->link = std::move(new_link);
}

int Coat::get_quantity() const {
    return this->quantity;
}

void Coat::set_quantity(int new_quantity) {
    if (new_quantity < 0)
        throw "Invalid quantity!\n";
    this->quantity = new_quantity;
}

int Coat::get_price() const {
    return this->price;
}

void Coat::set_price(int new_price) {
    if (new_price < 1)
        throw "Price cant be <=0!\n";
    this->price = new_price;
}

std::string Coat::get_link() const {
    return this->link;
}


Coat::Coat() {
    this->size = -1;
    this->link = std::string("");
    this->colour = std::string("");
    this->price = -1;
    this->quantity = -1;
}

int Coat::get_size() const {
    return this->size;
}

Coat::Coat(const Coat &other) {
    this->size = other.get_size();
    this->set_colour(other.get_colour());
    this->set_link(other.get_link());
    this->quantity = other.get_quantity();
    this->price = other.get_price();
}

Coat &Coat::operator=(const Coat &other) {
    this->size = other.get_size();
    this->set_link(other.get_link());
    this->set_colour(other.get_colour());
    this->quantity = other.get_quantity();
    this->price = other.get_price();
    return *this;
}

std::ostream &operator<<(std::ostream &stream, Coat &a) {
    stream << a.colour << ',' << a.size << ',' << a.price << ',' << a.quantity << ',' << a.link << '\n';
    return stream;
}

std::vector<std::string> tokenize(std::string str, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);
    return result;
}

std::istream &operator>>(std::istream &is, Coat &a) {

    std::string line;
    getline(is, line);
    std::vector<std::string> tokens = tokenize(line, ',');
    if (tokens.size() != 5)
        return is;
    a.colour = tokens[0];
    a.size = stoi(tokens[1]);
    a.price = stoi(tokens[2]);
    a.quantity = stoi(tokens[3]);
    a.link = tokens[4];

    return is;
}


Coat::~Coat() = default;



