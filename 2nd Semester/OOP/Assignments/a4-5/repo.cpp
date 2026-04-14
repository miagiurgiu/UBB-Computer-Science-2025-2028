#include "../repo/repo.h"
#include "../domain/coat.h"


Repository::Repository() {
    this->coats.add(Coat{"S", "black", 120, 10, "website/coat1.html"});
    this->coats.add(Coat{"M", "beige", 150, 8, "https://media.istockphoto.com/id/1294329344/ro/fotografie/fotografie-de-femeie-veselă-creț.jpg?s=612x612&w=is&k=20&c=8dYUnPa8yNDNMsoi3PCsMMl_AVMaCUozamzDVzcRq6c="});
    this->coats.add(Coat{"L", "grey", 180, 5, "https://media.istockphoto.com/id/1430670851/ro/fotografie/femeia-matură-elegantă-se-plimbă-pe-strada-orașului-poartă-haine-elegante-haină-de-lână.jpg?s=612x612&w=is&k=20&c=kMFYlnLNhAaE-w7J5W2tOV1j8_cnhE24B_Th_rVOmM4="});
    this->coats.add(Coat{"XL", "navy", 200, 7, "https://media.istockphoto.com/id/1487973931/ro/fotografie/om-de-afaceri-musulman-de-mers-pe-jos-om-de-afaceri-arab.jpg?s=612x612&w=is&k=20&c=OxirAtm4tvzp6WmmqwjRDBp0zx0Smh5f7oAVT61AUAg="});
    this->coats.add(Coat{"XS", "white", 110, 6, "https://media.istockphoto.com/id/2224667666/ro/fotografie/trenci-de-culoare-bej-izolat-pe-alb-îmbrăcăminte-feminină-îmbrăcăminte-pentru-femei.jpg?s=612x612&w=is&k=20&c=QQ_lbvSuVmfbNGv3sAMyoahW1Kap-8KJFbcMYMYmTIA="});
    this->coats.add(Coat{"M", "brown", 170, 9, "https://media.istockphoto.com/id/1334820536/ro/fotografie/figură-decupată-de-tânără-care-poartă-palton-elegant-maro-straniu-street-concept-casual.jpg?s=612x612&w=is&k=20&c=Adlz6onTTqihqlcnt5ACRxBjMavqTN57Dc68Wk6IrN0="});
    this->coats.add(Coat{"L", "cream", 190, 4, "https://media.istockphoto.com/id/2184484920/ro/fotografie/femeie-fericită-pe-drumul-de-întoarcere-de-la-cumpărături.jpg?s=612x612&w=is&k=20&c=9XzsuTgmOpJCi72WXVw-68CB4QaagyU6kT_jOwBP3Z8="});
    this->coats.add(Coat{"S", "red", 160, 3, "https://media.istockphoto.com/id/519977229/ro/fotografie/stilul-în-oraș.jpg?s=612x612&w=is&k=20&c=oS5R4p322L9z0c6RX5s6INpmDmsgrSUGL6D7gAT07eg="});
    this->coats.add(Coat{"XL", "green", 175, 11, "https://media.istockphoto.com/id/2011096902/ro/fotografie/fotografie-de-tânără-femeie-frumoasă-și-frumoasă-zâmbitoare-fericită-purtând-elegant.jpg?s=612x612&w=is&k=20&c=4Bz2W2tSrDDb6oPzJdr6bMcXnA1jSc3pG-4mpzu76lE="});
    this->coats.add(Coat{"M", "blue", 145, 12, "https://media.istockphoto.com/id/833018084/ro/fotografie/bleumarin-elegant-femeie-haina-de-toamna-izolat-alb.jpg?s=612x612&w=is&k=20&c=XGSTBZN4PvY5R1l3uJtDSDWGcvl_GN3WKCpp7OYU2ok="});
}

bool Repository::add_coat(const Coat& c) {
    for (int i=0; i<this->coats.get_size(); i++)
        if(this->coats.get_elem(i)==c) // checks the whole object c?? not just color and size?
            return false;
    this->coats.add(c);
    return true;
}

bool Repository::delete_coat(const std::string& size, const std::string& colour) {
    for(int i=0; i<this->coats.get_size(); i++) {
        Coat c = this->coats.get_elem(i);
        if(c.get_size() == size && c.get_colour() == colour) {
            this->coats.remove(i);
            return true;
        }
    }
    return false;
}

bool Repository::update_coat(const Coat& c) {
    for (int i=0; i<this->coats.get_size(); i++) {
        if (this->coats.get_elem(i) == c) {
            this->coats.remove(i);
            this->coats.add(c);
            return true;
        }
    }
    return false;
}

DynamicVector<Coat> Repository::get_all() const {
    return this->coats;
}