#include "../service/service.h"

Service:: Service(Repo& r) : repo{r} {}

bool Service::add_protein(const Protein& p) {
    return this->repo.add_protein(p);
}
DynamicArray Service::show_all_proteins() const {
    return this->repo.get_all();
}

/*
FUNCTION that shows sorted protains by name
receives from repo the whole array
traverses the array searching for the name given as parameter
adds it to a new array
traverse that array and do bubblesort on it
return the sorted array
*/
DynamicArray Service::show_proteins_sorted(const std::string& name) {
    DynamicArray proteins_chosen;
    DynamicArray proteins = this->repo.get_all();
    for(int i=0; i<proteins.get_size(); i++)
    {
        Protein p=proteins.get_elem(i);
        if(p.get_name()==name)
            proteins_chosen.add(p);
    }
    for(int i=0; i<proteins_chosen.get_size()-1; i++)
    {
        for(int j=i+1; j<proteins_chosen.get_size(); j++)
        {
            Protein p1=proteins_chosen.get_elem(i);
            Protein p2=proteins_chosen.get_elem(j);
            if (p1.get_organism()>p2.get_organism())
            {
                proteins_chosen.set_elem(i,p1);
                proteins_chosen.set_elem(j,p2);
            }
        }
    }
    return proteins_chosen;
}