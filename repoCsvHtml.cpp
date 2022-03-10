//
// Created by cenan on 4/17/2021.
//

#include "repoCsvHtml.h"

repoCsvHtml::repoCsvHtml() {
    vector<Coat> v;
    this->storage=v;
}

void repoCsvHtml::Add(Coat c) {
    repo::Add(c);
    this->write();
}
