//
// Created by cenan on 4/17/2021.
//

#pragma once
#include "repo.h"
#include "domain.h"
class repoCsvHtml : public repo<Coat>{
public:
    explicit repoCsvHtml();



    virtual void open()=0;

    void Add(Coat) override;

    std::string file_name;

private:
    virtual void write()=0;

};


