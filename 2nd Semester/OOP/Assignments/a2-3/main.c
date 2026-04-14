#include "../repository/repo_static.h"
#include "../service/service_static.h"
#include "../ui/ui.h"

int main() {
    Repository repo = create_repository();
    Service service = create_service(&repo); // give address of repo
    UI ui = create_ui(&service); // give address of service
    add_default_products(&service); 
    run(&ui); // give address of ui
    return 0;
}