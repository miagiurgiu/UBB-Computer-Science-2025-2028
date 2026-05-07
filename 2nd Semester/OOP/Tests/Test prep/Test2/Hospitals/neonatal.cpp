//
// Created by Maria on 30.04.2026.
//

#include "neonatal.h"

Neonatal::Neonatal(const std::string& hospitalName, int numberOfDoctors, int numberOfMothers, int numberOfNewborns, double averageGrade):Department{hospitalName, numberOfDoctors}, numberOfMothers{numberOfMothers}, numberOfNewborns{numberOfNewborns}, averageGrade {averageGrade} {};

bool Neonatal::isEfficient() {
    return this->averageGrade > 8.5;
}

std::string Neonatal::toString() {
    return Department::toString() + " | Newborns: " + std::to_string(numberOfNewborns) + " | Grade: " + std::to_string(averageGrade) + " (Neonatal)";
}
