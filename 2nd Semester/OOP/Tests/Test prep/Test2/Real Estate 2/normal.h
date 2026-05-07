//
// Created by Maria on 07.05.2026.
//

#ifndef REALESTATE2TEST2OOP_NORMAL_H
#define REALESTATE2TEST2OOP_NORMAL_H
#include "client.h"


class NormalClient:public Client {
private:
public:
    NormalClient(const std::string& name, double salary);
    double totalIncome() override; // !!!
    std::string toString() override;
    bool isInterested(Dwelling *d) override;
};



#endif //REALESTATE2TEST2OOP_NORMAL_H
