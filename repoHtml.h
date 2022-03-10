//
// Created by cenan on 4/18/2021.
//

#pragma once

#include "repoCsvHtml.h"

class repoHtml : public repoCsvHtml {
public:
    repoHtml() { this->file_name = "repo.html"; };

    void open() override;

private:
    void write() override;
};



