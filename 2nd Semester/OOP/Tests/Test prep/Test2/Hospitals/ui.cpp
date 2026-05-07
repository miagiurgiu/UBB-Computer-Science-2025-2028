//
// Created by Maria on 30.04.2026.
//

#include "ui.h"
#include "../service/service.h"
#include <iostream>
#include "../domain/neonatal.h"
#include "../domain/surgery.h"


UI::UI(const Service& service): service{service} {};

int UI::readInteger(const std::string& message) {
    int value;
    while (true) {
        std::cout<<message;
        if (std::cin>>value) {
            return value;
        }
        std::cout<<"Invalid input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

double UI::readDouble(const std::string& message) {
    double value;
    while (true) {
        std::cout<<message;
        if (std::cin>>value) {
            return value;
        }
        std::cout<<"Invalid input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
void UI::menu() {
    std::cout<<"1. Add department.\n";
    std::cout<<"2. Show departments.\n";
    std::cout<<"3. Show efficient departments.\n";
    std::cout<<"4. Save departments to file.\n";
    std::cout<<"0. Exit.\n";
}
void UI::addDepartment() {
    std::string departmentType;
    std::cout<<"Enter type of department (surgery/neonatal): ";

    // reading a string:
    if (!(std::cin>>departmentType) || (departmentType!="surgery" && departmentType!="neonatal")) {
        std::cout<<"Invalid input\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // in case the reading of string succeeds, remove \n from buffer

    std::string hospitalName;
    std::cout << "Enter hospital name: ";
    std::getline(std::cin, hospitalName);
    int nrDoctors = readInteger("Enter number of doctors: ");

    if (departmentType=="surgery") {
        int nrPatients = readInteger("Enter number of patients: ");
        Department* newDepartment = new Surgery(hospitalName, nrDoctors, nrPatients);
        try {
            this->service.addDepartment(newDepartment);
            std::cout<<"Department added successfully.\n";
        }
        catch (const std::runtime_error& e) {
            std::cout<<"Error: "<< e.what()<<"\n";
        }
    }
    else if (departmentType=="neonatal") {
        int nrMothers = readInteger("Enter number of mothers: ");
        int nrBabies = readInteger("Enter number of babies: ");
        double average = readDouble("Enter average: ");
        Department* newDepartment = new Neonatal(hospitalName, nrDoctors, nrMothers, nrBabies, average);
        this->service.addDepartment(newDepartment);
    }

}

void UI::showDepartments() {
    std::vector<Department*> departments = this->service.getAll();
    for (auto department : departments) {
        std::cout<<department->toString()<<"\n";
    }
}

void UI::showEfficientDepartments() {
    std::vector<Department*> efficientDepartments = this->service.getAllEfficientDepartments();
    if (efficientDepartments.size()==0) {
        std::cout<<"All departments in Romania are inefficient.\n";
        return;
    }
    for (auto department : efficientDepartments) {
        std::cout<<department->toString()<<"\n";
    }
}

void UI::saveDepartmentsToFile() {
    std::string nameOfFile;
    std::cout<<"Enter name of file: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //in case the reading of string succeeds, remove \n from buffer
    std::getline(std::cin,nameOfFile);
    this->service.writeToFile(nameOfFile);
    std::cout<<"Data saved successfully to file.\n";
}

void UI::run() {
    while (true) {
        menu();
        int option = readInteger("Enter option: ");
        if (option==0)
            break;
        switch (option) {
            case 1:
                addDepartment();
                break;
            case 2:
                showDepartments();
                break;
            case 3:
                showEfficientDepartments();
                break;
            case 4:
                saveDepartmentsToFile();
                break;
            default:
                std::cout<<"Invalid option\n";
                break;
        }

    }
}


