#include "tests.h"
#include "../domain/coat.h"
#include "../repo/repo.h"
#include "../service/service.h"
#include "../validation/validation.h"
#include <cassert>
#include <iostream>

// test domain
void test_coat_domain() {
    // 1. Test Default Constructor (Coverage for coat.cpp line 4)
    Coat default_c;
    assert(default_c.get_size() == "");
    assert(default_c.get_colour() == "");
    assert(default_c.get_price() == 0);
    assert(default_c.get_quantity() == 0);
    assert(default_c.get_photo() == "");

    // Test constructor and getters
    Coat c{"M", "Blue", 100, 5, "img.png"};
    assert(c.get_size() == "M");
    assert(c.get_colour() == "Blue");
    assert(c.get_price() == 100);
    assert(c.get_quantity() == 5);
    assert(c.get_photo()=="img.png");
    
    // Test setters
    c.set_price(120.5);
    assert(c.get_price() == 120.5);

    c.set_quantity(90);
    assert(c.get_quantity() == 90);

    c.set_colour("pink");
    assert(c.get_colour() == "pink");

    c.set_size("XS");
    assert(c.get_size() == "XS");

    c.set_photo("pink.jpg");
    assert(c.get_photo() == "pink.jpg");
    
    // Test equality operator (Size + Colour)

    // Case: Equal (Same size and colour)
    Coat c1{"M", "Blue", 100, 5, "img.png"};
    Coat c2{"M", "Blue", 50, 1, "different.png"};
    assert(c1 == c2); 
    
    // Case: Different Size
    Coat c3{"L", "Blue", 100, 5, "img.png"};
    assert(!(c1 == c3));

    // Case: Different Colour
    Coat c4{"M", "Red", 100, 5, "img.png"};
    assert(!(c1 == c4));

    // Case: Both Different
    Coat c5{"S", "Green", 100, 5, "img.png"};
    assert(!(c1 == c5));
    
    Coat default_coat; // trigger coat.cpp
    assert(default_coat.get_size() == "");

    std::cout << "Coat Domain tests passed!\n";
}

// test repo add
void test_repo() {
    Repository repo; // Repository constructor adds 10 default coats
    int initialSize = repo.get_all().get_size();
    
    // Test adding a new unique coat
    Coat new_coat{"XXL", "Purple", 300, 2, "purple.png"};
    bool added = repo.add_coat(new_coat);
    assert(added == true);
    assert(repo.get_all().get_size() == initialSize + 1);
    
    // Test adding a duplicate (Same size/color)
    Coat duplicate{"XXL", "Purple", 100, 1, "other.png"};
    bool added_duplicate = repo.add_coat(duplicate);
    assert(added_duplicate == false);
    
    // Test deleting a coat
    assert(repo.delete_coat("XXL", "Purple")==true); // delete sth existent
    assert(repo.delete_coat("sth", "sthelse")==false); // delete sth non existent

    // Test updating a coat
    Coat c{"M", "Purple", 300, 2, "purple.png"};
    repo.add_coat(c);
    Coat updated_c{"M", "Purple", 500, 10, "new_photo.png"};
    assert(repo.update_coat(updated_c)==true);
    assert(repo.get_all().get_elem(repo.get_all().get_size()-1).get_price()==500);
    Coat fake_coat{"sth", "sthelse",0,0, ""};
    assert(repo.update_coat(fake_coat)==false);
    std::cout << "Repository tests passed!\n";
}

/*
void test_dynamic_vector() {
    // create some elements
    DynamicVector<Coat> da(10);
    Coat c1{"XS", "Blueish",123,3,"photo100.jpg"};
    Coat c2{"XS", "Pinkish",123,3,"photo101.jpg"};
    Coat c3{"XS", "Rosieish",123,3,"photo102.jpg"};

    // add some elements
    da.add(c1);
    da.add(c2);
    da.add(c3);

    // remove first element
    da.remove(0);

    // size after remove
    assert(da.get_size()==2);
    
    // index 0 after remove should be c2
    assert(da.get_elem(0)==c2); // new element at that position (shifted left)

    // try to remove invalid position
    int current_size = da.get_size();
    da.remove(111); // position too big
    assert(da.get_size() == current_size);
    da.remove(-1); // position too small
    assert(da.get_size() == current_size);


    // test assignment operator
    DynamicVector<Coat> arr1(10);
    arr1.add(c1);
    DynamicVector<Coat> arr2(10);
    arr2=arr1;
    assert(arr2.get_size()==1);
    assert(arr2.get_elem(0)==c1);
    arr2=arr2; // self-assignment -> delete the elements of the array from which we want to copy??
    assert(arr2.get_size()==1);
    DynamicVector<Coat> arr3=arr1;
    assert(arr3.get_size()==arr1.get_size());

    std::cout << "Dynamic Vector tests passed!\n";

}
*/

