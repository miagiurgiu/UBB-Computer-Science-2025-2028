//
// Created by Maria on 04.05.2026.
//

#include "service/service.h"
#include "domain/block.h"
#include "domain/house.h"
#include "ui/ui.h"

int main() {
    Service service;
    service.addBuilding(new Block("bloc_init", 1980, 50, 45));
    service.addBuilding(new House("casa_init", 1900, "duplex", true));
    UI ui{service};
    ui.run();
    return 0;
}