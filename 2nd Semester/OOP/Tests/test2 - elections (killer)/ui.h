//
// Created by Maria on 07.05.2026.
//

#ifndef T2_MIAGIURGIU_1_UI_H
#define T2_MIAGIURGIU_1_UI_H
#include <string>
#include "../service/service.h"


class UI {
private:
    Service service;
    void menu();
    void add();
    void show();
    void showParliament();
    void save();
    int readInteger(const std::string& message);
    double readDouble(const std::string& message);
    std::string readString(const std::string& message);
public:
    UI(Service& service);
    void run();
};



#endif //T2_MIAGIURGIU_1_UI_H
