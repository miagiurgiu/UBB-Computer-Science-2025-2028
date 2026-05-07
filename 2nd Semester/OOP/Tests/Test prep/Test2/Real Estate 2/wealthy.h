//
// Created by Maria on 07.05.2026.
//

#ifndef REALESTATE2TEST2OOP_WEALTHY_H
#define REALESTATE2TEST2OOP_WEALTHY_H
#include "client.h"
#include <string>


class WealthyClient: public Client {
private:
    double moneyFromInvestments;
public:
    WealthyClient(const std::string& name, double salary, double moneyFromInvestments);
    double totalIncome() override;
    std::string toString() override;
    bool isInterested(Dwelling *d) override;
};



#endif //REALESTATE2TEST2OOP_WEALTHY_H
