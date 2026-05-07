//
// Created by Maria on 05.05.2026.
//

#include "person.h"
#include "bmi.h"
#include "bp.h"
#include <fstream>

Person::Person(const std::string& name): name(name) {
    // hard-coded analyses
    MedicalAnalysis* bmi1=new BMI("2025.10.11",18.1);
    MedicalAnalysis* bmi2=new BMI("2025.11.01",18.0);
    MedicalAnalysis* bp1=new BP("2026.04.11",100,61);
    MedicalAnalysis* bp2=new BP("2026.03.15",190,68);
    analyses.push_back(bmi1);
    analyses.push_back(bmi2);
    analyses.push_back(bp1);
    analyses.push_back(bp2);
};

void Person::addAnalysis(MedicalAnalysis* a) {
    analyses.push_back(a);
}

std::vector<MedicalAnalysis*> Person::getAllAnalyses() {
    return analyses;
}

std::vector<MedicalAnalysis*> Person::getAnalysesByMonth(int month) {
    std::vector<MedicalAnalysis*> result;
    for (auto a: analyses) {
        int amonth=std::stoi(a->getDate().substr(5,2));
        if (amonth == month) {
            result.push_back(a);
        }
    }
    return result;
}

bool Person::isIll(int month) {
    auto analysesThisMonth=getAnalysesByMonth(month);
    if (analysesThisMonth.empty()) {
        return false;
    }
    for (auto a: analysesThisMonth) {
        if (a->isResultOK()) // is ill if ALL analyses are not ok
            return false;
    }
    return true;
}

std::vector<MedicalAnalysis*> Person::getAnalysesBetweenDates(const std::string& date1, const std::string& date2) {
    std::vector<MedicalAnalysis*> analyses=getAllAnalyses();
    std::vector<MedicalAnalysis*> result;
    //int monthDate1=std::stoi(date1.substr(5,2));
    //int monthDate2=std::stoi(date2.substr(5,2));
    for (auto a: analyses) {
        int month=std::stoi(a->getDate().substr(5,2));
        //if (monthDate1<month && month>monthDate2)
        if (a->getDate()>=date1 && a->getDate()<=date2)
            result.push_back(a);
    }
    return result;
}

void Person::writeToFile(const std::string& filename, const std::string& date1, const std::string& date2) {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        return;
    }
    std::vector<MedicalAnalysis*> analyses=getAnalysesBetweenDates(date1,date2); // between dates!!
    for (auto a: analyses) {
        fout<<a->toString()<<" | Result: "<<(a->isResultOK() ? "OK":"NOT OK")<<'\n';
    }
    fout.close();
}

std::string Person::getName()const {
    return name;
}

Person::~Person() {
    for (auto a: analyses) {
        delete a;
    }
}