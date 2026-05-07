//
// Created by Maria on 05.05.2026.
//

#include "bp.h"

BP::BP(const std::string& date, int systolicValue, int diastolicValue):MedicalAnalysis{date},systolicValue{systolicValue},diastolicValue{diastolicValue} {};

bool BP::isResultOK() const {
    return systolicValue>=90 && systolicValue<=119 && diastolicValue>=60 && diastolicValue<=79;
}

std::string BP::toString() const {
    return MedicalAnalysis::toString()+" | BP | Systolic value: "+std::to_string(systolicValue)+" | Diastolic value: "+std::to_string(diastolicValue)+"\n";
}