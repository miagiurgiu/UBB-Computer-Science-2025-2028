//
// Created by Maria on 05.05.2026.
//

#include "bmi.h"

BMI::BMI(const std::string& date, double value):MedicalAnalysis{date}, value{value} {};

bool BMI::isResultOK() const {
    return value >=18.5 && value<=25;
}

std::string BMI::toString() const{
    return MedicalAnalysis::toString() + " | BMI | Value: " + std::to_string(value) +'\n';
}