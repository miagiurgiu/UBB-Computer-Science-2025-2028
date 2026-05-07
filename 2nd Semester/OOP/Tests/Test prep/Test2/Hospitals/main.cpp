//
// Created by Maria on 30.04.2026.
//

#include <iostream>
#include <ostream>
#include "../domain/department.h"
#include "../domain/surgery.h"
#include "../domain/neonatal.h"
#include "../repo/file_repo.h"
#include "../service/service.h"
#include "../ui/ui.h"

int main() {
    std::cout<<"Hello World"<<std::endl;
    Department* myDepartment = new Surgery("Central Hospital", 20,100);
    Department* neonatal = new Neonatal("Cluj Hospital", 50, 20, 25,8.7);
    std::cout<<myDepartment->toString()<<std::endl;
    std::cout<<neonatal->toString()<<std::endl;
    delete myDepartment; // memory deallocated form heap -> call destructor
    delete neonatal;

    FileRepo arepo;
    Service service{arepo};
    UI ui{service};
    ui.run();
    return 0;
}
