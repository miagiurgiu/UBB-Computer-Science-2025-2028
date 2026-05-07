//
// Created by Maria on 30.04.2026.
//

#include "surgery.h"

Surgery::Surgery(const std::string& hospitalName, int numberOfDoctors, int numberOfPatients) : Department{hospitalName, numberOfDoctors}, numberOfPatients{numberOfPatients} {}

bool Surgery::isEfficient() {
    if (this->numberOfDoctors == 0) {
        return false;
    }
    return (double)this->numberOfPatients / this->numberOfDoctors >= 2;
}
std::string Surgery::toString() {
    return Department::toString() + " | Patients: " + std::to_string(numberOfPatients) + " (Surgery)";
}