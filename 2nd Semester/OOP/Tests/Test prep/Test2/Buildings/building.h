//
// Created by Maria on 04.05.2026.
//

#ifndef BUILDINGSTEST2OOP_BUILDING_H
#define BUILDINGSTEST2OOP_BUILDING_H
#include <string>


class Building {
protected:
    std::string address;
    int constructionYear;
public:
    Building(const std::string &address, int constructionYear);
    virtual bool mustBeRestored()=0;
    virtual bool canBeDemolished()=0;
    virtual std::string toString();
    virtual ~Building()=default;

    // getters
    std::string getAddress() const;
    int getConstructionYear() const;
};



#endif //BUILDINGSTEST2OOP_BUILDING_H
