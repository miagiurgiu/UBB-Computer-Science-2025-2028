//
// Created by Maria on 07.05.2026.
//

#include "agency.h"
#include "normal.h"
#include <fstream>

#include "wealthy.h"

RealEstateAgency::RealEstateAgency() {
    Dwelling* d1=new Dwelling("big dwelling", 19999.9, 0);
    dwellings.push_back(d1);
    Client* c1=new NormalClient("Mia", 11000.2);
    clients.push_back(c1);
    Client* c2=new WealthyClient("it consulting",29999.9, 100000);
    clients.push_back(c2);
    Client* c3=new WealthyClient("my consulting",1009.9, 2000);
    clients.push_back(c3);
};

Dwelling* RealEstateAgency::addDwelling(const std::string& type, double price, bool isProfitable) {
    Dwelling* d=new Dwelling(type, price, isProfitable);
    dwellings.push_back(d);
    return d;
}

bool RealEstateAgency::removeClient(const std::string& name) {
    for (int i=0; i<clients.size(); i++) {
        if (clients[i]->getName()==name) {
            delete clients[i];
            clients.erase(clients.begin()+i);
            return true;
        }
    }
    return false;
}

std::vector<Client*> RealEstateAgency::getAllClients()const {
    return clients;
}

std::vector<Dwelling*> RealEstateAgency::getAllDwellings()const {
    return dwellings;
}


std::vector<Client*> RealEstateAgency::getInterestedClients(Dwelling* d){
    std::vector<Client*> interestedClients;
    for (auto c:clients) {
        if (c->isInterested(d))
            interestedClients.push_back(c);
    }
    return interestedClients;
}

void RealEstateAgency::writeToFile(const std::string& filename) {
    std::ofstream fout(filename);
    if (!fout.is_open()) return;
    std::vector<Client*> clients=getAllClients();
    for (auto c:clients) {
        fout<<c->toString()<<"\n";
    }
    fout.close();
}

RealEstateAgency::~RealEstateAgency() { /// !!!
    for (auto d:dwellings)
        delete d;
    for (auto c:clients)
        delete c;
}