## Lecture 1 - 25 feb 2026
introduction

## Lab 1 - 26 feb 2026
https://github.com/cs-ubbcluj-ro/a1-miagiurgiu-1
I received problem 11.

## HOW TO CLONE IN VISUAL STUDIO 2022 (WINDOWS)
 1. Main page -> Clone a repository
 2. Repository location (copy-paste link from browser)
 3. Browse -> Documents -> GitHub -> New -> Folder -> a1-oop -> Clone
 4. File -> New -> Project -> Empty Project (C++)
 5. Project name: a1
 6. Location: the folder of the cloned repo (C:\Users\Maria\Documents\GitHub\a1-oop)
 7. Right click on Source Files -> Add -> Existing Item -> select the .c file from a1-oop -> Add

## HOW TO CLONE IN VISUAL STUDIO CODE (MAC)
1. Source Control -> Changes -> 3 dots -> Clone -> copy-paste link from browser -> New File -> .c
2. Terminal: CTRL + ` 
3. How to compile: clang file_name.c -o filename
4. How to run: ./filename

Very big dilemmas:
- why do we need stuff like & and * in C but in C++ we did not?

Address vs Value in C:
- in C there exist only pointers (addresses) and values (copies)
- if you want a function to modify a variable from the outside of that function, you give its address -> pointer -> &len
- since when calling you did &len, inside the function you do *len so that you can go to the value from that address and write the new value in there
- * does two things:
		1. in a declaration (int *ptr) => "this is a pointer" => address
		2. in an expression (*ptr = 5) => "go to the address of ptr and put 5 (value)"

&x = WHERE is x in memory ? -> give me that location
*x = WHAT is stored at the address p? -> go to that location

pointer to a datatype -> int* vs pointer to a variable *p
- scanf needs address

### Try-Except Python vs C:

PYTHON:
if choice == 1:
    read_vector()
elif choice == 2:
    solve_a()
elif choice == 3:
    solve_b()
elif choice == 4:
    print("Exiting...")
else:
    print("Invalid option")

C method 1:
if (choice == 1) {
	read_vector(v, &len);
}
else if (choice == 2) {
	solve_a();
}
else if (choice == 3) {
	solve_b(v, len);
}
else if (choice == 4) {
	printf("Exiting...\n");
	return;
}
else {
	printf("Invalid option\n");
}

C method 2:
int len = 0;
...
switch (choice) {
	case 1:
		read_vector(v, &len);
		break;
	case 2:
		solve_a();
		break;
	case 3:
		solve_b(v, len);
		break;
	case 4:
		printf("Exiting...\n");
		return;
	default:
		printf("Invalid option\n");
}

## Lecture 2 - 4 mar 2026

Individual work after Lecture 2

![[Pasted image 20260305090821.png]]

![[Pasted image 20260305091520.png]]

https://www.youtube.com/watch?v=HEiPxjVR8CU

## Seminar 1 - 5 mar 2026

## Lab 1 - 5 mar 2026

A2-3: Intelligent refrigerator
- 2 weeks, 2 grades
- in C
- console-based application
- layered architecture (for week 3)
	- UI, Service/Controller, Repository, Domain
- modular programming (.c, .h)
- only include header files in this laboratory (not only c files)
- dynamic array used by Repository (repo contains all entities: add, remove etc.)
	- this repo uses some kind of data structure (list/dict)
	- you have to implement the list yourself = dynamic array
	- basic array type in C: int [20]
	- malloc - increase the size of dynamic array
	- dynamic array used by repo to contain the data
	- create structure dynamic array but it does not have to be dynamically allocated (should be static array for week2, but for week3 you need dynamic ?)
	- fine if in week2 modular does not work, but should work for week3
	- modular programming in C
- functional requirements:
	- a for week2 (CRUD)
	- b for week2 - display with condition (not the UI's job, which country should be display should be done in the service, part b split in 2: one that displays, one that searches)

## Lecture 3 - 12 mar 2026

Dynamic Array Implementation

DynamicArray.h
```
#pragma once
#include "Planet.h"

typedef void* TElem;
typedef void (*destroyFct)(TElem);

typedef struct {
	int capacity, size;
	TElem* elems;
	destroyFct destructionOperation;
} DynamicArray;

