//
// Created by Maria on 05.05.2026.
//

#ifndef MEDICALANALYSISREDONETEST2OOP_UI_H
#define MEDICALANALYSISREDONETEST2OOP_UI_H
#include "../repo/person.h"


class UI {
private:
    Person person;
    void menu();
    int readInteger(const std::string& message);
    std::string readString(const std::string& message);
    double readDouble(const std::string& message);
    void add();
    void show();
    void showIll();
    void save();
public:
    UI(const Person& person);
    void run();
};



#endif //MEDICALANALYSISREDONETEST2OOP_UI_H
