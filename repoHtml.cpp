//
// Created by cenan on 4/18/2021.
//

#include <fstream>
#include "repoHtml.h"

void repoHtml::write() {
    std::ofstream fo(this->file_name);
    fo<<"<!DOCTYPE html>    <!-- write this exactly as it is here -->\n"
        "<html> <!-- write this exactly as it is here -->\n"
        "<head> <!--  write this exactly as it is here -->\n"
        "    <title>Coat</title> <!-- replace “Playlist” with the title for your HTML -->\n"
        "</head> <!-- write this exactly as it is here (close head tag) -->\n"
        "<body> <!-- write this exactly as it is here -->\n"
        "<table border=\"1\"> <!-- write this exactly as it is here -->";
    fo<<"<tr>";
    fo<<"<td>";
    fo<<"Size";
    fo<<"</td>";
    fo<<"<td>";
    fo<<"Colour";
    fo<<"</td>";
    fo<<"<td>";
    fo<<"Price";
    fo<<"</td>";
    fo<<"<td>";
    fo<<"Quantity";
    fo<<"</td>";
    fo<<"<td>";
    fo<<"Link";
    fo<<"</td>";
    fo<<"</tr>";
    for(auto i:*this)
    {
        fo<<"<tr>";

        fo<<"<td>";
        fo<<i.get_size();
        fo<<"</td>";

        fo<<"<td>";
        fo<<i.get_colour();
        fo<<"</td>";

        fo<<"<td>";
        fo<<i.get_price();
        fo<<"</td>";

        fo<<"<td>";
        fo<<i.get_quantity();
        fo<<"</td>";

        fo<<"<td><a href='";
        fo<<i.get_link();
        fo<<"'>";
        fo<<i.get_link();
        fo<<"</a></td>";

        fo<<"</tr>";
    }

    fo<<"</table>\n"
        "</body>\n"
        "</html>";
}


void repoHtml::open() {
    this->write();
    system(std::string("start "+this->file_name).c_str());
}



