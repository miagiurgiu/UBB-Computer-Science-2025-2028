//
// Created by Maria on 07.05.2026.
//

#include "ui.h"
#include "../domain/party.h"
#include "../domain/alliance.h"
#include "../domain/independent.h"
#include <iostream>


UI::UI(Service& service) : service(service) {
}

void UI::menu() {
    std::cout<<"\n1.Add entity\n";
    std::cout<<"2.Show all entities\n";
    std::cout<<"3.Show all that form parliament.\n";
    std::cout<<"4.Save all entities to file.\n";
    std::cout<<"0.Exit\n";
}
void UI::add() {
    std::string type=readString("Give county type (party/alliance/independent): ");
    std::string name=readString("Give name: ");
    int votes=readInteger("Give nr of eligible votes: ");
    County* newCounty;
    if (type=="party") {
        //int votes=readInteger("Give nr of votes:");
        newCounty=new Party(name,votes);
        this->service.add(newCounty);
    }
    else if (type=="alliance") {
        int nr=readInteger("Give number of parties: ");
        newCounty=new Alliance(name,votes,nr);
        this->service.add(newCounty);
    }
    else if (type=="independent") {
        newCounty=new Independent(name,votes);
        this->service.add(newCounty);
    }
    else {
        std::cout<<"Invalid type\n";
        return;
    }
}
void UI::show() {
    auto entities=this->service.getAll();
    for (auto e:entities) {
         std::cout<<e->toString();
    }
}
void UI::showParliament() {
    return;
}
void UI::save() {
    std::string filename=readString("Give filename: ");
    auto entities=this->service.getAll();
    this->service.writeToFile(filename,entities);
}
int UI::readInteger(const std::string& message) {
    int value;
    while (true) {
        std::cout<<message;
        if (std::cin>>value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout<<"Please enter valid integer\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
double UI::readDouble(const std::string& message) {
    double value;
    while (true) {
        std::cout<<message;
        if (std::cin>>value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout<<"Please enter valid real number\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
std::string UI::readString(const std::string& message) {
    std::string value;
    std::cout<<message;
    std::getline(std::cin, value);
    return value;
}

void UI::run() {
    while (true) {
        menu();
        int option=readInteger("Give option: ");
        if (option==0) break;
        switch (option) {
            case 1:
                add();
                break;
            case 2:
                show();
                break;
            case 3:
                showParliament();
                break;
            case 4:
                save();
                break;
            default:
                std::cout<<"Invalid option!"<<std::endl;
        }
    }
}

