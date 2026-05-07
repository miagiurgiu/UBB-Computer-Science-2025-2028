//
// Created by Maria on 07.05.2026.
//

#ifndef REALESTATE2TEST2OOP_UI_H
#define REALESTATE2TEST2OOP_UI_H
#include "../service/agency.h"
#include <string>

class UI {
private:
    RealEstateAgency& agency;
    void menu();
    void add();
    void remove();
    void show();
    void save();
    int readInteger(const std::string& message);
    double readDouble(const std::string& message);
    std::string readString(const std::string& message);
public:
    UI(RealEstateAgency& agency);
    void run();
};



#endif //REALESTATE2TEST2OOP_UI_H
