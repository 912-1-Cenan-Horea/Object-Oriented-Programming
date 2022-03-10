//
// Created by cenan on 3/20/2021.
//

#include <iostream>

#include "domain.h"
#include "repo.h"
#include "service.h"
#include "admin_ui.h"
#include "tests.h"
#include <cstring>
#include "userUi.h"
#include "repo_file.h"
#include "RepoException.h"
#include "repoCsv.h"

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QFormLayout>
#include "adminGUI.h"
#include "userGUI.h"
#include "modeGUI.h"
#include "appGUI.h"
int main(int argc, char** argv) {

    test_all();
    //_CRT_SECURE_NO_WARNINGS;
    setbuf(stdout, nullptr);
    repo_file<Coat> r;
    service serv(r);
    /*

    admin_ui adminUi(serv);


    test_all();
    string opti = "-1";
    while (true) {
        try
        {
            std::cout << "Enter 1 for admin mode and 2 for user mode: ";
            std::cin >> opti;
            if (stoi(opti) == 0) {
                std::cout << "Invalid option\n";
            } else if (stoi(opti) != 1 && stoi(opti) != 2) {
                std::cout << "Invalid option\n";

            } else {
                break;
            }
        }
        catch(std::invalid_argument &ia){};

    }
    if (stoi(opti)== 1) {
        bool done = false;
        while (!done) {
            try {
                adminUi.print_menu();
                int option = adminUi.get_option();
                if (option == 0)
                    continue;
                if (option == 1)
                    adminUi.Add();
                if (option == 2)
                    adminUi.Delete();
                if (option == 3)
                    adminUi.Update();
                if (option == 4)
                    adminUi.Show_all();
                else if (option == -1)
                    done = true;
            }
            catch (ValidationException &ve) {
                std::cout << ve.what() << '\n';
            }
            catch (RepoException &re) {
                std::cout << re.what() << '\n';
            }
        }
    } else {
        std::string mode;
        int mode_int=-1;
        std::cout<<"Enter CSV or HTML: ";
        std::cin>>mode;
        if(mode=="CSV")
            mode_int=0;
        if(mode=="HTML")
            mode_int=1;
        userUi user_ui(serv,mode_int);
        user_ui.start_display();
    }
    */
    QApplication a{ argc, argv };
    appGUI app{serv};




    return QApplication::exec();

    return 0;
}