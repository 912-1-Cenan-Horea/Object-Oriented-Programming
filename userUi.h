//
// Created by admin on 26/03/2021.
//

#pragma once

#include "domain.h"
#include "service.h"
#include "repoCsvHtml.h"
#include "repoCsv.h"
#include "repoHtml.h"

class userUi {
public:
    userUi(service &s, int mode) : serv(s), mode(mode) {
        if (mode == 0)this->shoppingList = new repoCsv;
        else if (mode == 1)this->shoppingList = new repoHtml;
    };

    int get_size();

    std::string get_option();

    void start_display();

    void display_list();

private:
    service &serv;
    repoCsvHtml *shoppingList;
    int mode;

};


