//
// Created by Maria on 07.05.2026.
//

#ifndef REALESTATE2TEST2OOP_AGENCY_H
#define REALESTATE2TEST2OOP_AGENCY_H
#include <vector>

#include "dwelling.h"
#include "client.h"

class RealEstateAgency {
private:
    std::vector<Dwelling*> dwellings;
    std::vector<Client*> clients;
public:
    RealEstateAgency();
    Dwelling* addDwelling(const std::string& type, double price, bool isProfitable);
    bool removeClient(const std::string& name);
    std::vector<Client*> getAllClients()const;
    std::vector<Dwelling*> getAllDwellings()const;
    std::vector<Client*> getInterestedClients(Dwelling* d);
    void writeToFile(const std::string& filename);
    ~RealEstateAgency();
};



#endif //REALESTATE2TEST2OOP_AGENCY_H
