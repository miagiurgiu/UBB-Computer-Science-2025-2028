//
// Created by Maria on 07/07/2026.
//

#ifndef PRACTICALEXAM_RETAKE_MIAGIURGIU_CHEF_H
#define PRACTICALEXAM_RETAKE_MIAGIURGIU_CHEF_H


#include <string>

class Chef {
private:
    std::string name;
    std::string speciality;
public:
    Chef(const std::string& name,const std::string& speciality);
    std::string getName() const;
    std::string getSpeciality() const;
};



#endif //PRACTICALEXAM_RETAKE_MIAGIURGIU_CHEF_H
