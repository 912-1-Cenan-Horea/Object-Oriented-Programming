//
// Created by cenan on 3/20/2021.
//

#pragma once

#include "repo.h"
#include "domain.h"
#include <string.h>
#include "CoatValidator.h"


class service {
public:
    service(repo<Coat> &rep) : r(rep) {};


    service &operator=(service);

    /// Adds a new coat to the coat list,throws char* if input is invalid
    /// \param size
    /// \param colour
    /// \param price
    /// \param quantity
    /// \param link
    void Add(int size, char *colour, int price, int quantity, char *link);

    /// Deletes a given coat from the coat list,throws char* if the coat doesnt exist
    /// \param size
    /// \param colour
    void Delete(int size, char *colour);

    /// Updates a coat with new information,throws char* if coat doesnt exist
    /// \param size
    /// \param colour
    /// \param price
    /// \param quantity
    /// \param link
    /// \param new_size
    /// \param new_colour
    /// \param new_price
    /// \param new_quantity
    /// \param new_link
    void
    Update(int size, char *colour, int price, int quantity, char *link, int new_size, char *new_colour, int new_price,
           int new_quantity, char *new_link);

    /// Returns a repo with only the coats having a given size(or all coats if the size is -1)
    /// \param size
    /// \return poniter to the new repo
    repo<Coat> *filter_by_size(int size);

    ///
    /// \return The lenght of the coat list
    int Lenght();

    /// returns copy  of the repo from  the service
    /// \return
    repo<Coat> list();

private:
    repo<Coat> &r;

};

