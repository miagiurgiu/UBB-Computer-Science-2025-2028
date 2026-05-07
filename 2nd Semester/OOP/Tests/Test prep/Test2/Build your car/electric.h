//
// Created by Maria on 06.05.2026.
//

#ifndef BUILDYOURCAROOPTEST2_ELECTRIC_H
#define BUILDYOURCAROOPTEST2_ELECTRIC_H
#include "engine.h"


class ElectricEngine:public Engine {
private:
    int autonomy;
public:
    ElectricEngine(int autonomy);
    double getPrice() override;
    std::string toString() override;
};



#endif //BUILDYOURCAROOPTEST2_ELECTRIC_H
