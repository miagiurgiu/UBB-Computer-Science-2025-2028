//
// Created by Maria on 06.05.2026.
//

#ifndef BUILDYOURCAROOPTEST2_ENGINE_H
#define BUILDYOURCAROOPTEST2_ENGINE_H
#include <string>


class Engine {
protected:
    double basePrice;
public:
    Engine();
    virtual double getPrice();
    virtual std::string toString();
    virtual ~Engine()=default;
};



#endif //BUILDYOURCAROOPTEST2_ENGINE_H
