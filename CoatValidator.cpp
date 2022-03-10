//
// Created by admin on 11/04/2021.
//

#include "CoatValidator.h"

string ValidationException::what() {
    return this->msg;
}
