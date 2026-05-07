//
// Created by Maria on 05.05.2026.
//

#include "ui.h"
#include "analysis.h"
#include "bmi.h"
#include "bp.h"

#include <iostream>
#include <limits>

UI::UI(const Person& person): person(person) {};


void UI::menu() {
    std::cout<<"\n1. Add new analysis.\n";
    std::cout<<"2. Show all analyses.\n";
    std::cout<<"3. Show if person is ill.\n";
    std::cout<<"4. Save to file all analyses between given dates.\n";
    std::cout<<"0. Exit\n";
}

int UI::readInteger(const std::string& message) {
    int value;
    std::cout<<message;
    while (true) {
        if (std::cin>>value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout<<"Invalid input - enter an integer number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double UI::readDouble(const std::string& message) {
    double value;
    std::cout<<message;
    while (true) {
        if (std::cin>>value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cout<<"Invalid input - enter a real number.\n";
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

void UI::add() {
    std::string date = readString("Give date of analysis: ");
    std::string type = readString("Give type of analysis (BMI/BP): " );
    if (type=="BMI") {
        double value = readDouble("Give real value of BMI: ");
        try {
            MedicalAnalysis* newBMIAnalysis = new BMI(date,value);
            this->person.addAnalysis(newBMIAnalysis);
            std::cout<<"BMI Analysis added successfully!";
        }
        catch (std::exception& e) {
            std::cout<<"Error in adding BMI analysis.\n";
        }
    }
    else if (type=="BP") {
        int sys=readInteger("Give systolic value: ");
        int dya=readInteger("Give dyastolic value: ");
        try {
            MedicalAnalysis* newBPAnalysis = new BP(date,sys,dya);
            this->person.addAnalysis(newBPAnalysis);
            std::cout<<"BP Analysis added successfully!";
        }
        catch (std::exception& e) {
            std::cout<<"Error in adding BP analysis.\n";
        }
    }
    else {
        std::cout<<"Invalid input - enter a valid type (BMI/BP).\n";
        return; // continue?? break?? - help here!
    }
}

void UI::show() {
    auto analyses = this->person.getAllAnalyses();
    for (auto a: analyses) {
        std::cout<<a->toString();
    }
}

void UI::showIll() {
    int month=readInteger("Give month: ");
    int ok=0;
    /*
    auto analyses = this->person.getAnalysesByMonth(month);

    for (auto a: analyses) {
        if (!a->isResultOK()) {
            std::cout<<a->toString();
            ok=1;
        }
    }*/
    if (this->person.isIll(month))
        std::cout<<"Person is ill!\n";
    else
        std::cout<<"Not ill!";
}
void UI::save() {
    std::string filename=readString("Save to this file: ");
    std::string date1=readString("Give date1 of analysis: ");
    std::string date2=readString("Give date2 of analysis: ");
    this->person.writeToFile(filename,date1,date2);
}

void UI::run() {
    while (true) {
        menu();
        int option=readInteger("Choose option: ");
        if (option==0) break;
        switch (option) {
            case 1:
                add();
                break;
            case 2:
                show();
                break;
            case 3:
                showIll();
                break;
            case 4:
                save();
                break;
            default:
                std::cout<<"Invalid option!";
        }
    }
}