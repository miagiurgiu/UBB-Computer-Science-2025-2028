//
// Created by Maria on 07.05.2026.
//

#ifndef T2_MIAGIURGIU_1_INDEPENDENT_H
#define T2_MIAGIURGIU_1_INDEPENDENT_H
#include <string>
#include "county.h"

class Independent:public County {
private:
    std::string name;
    int votes;
    int number;
public:
    Independent(const std::string& name, int votes);
    bool eligible() override;
    int mandates() override;
    std::string toString() override;

};



#endif //T2_MIAGIURGIU_1_INDEPENDENT_H
