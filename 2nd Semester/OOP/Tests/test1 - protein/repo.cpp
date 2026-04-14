#include "../repo/repo.h"
#include "../domain/protein.h"

Repo::Repo() {
    this->proteins.add(Protein{"Human", "Myosin-2", "SDMS"});
    this->proteins.add(Protein{"Human", "Keratin", "TCGS"});
    this->proteins.add(Protein{"Human22", "Keratin", "vls"});
    this->proteins.add(Protein{"Human2", "Myosin-22", "SDMST"});
    this->proteins.add(Protein{"Human3", "Myosin-23", "SDMSV"});
    this->proteins.add(Protein{"Human4", "Myosin-24", "SDMSQ"});
    this->proteins.add(Protein{"Human4", "Myosin-25", "SDMSE"});
}

/*
receives an object protein
iterates through our dynamic array of proteins
checks if there exists the given protein already
if yes, returns false 
otherwise, means it does not exist and it adds it to the array
*/
bool Repo::add_protein(const Protein& p) {
    for(int i=0; i<this->proteins.get_size(); i++)
    {
        if(this->proteins.get_elem(i)==p) // already exists
        {
            return false;
        }
    }
    this->proteins.add(p);
    return true;
}
DynamicArray Repo::get_all() const {
    return this->proteins;
}