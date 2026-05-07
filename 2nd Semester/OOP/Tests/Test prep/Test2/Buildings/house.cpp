//
// Created by Maria on 04.05.2026.
//

#include "house.h"

House::House(const std::string& address, int constructionYear, const std::string& type, bool isHistorical):Building{address,constructionYear}, type{type}, isHistorical{isHistorical} {};

bool House::mustBeRestored() {
    if (2026-constructionYear>100)
        return true;
    return false;
}

bool House::canBeDemolished() {
    if (isHistorical)
        return false;
    return true;
}

std::string House::toString() {
    return Building::toString() + " | Type: " + type + " | Historical: " + std::to_string(isHistorical) + "\n";
}