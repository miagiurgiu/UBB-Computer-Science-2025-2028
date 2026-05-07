//
// Created by Maria on 04.05.2026.
//

#include "service.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>

Service::Service() {}

void Service::addBuilding(Building* b) {
    for (auto building : buildings) {
        if (building->getAddress()==b->getAddress()) {
            throw std::runtime_error("Duplicate building");
        }
    }
    buildings.push_back(b);
}

std::vector<Building*> Service::getAllBuildings() {
    std::vector<Building*> sorted=buildings;
    std::sort(sorted.begin(),sorted.end(), [](Building* a, Building* b) {
        return a->getConstructionYear()<b->getConstructionYear();
    });
    return sorted;
}

std::vector<Building*> Service::getAllToBeRestored() {
    std::vector<Building*> result;
    for (auto b : buildings) {
        if (b->mustBeRestored())
            result.push_back(b);
    }
    return result;
}

std::vector<Building*> Service::getAllToBeDemolished() {
    std::vector<Building*> result;
    for (auto b : buildings) {
        if (b->canBeDemolished())
            result.push_back(b);
    }
    return result;
}

void Service::writeToFile(const std::string& filename, const std::vector<Building*>& buildings) {
    std::ofstream fout(filename);
    if (!fout.is_open())
        return;
    for (auto b : buildings)
        fout << b->toString() << std::endl;
    fout.close();
}