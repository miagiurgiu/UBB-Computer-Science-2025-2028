//
// Created by Maria on 06.05.2026.
//

#ifndef BUILDYOURCAROOPTEST2_CAR_H
#define BUILDYOURCAROOPTEST2_CAR_H
#include <string>
#include "engine.h"

class Car {
private:
    std::string bodyStyle;
    Engine* engine; // composition!!
public:
    Car(const std::string& bodyStyle, Engine* engine);
    double computePrice();
    std::string toString();
    ~Car();
};



#endif //BUILDYOURCAROOPTEST2_CAR_H
