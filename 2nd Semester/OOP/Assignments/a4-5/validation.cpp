#include "../validation/validation.h"
#include <iostream>
#include <string>

bool Validation::validate_add_input(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo) {
    bool valid_size = 
        size == "XS" || size == "S" || size == "M" || size == "L" || size == "XL" || size == "XXL" || size == "XXS";

    if(!valid_size) {
        //std::cout<<"Invalid size\n";
        return false;
    }

    /*
    if (size.empty()) {
        std::cout<<"Invalid size\n";
        return false;
    }
    */

    if (colour.empty()) {
        //std::cout<<"Invalid colour\n";
        return false;
    }
    if (price < 0) {
        //std::cout<<"Invalid price\n";
        return false;
    }
    if (quantity < 0) {
        //std::cout<<"Invalid quantity\n";
        return false;
    }
    if (photo.empty()) {
        //std::cout<<"Invalid photo\n";
        return false;
    }
    return true;
}
bool Validation::validate_delete_input(const std::string& size, const std::string& colour) {
    if (size.empty()) {
        //std::cout<<"Invalid size\n";
        return false;
    }
    if (colour.empty()) {
        //std::cout<<"Invalid colour\n";
        return false;
    }
    return true;
}
bool Validation::validate_update_input(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo) {
    if (size.empty()) {
        //std::cout<<"Invalid size\n";
        return false;
    }
    if (colour.empty()) {
        //std::cout<<"Invalid colour\n";
        return false;
    }
    if (price < 0) {
       // std::cout<<"Invalid price\n";
        return false;
    }
    if (quantity < 0) {
        //std::cout<<"Invalid quantity\n";
        return false;
    }
    if (photo.empty()) {
        //std::cout<<"Invalid photo\n";
        return false;
    }
    return true;
}