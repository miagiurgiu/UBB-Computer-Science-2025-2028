#pragma once
#include "../domain/coat.h"
#include "../repo/dynamic_vector_template.h"

class Repository {
private:
    DynamicVector<Coat>coats;
public:
    Repository(); // usage: Repository repo;
    bool add_coat(const Coat& c);
    bool delete_coat(const std::string& size, const std::string& colour);
    bool update_coat(const Coat& c);
    DynamicVector<Coat> get_all() const;
};