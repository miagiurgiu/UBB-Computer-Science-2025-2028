#pragma once
#include <string>


class Validation {
    public:
        static bool validate_add_input(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo);
        static bool validate_delete_input(const std::string& size, const std::string& colour);
        static bool validate_update_input(const std::string& size, const std::string& colour, double price, int quantity, const std::string& photo);
};