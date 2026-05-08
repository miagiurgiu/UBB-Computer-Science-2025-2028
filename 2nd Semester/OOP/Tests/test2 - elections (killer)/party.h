//
// Created by Maria on 07.05.2026.
//

#ifndef T2_MIAGIURGIU_1_PARTY_H
#define T2_MIAGIURGIU_1_PARTY_H
#include "county.h"


class Party:public County {
private:
    std::string name;
    int votes;
public:
    Party(const std::string& name, int votes);
    bool eligible() override;
    int mandates() override;
    std::string toString() override;
    int getVotes() const;
};



#endif //T2_MIAGIURGIU_1_PARTY_H