DynamicArray* createArray(int cap, destroyFct op);
void destroyDynamicArray(DynamicArray* arr);
void add(DynamicArray* arr, TElem elem);
```

DynamicArray.c
```
#include "DynamicArray.h"
#include <stdlib.h>

DynamicArray* createArray(int cap, destroyFct op)
{
	DynamicArray* arr = malloc(sizeof(DynamicArray));
	if (arr == NULL)
		return NULL;
	arr->capacity = cap;
	arr->size = 0;
	arr->destructionOperation = op;
	arr->elems = malloc(sizeof(TElem) * cap);
	if (arr->elems == NULL)
	{
		free(arr);
		return NULL;
	}
	return arr;
}

void destroyDynamicArray(DynamicArray* arr)
{
	if (arr == NULL)
		return;
	for (int i = 0; i < arr->size; i++)
		arr->destructionOperation(arr->elems[i]);
	free(arr->elems);
	free(arr);
}

void resize(DynamicArray* arr) {
	if (arr == NULL)
		return;
	arr->capacity *= 2;
	/*TElem* aux = malloc(sizeof(TElem) * arr->capacity);
	for (int i = 0; i < arr->size; i++)
		aux[i] = arr->elems[i];
	free(arr->elems);
	arr->elems = aux;*/
	TElem* aux = realloc(arr->elems, arr->capacity * sizeof(TElem));
	if (aux == NULL)
		return;
	arr->elems = aux;
}

void add(DynamicArray* arr, TElem elem)
{
	if (arr == NULL)
		return;
	if (arr->size == arr->capacity)
		resize(arr);
	arr->elems[arr->size++] = elem;
}
```

main.c
```
#include "DynamicArray.h"
#include <crtdbg.h>

int main() {
Planet* p1 = createPlanet("Wolf 1061 c", "terrestrial", 13.8);
Planet* p2 = createPlanet("HAT-P-26b", "Neptune-like", 450);
Planet* p3 = createPlanet("Proxima Centauri b", "terrestrial", 4.2);

DynamicArray* arr = createArray(2, &destroyPlanet);
add(arr, p1);
add(arr, p2);
add(arr, p3);
// destroyDynamicArray(arr);

DynamicArray* arrayOfArrays = createArray(2, &destroyDynamicArray);
add(arrayOfArrays, arr);
destroyDynamicArray(arrayOfArrays);
_CrtDumpMemoryLeaks();
return 0;
}
```

Planet.c
```
#include "Planet.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

  
Planet* createPlanet(char* name, char* type, double distanceFromEarth)
{
	Planet* p = (Planet*)malloc(sizeof(Planet));
	if (p == NULL)
		return NULL;
	p->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(p->name, name);
	p->type = (char*)malloc(sizeof(char) * (strlen(type) + 1));
	strcpy(p->type, type);
	p->distanceFromEarth = distanceFromEarth;
	return p;
}

void destroyPlanet(Planet* p)
{
	if (p == NULL)
		return;
	// free the memory which was allocated for the component fields
	free(p->name);
	free(p->type);
	// free the memory which was allocated for the planet structure
	free(p);
}

Planet* copyPlanet(Planet* p)
{
	if (p == NULL)
		return NULL;
	Planet* newPlanet = createPlanet(getName(p), getType(p), getDistanceFromEarth(p));
		return newPlanet;
}

char* getName(Planet* p)
{
	return p->name;
}

char* getType(Planet* p)
{
	return p->type;
}

double getDistanceFromEarth(Planet* p)
{
	return p->distanceFromEarth;
}

void toString(Planet* p, char str[])
{
	sprintf(str, "Planet %s is a %s planet and its distance from Earth is %.2lf.", p->name, p->type,p->distanceFromEarth);
}
```




How to run only tests (needs linking):
tests % clang tests.c ../repository/dynamic_array.c ../domain/product.c -o tests
./tests
Maria@Mac tests % ./tests


## Lecture 4 - 18 mar 2026
C++
1) Reference = another name for the same memory
- by copying
- by using a reference
- by const reference (when you want the values from original array not modified, but don't want a copy either) -> a certain object should not be changed

```
.h
class DynamicArray {
	private: int size, capacity;
			Telem* elems; // only the pointer is deallocated, not the pointer it points to; provide for that class too maybe?
	public:
		DynamicArray(int capacity=10);
}
```

```
.cpp
DynamicArray::DynamicArray(int capacity) {
		this->capacity=capacity;
		this->size=0;
}
```

arrow because "this" is a pointer to the current object.
*this -> dereference the pointer


2) Copy constructors
- implement your own copy constructor
- invoked when we create memory on heap and then initialise it
- when the copy constructor is called
```
{
Vector2D x{1,2}; // data allocated on the stack
Vector2D y=x;
Vector2D y{x}; // initialising y with x
}

