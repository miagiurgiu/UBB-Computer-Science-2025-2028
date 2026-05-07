//
// Created by Maria on 06.05.2026.
//

#include "ui.h"
#include <iostream>
#include <iomanip>

#include "electric.h"

UI::UI(const Service& service): service(service) {};

void UI::menu() {
    std::cout<<"\n1.Add new car.\n";
    std::cout<<"2.Show all cars.\n";
    std::cout<<"3.Save to file all cars having price less than given price.\n";
    std::cout<<"0.Exit.\n";
}

void UI::add() {
    std::string bodyStyle=readString("Give body style of car (Sedan/Convertible): ");
    double price;
    if (bodyStyle!="Sedan" && bodyStyle!="Convertible") {
        std::cout<<"\nInvalid body style - please enter Sedan/Convertible\n";
        return;
    }
    std::string engine=readString("Give engine of car (electric/turbo): ");
    if (engine=="electric") {
        int autonomy=readInteger("Give autonomy of electric car (integer value): ");
        if (autonomy<0) {
            std::cout<<"\nInvalid autonomy\n";
            return;
        }
        this->service.addCar(bodyStyle,engine,autonomy);
        // print its price
        price = this->service.getLastCarPrice();
        std::cout<<"Price of the car added: "<<std::fixed<<std::setprecision(4)<<price<<std::endl;
    }
    else if (engine=="turbo") {
        this->service.addCar(bodyStyle,engine,0);
        // print its price
        price = this->service.getLastCarPrice();
        std::cout<<"Price of the car added: "<<std::fixed<<std::setprecision(4)<<price<<std::endl;
    }
    else {
        std::cout<<"\nInvalid engine - please enter electric/turbo\n";
        return;
    }
}
void UI::show() {
    auto cars = this->service.getAll();
    for (auto c:cars) {
        std::cout<<c->toString();
    }
}
void UI::save() {
    std::string filename=readString("Save to this file: ");
    double price=readDouble("Save cars with price less than: ");
    auto cars=this->service.getCarsWithMaxPrice(price);
    this->service.writeToFile(filename,cars);
}
int UI::readInteger(const std::string& message) {
    int value;
    std::cout<<message;
    while (true) {
        if (std::cin>>value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout<<"Invalid input - please enter an integer\n";
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

double UI::readDouble(const std::string& message) {
    double value;
    std::cout<<message;
    while (true) {
        if (std::cin>>value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout<<"Invalid input - please enter a real number\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void UI::run() {
    while (true) {
        menu();
        int option=readInteger("Enter your option: ");
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
                std::cout<<"\nInvalid option\n";
        }
    }
}