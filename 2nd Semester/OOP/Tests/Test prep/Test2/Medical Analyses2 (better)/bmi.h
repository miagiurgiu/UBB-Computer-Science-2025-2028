//
// Created by Maria on 05.05.2026.
//

#ifndef MEDICALANALYSISREDONETEST2OOP_BMI_H
#define MEDICALANALYSISREDONETEST2OOP_BMI_H
#include "analysis.h"


class BMI:public MedicalAnalysis {
private:
    double value;
public:
    BMI(const std::string& date, double value);
    bool isResultOK() const override;
    std::string toString() const override;
};



#endif //MEDICALANALYSISREDONETEST2OOP_BMI_H
