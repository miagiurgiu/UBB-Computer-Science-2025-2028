//
// Created by Maria on 07.05.2026.
//

#include "service.h"
#include "../domain/party.h"
#include "../domain/alliance.h"
#include "../domain/independent.h"
#include <fstream>

Service::Service() {
    County* c1=new Party("Name1", 20);
    County* c2=new Alliance("Name2", 30, 60);
    County* c3=new Independent("Name3", 80);
    counties.push_back(c1);
    counties.push_back(c2);
    counties.push_back(c3);
}
void Service::add(County* c) {
    counties.push_back(c);
}

std::vector<County*> Service::getAll() {
    return counties;
}

void Service::writeToFile(const std::string& filename, std::vector<County*> counties) {
    std::ofstream fout(filename);
    if (!fout.is_open()) return;
    for (auto c:counties) {
        fout<<c->toString();
    }
    fout.close();
}

int Service::getVotes() const {
    int sum=0;
    for (auto c: counties) {
        sum = sum + c->getTotalVotes();
    }
    return sum;
}