#pragma once
#include "../repo/repo.h"
#include "../domain/coat.h"
#include "../repo/dynamic_vector_template.h"

class Service {
    private:
        Repository repo;
        DynamicVector<Coat> basket; // private basket
        double total;
    public:
        Service(const Repository& r); // usage: Service serv{repo};
        
        // admin functionalities
        bool add_coat(const Coat& c);
        bool delete_coat(const std::string& size, const std::string& colour);
        bool update_coat(const Coat& c);
        DynamicVector<Coat> get_all() const;

        // user functionalities
        DynamicVector<Coat> get_basket(); // shopping basket
        DynamicVector<Coat> get_coats_by_size(const std::string& size);
        void add_to_basket(const Coat& c);
        double get_total(); // 
};