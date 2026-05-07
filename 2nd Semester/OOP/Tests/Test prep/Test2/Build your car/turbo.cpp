//
// Created by Maria on 06.05.2026.
//

#include "turbo.h"


Turbo::Turbo(): Engine{} {};


double Turbo::getPrice() {
    return basePrice + 100;
}

std::string Turbo::toString() {
    return "Turbo: " + Engine::toString();
}