y gets destroyed, then x gets destroyed, statically allocated, they go out of scope when function finishes.
x on the stack -> memory automatically managed
```

Constructors with parameters using member initialisation?

3) Destructors
- called when objects should be destroyed
```
Vector2D x = new Vector2D{1,2}; // data allocated on the heap
delete x; // destructor is being called => memory deallocated
```
- default destructor?
```
~DynamicArray() -> specifies that this is a destructor (no return value, a tilda, no parameters, the name of the class)
```
- if we have dinamically allocated data, create your own destructor!
- you could just print sth in the destructor 
 
 when i have "const" inside the header function i am not allowed to use "this"

4) Copy constructor vs assignment operator
```
Vector2D v7=v1;  // copy constructor is called

Vector2D v8;
v8=v2; // assignment operator
```

5) 
Lecture 4 wrap-up:
- it teaches me why manual memory management is tricky

"BIG THREE" of C++ memory management:
- 1. copy constructor - to handle DynamicArray a=b (creation)
- 2. destructor - to free memory
- 3. copy assignment operator - to handle a=b

SHALLOW COPY - copies the pointer
DEEP COPY - allocates new memory

main.cpp:
- arr1 creates a memory block on the heap -> ADDRESS A
- arr3 creates a different memory block on the heap -> ADDRESS B
- arr3 = arr1 => DISASTER because we did not write a custom = operator, C++ just copies the POINTER => arr3.elems points to ADDRESS A and ADDRESS B is forgotten => memory leak
- ~arr3() -> successfully frees up memory (delete[] ADDRESS A)
- ~arr1() -> crash (ADDRESS A is already gone)
```
#include "DynamicArray.h"
// #include <crtdbg.h> // does not work on mac/linux
#include <iostream>

int main() {
{
	DynamicArray arr1{ 2 }; // calls default constryctor, allocates a heap array of size 2
	//DynamicArray arr2{ arr1 }; 
	DynamicArray arr2 = arr1; // calls copy constructor (even though there is an = sign, the assignment operator is not called because arr2 is created for the first time on this line) => deep copy
	DynamicArray arr3{10}; // arr3 creates a different memory block on the Heap
	// this line currently causes a memory leak
	arr3 = arr1; // arr3 already exists -> looks for operator= -> does not find it -> shallow copy
}
	// _CrtDumpMemoryLeaks(); // does not work on mac/linux -> use command (*) in teminal 
	std::cout << "Program finished. Check terminal for sanitizer reports if enabled. " << std::endl;
	return 0;
}
```

DynamicArray.h
```
#pragma once
typedef int TElem // instead of hardcoding int everywhere

class DynamicArray {
	private:
		int size;
		int capacity;
		TElem* elems;
	public:
		DynamicArray(int n=10);
		~DynamicArray();
		DynamicArray(const DynamicArray& arr);
};
```

DynamicArray.cpp
```
#include "DynamicArray.h"

// constructor
DynamicArray::DynamicArray(int cap): capacity{cap}, size{0}
{
	this->elems = new TElem[this->capacity]; // allocates new memory on the Heap
}

// DESTRUCTOR: frees that memory using delete[]
DynamicArray::~DynamicArray()
{
	delete[] this->elems; // new - delete
}

// COPY CONSTRUCTOR: deep copy
DynamicArray::DynamicArray(const DynamicArray& arr)
{
	this->capacity = arr.capacity;
	this->size = arr.size;
	this->elems = new TElem[this->capacity]; // allocate new memory
	for (int i = 0; i < this->size; i++)
	this->elems[i] = arr.elems[i]; // copy data manually
}
```


What command to use in vs code terminal to see memory leaks:
```
g++ -g -fsanitize=address main.cpp DynamicArray.cpp -o app

