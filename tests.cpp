//
// Created by cenan on 3/20/2021.
//
#pragma once

#include "tests.h"
#include <string.h>
#include "RepoException.h"

void test_domain() {
    char *colour = new char[100];
    strcpy(colour, "red");
    char *link = new char[100];
    strcpy(link, "abc.com");
    Coat c(12, colour, 1, 3, link);
    assert(c.get_size() == 12);
    assert(c.get_price() == 1);
    assert(c.get_quantity() == 3);
    assert(c.get_link() == link);
    assert(c.get_colour() == colour);
    c.set_size(29);
    assert(c.get_size() == 29);
    c.set_price(333);
    assert(c.get_price() == 333);
    c.set_quantity(2);
    assert(c.get_quantity() == 2);
    strcpy(colour, "blue");
    try {
        c.set_size(-2);
    }
    catch (const char *msg) {
        assert(true);
    }

    try {
        c.set_quantity(-4);
    }
    catch (const char *msg) {
        assert(true);
    }

    try {
        c.set_price(-4);
    }
    catch (const char *msg) {
        assert(true);
    }
    try {
        char a[20];
        strcpy(a, "");
        c.set_link(a);
    }
    catch (const char *msg) {
        assert(true);
    }

    c.set_colour(colour);
    assert(c.get_colour() == colour);
    strcpy(link, "blue.com");
    assert(c.get_link() != link);
    c.to_Str();
    c.set_link(link);
    Coat d(3, colour, 3, 4, link);
    assert(!(c == d));
    assert(c.get_link() == link);

    delete[] colour;
    delete[] link;

}


void test_repo() {
    repo<int> r;
    for (int i = 1; i <= 200; i++)
        r.Add(i);
    try {
        r.Add(3);
    }
    catch (RepoException &re) {
        assert(true);
    }

    try {
        r.Delete(300);
    }
    catch (RepoException &re) {
        assert(true);
    }
    try {
        r[500];
    }
    catch (RepoException &re) {
        re.what();
        assert(true);
    }
    try {
        r.Update(500, 2);
    }
    catch (RepoException &re) {
        assert(true);
    }

    assert(r.Lenght() == 200);
    assert(r[99] == 100);
    r.Delete(199);

    assert(r.Lenght() == 199);
    assert(r[198] == 200);
    r.Update(1, 33);
    assert(r[198] == 33);
}

void test_service() {
    repo<Coat> r;
    service serv(r);
    char *colour = new char[100];
    strcpy(colour, "red");
    char *link = new char[100];
    strcpy(link, "abc.com");
    serv.Add(1, colour, 100, 2, link);
    try {
        serv.Add(-2, colour, 30, 3, link);
    }
    catch (ValidationException &ve) {
        assert(true);
    }
    try {
        serv.Add(5, colour, -30, 3, link);
    }
    catch (ValidationException &ve) {
        assert(true);
    }
    try {
        serv.Add(2, colour, 30, -9, link);
    }
    catch (ValidationException &ve) {
        assert(true);
    }

    assert(serv.list()[0].get_quantity() == 2);
    assert(serv.list()[0].get_link()==link);

    repo<Coat> *r1 = serv.filter_by_size(1);
    assert(r1->Lenght() == 1);
    repo<Coat> *r2 = serv.filter_by_size(-1);
    assert(r2->Lenght() == 1);
    serv.Delete(1, colour);
    assert(serv.Lenght() == 0);


}

void test_all() {
    test_domain();
    test_repo();
    test_service();
}