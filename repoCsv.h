//
// Created by cenan on 4/17/2021.
//

#pragma once

#include <fstream>
#include "repoCsvHtml.h"

class repoCsv : public repoCsvHtml {
public:
    repoCsv() {
        this->file_name = "repo.csv";
    };


    void open() override;



private:
    void write() override;
    std::ofstream fo;
};


