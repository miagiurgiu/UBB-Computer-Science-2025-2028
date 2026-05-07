//
// Created by Maria on 30.04.2026.
//

#include "file_repo.h"
#include <fstream>
FileRepo::FileRepo() {
    //this->readFromFile();
}

void FileRepo::addDepartment(Department* department) {
    for (auto d: this->departments) {
        if (d->getHospitalName()==department->getHospitalName()) {
            delete department;
            return;
        }
    }
    this->departments.push_back(department);
    //this->writeToFile(this->departments);
}

std::vector<Department*> FileRepo::getAll() const {
    return this->departments;
}

FileRepo::~FileRepo() {
    for (auto d: this->departments) {
        delete d;
    }
}