//
// Created by Maria on 04.05.2026.
//

#ifndef BUILDINGSTEST2OOP_HOUSE_H
#define BUILDINGSTEST2OOP_HOUSE_H
#include "building.h"


class House: public Building {
private:
    std::string type;
    bool isHistorical;
public:
    House(const std::string& address, int constructionYear, const std::string& type, bool isHistorical);
    bool mustBeRestored() override;
    bool canBeDemolished() override;
    std::string toString() override;
};



#endif //BUILDINGSTEST2OOP_HOUSE_H
