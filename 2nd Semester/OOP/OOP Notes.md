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
Polymorphism (NEEDS POINTERS, not PLAIN OBJECTS because of SLICING)
- acts differently at runtime depending on object type
- objects behave differently according to their types
- ex: message is "speak": each animal makes a different sound
- works with DYNAMIC BINDING (Animal* a = new Dog(); NOT Animal a = Dog();)

1) static binding vs dynamic binding (late binding): 
static binding 
- COMPILER LOOKS AT TYPE (left side of = ) => sees Animal => faster => less flexible
- the choice of which function to call is done at COMPILE time
- depends on the declared type of the variable (not the type of the real object)
- TO BE USED when behaviour should not change -> for shared, fixed logic
- SLICING because without a pointer/reference. the Dog part of the object is cut off to fit into an Animal variable, destroying polymorphism
```
Animal a = Dog();
a.speak(); // static binding
```
dynamic binding
- COMPILER LOOKS AT THE OBJECT IN MEMORY AT RUNTIME
- the choice of which function to call is done at runtime
- depends on the type of the real object
- the correct function is called (ex: to_string, speak)
- TO BE USED whenever you want subclasses to provide their own logic (speak() is different for each animal) -> for behaviour that changes per subclass
- ONLY WHEN we have pointers of references to a base class pointing to a derived object
- VIRTUAL (tells the compiler to look at the vtable at runtime to find the correct function)
```
Animal* a = new Dog();
a->speak(); // dynamic binding
```

virtual function
- declared in base class (animal) with VIRTUAL
- in java, all methods are virtual by default
works with pointers, not objects

```
virtual function_signature
```

2) in Animal.h - virtual vs non virtual 
- override specifier
	- helps us in case we forget to say virtual in the base class
	- it catches your mistakes
	- the code won't compile if you forgot to put virtual in the base class
	- this prevents "shadowing" (creating a new function instead of overriding the old one)
```
std::string toString() const; // the standard -> derived class -> if the base is virtual

vs 

std::string toString() const override; // the safeguard -> derived class -> forces compiler to check if a matching virtual function exists in the base class

vs

virtual std::string toString() const; // the trigger -> base class -> opens the door for dynamic binding
```

3) virtual table is a data member automatically allocated when calling stuff with "virtual"
- "Although is an animal at compile time, it will be a dog at runtime and it will act according to Dog class"

When virtual functions are used, compiler manages polymorphism through these steps:
1) create virtual table (vtable)
	- create static array of function addresses for every class using virtual functions
	- each element of the array points to the most derived function 
2) add pointer to it (vptr)
	- add to the base class a hidden pointer to the virtual table
	- vptr is inherited by all derived classes
3) initialise vptr
	- when creating an object, vptr is set to point to the virtual table of that object's address
4) indirect call
	- when calling via a pointer, the program dereferences the vptr to find the table and makes an indirect call using the address stored there

5) upcasting, downcasting, static casting
upcasting (up=implicit) 
- moving UP the hierarchy to a more general type
- Upcasting is the process of converting a derived class pointer or reference to a base class pointer or reference. 
- It’s called “up” casting because we’re moving up the inheritance hierarchy, from a more specific type to a more general one.
- a Dog is always an Animal, so no special cast is needed
- always allowed implicitly for public inheritance

downcasting 
- moving DOWN the hierarchy to a more specific type
- casting a base class pointer to a derived class pointer ()
- an Animal might not be a Dog, so the users must take responsibility
- not allowed without an explicit cast

static cast 
- TO BE USED at COMPILE time
- converts ref/pointer to specified type
- only checks if types are in the same hierarchy
- does not check the real object at runtime -> bad casts cause errors

ability to check with dynamic casting
- to be used ar RUN time
- Verifies if the object can actually be converted.
- Returns `nullptr` if the cast fails (safe way to check type)
- Only works with **pointers or references**

4) why does the destructor have to be virtual?
- usually need to be virtual
- main.cpp - see Animal* a, ... inside virtualDestructors()
- we want the destructor to delete everything, not just the animal, i want the penguin to be correctly destroyed
- If the base destructor isn't `virtual`, deleting a `Dog` through an `Animal*` only calls `~Animal()`. This leaves the `Dog` parts in memory, causing **leaks**. A `virtual` destructor ensures the program looks at the **actual object type** and calls both destructors in the correct order

