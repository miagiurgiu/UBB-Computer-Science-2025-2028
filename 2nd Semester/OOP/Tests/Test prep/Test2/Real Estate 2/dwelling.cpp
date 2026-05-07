//
// Created by Maria on 07.05.2026.
//

#include "dwelling.h"


Dwelling::Dwelling(const std::string &type, double price, bool isProfitable):type{type},price{price},isProfitable{isProfitable} {};

double Dwelling::normalBankRate() {
    return price/1000;
}

double Dwelling::largerBankRate() {
    return price/100;
}

bool Dwelling::getIsProfitable() {
    return isProfitable;
}

std::string Dwelling::toString() {
    return "Dwelling | Type: " + type + " | Price: " + std::to_string(price) + " | IsProfitable: " + std::to_string(isProfitable) + '\n';
}