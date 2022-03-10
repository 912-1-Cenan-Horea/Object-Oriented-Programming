//
// Created by cenan on 4/17/2021.
//

#include "repoCsv.h"

void repoCsv::write() {

    this->fo.open(this->file_name);
    this->fo<<"Size,Colour,Price,Quantity,Link\n";
    for (auto i:this->storage)
        this->fo << i;

    this->fo.close();

}




void repoCsv::open() {
    this->write();
    system(string("start excel "+this->file_name).c_str());

}