5) constructors cannot be virtual
- because we need the exact type of the object at the moment of creation
- virtual table pointer (vptr) is actually initialised during the constructor's execution

PURE VIRTUAL FUNCTIONS
- functions with no body in the base class
- the compiler reserves a slot in the vtable leaving the address empty
```
virtual function_signature = 0;
```

ABSTRACT CLASSES
- any class containing at least one PURE VIRTUAL function
- you cannot create objects of an abstract class (can't instantiate)
- it serves as a blueprint for derived classes

PURE ABSTRACT CLASSES
- pure abstract - only virtual stuff (only PURE VIRTUAL functions)
- UML: abstract entities (classes or functions) are represented using **italic font**
- describes capabilities without committing to a specific implementation.

6) see employee exercise 
- employee is not an interface in this case (it is a normal, base class) -> normal inheritance (continuous line)
- if we had dotted line it would have been an interface because dotted line appears only when there is an interface (abstract stuff)
- like in animals (abstract class, resembles to interface)

This scheme shows polymorphism (Animal -> Penguin) and architecture (Service -> Repo)
![[Pasted image 20260414180854.png]]
```
// this shows POLYMORPHISM

Animal* a = new Penguin();
a->speak();
a->walkLikePenguin();


pointer to base is Animal*
real object is Penguin
the call goes to the function from Penguin (dynamic binding)
```

```
// this shows ARCHITECTURE
IRepository = interface -> ADD, REMOVE, UPDATE, GET
	contains CSVRepo, MemoryRepo, DBRepo, XMLRepo 

Service {
	IRepository* repo; // service does not know what exact repo does it have, but it calls repo.add(), repo.remove() etc and functions correctly no matter the repo type
}

```

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
- any input/output operation performed on the stream will be applied to the file associated with that stream
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

## A6-7
A6:
- ERG

A7:
- "A pure abstract class is also called an interface" - Lecture 6
- "Defining an interface would allow us to use any class that implements it." - Lecture 6
- Inheritance can be used if there is a kind of or is a relationship between the objects. - Lecture 5
- Inheritance requires at least two classes: a base class and a derived class
- An abstract class serves as a base class for a collection of related derived classes and it provides: a common public interface...
- The existing class is not modified. The new class can use all the features of the old one and add new features of its own.
- => I don't link the service with a list, but with an interface
FOR FUNCTIONALITY 4:
1) create new folder shopping_basket -> abstract_shopping_basket.cpp, .h


## Seminar 4 - 23 apr 2026

Polymorphism does not work with objects, but with pointers/references.

- linked list implementation
- have just one function called testList - call this function in main
- make DynamicVector and LinkedList inherit from List
```
static void testList(List& l)

better:  static void testList(List<int>& l) -> accepts any type of list -> because of the reference (&), it correctly chooses the right function getSize() or add() from the specific version (Vector or Linked List)

if i am providing a linked list -> add from linked list
if i am providing a vector -> add from vector -> getSize() will be taken from dynamic vector
```
- operations for the List (template class)
```
List
--------------------------------
+ add(T e) - element of type T
+ getSize(): int
+ operator[](pos:int): T
```
- ALL virtual function =>abstract class
```
DynamicVector
--------------------
-size: int
-cap: int
-elems: T[0..*] - dinamic array can hold any nr of elements (->infinity)
--------------------
+ add
+ getSize
+ op
```

```
LinkedList
----------------------
- first: Node<T>
- size: int
----------------------
+ add
+ getSize
+ op ...
```

Animal.cpp (combined, no .h)
```
using namespace std; // i am in a cpp file
class Animal {
protected:
	string colour;
public:
	Animal(const string& col): colour {col} {}
	virtual string toString() { // MAKE IT VIRTUAL!
		return "Animal: " + this->colour;
	}
	virtual ~Animal() {
	};
};

class Dog: public Animal {
private:
	string breed;
public:
	Dog(const string& col, const srtring& breed): animal{col}, breed{}
	string toString() {
		return "Dog: " + this->colour + " " + this->breed + "\n";
	}
	~Dog() {
	};
};

int main() {
	Animal * a = new Animal { "red" };
	cout<< a->toString();
	Animal * d = new Dog{"brown", "labrador"};
	cout<<d->toString();
	delete d; // destructor of the base class (animal) instead of derived class (dog) if the destructor is not virtual
	return 0;
}
```

