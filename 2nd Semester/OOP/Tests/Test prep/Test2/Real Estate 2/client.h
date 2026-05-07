//
// Created by Maria on 07.05.2026.
//

#ifndef REALESTATE2TEST2OOP_CLIENT_H
#define REALESTATE2TEST2OOP_CLIENT_H
#include <string>
#include "dwelling.h"

class Client {
protected:
    std::string name;
    double salary;
public:
    Client(const std::string &name, double salary);
    virtual double totalIncome()=0;
    virtual std::string toString();
    virtual bool isInterested(Dwelling* d)=0;
    std::string getName();
    virtual ~Client()=default;
};



#endif //REALESTATE2TEST2OOP_CLIENT_H
