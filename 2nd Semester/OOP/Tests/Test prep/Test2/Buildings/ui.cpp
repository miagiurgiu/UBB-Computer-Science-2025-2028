//
// Created by Maria on 04.05.2026.
//

#include "ui.h"
#include "../domain/block.h"
#include "../domain/house.h"
#include "../domain/building.h"
#include <iostream>

UI::UI(const Service& service): service(service) {};

void UI::menu() {
    std::cout<<"1. Add new building.\n";
    std::cout<<"2. Show all buildings.\n";
    std::cout<<"3. Save buildings to file.\n";
    std::cout<<"0. Exit.\n";
}
void UI::add() {
    std::string address=readString("Give address of building: ");
    int year=readInteger("Give year of construction: ");

    std::string type = readString("Please enter your building type (block/house): ");
    if (type!="block" && type!="house") {
        std::cout<<"Invalid choice!";
        // clear stuff before??
        return;
    }
    if (type == "block") {
        int totalAppartments=readInteger("Give total number of appartments: ");
        int occupiedAppartments=readInteger("Give number of occupied appartments: ");
        Building* newBuilding = new Block(address,year,totalAppartments,occupiedAppartments);
        try {
            this->service.addBuilding(newBuilding);
            std::cout<<"Block of flats added successfully!\n";
        }
        catch (...) {
            delete newBuilding;
            std::cout<<"Error in adding building!";
        }
    }
    else {
        std::string type=readString("Give type of house (one story/two stories/duplex): ");
        std::string historical=readString("Historical house or not? (yes/no):");
        bool isHistorical;
        if (historical=="yes") {
            isHistorical=true;
        }
        else if (historical=="no") {
            isHistorical=false;
        }
        else {
            std::cout<<"Invalid choice! Historical? (yes/no):";
            return;
        }
        Building* newBuilding=new House(address,year,type,isHistorical);
        try {
            this->service.addBuilding(newBuilding);
        }
        catch (...) {
            std::cout<<"Error in adding house!\n";
        }
    }
}

void UI::show() {
    auto buildings=this->service.getAllBuildings();
    std::cout<<"Buildings sorted by construction year: \n";
    for (auto building : buildings) {
        std::cout<<building->toString();
    }
}

void UI::save() {
    std::string filename1=readString("Save buildings that must be RESTORED in a file (give filename): ");
    std::vector<Building*> restoredBuildings=this->service.getAllToBeRestored();
    this->service.writeToFile(filename1,restoredBuildings);
    std::string filename2=readString("Save buildings that must be DEMOLISHED in a file (give filename): ");
    std::vector<Building*> demolishedBuildings=this->service.getAllToBeDemolished();
    this->service.writeToFile(filename2,demolishedBuildings);
}

int UI::readInteger(const std::string& message) {
    int value;
    while (true) {
        std::cout<<message;
        if (std::cin>>value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout<<"Invalid input!";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string UI::readString(const std::string& message) {
    std::string value;
    std::cout<<message;
    std::getline(std::cin,value);
    return value;
}

void UI::run() {
    while (true) {
        menu();
        int option=readInteger("Your option: ");
        if (option==0) break;
        switch (option) {
            case 1:
                add();
                break;
            case 2:
                show();
                break;
            case 3:
                save();
                break;
            default:
                std::cout<<"Invalid option!";
        }
    }
}
