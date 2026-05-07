//
// Created by Maria on 06.05.2026.
//

#include "service.h"
#include "turbo.h"
#include "electric.h"
#include <fstream>

Service::Service() {
    Car* c1=new Car("Sedan", new ElectricEngine(500));
    cars.push_back(c1);
    Car* c2=new Car("Sedan", new Turbo());
    cars.push_back(c2);
    Car* c3=new Car("Convertible", new ElectricEngine(240));
    cars.push_back(c3);
};

void Service::addCar(const std::string& bodyStyle, const std::string& engineType, int autonomy) {
    Engine* newEngine;
    if (engineType == "turbo") {
        newEngine = new Turbo();
    }
    else if (engineType == "electric") {
        newEngine = new ElectricEngine(autonomy);
    }
    Car* newCar = new Car(bodyStyle, newEngine);
    cars.push_back(newCar);
}

std::vector<Car*> Service::getAll() {
    return this->cars;
}

double Service::getLastCarPrice() {
    if (cars.empty()) {
        return 0;
    }
    return cars.back()->computePrice();
}

std::vector<Car*> Service::getCarsWithMaxPrice(double maxPrice) {
    auto cars=getAll();
    std::vector<Car*> result;
    for (auto c:cars) {
        if (c->computePrice()<maxPrice) {
            result.push_back(c);
        }
    }
    return result;
}

void Service::writeToFile(const std::string& filename, std::vector<Car*> cars) {
    std::ofstream fout(filename);
    if (!fout.is_open()) return;
    // sort ascending by price
    std::sort(cars.begin(),cars.end(),[](Car* c1, Car* c2) {
        return c1->computePrice()<c2->computePrice();
    });

    for (auto car:cars) {
        fout<<car->toString()<<'\n';
    }
    fout.close();
}

Service::~Service() {
    for (auto car:cars) {
        delete car;
    }
}
