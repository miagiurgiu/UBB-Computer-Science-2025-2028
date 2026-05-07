//
// Created by Maria on 30.04.2026.
//

#ifndef HOSPITAL_NEONATAL_H
#define HOSPITAL_NEONATAL_H
#include "department.h"
#include <string>

class Neonatal: public Department {
private:
    int numberOfMothers;
    int numberOfNewborns;
public:
    double averageGrade;
    Neonatal(const std::string& hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborns, double averageGrade);
    bool isEfficient() override;
    std::string toString() override;
};

#endif //HOSPITAL_NEONATAL_H
