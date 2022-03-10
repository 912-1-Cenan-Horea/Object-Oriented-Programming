//
// Created by admin on 11/04/2021.
//

#pragma once

#include <string>
#include "repo.h"
#include <iostream>
#include <fstream>
#include "domain.h"

template<typename T>
class repo_file : public repo<T> {
private:
    std::string file_name;
    std::ofstream fo;
    std::ifstream fi;

    void write();

    void read();

public:
    repo_file() {
        this->file_name = "G:/Object Oriented Programing/OOP/a89-912-1-Cenan-Horea/repo.txt";
        this->read();

    };

    void Add(T);

    void Delete(T);

    void Update(T, T);

};

template<typename T>
void repo_file<T>::write() {

    this->fo.open(this->file_name);

    for (auto i:this->storage)
        this->fo << i;

    this->fo.close();
}

template<typename T>
void repo_file<T>::Add(T elem) {
    repo<T>::Add(elem);
    this->write();

}

template<typename T>
void repo_file<T>::Delete(T elem) {
    repo<T>::Delete(elem);
    this->write();
}

template<typename T>
void repo_file<T>::read() {
    this->fi.open(this->file_name);
    if (!this->fi.is_open())
    {

        throw RepoException("Could not open file!\n");
    }

    Coat c;
    while (this->fi >> c) {
        repo<T>::Add(c);
    }
    this->fi.close();

}


template<typename T>
void repo_file<T>::Update(T old_elem, T new_elem) {
    repo<T>::Update(old_elem, new_elem);
    this->write();

}





