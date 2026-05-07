//
// Created by Maria on 04.05.2026.
//

#ifndef BUILDINGSTEST2OOP_UI_H
#define BUILDINGSTEST2OOP_UI_H
#include "../service/service.h"
#include <string>

class UI {
private:
    Service service;
    void menu();
    void add();
    void show();
    void save();
    int readInteger(const std::string& message);
    std::string readString(const std::string& message);
public:
    UI(const Service& service);
    void run();
};



#endif //BUILDINGSTEST2OOP_UI_H
