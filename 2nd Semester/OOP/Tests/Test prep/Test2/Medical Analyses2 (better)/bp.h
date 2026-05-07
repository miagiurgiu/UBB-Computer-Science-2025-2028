//
// Created by Maria on 05.05.2026.
//

#ifndef MEDICALANALYSISREDONETEST2OOP_BP_H
#define MEDICALANALYSISREDONETEST2OOP_BP_H
#include "analysis.h"


class BP:public MedicalAnalysis {
private:
    int systolicValue;
    int diastolicValue;
public:
    BP(const std::string& date, int systolicValue, int diastolicValue);
    bool isResultOK() const override;
    std::string toString() const override;
};



#endif //MEDICALANALYSISREDONETEST2OOP_BP_H
