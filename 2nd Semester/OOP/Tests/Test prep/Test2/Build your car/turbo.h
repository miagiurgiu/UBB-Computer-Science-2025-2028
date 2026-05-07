//
// Created by Maria on 06.05.2026.
//

#ifndef BUILDYOURCAROOPTEST2_TURBO_H
#define BUILDYOURCAROOPTEST2_TURBO_H
#include "engine.h"


class Turbo:public Engine {
public:
    Turbo();
    double getPrice() override;
    std::string toString() override;
};



#endif //BUILDYOURCAROOPTEST2_TURBO_H
