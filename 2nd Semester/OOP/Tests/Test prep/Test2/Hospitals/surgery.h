//
// Created by Maria on 30.04.2026.
//

#ifndef HOSPITAL_SURGERY_H
#define HOSPITAL_SURGERY_H
#include <string>
#include "department.h"

class Surgery: public Department {
private:
    int numberOfPatients;
public:
    Surgery(const std::string& hospitalName, int numberOfDoctors, int numberOfPatients);
    bool isEfficient() override;
    std::string toString() override;
};


#endif //HOSPITAL_SURGERY_H