- when at least one function is virtual -> a new field created (not seen, but it's there) - that is the virtual table, will be inside the derived classes as well, will appear the address of the function inside the virtual table of those classes that inherit
- virtual destructor in the base class => delete d => destructor of derived class calls the destructor of base class
- virtual table contains address of function -> call
- =0 means no implementation
- destructor should be either default or empty implementation
- abstract class = at least one virtual function

```
you can't do: 
List<int> l; // you cannot create an object of an abstract class
```

List.h
```
template <typename T> 
class List {
	public:
		// PURE virtual function:
		virtual void add(const T& e) = 0; // e can be skipped, PUT = 0 !
		virtual int getSize() = 0;
		virtual T& operator[](int pos) = 0; // ref because we will modify that element
		virtual ~List();
};
```

DynamicVector.h
- override is useful because sometimes we might forget to say virtual in the base class
```
#pragma once
#include <iterator>
#include "List.h"

class DynamicVector: public List<T> {
	...
	void add(const T& e) override; 
	T& operator[](int pos) override;
};
```

Tests.h
```
#pragma once
#include "List.h"

...
static void testList(List<int>& l);
...

int main() {
	DynamicVector<int> v{};
	Test::testList(ll);
	
	Dynamicvector<int>  //?
	Test::testList(ll); //?
}

void fct(Animal a); // object, not ok
void fct(Animal& a);
```

LinkedList.h
- class linked list inherits from the List implemented earlier
```

```

I want a filePlaylist
- write to file
- display playlist = launch an external application that shows my playlist
- see JSON 

main.cpp:
```
if (playlist type == csv)
	playlist = new csvplaylist{"playlist.csv"}
else if playlist type = json
	playlist = new jsonplaylist{"platlist.txt"}
```

Implement filePlaylist inheriting from playlist, json playlist, csv playlist

filePlayList.h
```
class FilePlayList: public PlayList {
	protected: 
		std::string filename;
	public:
		FilePlaylist(const std::string& filename) : filename(filename) {}
		virtual void writeToFile() const = 0;
		virtual void display() const = 0;
		virtual ~FilePlaylist() = default;
}

```

JSONPlaylist.h
```
#include "FilePlayList.h"

class JSONPlaylist: public filePlaylist {
public:
	JSONPlaylist(const std::string& filename): FilePlaylist(filename);
	void writeToFile() const override;
	
}
```

JSONPlayList.cpp
```
#include "JSONPlayList.h"
#include <fstream>
void JSONPlayLit::writeToFile() const {
	if (!fout.is_open()) {
		return;	
	}
	fout<<"{\"songs\":[\n]}
}

```

- inside Song.h -> toJson function
```
std::string Song::toJSON() const
```

1) write
2) display

ShellExecuteA -> 

## A7

BASKET SHOULD BE SEEN IN THE CONSOLE AS WELL for A7!
UML Diagram:

Inheritance:
CSVShoppingBasket, HTMLShoppingBasket -> AbstractShoppingBasket 

Composition: full diamond
Repository -> Coat
- Repository stores 
```
vector<Coat>
```
 => repository has control over coats lifetime => composition (has-a, strong ownership) => if the repo is destroyed, its coats get destroyed as well
AbstractShoppingBasket -> Coat
Service -> Repository

Aggregation: empty diamond
Service -> AbstractShoppingBasket

Association:

UI -> Service

Dependency:
Service -> Coat

DB:
1) create repo.h -> abstract repo
- virtual void add_coat ... = 0
- virtual void delete_coat... = 0
- virtual void update_coat... = 0
- virtual std::vector... getall const =0;
- virtual ~Repository = default;

2) rename current repo -> filerepo: public repo
3) database_repo -> database repo: public repo
- add, delete, update, getall -> override
- destructor
- constructor
- private fields -> to be continued

