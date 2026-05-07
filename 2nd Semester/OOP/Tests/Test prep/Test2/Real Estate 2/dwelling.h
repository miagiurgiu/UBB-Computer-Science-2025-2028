//
// Created by Maria on 07.05.2026.
//

#ifndef REALESTATE2TEST2OOP_DWELLING_H
#define REALESTATE2TEST2OOP_DWELLING_H
#include <string>


class Dwelling {
private:
    std::string type;
    double price;
    bool isProfitable;
public:
    Dwelling(const std::string &type, double price, bool isProfitable);
    double normalBankRate();
    double largerBankRate();
    bool getIsProfitable();
    std::string toString();
    ~Dwelling()=default;
};



#endif //REALESTATE2TEST2OOP_DWELLING_H
