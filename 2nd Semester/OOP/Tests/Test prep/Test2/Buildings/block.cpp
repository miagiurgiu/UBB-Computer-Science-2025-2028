//
// Created by Maria on 04.05.2026.
//

#include "block.h"

Block::Block(const std::string& address, int constructionYear, int totalApartments, int occupiedApartments) : Building{address,constructionYear}, totalApartments{totalApartments}, occupiedApartments{occupiedApartments} {};

bool Block::mustBeRestored() {
    int percentage=occupiedApartments*100/totalApartments;
    if (2026-constructionYear>40 && percentage>80)
        return true;
    return false;
}

bool Block::canBeDemolished() {
    int percentage=occupiedApartments*100/totalApartments;
    if (percentage<5)
        return true;
    return false;
}

std::string Block::toString() {
    return Building::toString() + " | Total apartments: " + std::to_string(totalApartments) + " | Occupied apartments: " + std::to_string(occupiedApartments) + "\n";
}