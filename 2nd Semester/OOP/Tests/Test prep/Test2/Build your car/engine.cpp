//
// Created by Maria on 06.05.2026.
//

#include "engine.h"


Engine::Engine() :basePrice(3000){};

double Engine::getPrice() {
    return basePrice;
}
std::string Engine::toString() {
    return "Base price: " + std::to_string(basePrice);
}