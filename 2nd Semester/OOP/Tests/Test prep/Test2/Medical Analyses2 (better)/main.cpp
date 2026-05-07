//
// Created by Maria on 05.05.2026.
//

#include "../repo/person.h"
#include "../ui/ui.h"
int main() {
    Person person{"Mia"};
    UI ui{person};
    ui.run();
    return 0;
}
