//
// Created by Maria on 06.05.2026.
//

#include "car.h"


Car::Car(const std::string& bodyStyle, Engine* engine): bodyStyle{bodyStyle}, engine{engine} {};

double Car::computePrice() {
    double bodyPrice=0;
    if (bodyStyle=="Sedan")
        bodyPrice=8000;
    else if (bodyStyle=="Convertible")
        bodyPrice=8000+1000;
    return bodyPrice+engine->getPrice();
}

std::string Car::toString() {
    return "Car: Body style: " + bodyStyle + " | Engine: " + engine->toString() + " Price: " + std::to_string(computePrice()) + '\n';
}

Car::~Car() {
    delete engine;
}