#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../repository/dynamic_array.h"
#include "../repository/repo_dynamic.h"
#include "../service/service_dynamic.h"
#include "../domain/product.h"

void test_create_dynamic_array() {
    DynamicArray* arr = create_dynamic_array(5);
    assert(arr != NULL);
    assert(arr->capacity == 5);
    assert(arr->size == 0);
    destroy_dynamic_array(arr);
}

void test_add() {
    DynamicArray* arr = create_dynamic_array(2);

    Product p1 = create_product("milk", "dairy", 10,10,5,2026);
    Product p2 = create_product("apple", "fruit", 5,12,5,2026);

    add(arr,p1);
    add(arr,p2);

    assert(arr->size==2);
    assert(strcmp(arr->elems[0].name,"milk")==0);
    assert(strcmp(arr->elems[1].name,"apple")==0);

    destroy_dynamic_array(arr);
}

void test_resize() {
    DynamicArray* arr = create_dynamic_array(1);

    Product p1 = create_product("milk", "dairy", 10,10,5,2026);
    Product p2 = create_product("apple", "fruit", 5,12,5,2026);

    add(arr,p1);
    add(arr,p2); // should trigger resize

    assert(arr->size == 2);
    assert(arr->capacity>=2);

    assert(strcmp(arr->elems[0].name, "milk")==0);
    assert(strcmp(arr->elems[1].name, "apple")==0);

    destroy_dynamic_array(arr);
}

void test_service() {
    Repository repo = create_repository();
    Service serv = create_service(&repo);

    // Test Validations
    assert(is_valid_category("dairy") == 1);
    assert(is_valid_category("candy") == 0);
    assert(is_valid_date(10, 10, 2028) == 1);
    assert(is_valid_date(10, 10, 2020) == 0);

    // Test Service Add (Logic: adding existing product updates quantity)
    add_product_service(&serv, "Milk", "dairy", 10, 1, 1, 2027);
    assert(get_repo_length(&repo) == 1);
    add_product_service(&serv, "Milk", "dairy", 5, 1, 1, 2027);
    assert(repo.products->elems[0].quantity == 15);

    // Test Filtering
    Product filtered[10];
    int res_len = 0;
    filter_products_by_name(&serv, "Mil", filtered, &res_len);
    assert(res_len == 1);
    assert(strcmp(filtered[0].name, "Milk") == 0);

    destroy_service(&serv);
    destroy_repository(&repo);
}

void test_undo_redo() {
    Repository repo = create_repository();
    Service serv = create_service(&repo);

    // Add then Undo
    add_product_service(&serv, "Bread", "sweets", 1, 1, 1, 2027);
    assert(get_repo_length(&repo) == 1);
    undo_service(&serv);
    assert(get_repo_length(&repo) == 0);

    // Redo
    redo_service(&serv);
    assert(get_repo_length(&repo) == 1);

    destroy_service(&serv);
    destroy_repository(&repo);
}

void test_repo() {
    Repository repo = create_repository();
    Product p = create_product("Milk", "Dairy", 10, 1, 1, 2027);
    
    add_product_repo(&repo, p);
    assert(get_repo_length(&repo) == 1);
    assert(find_product(&repo, "Milk", "Dairy") == 0);
    
    delete_product_repo(&repo, "Milk", "Dairy");
    assert(get_repo_length(&repo) == 0);
    
    destroy_repository(&repo);
}


void run_tests() {
    test_create_dynamic_array();
    test_add();
    test_resize();
    test_service();
    test_undo_redo();
    test_repo();
}

int main() {
    run_tests();
    printf("All tests passed!\n");
    return 0;
}
