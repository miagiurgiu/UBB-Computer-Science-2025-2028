//
// Created by Maria on 07.05.2026.
//

#ifndef T2_MIAGIURGIU_1_COUNTY_H
#define T2_MIAGIURGIU_1_COUNTY_H
#include <string>


class County {
protected:
    std::string name;
public:
    County(const std::string& name);
    virtual bool eligible()=0;
    virtual int mandates()=0;
    virtual std::string toString();
    virtual ~County()=default;

    int getTotalVotes() const;
    std::string getName() const;
};



#endif //T2_MIAGIURGIU_1_COUNTY_H
