//
// Created by Maria on 07.05.2026.
//

#include "county.h"


County::County(const std::string& name):name{name}{};

std::string County::toString(){
    return "County: Name: "+ name;
}

std::string County::getName() const {
    return name;
}

int County::getTotalVotes() const {
    return 0;
}