//
// Created by cenan on 3/20/2021.
//
#pragma once


#include <vector>
#include <algorithm>
#include "RepoException.h"

template<typename T>
class repo {
public:
    repo();

    virtual /// Adds object T from the array
    void Add(T);

    virtual /// Deletes object T from the array
    void Delete(T);

    virtual /// Updates an element T with another T element
    void Update(T, T);

    /// Returns the lenght of the repo
    int Lenght();

    repo &operator=(repo);

    /// Acces operator
    T operator[](int);

    typename std::vector<T>::iterator begin();

    typename std::vector<T>::iterator end();


protected:
    std::vector<T> storage;
};

template<typename T>
void repo<T>::Add(T elem) {
    auto pos = std::find(this->storage.begin(), this->storage.end(), elem);
    if (pos != this->storage.end())
        throw RepoException("Element already exists!\n");
    this->storage.push_back(elem);
}

template<typename T>
void repo<T>::Delete(T elem) {
    auto pos = std::find(this->storage.begin(), this->storage.end(), elem);
    if (pos == this->storage.end())
        throw RepoException("Cant delete an inexistent element!\n");
    this->storage.erase(pos);
}

template<typename T>
void repo<T>::Update(T old_elem, T new_elem) {
    auto pos = std::find(this->storage.begin(), this->storage.end(), old_elem);
    if (pos == this->storage.end())
        throw RepoException("Cant update an object that doesnt exist!\n");
    this->storage.erase(pos);
    this->storage.push_back(new_elem);
}

template<typename T>
int repo<T>::Lenght() {
    return this->storage.size();
}

template<typename T>
repo<T>::repo() {
    std::vector<T> v;
    this->storage = v;
}

template<typename T>
T repo<T>::operator[](int pos) {
    if (pos < 0 || pos >= this->storage.size())
        throw RepoException("Invalid position");
    return this->storage[pos];
}


template<typename T>
repo<T> &repo<T>::operator=(repo other) {
    for(auto i:other)
        this->Add(i);
   // this->storage = other.get_storage();
    return *this;
}

template<typename T>
typename std::vector<T>::iterator repo<T>::begin() {
    return this->storage.begin();
}

template<typename T>
typename std::vector<T>::iterator repo<T>::end() {
    return this->storage.end();
}