4) special implementation for database repo.cpp
- constructor
- create table
- add 
- get all
- delete
- update
- destructor

5) main: 
DatabaseRepository repo{"coats.db"};
Service service{repo};

6) service: NOT CONST REPOSITORY

UML RELATIONS:
ASSOCIATION = class-level reference -> in code: & or *
![[Pasted image 20260429213157.png]]
COMPOSITION = lifetime owned -> in code: new or delete -> it does create and destroy
![[Pasted image 20260429213215.png]]
AGGREGATION = contained object can exist independently -> in code: &
![[Pasted image 20260429213538.png]]
DEPENDENCY = used only in a method/parameter/local variable
![[Pasted image 20260429213700.png]]
INHERITANCE="is-a"
![[Pasted image 20260429213739.png]]

For Coats app:
- composition:
![[Pasted image 20260429222158.png]]
- aggregation:
![[Pasted image 20260429222236.png]]
![[Pasted image 20260429222401.png]]
![[Pasted image 20260429222425.png]]
- dependency:
![[Pasted image 20260429222456.png]]
![[Pasted image 20260429222542.png]]



### Test 2 OOP Prep

UI STUFF: 
- pentru `int/double` verifici cu `if (!(cin >> x))`
- pentru `yes/no` citești ca `string`, nu ca `bool`
- dacă inputul e greșit, faci `return`, nu continui mai departe.

## Lecture 9 - 29 apr 2026
Exceptions. RAII

 - throw by value and catch by reference
- catch blocks are executed in the order they were declared
- garbage collector
	- separate program that searches stuff that is no longer used and deletes those
	- java, python there is no need for deallocation because they use garbage collector
- Lex Fridman Podcast

![[Pasted image 20260429143025.png]]
- the "delete a" block might never be reached because throw goes to catch
	- SOLUTION 1: make sure the variable is deallocated in the catch block
		- this is not the best strategy because you might have multiple variables that need to be deallocated
	- SOLUTION 2: RAII
		- destructors are called automatically when we go out of scope
		- do that thing right in the destructor because we know for sure the destructor will be always called when going out of scope
		- environment is faster 
		- when working with files, RAII is used
			- when having an object of type ifstream/ofstream, the constructor aquires the resource (file handle) and will automatically open the file
```
{
	ofstream f{...};
}
```

```
int d{4.5}; // error because it can't initialise an int with 4.5
int e(4.5); // silently casts it to an int -> 4
```

Smart Pointers:
- shared_ptr is the most used one
- they receive some memory that has already been allocated
- behave as pointers but they also know how to automatically destroy when we no longer work with stuff - it should be able to get destroyed automatically? destroy WHAT? the resource (=the newly allocated memory)
- they are wrappers of some raw pointers?
- smart pointer doesn’t create the resource, it **owns and manages it**
- if i get a resource from somewhere else, it is my responsibility to deallocate it etc.
	- `new int{3}` → creează resursa
	- `SmartPointer` → devine responsabil de ea
```
SmartPointer a{new int{3}}
```
- why don't we do the allocation inside the constructor?
	- if you allocate inside constructor, you lose flexibility and genericity
	- because in this case it's a class (object)
```
SmartPointer(int ...) {
	this-> ... = new int (val); // works only for int
}
```
- you create different objects at runtime, smart pointer doesn’t care, just deletes correctly at the end
```
FilePlaylist fp = nullptr;
if ...
	fp = new CSV
else3
	fp = new HTML
```


Types of smart pointers:
1) std::unique_ptr
2) std::shared_ptr - most used one
3) std::weak_ptr

 std::unique_ptr
- owns its object uniquely
- if i want another pointer to point to that object i have to "move"
- you can't pass them by value because this means a copy will be made
- as any other smart pointer, when we go out of scope, newly allocated memory will be destroyed
- no constructor is called because make_unique is a function
![[Pasted image 20260429152727.png]]

