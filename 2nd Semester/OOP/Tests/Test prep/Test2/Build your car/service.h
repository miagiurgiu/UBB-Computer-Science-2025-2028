//
// Created by Maria on 06.05.2026.
//

#ifndef BUILDYOURCAROOPTEST2_SERVICW_H
#define BUILDYOURCAROOPTEST2_SERVICW_H
#include <vector>

#include "car.h"


class Service {
private:
    std::vector<Car*> cars;
public:
    Service();
    void addCar(const std::string& bodyStyle, const std::string& engineType, int autonomy);
    std::vector<Car*> getCarsWithMaxPrice(double maxPrice);
    std::vector<Car*> getAll();
    double getLastCarPrice();
    void writeToFile(const std::string& filename, std::vector<Car*> cars);
    ~Service();
};



#endif //BUILDYOURCAROOPTEST2_SERVICW_H
