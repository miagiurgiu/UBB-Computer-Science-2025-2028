#pragma once
#include "../domain/protein.h"
#include "../repo/dynamic_array.h"

class Repo {
private:
    DynamicArray proteins;
public:
    Repo();
    bool add_protein(const Protein& p);
    DynamicArray get_all() const;
};