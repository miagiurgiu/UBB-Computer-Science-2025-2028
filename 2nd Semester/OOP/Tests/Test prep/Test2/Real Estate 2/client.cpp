//
// Created by Maria on 07.05.2026.
//

#include "client.h"


Client::Client(const std::string &name, double salary): name(name), salary(salary) {}

std::string Client::toString() {
    return "Client | Name: " + name + " | Salary: " + std::to_string(salary);
}

std::string Client::getName() {
    return name;
}