//
// Created by Maria on 06.05.2026.
//

#ifndef BUILDYOURCAROOPTEST2_UI_H
#define BUILDYOURCAROOPTEST2_UI_H
#include "../service/service.h"


class UI {
private:
    Service service;
    void menu();
    void add();
    void show();
    void save();
    int readInteger(const std::string& message);
    std::string readString(const std::string& message);
    double readDouble(const std::string& message);
public:
    UI(const Service& service);
    void run();
};



#endif //BUILDYOURCAROOPTEST2_UI_H
