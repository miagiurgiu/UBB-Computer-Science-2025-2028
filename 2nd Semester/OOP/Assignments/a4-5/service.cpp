#include "../service/service.h"

Service::Service(const Repository& r): repo{r} {};

bool Service::add_coat(const Coat& c)
{
    return this->repo.add_coat(c);
}

bool Service::delete_coat(const std::string& size, const std::string& colour)
{
    return this->repo.delete_coat(size, colour);
}

bool Service::update_coat(const Coat& c)
{
    return this->repo.update_coat(c);
}

DynamicVector<Coat> Service::get_all() const 
{
    return this->repo.get_all();
}

DynamicVector<Coat> Service::get_coats_by_size(const std::string& size) {
    DynamicVector<Coat> all_coats = this->repo.get_all();
    DynamicVector<Coat> filtered;

    if(size=="")
    {
        return all_coats;
    }

    for(int i=0; i<all_coats.get_size(); i++) 
    {
        Coat c = all_coats.get_elem(i);
        if(c.get_size() == size) 
        {
            filtered.add(c);
        }
    }
    return filtered;
}

void Service::add_to_basket(const Coat& c) {
    this->basket.add(c);
    this->total += c.get_price();
}
double Service::get_total() {
    return this->total;
}

DynamicVector<Coat> Service::get_basket() {
    return this->basket;
}