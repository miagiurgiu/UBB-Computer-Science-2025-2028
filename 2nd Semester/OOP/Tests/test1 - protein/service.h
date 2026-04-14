#pragma once
#include "../repo/repo.h"
#include "../domain/protein.h"

class Service {
    private:
        Repo& repo;
    public:
        Service(Repo& r);
        bool add_protein(const Protein& p);
        DynamicArray show_all_proteins() const;
        DynamicArray show_proteins_sorted(const std::string& name);
};