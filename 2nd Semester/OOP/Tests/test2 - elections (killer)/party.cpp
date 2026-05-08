//
// Created by Maria on 07.05.2026.
//

#include "party.h"


Party::Party(const std::string& name, int votes):County{name},votes{votes} {};

bool Party::eligible() {
    return 5*100/votes;
}
std::string Party::toString() {
    return County::toString() + " | Name: "  + name +  " | Nr votes: " + std::to_string(votes) + " (Party)" + '\n';
}
int Party::getVotes() const {
    return votes;
}

int Party::mandates() {
    return 0;
}