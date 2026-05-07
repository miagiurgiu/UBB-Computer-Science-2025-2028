//
// Created by Maria on 30.04.2026.
//

#ifndef HOSPITAL_SERVICE_H
#define HOSPITAL_SERVICE_H
#include "../repo/abstract_repo.h"

class Service {
private:
    AbstractRepo& arepo; // service does not modify the repo => points to original one
public:
    Service(AbstractRepo& arepo); // service does modify repo => no const
    void addDepartment(Department* department);
    std::vector<Department*> getAll() const;
    std::vector<Department*> getAllEfficientDepartments() const;
    void writeToFile(const std::string& filename);
};

#endif //HOSPITAL_SERVICE_H
