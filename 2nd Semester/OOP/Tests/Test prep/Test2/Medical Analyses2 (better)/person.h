//
// Created by Maria on 05.05.2026.
//

#ifndef MEDICALANALYSISREDONETEST2OOP_PERSON_H
#define MEDICALANALYSISREDONETEST2OOP_PERSON_H
#include <string>
#include "analysis.h"
#include <vector>

class Person {
private:
    std::string name;
    std::vector<MedicalAnalysis*> analyses;
public:
    Person(const std::string& name);
    void addAnalysis(MedicalAnalysis* a);
    std::vector<MedicalAnalysis*> getAllAnalyses();
    std::vector<MedicalAnalysis*> getAnalysesByMonth(int month);
    bool isIll(int month);
    std::vector<MedicalAnalysis*> getAnalysesBetweenDates(const std::string& date1, const std::string& date2);
    void writeToFile(const std::string& filename, const std::string& date1, const std::string& date2);
    ~Person();

    std::string getName()const;
};



#endif //MEDICALANALYSISREDONETEST2OOP_PERSON_H
