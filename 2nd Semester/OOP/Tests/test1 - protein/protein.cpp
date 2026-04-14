#include "../domain/protein.h"

Protein::Protein() : organism(""), name(""), sequence("") {}

Protein::Protein(const std::string& organism, const std::string& name, const std::string& sequence) : organism{organism}, name{name}, sequence{sequence} {}

bool Protein::operator==(const Protein& other) {
    return this->organism==other.organism && this->name==other.name;
}
Protein::~Protein() = default;

// getters
std::string Protein::get_organism() const {
    return this->organism;
}

std::string Protein::get_name() const {
    return this->name;
}

std::string Protein::get_sequence() const {
    return this->sequence;
}

// setters
void Protein::set_organism(const std::string& organism) {
    this->organism = organism;
}

void Protein::set_name(const std::string& name) {
    this->name = name;
}

void Protein::set_sequence(const std::string& sequence) {
    this->sequence = sequence;
}