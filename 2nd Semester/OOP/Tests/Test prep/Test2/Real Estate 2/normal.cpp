//
// Created by Maria on 07.05.2026.
//

#include "normal.h"


NormalClient::NormalClient(const std::string& name, double salary):Client(name, salary) {};

double NormalClient::totalIncome() { // !!!
    return salary; // !!!
}

bool NormalClient::isInterested(Dwelling *d) {
    return d->normalBankRate()<=salary;
}

std::string NormalClient::toString() {
    return Client::toString() + " | Total income: " + std::to_string(salary) + + " | Normal" + '\n';
}