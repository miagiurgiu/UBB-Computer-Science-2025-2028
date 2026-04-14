#include "../repository/repo_dynamic.h"
#include "../service/service_dynamic.h"
#include "../ui/ui_dynamic.h"

int main() {
    Repository repo = create_repository();
    Service service = create_service(&repo); // give address of repo
    UI ui = create_ui(&service); // give address of service
    add_default_products(&service); 
    run(&ui); // give address of ui

    // check for memory leaks
    destroy_service(&service);
    destroy_repository(&repo);
    return 0;
}