#include "coat.h"

// default constructor, empty values
Coat::Coat(): size(""),colour(""),price(0),quantity(0),photo("") {}

// constructor with parameters
Coat::Coat(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo) {
    this->size = size;
    this->colour = colour;
    this->price = price;
    this->quantity = quantity;
    this->photo = photo;
}

bool Coat::operator==(const Coat& other) const { // what does "unique" mean
    return this->size == other.size && this->colour == other.colour;
}

// getters implementation
std::string Coat::get_size() const {
    return size;
}

std::string Coat::get_colour() const {
    return colour;
}

double Coat::get_price() const {
    return price;
}

int Coat::get_quantity() const {
    return quantity;
}

std::string Coat::get_photo() const {
    return photo;
}

// setters implementation
void Coat::set_price(double price) {
    this->price = price;
}

void Coat::set_quantity(int quantity) {
    this->quantity = quantity;
}

void Coat::set_colour(const std::string& colour) {
    this->colour = colour;
}

void Coat::set_size(const std::string& size) {
    this->size = size;
}
void Coat::set_photo(const std::string& photo) {
    this->photo = photo;
}