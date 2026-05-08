//
// Created by Maria on 07.05.2026.
//
#include "../service/service.h"
#include "../ui/ui.h"

int main() {
    Service service;
    UI ui{service};
    ui.run();
    return 0;
}