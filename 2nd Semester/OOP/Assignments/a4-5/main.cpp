#include "../repo/repo.h"
#include "../service/service.h"
#include "../ui/ui.h"
#include "../tests/tests.h"

int main() {
    run_all_tests();
    Repository repo;
    Service service{repo};
    UI ui{service};

    ui.runApplication();
    return 0;
}

