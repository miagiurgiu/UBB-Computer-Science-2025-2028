//
// Created by Maria on 30.04.2026.
//

#include "service.h"
#include <fstream>

Service::Service(AbstractRepo& arepo): arepo{arepo} {}; // service does modify repo => no const
void Service::addDepartment(Department* department) {
    this->arepo.addDepartment(department);
}

std::vector<Department*> Service::getAll() const {
    return this->arepo.getAll();
}

void Service::writeToFile(const std::string& filename){
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        return;
    }
    std::vector<Department*> departments = this->arepo.getAll();

    std::sort(departments.begin(), departments.end(), [](Department* a, Department* b) {
        return a->getHospitalName() < b->getHospitalName();
    });

    for (auto d: departments) {
        std::string efficiency = d->isEfficient() ? " [EFFICIENT]": " [INEFFICIENT]";
        fout<<d->toString()<<efficiency<<"\n";
    }
    fout.close();
}

std::vector<Department*> Service::getAllEfficientDepartments() const {
    std::vector<Department*> departments = this->arepo.getAll();
    std::vector<Department*> efficient;
    for (auto d: departments) {
        if (d->isEfficient()) {
            efficient.push_back(d);
        }
    }
    return efficient;
}