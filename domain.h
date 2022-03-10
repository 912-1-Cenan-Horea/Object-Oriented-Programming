//
// Created by cenan on 3/20/2021.
//


#pragma once

#include <iostream>

class Coat {
public:

    ///Constructor wich takes as parameters the values of the coat
    Coat(int, char *, int, int, char *);

    ///Default constructor
    Coat();

    /// Copy constructor
    Coat(const Coat &other);

    /// Return string representation of the coat
    std::string to_Str() const;

    int get_size() const;

    void set_size(int);

    std::string get_colour() const;

    void set_colour(std::string new_colour);

    int get_quantity() const;

    void set_quantity(int);

    int get_price() const;

    void set_price(int);

    std::string get_link() const;


    void set_link(std::string new_link);

    /// Checks if two coats are the same
    bool operator==(Coat);

    /// Assignment operator
    Coat &operator=(const Coat &other);

    ~Coat();

    friend std::ostream &operator<<(std::ostream &stream, Coat &a);

    friend std::istream &operator>>(std::istream &is, Coat &a);

private:
    int size;
    std::string colour;
    int price;
    int quantity;
    std::string link;


};
