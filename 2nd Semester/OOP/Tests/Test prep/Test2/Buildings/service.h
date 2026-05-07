//
// Created by Maria on 04.05.2026.
//

#ifndef BUILDINGSTEST2OOP_SERVICE_H
#define BUILDINGSTEST2OOP_SERVICE_H
#include "../domain/building.h"
#include <vector>

class Service {
private:
    std::vector<Building*> buildings;
public:
    Service();
    void addBuilding(Building* b);
    std::vector<Building*> getAllBuildings();
    std::vector<Building*> getAllToBeRestored();
    std::vector<Building*> getAllToBeDemolished();
    void writeToFile(const std::string& filename, const std::vector<Building*>& buildings);
};



#endif //BUILDINGSTEST2OOP_SERVICE_H
