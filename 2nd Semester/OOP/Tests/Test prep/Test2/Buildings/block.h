//
// Created by Maria on 04.05.2026.
//

#ifndef BUILDINGSTEST2OOP_BLOCK_H
#define BUILDINGSTEST2OOP_BLOCK_H
#include "building.h"
#include <string>

class Block: public Building {
private:
    int totalApartments;
    int occupiedApartments;
public:
    Block(const std::string& address, int constructionYear, int totalApartments, int occupiedApartments);
    bool mustBeRestored() override;
    bool canBeDemolished() override;
    std::string toString() override;
};



#endif //BUILDINGSTEST2OOP_BLOCK_H
