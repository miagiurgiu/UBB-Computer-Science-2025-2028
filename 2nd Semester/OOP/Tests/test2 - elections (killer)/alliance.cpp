//
// Created by Maria on 07.05.2026.
//

#include "alliance.h"


Alliance::Alliance(const std::string& name, int votes, int number):County{name},votes{votes},number{number} {};

bool Alliance::eligible() {
    return false;
}
int Alliance::mandates() {
    return 0;
}
std::string Alliance::toString() {
    return County::toString() + " | Name: " + name + " | Nr votes: " + std::to_string(votes) + " | Number of parties: " + std::to_string(number) + " (Alliance) " + '\n';
}
int Alliance::getVotes() const{
    return votes;
}
int Alliance::getNumber() const{
    return number;
}