std::shared_ptr
- we only deallocate only after we make sure there are no pointers pointing to that memory
- when we remove those pointers because they get out of scope, reference_count decreases
- TO USE ONLY in situations you know you actually need it (because it's slower than unique_ptr, so unique_ptr is prefered)
- BUT in the case of shared pointers, there are 2 implementations:
- FIRST IMPLEMENTATION:
	- 3 is the reference_count
![[Pasted image 20260429153406.png]]
- SECOND IMPLEMENTATION:
 ![[Pasted image 20260429153451.png]]

- THIRD IMPLEMENTATION:
![[Pasted image 20260429153515.png]]

std::weak_ptr
- circular reference (between member and team - team contains a vector of members)
- the problem: the team does not get destroyed because the reference_count is 3 and it destroys only when reference_count is 0/1
- solution: instead of using shared_ptr, used a weak_ptr because they don't increase the reference_count for the team

![[Pasted image 20260430094041.png]]


Comments after presenting the code:
- when you have multiple things for stuff -> like repository-coat for example, it is safer to say aggregation on the UML (empty diamond), not composition - the fact that it is value/reference does not really matter
## A8-9

- no QT creator
- use layouts
- create UI for admin + user
- only thing that should work: display elements - a window with the elements - for admin

## Lecture 10 - 6 may 2026
QT

exec() -> generates an event

QCoreApplication -> non-GUI QT applications

WIDGETS
- any window is a widget
- button/window/list
- parent-child widgets: a button is a child of the main window (parentt)

QLabel
- display text/image
QLineEdit
QTextEdit
QPushButton

Absolute positioning vs Layout
Absolute positioning: setGeometry() -> give exact position
Layout -> resizes automatically

GUI.h
- labels, layouts don't have to be modified - only create them locally in the function, not needed to add them as data members
```
class GUI: public QWidget {
	private:
		Service& serv; // data members of the class
	public:
		GUI(Service& serv);
		void buildGUI();
}
```

```

GUI::GUI(Service& serv): serv{serv}

void GUI::buildGUI() {
	QHBoxLayout* mainLayout=new QHBoxLayout{this};
	
}
```

In case CLion crashed (segmentation fault):
Edit VM -> 
-Dide.browser.jcef.enabled=false  
-Dide.mac.file.chooser.native=false  
-Dsun.java2d.metal=false  
-Dsun.java2d.opengl=false


## Seminar 5 - 7 may 2026
```
class UI  
{  
private:  
    Service& serv; // reference to the Service (Service cannot be copied!)  
  
public:  
    UI(Service& s) : serv(s) {}  
  
    void run();
```

When const - field must be value
```
class UI  
{  
private:  
    Service serv; // VALUE
  
public:  
    UI(const Service& s) : serv(s) {}   // CONST
  
    void run();
```

```
class UI  
{  
private:  
    Service serv; // VALUE
  
public:  
    UI(Service s) : serv(s) {}   // VALUE ??
  
    void run();
```

## Lecture 11 - 13 may 2026
QT signals and slots

EVENT HANDLING IN GUI FRAMEWORKS
1) callback = function (=callback function) called by another function (=processing function)
- that function is executed at the time of clicking that button
- ex: sorting algorithm - comparison function passed to a sorting algorithm (dsa, fp)
- that smaller function - measures the progress
- pass function as parameter
- function pointer (in C/C++) / std::function (in C++)
- disadvantage: processing function has to know about callback function
![[Pasted image 20260513141315.png|412]]

2) Slots and Signals = alternatives to the callback mechanism
- communication between objects
-  slots = functions (function called in response to a particular signal)
 - signals = events (ex: signal emitted when a button is clicked, as a result of user)
 - they can be independent and then be interchanged ex: signals of one class can access the slots of another class
 - one signal -> multiple slots
 - more signals -> same slot
 - ! SIGNATURE OF SIGNAL MUST MATCH THE SIGNATURE OF RECEIVING SLOT! (the signals and slots mechanism is type safe)
 ![[Pasted image 20260513142134.png|405]]
 - starting with QT5, you don't have to write "slots: " inside the myGUI class, only "signal:" if you want to define your own signals
 - how to connect a signal and a slot (ex: synchronise spinner and slidebox)

