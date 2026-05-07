//
// Created by Maria on 07.05.2026.
//

#include "service/agency.h"
#include "ui/ui.h"

int main() {
    RealEstateAgency agency;
    UI ui(agency);
    ui.run();
    return 0;
}
