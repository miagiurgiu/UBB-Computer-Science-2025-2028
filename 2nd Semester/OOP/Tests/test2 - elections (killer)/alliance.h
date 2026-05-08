//
// Created by Maria on 07.05.2026.
//

#ifndef T2_MIAGIURGIU_1_ALLIANCE_H
#define T2_MIAGIURGIU_1_ALLIANCE_H
#include "county.h"


class Alliance:public County {
private:
    std::string name;
    int votes;
    int number;
public:
    Alliance(const std::string& name, int votes, int number);
    bool eligible() override;
    int mandates() override;
    std::string toString() override;
    int getVotes() const;
    int getNumber() const;
};



#endif //T2_MIAGIURGIU_1_ALLIANCE_H
