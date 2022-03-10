//
// Created by admin on 11/04/2021.
//


#pragma once

#include <string>
#include <utility>
#include "domain.h"
using namespace std;


class ValidationException : public std::exception {
public:
    explicit ValidationException(string msg) : msg(std::move(msg)) {};
    string what();

private:
    string msg;
};


class CoatValidator {
public:
    void validate(Coat c) {
        if (c.get_size() <= 0)
            throw ValidationException("Invalid size!\n");
        if (c.get_price() <= 0)
            throw ValidationException("Invalid price!\n");
        if (c.get_quantity() <= 0)
            throw ValidationException("Invalid quantity!\n");
    }
};

