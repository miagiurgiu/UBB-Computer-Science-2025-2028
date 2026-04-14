#pragma once
#include <string>

class Protein {
private:
    std::string organism;
    std::string name;
    std::string sequence;
public:
    Protein(); 
    Protein(const std::string& organism, const std::string& name, const std::string& sequence);
    bool operator==(const Protein& other);
    ~Protein();

    // getters
    std::string get_organism() const;
    std::string get_name() const;
    std::string get_sequence() const;

    // setters
    void set_organism(const std::string& organism);
    void set_name(const std::string& name);
    void set_sequence(const std::string& sequence);
};