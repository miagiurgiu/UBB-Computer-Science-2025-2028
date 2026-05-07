//
// Created by Maria on 06.05.2026.
//

#include "electric.h"


ElectricEngine::ElectricEngine(int autonomy): Engine{}, autonomy {autonomy} {};


double ElectricEngine::getPrice() {
    return basePrice + autonomy*0.01;
}

std::string ElectricEngine::toString() {
    return "ElectricEngine: " + Engine::toString() + " | Autonomy: " + std::to_string(autonomy);
}