//
// Created by Maria on 05.05.2026.
//

#include "analysis.h"


MedicalAnalysis::MedicalAnalysis(const std::string& date): date{date} {};

std::string MedicalAnalysis::toString() const{
    return "Analysis: Date: " +date;
}

std::string MedicalAnalysis::getDate() const {
    return date;
}