void test_dynamic_vector() {
    Coat c1{"XS", "Blue", 100, 3, "p1.jpg"};
    Coat c2{"S", "Red", 120, 4, "p2.jpg"};
    Coat c3{"M", "Green", 140, 5, "p3.jpg"};
    Coat c4{"L", "Black", 160, 6, "p4.jpg"};

    DynamicVector<Coat> v(2);
    assert(v.get_size() == 0);

    v.add(c1);
    v.add(c2);
    assert(v.get_size()==2);
    assert(v.get_elem(0)==c1);
    assert(v.get_elem(1)==c2);

    v.add(c3);
    assert(v.get_size()==3);
    assert(v.get_elem(0)==c1);
    assert(v.get_elem(1)==c2);
    assert(v.get_elem(2) == c3);

    v.remove(1);
    assert(v.get_size() == 2);
    assert(v.get_elem(0) == c1);
    assert(v.get_elem(1) == c3);

    // remove first
    v.remove(0);
    assert(v.get_size() == 1);
    assert(v.get_elem(0) == c3);

    // remove invalid negative
    int old_size = v.get_size();
    v.remove(-1);
    assert(v.get_size() == old_size);

    // remove invalid too large
    v.remove(100);
    assert(v.get_size() == old_size);

    // copy constructor
    DynamicVector<Coat> copy(v);
    assert(copy.get_size() == v.get_size());
    assert(copy.get_elem(0) == v.get_elem(0));

    // check deep-copy behavior
    v.add(c4);
    assert(v.get_size() == 2);
    assert(copy.get_size() == 1);
    assert(copy.get_elem(0) == c3);

    // assignment operator
    DynamicVector<Coat> assigned(10);
    assigned.add(c1);
    assigned.add(c2);
    assigned = v;
    assert(assigned.get_size() == v.get_size());
    assert(assigned.get_elem(0) == v.get_elem(0));
    assert(assigned.get_elem(1) == v.get_elem(1));

    // self assignment
    assigned = assigned;
    assert(assigned.get_size() == 2);
    assert(assigned.get_elem(0) == c3);
    assert(assigned.get_elem(1) == c4);
}

void test_service() {
    Repository repo;
    Service service{repo}; // pass repo to service's constructpr -> this repo from the service is different than the one ... ?
    Coat c{"S", "greeeeen", 123,3,"ergre"};
    // test add
    assert(service.add_coat(c)==true);

    // test get_all
    assert(service.get_all().get_size()==11);

    // test update
    Coat update_c{"S", "greeeeen", 111,3,"sgreg"};
    assert(service.update_coat(update_c)==true);

    // test delete
    assert(service.delete_coat("S", "greeeeen")==true);
}

// test validation
void test_validation(){
    Validation v;
    // test invalid size
    assert(v.validate_add_input("Small", "Blue", 100,1,"link")==false);
    assert(v.validate_add_input("", "Blue", 100, 5, "link.png") == false);
    // test empty colour
    assert(v.validate_add_input("XS", "", 123,2,"RGERG")==false);
    // test negative price
    assert(v.validate_add_input("M", "blue", -123,2,"reger")==false);
    // test negative quantity
    assert(v.validate_add_input("M", "blue", 123,-2,"reger")==false);
    // test empty photo
    assert(v.validate_add_input("M", "blue", 123,2,"")==false);
    // test delete input (empty fields)
    assert(v.validate_delete_input("", "Blue")==false);
    assert(v.validate_delete_input("S", "")==false);
    assert(v.validate_delete_input("S", "Blue") == true);
    // test validate update (invalid price)
    assert(v.validate_update_input("XS", "White", -1.0, 10, "link") == false);
    // test valid input
    assert(v.validate_add_input("XS", "Pink", 200, 2, "photo.jpg") == true);
    assert(v.validate_add_input("XXS", "White", 50, 1, "image.png") == true);
    assert(v.validate_update_input("L", "Beige", 150, 8, "photo2.png") == true);
    assert(v.validate_update_input("", "Blue", 100, 5, "link") == false);      // Target: size empty
    assert(v.validate_update_input("M", "", 100, 5, "link") == false);        // Target: colour empty
    assert(v.validate_update_input("M", "Blue", 100, -5, "link") == false);   // Target: negative quantity
    assert(v.validate_update_input("M", "Blue", 100, 5, "") == false);        // Target: photo empty
    std::cout << "All validation tests passed!\n";
}

// Call these in a main or a dedicated test runner
void run_all_tests() {
    test_coat_domain();
    test_repo();
    test_dynamic_vector();
    test_service();
    test_validation();
}