g++ => the compiler GNU C++
-g -> debug symbols
-fsanitize=address -> turns on AddressSanitizer (ASan) which tracks eery byte I allocate (if i try to delete sth twice or read memory i don't own, program stops)
-o app -> names output file
```

## A2-3

run dynamic version:
```
gcc -g domain/product.c repository/dynamic_array.c repository/repo_dynamic.c service/service_dynamic.c service/OperationStack.c ui/ui_dynamic.c main_dynamic.c -o fridge_dynamic
./fridge_dynamic
```


run static version:
```
 gcc -g domain/product.c repository/repo_static.c service/service_static.c ui/ui.c main.c -o fridge_static
./fridge_static
```

run tests:
```
gcc -g domain/product.c repository/dynamic_array.c repository/repo_dynamic.c service/service_dynamic.c service/OperationStack.c tests.c -o test_suite
./test_suite
```

## Lab 4 

A4-5:
- c++
- console based app with a menu
- admin mode (for next week)
	- crud
- user mode 
- layered architecture
	- ui-service-repo-dynamicvector-domain
	- tests with code coverage 98%
	- cppcoverage - generic tool that counts lines of code covered by tests -> for next week if we receive examples
	- example at the lecture on how to use code coverage
	- user input validation -> throwing and catching errors, exceptions (like try except in python -> try - catch)
- what makes a ... unique? add a movie that has the same name and year -> duplicate -> not allowed
- hardcode some elements
-

gcc -g domain/product.c repository/dynamic_array.c repository/repo_dynamic.c service/service_dynamic.c service/OperationStack.c ui/ui_dynamic.c start/main_dynamic.c -o fridge_dynamic
./fridge_dynamic



```
gcc -g domain/product.c repository/dynamic_array.c repository/repo_dynamic.c service/service_dynamic.c service/OperationStack.c tests/tests.c -o test_suite

leaks --atExit -- ./test_suite
```

Constructors

if I want constructor with parameters, I **don’t need** default constructor as well because the default constructor does the "starting state" of the fields of the object **only when used**. and then inside the constructor with parameters those initialised fields are filled out with the given parameters. constructor with initialisation list can exist on its own, without a default constructor. it creates the starting state + initialises at the same time.


A4-5

how to compile:
```
g++ -std=c++17 start/main.cpp ui/ui.cpp service/service.cpp repo/repo.cpp repo/dynamic_vector.cpp domain/coat.cpp -o app
```

run tests with coverage mac:
```
clang++ -std=c++11 -fprofile-instr-generate -fcoverage-mapping \
domain/coat.cpp \
repo/dynamic_vector.cpp \
repo/repo.cpp \
service/service.cpp \
validation/validation.cpp \
ui/ui.cpp \
tests/tests.cpp \
start/main.cpp \
-o app

./app


xcrun llvm-profdata merge -sparse default.profraw -o app.profdata

xcrun llvm-cov report ./app -instr-profile=app.profdata 

xcrun llvm-cov show ./app -instr-profile=app.profdata -format=html > coverage_report.html

```

```
./app && xcrun llvm-profdata merge -sparse default.profraw -o app.profdata && xcrun llvm-cov report ./app -instr-profile=app.profdata




correct order:


clang++ -std=c++11 -fprofile-instr-generate -fcoverage-mapping \ domain/coat.cpp repo/dynamic_vector.cpp repo/repo.cpp service/service.cpp \ validation/validation.cpp ui/ui.cpp tests/tests.cpp start/main.cpp -o app

rm default.profraw

exit app with 0

xcrun llvm-profdata merge -sparse default.profraw -o app.profdata

xcrun llvm-cov report ./app -instr-profile=app.profdata

xcrun llvm-cov show ./app -instr-profile=app.profdata -format=html > coverage_report.html && open coverage_report.html

```

- **Shallow Copy (Bad):** Two different array objects would point to the _same_ memory address on the heap. When the first one is destroyed, it deletes the memory. When the second one is destroyed, it tries to delete that same memory again (causing a **Double Free** crash).
    
- **Deep Copy (Your Code):** Your Copy Constructor and Assignment Operator solve this by using `new` to allocate a _separate_ block of memory for the new object and manually copying the elements over.


## Lecture 5 - 25 mar 2026
DynamicArray.h, DynamicArray.cpp, main.cpp

1) ASSIGNMENT OPERATOR:
- implementation of the assignment operator
- could return void, could return DynamicArray& (reference ) -> use reference!
- that if protects self-assignment
- dynamic allocation -> our own destructor -> rule of three
- references behave like objects

```
DynamicArray& DynamicArray::operator=(const DynamicArray& arr) {
    // 1. Check for self-assignment
    if (this == &arr) {
        return *this; 
    }

    // 2. Free existing memory
    delete[] this->elems;

    // 3. Copy scalar data
    this->capacity = arr.capacity;
    this->size = arr.size;

    // 4. Deep copy the array
    this->elems = new TElem[this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->elems[i] = arr.elems[i];
    }

    // 5. Return the object itself
    return *this; 
}

```

2) difference between the repo in the service vs the one...
```
class Service
{
	private: 
		Repository repo;
	public:
		Service(const Repository& repo ); // instead of creating a brand new copy of the repository (slow), service simply points to the existing one
	
}


main:
Repository repo {}; () -> 3
Service serv{repo};
serv.add("song1", "artist1"); -> 4 4

Service::Service(Repository ....)
```

3) initialisation lists are faster because it does not do two operations (allocation + deallocation)
	- initializes the member directly rather
```
Service(Repo r) : repo{r} {}

```

```
Song(std::string artist)

or

Song(const std::string& artist)

```

4) implement your own resize and add function
5) vector_3d.cpp
6) static data members
- global variables for the class
- new instance -> that instance has access to the same static element -> same value for all instances/objects of the class??

4) TEMPLATES
- Template = skeleton
- Declaration:
```
template <typename T>
T add(T a, T b)
{
	return a+b;
}

T - template parameter
```
- Instantiation = the process of generating a function from a template function
```
int resInt = add<int>(3,4);
double resDouble = add<double>(-1.2,2.6);
```
## Lecture 7 - 8 apr 2026
Polymorphism
- acts differently at runtime depending on object type
- objects behave differently according to their types
- ex: message is "speak": each animal makes a different sound

1) static binding vs dynamic binding (late binding): 
static binding 
- the choice of which function to call is done at compile time, depending on the object?
dynamic - at runtime - when we know the type of the object - so that the correct to_string function is called
virtual function declared like this in the base class animal (in java, they are virtual by default)
works with pointers, not objects

```
virtual function_signature
```

2) in Animal.h - virtual vs non virtual 
- override specifier - helps us in case we forget to say virtual in the base class
```
std::string toString() const;

vs 

std::string toString() const override;

vs

virtual std::string toString() const;
```

3) virtual table is a data member automatically allocated when calling stuff with "virtual"
- "Although is an animal at compile time, it will be a dog at runtime and it will act according to Dog class"

steps (not directly)
- crate virtual table
- pointer to it
- ...
- call

3) upcasting, downcasting, static casting
upcasting (up=implicit) - Upcasting is the process of converting a derived class pointer or reference to a base class pointer or reference. It’s called “up” casting because we’re moving up the inheritance hierarchy, from a more specific type to a more general one.

downcasting - down the hierarchy - casting a base class pointer to a derived class pointer ()

static cast - converts ref/pointer to specified type

ability to check with dynamic casting.

4) why does the destructor have to be virtual?
- usually need to be virtual
- main.cpp - see Animal* a, ... inside virtualDestructors()
- we want the destructor to delete everything, not just the animal, i want the penguin to be correctly destroyed
- 

5) constructors cannot be virtual
- we need the exact type
- virtual table pointer is actually initialised in the constructor


pure abstract - only virtual stuff
pure implementation in the base class - in italics - pure abstract

6) see employee exercise 
- employee is not an interface in this case
- dotted line in that case
- like in animals

A5
CHECK FOR memory leaks in CLion terminal:
```
MallocStackLogging=1 leaks --atExit -- ./cmake-build-debug/a45
```

## Lab 7 - 9 apr 2026

A6-7
- use STL library
	- replace everywhere from vector to the vector from STL
	- use algorithms from the STL library: copy if, find if, erase if, count if, sort 
	- replace for with an algorithm/range-based for (for auto element ...)
- read/write to file - load your data from file (only data from admin mode)
	- use the iostream library
	- overload the insertion/extraction operators
	- >>, << - usually used for reading/writing to a file, not only for reading/writing to console

## THEORY

std::vector
![[Pasted image 20260414131235.png]]

std::deque
![[Pasted image 20260414131326.png]]

std::list
![[Pasted image 20260414131404.png]]

lambda expressions:
![[Pasted image 20260414131752.png]]
ex: 
```
void Repository::delete_coat(const std::string& size, const std::string& colour) {  
    auto it = std::find_if(this->coats.begin(), this->coats.end(),  
        [&](const Coat& c) {  
            return c.get_size() == size && c.get_colour() == colour;  
        });  
    if (it==this->coats.end()) { // did not find the desired coat  
        throw RepositoryException("Coat does not exist");  
    }  
    this->coats.erase(it);  
    this->load_to_file();  
    //return true;  
}
```

![[Pasted image 20260414132000.png]]

dynamic binding = decide later

![[Pasted image 20260414155314.png]]

```
#pragma once  
#include "Animal.h"  
#include <string>  
  
class Filter  
{  
public:  
    virtual bool include(const Animal& a) const = 0;  
    virtual ~Filter() {};  
};  
  
class FilterWeightLessThan : public Filter  
{  
private:  
    int weight;  
  
public:  
    FilterWeightLessThan(int w) : weight(w) {}  
    bool include(const Animal& a) const override   
{ return a.getWeight() < this->weight; }  
};  
  
class FilterColour : public Filter  
{  
private:  
    std::string colour;  
  
public:  
    FilterColour(std::string c) : colour(c) {}  
    bool include(const Animal& a) const override   
{ return a.getColour() == this->colour; }  
};
```
usage:
```
void filterAnimals()  
{  
    vector<Animal*> animals = createAnimals();  
  
    FilterWeightLessThan filterW{ 30 };  
    FilterColour filterC{ "black" };  
  
    cout << "Animals having weight less than 30: ";  
    filterByCriterion(animals, &filterW);  
  
    cout << "Black animals: ";  
    filterByCriterion(animals, &filterC);  
  
    destroyAnimals(animals);  
}
```

![[Pasted image 20260414155733.png]]
```
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// =======================
// Domain
// =======================

class Employee
{
protected:
    string name;
    double baseSalary;

public:
    Employee(const string& name, double baseSalary)
        : name{name}, baseSalary{baseSalary} {}

    virtual ~Employee() = default;

    virtual string toString() const
    {
        return name;
    }

    virtual double computeSalary() const
    {
        return baseSalary;
    }
};

class Manager : public Employee
{
private:
    double bonus;

public:
    Manager(const string& name, double baseSalary, double bonus)
        : Employee{name, baseSalary}, bonus{bonus} {}

    string toString() const override
    {
        return "Manager " + name;
    }

    double computeSalary() const override
    {
        return baseSalary + bonus;
    }
};

// =======================
// Filters
// =======================

class Filter
{
public:
    virtual bool include(const Employee& e) const = 0;
    virtual ~Filter() = default;
};

class FilterSalaryGreaterThan : public Filter
{
private:
    double value;

public:
    FilterSalaryGreaterThan(double value) : value{value} {}

    bool include(const Employee& e) const override
    {
        return e.computeSalary() > value;
    }
};

class FilterName : public Filter
{
private:
    string text;

public:
    FilterName(const string& text) : text{text} {}

    bool include(const Employee& e) const override
    {
        return e.toString().find(text) != string::npos;
    }
};

// =======================
// Helper functions
// =======================

vector<Employee*> createEmployees()
{
    vector<Employee*> employees;

    employees.push_back(new Employee{"Ana", 4000});
    employees.push_back(new Employee{"Vlad", 3500});
    employees.push_back(new Manager{"Ion", 5000, 1500});
    employees.push_back(new Manager{"Maria", 6000, 2000});

    return employees;
}

void destroyEmployees(vector<Employee*>& employees)
{
    for (Employee* e : employees)
        delete e;
    employees.clear();
}

void filterByCriterion(const vector<Employee*>& employees, const Filter* filter)
{
    for (Employee* e : employees)
    {
        if (filter->include(*e))
            cout << e->toString() << " | salary = " << e->computeSalary() << '\n';
    }
}

void filterEmployees()
{
    vector<Employee*> employees = createEmployees();

    FilterSalaryGreaterThan filterS{5000};
    FilterName filterN{"Manager"};

    cout << "Employees having salary greater than 5000:\n";
    filterByCriterion(employees, &filterS);

    cout << "\nEmployees whose name/title contains 'Manager':\n";
    filterByCriterion(employees, &filterN);

    destroyEmployees(employees);
}

// =======================
// Main
// =======================

int main()
{
    filterEmployees();
    return 0;
}


// exercise 3
void printEmployees(const std::vector<Employee*>& employees)
{
    for (const auto e : employees)
    {
        std::cout << e->toString() << " | ";
        std::cout << e->computeSalary() << "\n";
    }
}

void testEmployees()
{
    std::vector<Employee*> employees;

    employees.push_back(new Employee{"Ana", 4000});
    employees.push_back(new Employee{"Vlad", 3500});
    employees.push_back(new Manager{"Ion", 5000, 1500});
    employees.push_back(new Manager{"Maria", 6000, 2000});

    printEmployees(employees);

    // cleanup
    for (auto e : employees)
        delete e;
}

int main()
{
    testEmployees();
    return 0;
}

```


## Streams, files, exceptions

1) STREAM = abstraction for receiving/sending data in input/output
- they are SERIAL (data sent one at a time, in a SERIAL manner)
ex: receive data from keyboard/memory/file -> send it to destination display/memory/file
ex: file streams = c++ objects used to interact with files
![[Pasted image 20260414160719.png]]

2) BUFFER = memory block acting as an intermediary between the STREAM and the DESTINATION
- useful because writing large chunks at once is more efficient than doing it byte-by-byte (because there are fewer read/write calls needed)
- output stream => when the buffer is flushed, data contained in the buffer is written to the physical medium
- input stream => when the buffer is flushed, data contained in it is flushed.
 = SYNCRONIZATION 
 
3) IOSTREAM library
- provides input/output functionality using streams
- insertion operator:
![[Pasted image 20260414161936.png]]
- extraction operator:
![[Pasted image 20260414162116.png]]
- inside Coat.h
```
std::ostream& operator<<(std::ostream& os, const Coat& c);  
std::istream& operator>>(std::istream& is, Coat& c);
```

4) MANIPULATORS = functions used along insertion and extraction operators on stream objects (ex: endl)
5) FILES = data structures stored on a disk device
- in order to work with a file, we must connect a stream to that file
- any input/output operation performed on the stream will be applies to the file associated with that stream
	- fstream class
		- ifstream (class derived from istream) -> input file stream
		- ofstream (class derived from ostream) -> output file stream
- open a file using the constructor of the classes ifstream and ofstream:
![[Pasted image 20260414162803.png|685]]
- open a file using the fstream member function open:
![[Pasted image 20260414162833.png]]
- flags:
- these flags can be combined using | (OR)
![[Pasted image 20260414163033.png]]

6) How to check if a file stream was successfully opened for a file:
![[Pasted image 20260414163151.png]]

7) EOF
- it is a flag that gets set only after a failed attempt to read past the end of the file

8) HANDLING EXCEPTIONS
- in C: error flags, return codes (without exceptions)
- = an organised way of managing exceptional situations occuring during execution
- try -> dangerous code
- catch -> what to do in case of dangerous code (holds the code that deals with the problem)
	- catch (...) means it will catch any type of exception
- throw -> the problematic code notifies the calling code
- THROW BY VALUE AND CATCH BY REFERENCE (to avoid copying the object and to preserve polymorphism)
![[Pasted image 20260414163843.png]]
- what() -> used when we want to create (override) a class that inherits from std::exception, but std::exception does not allow a string in the constructor, so we need std::runtime_error as well, which receives a string as a parameter in the constructor, and std::runtime_error is a sub-class of std::exception.
- noexcept -> indicates whether a function will throw exceptions or not
![[Pasted image 20260414164440.png]]

wrap-up:
![[Pasted image 20260414164708.png]]