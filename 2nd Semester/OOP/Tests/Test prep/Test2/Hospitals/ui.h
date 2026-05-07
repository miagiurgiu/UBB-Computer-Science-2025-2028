//
// Created by Maria on 30.04.2026.
//

#ifndef HOSPITAL_UI_H
#define HOSPITAL_UI_H
#include "../service/service.h"

class UI {
private:
    Service service; // service is a regular object (not a reference) => ui creates a local copy of the service
    int readInteger(const std::string& message);
    double readDouble(const std::string& message);
    void addDepartment();
    void showDepartments();
    void showEfficientDepartments();
    void saveDepartmentsToFile();
    void menu();
public:
    UI(const Service& service); // pass a service, clone it to my own variable => copy => ui can call any non-const method
    void run();
};



#endif //HOSPITAL_UI_H
