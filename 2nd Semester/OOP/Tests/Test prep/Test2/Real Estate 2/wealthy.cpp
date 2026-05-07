//
// Created by Maria on 07.05.2026.
//

#include "wealthy.h"


WealthyClient::WealthyClient(const std::string &name, double salary, double moneyFromInvestments) : Client{name,salary}, moneyFromInvestments(moneyFromInvestments) {};

double WealthyClient::totalIncome() {
    return salary+moneyFromInvestments;
}

std::string WealthyClient::toString() {
    return Client::toString() + " | Money from investments: " + std::to_string(moneyFromInvestments) + " | Total income: " + std::to_string(totalIncome()) + " | Wealthy" + "\n";
}

bool WealthyClient::isInterested(Dwelling *d) {
    return d->largerBankRate()<=totalIncome() && d->getIsProfitable();
}