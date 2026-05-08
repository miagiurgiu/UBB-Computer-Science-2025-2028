//
// Created by Maria on 07.05.2026.
//

#include "independent.h"


Independent::Independent(const std::string& name, int votes):County{name},votes{votes}{};

bool Independent::eligible() {
    return 8*100/votes || 9*100/votes || 10*100/votes;
}
int Independent::mandates() {
    return 0;
}
std::string Independent::toString() {
    return County::toString() + " | Eligible: " + std::to_string(eligible()) + " | Mandates: " + std::to_string(mandates()) + " (Independent) " +'\n';
}