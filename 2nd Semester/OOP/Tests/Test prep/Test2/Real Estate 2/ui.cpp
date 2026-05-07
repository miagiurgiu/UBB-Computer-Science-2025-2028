//
// Created by Maria on 07.05.2026.
//

#include "ui.h"

#include <iostream>

UI::UI(RealEstateAgency& agency):agency(agency){};

void UI::menu() {
    std::cout<<"\n1.Remove client.\n";
    std::cout<<"2.Show all clients and dwellings.\n";
    std::cout<<"3.Add dwelling.\n";
    std::cout<<"4.Save all clients.\n";
    std::cout<<"0.Exit\n";
}
void UI::add() {
    std::string type=readString("Give type: ");
    double price=readDouble("Give price: ");
    bool isProfitable;
    Dwelling* newDwelling;
    std::string profitable=readString("Give profitable (yes/no): ");
    if (profitable=="yes") {
        isProfitable=true;
    }
    else if (profitable=="no") {
        isProfitable=false;
    }
    else {
        std::cout<<"Invalid input (give yes/no)!"<<std::endl;
        return; // !!!
    }
    try {
        newDwelling = this->agency.addDwelling(type,price,isProfitable);
        std::cout<<"Dwelling added.\n";
    }
    catch (std::exception& e) {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<"Clients interested in this dwelling: \n";
    auto clients = this->agency.getInterestedClients(newDwelling);
    for (auto c: clients) {
        std::cout<<c->toString();
    }

}
void UI::remove() {
    std::string name=readString("Give name: ");
    if (agency.removeClient(name)) {
        std::cout<<"Client removed.\n";
    }
    else {
        std::cout<<"Client not removed.\n";
    }
    /*
    try {
        this->agency.removeClient(name);
        std::cout<<"Client removed.\n";
    }
    catch (...) {
        std::cout<<"Client could not be removed.\n";
    }*/
}
void UI::show() {
    auto clients=this->agency.getAllClients();
    auto dwellings=this->agency.getAllDwellings();
    std::cout<<"\nClients:\n";
    for (auto c: clients) {
        std::cout<<c->toString();
    }
    std::cout<<"\nDwellings:\n";
    for (auto d: dwellings) {
        std::cout<<d->toString();
    }
}
void UI::save() {
    std::string filename=readString("Give filename: ");
    this->agency.writeToFile(filename);
}

int UI::readInteger(const std::string& message) {
    int value;
    while (true) {
        std::cout<<message;
        if (std::cin>>value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout<<"Invalid.\n";
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
        std::cout<<"Invalid.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string UI::readString(const std::string& message) {
    std::string value;
    while (true) {
        std::cout<<message;
        std::getline(std::cin,value);
        if (!value.empty()) {
            return value;
        }
        std::cout<<"Invalid.\n";
    }
}

void UI::run() {
    while (true) {
        menu();
        int option=readInteger("Give option: ");
        if (option==0) break;
        switch (option) {
            case 1:
                remove();
                break;
            case 2:
                show();
                break;
            case 3:
                add();
                break;
            case 4:
                save();
                break;
            default:
                std::cout<<"Invalid option!"<<std::endl;
        }
    }
}
