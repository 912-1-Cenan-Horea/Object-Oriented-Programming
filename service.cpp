//
// Created by admin on 17/04/2021.
//

#include "service.h"



void service::Add(int size, char *colour, int price, int quantity, char *link) {

    char *co = new char[100];
    strcpy(co, colour);
    char *l = new char[100];
    strcpy(l, link);

    Coat c(size, co, price, quantity, l);
    CoatValidator val;
    val.validate(c);
    this->r.Add(c);

}


void service::Delete(int size, char *colour) {
    Coat elem;
    elem.set_size(size);
    elem.set_colour(colour);
    this->r.Delete(elem);
}


void service::Update(int size, char *colour, int price, int quantity, char *link, int new_size, char *new_colour,
                     int new_price, int new_quantity, char *new_link) {
    CoatValidator val;
    Coat old_elem(size, colour, price, quantity, link);
    val.validate(old_elem);
    Coat new_elem(new_size, new_colour, new_price, new_quantity, new_link);
    val.validate(new_elem);
    this->r.Update(old_elem, new_elem);
}


service &service::operator=(service other) {
    this->r = other.r;
    return *this;
}


repo<Coat> service::list() {
    return this->r;
}


int service::Lenght() {
    return this->r.Lenght();
}



repo<Coat> *service::filter_by_size(int size) {
    repo<Coat> *lst = new repo<Coat>;
    std::vector<Coat> init;
    std::vector<Coat> v;
    for(auto i:this->list())
        init.push_back(i);

    std::copy_if(init.begin(), init.end(), back_inserter(v), [size](Coat &c) {
        if (size == -1)
            return true;
        else if (c.get_size() == size)
            return true;
        return false;
    });


    for (auto i:v)
        lst->Add(i);

    return lst;
}

