//
// Created by admin on 26/03/2021.
//

#include "userUi.h"


int userUi::get_size() {
    int size;
    std::cout << "Enter size you are searching for(Enter -1 for all sizez): ";
    std::cin >> size;
    if (size == 0) {
        std::cout << "Invalid size!";
        return 0;
    }
    return size;


}

void userUi::start_display() {
    int size = this->get_size();
    repo<Coat> *r = this->serv.filter_by_size(size);
    int step = 1;
    int total = 0;
    while (step <= r->Lenght()) {

        std::cout << r->operator[](step - 1).to_Str();

        std::string s = this->get_option();
        if (s == "Y") {
            total += r->operator[](step - 1).get_price();
            std::cout << "Your total is: " << total << '\n';
            this->shoppingList->Add(r->operator[](step - 1));
            r->Delete(r->operator[](step - 1));
            step--;
        } else if (s == "finish") {
            this->display_list();
            std::cout << "Your total is: " << total;
            return;
        }
        else if(s == "display")
        {
            this->display_list();
            step--;
        }
        else if (s != "N") {
            std::cout << "Invalid option\n";
            step--;
        }



        step++;
        if (step > r->Lenght())
            step = 1;
    }
    std::cout << "Wow,you bought all our stock! Your total is: " << total;

}

std::string userUi::get_option() {
    std::string s;
    std::cout << "Do you want to buy this coat(Y/N/finish/display)?: ";
    std::cin >> s;
    return s;
}

void userUi::display_list() {
    this->shoppingList->open();
    /*
    for(int i=0;i<this->shoppingList->Lenght();i++)
    {
        std::cout<<this->shoppingList->operator[](i).to_Str()<<'\n';
        std::cout<<"----------------------------------------------\n";
    }*/

}
