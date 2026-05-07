//
// Created by Maria on 05.05.2026.
//

#ifndef MEDICALANALYSISREDONETEST2OOP_ANALYSIS_H
#define MEDICALANALYSISREDONETEST2OOP_ANALYSIS_H
#include <string>


class MedicalAnalysis {
protected:
    std::string date;
public:
    MedicalAnalysis(const std::string& date);
    virtual bool isResultOK()const=0;
    virtual std::string toString() const ;
    virtual ~MedicalAnalysis()=default;
    std::string getDate() const;
};



#endif //MEDICALANALYSISREDONETEST2OOP_ANALYSIS_H