META-OBJECT SYSTEM
- allows us to have extra information about classes
 1) introspection = at runtime you can inspect your objects: what are its superclasses, see their methods, see all (private+public) attributes -> provided by MOC (meta-object-compiler, this is the tool that provides introspection support)
 - MOC = code generator, it parses the header files and generates an additional c++ file that is compiled with the rest of the program -> this does everything related to signal and slots + allows us to do introspection on that class
 2) signals and slots

If you connect like this, you don't need the additional macro Q_OBJECT
 ![[Pasted image 20260513144508.png|588]]

- create your own signals: using "signals" macro
	- they must be of type void
![[Pasted image 20260513144630.png|600]]
- emit your own signals: using "emit" macro
![[Pasted image 20260513144734.png|599]]

QT DESIGNER
- UIC = user interface compiler, code generator, it generates additional c++ file that is compiled with the rest of the program 

- files:
GUI.ui -> xml files that gets modified from the QTDesigner
GUI.h -> class GUI -> has inside private: Ui::GUIClass ui;
GUI.cpp -> 

Inside GUIClass -> all the elements
- spaceshipsListWidget;
- layouts
- labels...
![[Pasted image 20260513152800.png|495]]
- for(auto& s: elems) -> reference, avoid copies for each element
- for(auto s: elems) -> copies data, wasting memory
- for(const auto& s: elems) -> for reading data only (because it prevents accidental modification)

QMainWindow -> a more customizable, complex window, not just a widget
- menu bar
- toolbars
- central widget
- status bar


### Lab 14 may 2026

A9:
-  implementing GUI for A4-A7

### Lecture 12 - 20 may 2026
1) MVC 
- appropriate for GUIs
- model changes => update the view
- MODEL=application object
- VIEW=screen presentation
- CONTROLLER=the way the user interface reacts to user input
![[Pasted image 20260520142000.png|300]]
2) Model/View Architecture in QT I
- no controller
- the view also allows the user to interact with the data
- MODEL-represents the data
- VIEW-displays the data
- DELEGATE-

QAbstractTableModel
- rowCount=0 -> to know how many rows to count
- columnCount=0 -> to know how many columns to count
- data=0 -> what to show in each cell -> has an index -> according to that index -> view knows how to show that data
QTableView
setModel


### Test prep (GUIs)

##### Setup:
```
cmake_minimum_required(VERSION 4.2)  
project(GUIExperiments)  
  
set(CMAKE_CXX_STANDARD 14)  
set(CMAKE_INCLUDE_CURRENT_DIR ON)  
  
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")  
  
set(CMAKE_AUTOMOC ON)  
set(CMAKE_AUTOUIC ON)  
set(CMAKE_AUTORCC ON)  
  
find_package(Qt6 COMPONENTS Widgets REQUIRED)  
  
add_executable(ProgramName 
        gui.cpp  
        gui.h  
        gui.ui  
        README.md  
        main.cpp)  
target_link_libraries(ProgramName Qt6::Widgets)

```

##### General structure of the main:
```
#include <QApplication>  
#include "gui.h"  
  
int main(int argc, char *argv[]) {  
    QApplication app(argc,argv);  
    GUI gui;  
    gui.show();  
    return app.exec();  
}
```


### Seminar 6 - 21 may 2026
Model/View architecture
- suitable for any app in which we want to work with GUI
- view and model are separated
- the view only has to know about the model
- when you change sth in the model, both views (if there are 2 views) are changed
- FLAGS - define behaviour
- ROLES - ?

TableView
- QAbstractTableModel documentation -> more -> subclassing -> rowcount()
- QSourceFiterProxyModel -> receives a source and does sth with it
- rowCount(), columnCount(), data() need to be implemented because they are abstract!

1) create a window in which we add a table view
- one table widget - create model class - set model to this table view
- how the table view renders itself according to what we implemented in the custom model class

1) know how to copy-paste the correct functions from qt documentation
https://doc.qt.io/qt-6/qabstracttablemodel.html
https://doc.qt.io/archives/qt-5.15/qabstractitemmodel.html


### Lab 21 may 2026
A10:
1) unlimited undo/redo - add/remove/update, admin mode
- inheritance and polymorphism
- buttons: undo, redo
- shortcuts: ctrl+z/ctrl+y
2) new way of displaying the user list
- create new window with Table View