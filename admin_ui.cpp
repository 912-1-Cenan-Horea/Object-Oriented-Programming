//
// Created by admin on 17/04/2021.
//

#include "admin_ui.h"



void admin_ui::print_menu() {
    std::cout << "\n1.Add a new coat\n2.Delete a coat\n3.Update a coat\n4.List all coats\n";
}


int admin_ui::get_option() {
    int option = 5;
    std::cout << "Enter option: ";
    std::cin >> option;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    return option;
}



void admin_ui::Add() {
    int size;
    char *colour = new char[100];
    char *link = new char[100];
    int price;
    int quantity;

    std::cout << "Enter coat size: ";
    std::cin >> size;

    std::cout << "Enter coat colour: ";
    std::cin >> colour;

    std::cout << "Enter coat price: ";
    std::cin >> price;

    std::cout << "Enter coat  quantity: ";
    std::cin >> quantity;

    std::cout << "Enter coat  photography link: ";
    std::cin >> link;
    this->serv.Add(size, colour, price, quantity, link);

}

void admin_ui::Show_all() {
    for (auto i : this->serv.list()) {
        std::cout << i.to_Str();
        std::cout << "\n----------------------------------------------------------------------------------------\n";
    }


}


void admin_ui::Delete() {
    int size;
    char *colour = new char[100];

    std::cout << "Enter coat size: ";
    std::cin >> size;

    std::cout << "Enter coat colour: ";
    std::cin >> colour;

    this->serv.Delete(size, colour);
}


void admin_ui::Update() {
    int size, new_size;
    char *colour = new char[100];
    char *new_colour = new char[100];
    char *link = new char[100];
    char *new_link = new char[100];
    int price, new_price;
    int quantity, new_quantity;
    std::cout << "Enter coat size: ";
    std::cin >> size;

    std::cout << "Enter coat colour: ";
    std::cin >> colour;

    std::cout << "Enter coat price: ";
    std::cin >> price;

    std::cout << "Enter coat  quantity: ";
    std::cin >> quantity;

    std::cout << "Enter coat  photography link: ";
    std::cin >> link;

    ///
    std::cout << "Enter new coat size: ";
    std::cin >> new_size;

    std::cout << "Enter new coat colour: ";
    std::cin >> new_colour;

    std::cout << "Enter new coat price: ";
    std::cin >> new_price;

    std::cout << "Enter new coat  quantity: ";
    std::cin >> new_quantity;

    std::cout << "Enter new coat  photography link: ";
    std::cin >> new_link;

    this->serv.Update(size, colour, price, quantity, link, new_size, new_colour, new_price, new_quantity, new_link);

}
