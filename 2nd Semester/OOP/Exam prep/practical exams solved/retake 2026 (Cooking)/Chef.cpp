//
// Created by Maria on 07/07/2026.
//

#include "Chef.h"

Chef::Chef(const std::string &name, const std::string &speciality):name{name},speciality{speciality} {
}

std::string Chef::getName() const {
    return name;
}

std::string Chef::getSpeciality() const {
    return speciality;
}
