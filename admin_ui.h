//
// Created by cenan on 3/20/2021.
//

#pragma once

#include <iostream>
#include "service.h"


class admin_ui {
public:
    admin_ui(service &ser) : serv(ser) {};

    void print_menu();

    int get_option();

    void Add();

    void Delete();

    void Update();

    void Show_all();

private:
    service &serv;
};



