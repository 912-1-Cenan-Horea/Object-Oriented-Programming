//
// Created by admin on 11/04/2021.
//

#pragma once
using namespace std;
#include <string>

class RepoException : public std::exception {
public:
    explicit RepoException(string msg) :

            msg(std::move(msg)) {};

    string what()
    {return this->msg;};

private:
    string msg;
};
