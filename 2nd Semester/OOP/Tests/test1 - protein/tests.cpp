#include "../tests/tests.h"
#include "../domain/protein.h"
#include "../repo/repo.h"
#include "../service/service.h"
#include <cassert>
#include <iostream>


void test_repo() {
    Repo repo;
    int initial_size=repo.get_all().get_size();

    // test add unique prorein
    Protein new_protein{"ecolii", "myosin", "sdms"};
    assert(repo.add_protein(new_protein)==true);
    assert(repo.get_all().get_size()==initial_size+1);

    // test add existing protein
    Protein duplicate_protein{"ecolii", "myosin", "sdms"};
    assert(repo.add_protein(duplicate_protein)==false);

    std::cout<<"Repo tests passed\n";
}

void test_service() {
    Repo repo;
    Service service{repo};
    int initial_size=service.show_all_proteins().get_size();
    //assert(service.)
    std::cout<<"service tests passed\n";
}

void run_all_tests() {
    test_repo();
    test_service();
}