//
// Created by Maria on 30.04.2026.
//

#include "department.h"


Department::Department(const std::string& hospitalName, int numberOfDoctors):hospitalName(hospitalName), numberOfDoctors(numberOfDoctors) {}

std::string Department::toString() {
    return "Hospital: " + this->hospitalName + " | Doctors: " + std::to_string(this->numberOfDoctors);
}

// getters
std::string Department::getHospitalName() const {
    return this->hospitalName;
}
int Department::getNumberOfDoctors() const {
    return this->numberOfDoctors;
}
