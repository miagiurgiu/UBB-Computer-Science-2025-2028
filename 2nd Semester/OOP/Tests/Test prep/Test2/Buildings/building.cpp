//
// Created by Maria on 04.05.2026.
//

#include "building.h"

Building::Building(const std::string &address, int constructionYear): address(address), constructionYear(constructionYear) {};

// getters
std::string Building::getAddress() const {
    return address;
}
int Building::getConstructionYear() const {
    return constructionYear;
}

std::string Building::toString() {
    return "Address: " + address + " | Construction Year: " + std::to_string(constructionYear) ;
}