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

C++:
```
#include <iostream>

#include <Windows.h>

  

using namespace std;

  

auto fct(int a)

{

return (a % 2 == 0);

}

  

namespace A

{

int a = 3;

int d = 25;

  

int increaseValue(int x)

{

return ++x;

}

}

  

namespace B

{

int a = 5;

}

  

int main()

{

system("color f4");

  

// Reading and writing data

int q = 0;

cout << "Input a value for q: ";

cin >> q;

cout << "The variable q is now: " << q << "\n.";

  

// ------------------------------------------------------------------------------------------------------------------------

// References

int x = 2;

int& y = x; // x and y refer to the same memory location, y is an alias for x

y = 10;

x = 5;

cout << "Value of x: " << x << ", value of y: " << y << ".\n";

  

int* px = &x;

int* py = &y;

cout << "Address of x: " << px << ", address of y: " << py << ".\n"; // the memory addresses of x and y are identical.

  

//int& z; // Error - a reference must be initialized.

  

// Const references

const int& z = x;

cout << "Value of z: " << z;

//z = 20; // a const reference cannot be modified

// ------------------------------------------------------------------------------------------------------------------------

// auto specifier

double m{ 2 };

int n{ 3 };

auto s = m + n;

cout << "s: " << s << "\n";

auto resFct = fct(20);

auto res = resFct ? "true" : "false";

cout << "res: " << res << "\n";

  

// ------------------------------------------------------------------------------------------------------------------------

// Namespaces

int a = 100;

A::a = 20;

cout << "a in main: " << a << ", a in namespace A: " << A::a << ", a in namespace B: " << B::a << "\n";

auto res2 = A::increaseValue(A::a);

res2 = A::increaseValue(B::a);

res2 = A::increaseValue(a);

  

{

using namespace A;

cout << d << endl; // no need to use the scope resolution operator

}

  

// ------------------------------------------------------------------------------------------------------------------------

// Ranged-based for loop

int v[] = { 1, 2, 3, 4, 5 };

for (int val : v)

cout << val << " ";

cout << endl;

  

int i{ 0 };

for (auto val : v) // val is a copy of each element from v (one at a time)

{

cout << val << " ";

val += 100;

cout << val << " ";

cout << v[i] << endl;

i++;

}

cout << endl;

  

i = 0;

for (auto& val : v) // val is now a reference of each element from v => the elements will be modified

{

cout << val << " ";

val += 100;

cout << val << " ";

cout << v[i] << endl;

i++;

}

cout << endl;

  

i = 0;

for (const auto& val : v) // val is now a const reference of each element from v => no copies are made and the elements CANNOT be modified

{

cout << val << " ";

//val += 100; // ERROR

cout << v[i] << endl;

i++;

}

cout << endl;

  

return 0;

}

```

main.cpp:
```
#include "Vector2D.h"

#include <iostream>

#include <Windows.h>

  

#define PI 3.14159265

#include<cmath>

  

int main()

{

system("color f4");

  

//Vector2D v1{ 1, 1 }; // aggregate initialization

//Vector2D v2; // uninitialised: x and y coordinates contain garbage!

//v2.xCoordinate = 2;

//v2.yCoordinate = 3;

  

//Vector2D v3{}; // x and y coordinates are initialised with default values for their types (0 - for doubles)

  

//v1.add(v2);

//std::cout << "x and coordinates for v1: (" << v1.xCoordinate << ", " << v1.yCoordinate << ")" << std::endl;

  

//v1.rotate(PI / 3);

//std::cout << "x and coordinates for v1: (" << v1.xCoordinate << ", " << v1.yCoordinate << ")" << std::endl;

  

//v2.subtract(v3);

//std::cout << "x and coordinates for v2: (" << v2.xCoordinate << ", " << v2.yCoordinate << ")" << std::endl;

  

//system("pause");

return 0;

}
```

Vector2D.cpp
```
#include "Vector2D.h"

#include <cmath>

  

void Vector2D::add(Vector2D v)

{

this->xCoordinate += v.xCoordinate;

this->yCoordinate += v.yCoordinate;

}

  

void Vector2D::subtract(Vector2D v)

{

this->xCoordinate -= v.xCoordinate;

this->yCoordinate -= v.yCoordinate;

}

  

void Vector2D::rotate(double angle)

{

this->xCoordinate = this->xCoordinate * cos(angle) - this->yCoordinate * sin(angle);

this->yCoordinate = this->xCoordinate * sin(angle) + this->yCoordinate * cos(angle);

}

  

void Vector2D::multiplyByScalar(double scalarValue)

{

this->xCoordinate *= scalarValue;

this->yCoordinate *= scalarValue;

}
```

Vector2D.h
```
#pragma once

  

class Vector2D

{

private:

double xCoordinate;

double yCoordinate;

  

public:

/*

Add the given 2D vector to the current 2D vector.

Input: v - Vector2D

Output: v is added to the current 2D vector.

*/

void add(Vector2D v);

  

/*

Subtract the given 2D vector from the current 2D vector.

Input: v - Vector2D

Output: v is subtracted from the current 2D vector.

*/

void subtract(Vector2D v);

  

/*

Rotates the current 2D vector.

Input: angle - real value

Output: the current 2D vector is rotated with the given angle.

*/

void rotate(double angle);

  

/*

Multiplies the current 2D vector with a scalar value.

Input: scalarValue - real number

Output: the current 2D vector is multiplied by the given value.

*/

void multiplyByScalar(double scalarValue);

};
```

vector_ex2.cpp
```
#include "Vector2D.h"

#include <iostream>

#include <Windows.h>

  

#define PI 3.14159265

#include<cmath>

  

int main()

{

system("color f4");

  

{

Vector2D v{1, 2};

}

  

Vector2D v1{}; // default constructor called

//Vector2D v3(); // !!! This is a function definition

  

Vector2D v3{ 2, 3 }; // constructor with parameters called

const Vector2D a = v3;

//a.add(v3); // error - a is const and the function add is not const

  

Vector2D arrayOfVectors[5]; // default constructor is called 5 times

  

Vector2D arrayOfVectorsInitialized[3] = { {}, {2, 3}, Vector2D{-1, 1} }; // first default constructor, then 2 times the constructor with parameters

  

Vector2D v4{v3}; // copy constructor called

Vector2D v5 = v4; // copy constructor called

  

// dynamic allocation

Vector2D* v6 = new Vector2D{}; // default constructor

Vector2D* v7 = new Vector2D{1, 7}; // constructor with parameters

Vector2D* v8 = new Vector2D{ *v7 }; // copy constructor

Vector2D* arrayOfVectorsDynamic = new Vector2D[3]; // default constructor

v6->add(*v7); // is any constructor called in this case?

// deallocation

delete v6;

delete v7;

delete v8;

delete[] arrayOfVectorsDynamic;

  

system("pause");

return 0;

}
```

Vector2D.cpp

```
#include "Vector2D.h"

#include <cmath>

#include <iostream>

  

//Vector2D::Vector2D()

//{

// this->xCoordinate = 0;

// this->yCoordinate = 0;

//

// std::cout << "Constructor called.";

//}

  

//Vector2D::Vector2D(double x, double y)

//{

// this->xCoordinate = x;

// this->yCoordinate = y;

//}

  

//Vector2D::Vector2D(double x, double y)

//{

// this->xCoordinate = x;

// this->yCoordinate = y;

//}

  

// constructor with parameters using member initialization

Vector2D::Vector2D(double x, double y) : xCoordinate{ x }, yCoordinate{ y }

{}

  

Vector2D::Vector2D(const Vector2D& v)

{

this->xCoordinate = v.xCoordinate;

this->yCoordinate = v.yCoordinate;

}

  

Vector2D::~Vector2D()

{

std::cout << "Destructor called for " << this->xCoordinate << ", " << this->yCoordinate << std::endl;

}

  

void Vector2D::setXCoordinate(double newX)

{

if (newX < 0)

throw std::invalid_argument{"New value must be > 0!"};

this->xCoordinate = newX;

}

  

void Vector2D::add(Vector2D v)

{

this->xCoordinate += v.xCoordinate;

this->yCoordinate += v.yCoordinate;

}

  

void Vector2D::subtract(Vector2D v)

{

this->xCoordinate -= v.xCoordinate;

this->yCoordinate -= v.yCoordinate;

}

  

void Vector2D::rotate(double angle)

{

this->xCoordinate = this->xCoordinate * cos(angle) - this->yCoordinate * sin(angle);

this->yCoordinate = this->xCoordinate * sin(angle) + this->yCoordinate * cos(angle);

}

  

void Vector2D::multiplyByScalar(double scalarValue)

{

this->xCoordinate *= scalarValue;

this->yCoordinate *= scalarValue;

}
```

Vector2D.h
```
#pragma once

  

class Vector2D

{

private:

double xCoordinate;

double yCoordinate;

  

public:

// default constructor

//Vector2D();

//Vector2D() = default;

Vector2D(double x = 0, double y = 0);

  

// constructor with parameters

//Vector2D(double x, double y);

  

// copy constructor

Vector2D(const Vector2D& v);

  

// destructor

~Vector2D();

  

// we can have 2 functions with the same name and parameter list, if one is const

double getXCoordinate() { return this->xCoordinate; }

double getXCoordinate() const { return this->xCoordinate; }

double getYCoordinate() const { return this->yCoordinate; }

  

void setXCoordinate(double newX);

  

/*

Add the given 2D vector to the current 2D vector.

Input: v - Vector2D

Output: v is added to the current 2D vector.

*/

void add(Vector2D v);

  

/*

Subtract the given 2D vector from the current 2D vector.

Input: v - Vector2D

Output: v is subtracted from the current 2D vector.

*/

void subtract(Vector2D v);

  

/*

Rotates the current 2D vector.

Input: angle - real value

Output: the current 2D vector is rotated with the given angle.

*/

void rotate(double angle);

  

/*

Multiplies the current 2D vector with a scalar value.

Input: scalarValue - real number

Output: the current 2D vector is multiplied by the given value.

*/

void multiplyByScalar(double scalarValue);

};
```

DynamicVector.h
```
#pragma once

  

typedef int TElement;

  

class DynamicVector

{

private:

TElement* elems;

int size;

int capacity;

  

public:

// default constructor for a DynamicVector

DynamicVector(int capacity = 10);

  

// copy constructor for a DynamicVector

DynamicVector(const DynamicVector& v);

~DynamicVector();

  

// assignment operator for a DynamicVector

DynamicVector operator=(const DynamicVector& v);

  

// Adds an element to the current DynamicVector.

void add(TElement e);

  

/*

Overloading the subscript operator

Input: pos - a valid position within the vector.

Output: a reference to the element o position pos.

*/

TElement& operator[](int pos);

  

int getSize() const;

  

private:

// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number).

void resize(int factor = 2);

};

```

DynamicVector.cpp
```
#include "DynamicVector.h"

  
  

DynamicVector::DynamicVector(int capacity)

{

this->size = 0;

this->capacity = capacity;

this->elems = new TElement[capacity];

}

  

DynamicVector::DynamicVector(const DynamicVector& v)

{

this->size = v.size;

this->capacity = v.capacity;

this->elems = new TElement[this->capacity];

for (int i = 0; i < this->size; i++)

this->elems[i] = v.elems[i];

}

  

DynamicVector::~DynamicVector()

{

delete[] this->elems;

}

  

DynamicVector DynamicVector::operator=(const DynamicVector& v)

{

if (this == &v)

return *this;

this->size = v.size;

this->capacity = v.capacity;

delete[] this->elems;

this->elems = new TElement[this->capacity];

for (int i = 0; i < this->size; i++)

this->elems[i] = v.elems[i];

  

return *this;

}

  

void DynamicVector::add(TElement e)

{

if (this->size == this->capacity)

this->resize();

this->elems[this->size] = e;

this->size++;

}

  

void DynamicVector::resize(int factor)

{

this->capacity *= factor;

TElement* els = new TElement[this->capacity];

for (int i = 0; i < this->size; i++)

els[i] = this->elems[i];

  

delete[] this->elems;

this->elems = els;

}

  

TElement & DynamicVector::operator[](int pos)

{

return this->elems[pos];

}

  

int DynamicVector::getSize() const

{

return this->size;

}

```

vector_ex3.cpp
```
#include "Vector2D.h"

#include "DynamicVector.h"

#include <iostream>

#include <string>

#include <Windows.h>

#include <crtdbg.h>

  

#define PI 3.14159265

#include<cmath>

#include <iostream>

  

int main()

{

system("color f4");

  

Vector2D v1{ -1, 1 };

std::cout << Vector2D::getNumberOfInstances() << "\n";

  

Vector2D v2{2, 3};

std::cout << Vector2D::getNumberOfInstances() << "\n";

  

Vector2D v3 = v1 + v2; // <=> Vector2D v3 = v1.operator+(v2);

std::cout << Vector2D::getNumberOfInstances() << std::endl;

  

Vector2D v4 = v1 * 3; // <=> Vector2D v3 = v1.operator*(3);

std::cout << "There are " << Vector2D::getNumberOfInstances() << " objects of class Vector2D." << std::endl;

  

Vector2D v5 = 3 * v1; // will this work? Why/why not?

std::cout << "v3 is: " << v3.toString();

std::cout << "v4 is: " << v4.toString();

//std::cout << "v5 is: " << v5.toString();

  

Vector2D v6{};

v6 = v4; // assignment operator called

v6 = v2 = v1; // assignment operator called twice <=> v6.operator=(v2.operator=(v1))

  

Vector2D v7 = v1; // copy constructor is called (a new object is created and data is copied into it)

Vector2D v8{};

v8 = v2; // assignment operator is called (the object already exists, data is copied into it)

  

// Dynamic Vector - What happens here if the DynamicVector class does not have an overloaded assignment operator?

DynamicVector vect1;

{

DynamicVector vect2{ 5 }; // initializes a dynamic vector, capacity = 5

vect2.add(1);

vect2.add(2);

vect1 = vect2;

}

int x = vect1[1];

std::cout << x << std::endl;

// static class member

//std::cout << "There are " << Vector2D::numberOfInstances << " objects of class Vector2D." << std::endl;

std::cout << "There are " << Vector2D::getNumberOfInstances() << " objects of class Vector2D." << std::endl;

  

// friend function

std::cout << "v4 is: ";

printVectorData(v4);

  

// friend class

Vector2D vectorOf2DVectors[20] = { v1, v2, v3, v4 };

std::cout << "There are " << Vector2D::getNumberOfInstances() << " objects of class Vector2D." << std::endl;

Graphics g(vectorOf2DVectors, 4);

g.printAllYCoordinates();

std::cout << "There are " << Vector2D::getNumberOfInstances() << " objects of class Vector2D." << std::endl;

  

return 0;

}

```

Vector2D.cpp
```
#include "Vector2D.h"

#include <cmath>

#include <sstream>

#include <iostream>

  

// initialize the static member

int Vector2D::numberOfInstances = 0;

  

int Vector2D::getNumberOfInstances()

{

return numberOfInstances;

}

  

Vector2D::Vector2D(double x, double y) : xCoordinate{ x }, yCoordinate{ y }

{

numberOfInstances++;

}

  

Vector2D::Vector2D(const Vector2D& v)

{

this->xCoordinate = v.xCoordinate;

this->yCoordinate = v.yCoordinate;

  

numberOfInstances++;

}

  

Vector2D::~Vector2D()

{

std::cout << "Destructor\n";

  

//numberOfInstances--;

}

  

void Vector2D::add(const Vector2D& v)

{

this->xCoordinate += v.xCoordinate;

this->yCoordinate += v.yCoordinate;

}

  

void Vector2D::subtract(Vector2D v)

{

this->xCoordinate -= v.xCoordinate;

this->yCoordinate -= v.yCoordinate;

}

  

void Vector2D::rotate(double angle)

{

this->xCoordinate = this->xCoordinate * cos(angle) - this->yCoordinate * sin(angle);

this->yCoordinate = this->xCoordinate * sin(angle) + this->yCoordinate * cos(angle);

}

  

void Vector2D::multiplyByScalar(double scalarValue)

{

this->xCoordinate *= scalarValue;

this->yCoordinate *= scalarValue;

}

  

std::string Vector2D::toString()

{

std::stringstream txt;

txt << "X and Y coordinates: (" << this->xCoordinate << "," << this->yCoordinate << ")" << std::endl;

return txt.str();

}

  

Vector2D Vector2D::operator+(const Vector2D& v)

{

Vector2D res{ this->xCoordinate, this->yCoordinate };

res.add(v);

return res;

}

  

Vector2D Vector2D::operator*(double scalarValue)

{

Vector2D res{ *this };

res.multiplyByScalar(scalarValue);

return res;

}

  

Vector2D& Vector2D::operator=(const Vector2D& v)

{

this->xCoordinate = v.xCoordinate;

this->yCoordinate = v.yCoordinate;

return *this;

}

  
  

// non-member function

Vector2D operator*(double scalarValue, const Vector2D& v)

{

Vector2D res{ v };

res.multiplyByScalar(scalarValue);

return res;

}

  

// friend function definition

void printVectorData(const Vector2D& v)

{

std::cout << "X and Y coordinates: (" << v.xCoordinate << "," << v.yCoordinate << ")" << std::endl;

}

  
  
  

// friend class

Graphics::Graphics(Vector2D elems[], int size)

{

this->noOfElements = size;

for (int i = 0; i < size; i++)

this->graphicElements[i] = elems[i];

}

  

void Graphics::printAllYCoordinates()

{

for (int i = 0; i < this->noOfElements; i++)

std::cout << "Y coordinate: " << i << ": " << this->graphicElements[i].yCoordinate << std::endl;

}

```

Vector2D.h
```
#pragma once

#include <string>

  

class Vector2D

{

private:

double xCoordinate;

double yCoordinate;

  

// static data member

static int numberOfInstances;

  

public:

// static function

static int getNumberOfInstances();

  

// default constructor

Vector2D(double x = 0, double y = 0);

  

// copy constructor

Vector2D(const Vector2D& v);

  

// destructor

~Vector2D();

  

double getXCoordinate() { return this->xCoordinate; }

double getXCoordinate() const { return this->xCoordinate; }

double getYCoordinate() { return this->yCoordinate; }

  

/*

Add the given 2D vector to the current 2D vector.

Input: v - Vector2D

Output: v is added to the current 2D vector.

*/

void add(const Vector2D& v);

  

/*

Subtract the given 2D vector from the current 2D vector.

Input: v - Vector2D

Output: v is subtracted from the current 2D vector.

*/

void subtract(Vector2D v);

  

/*

Rotates the current 2D vector.

Input: angle - real value

Output: the current 2D vector is rotated with the given angle.

*/

void rotate(double angle);

  

std::string toString();

  

/*

Multiplies the current 2D vector with a scalar value.

Input: scalarValue - real number

Output: the current 2D vector is multiplied by the given value.

*/

void multiplyByScalar(double scalarValue);

  

// operator overloading

/*

Overloading the + operator to add 2 2D vectors.

Input: v - Vector2D

Output: a 2D vector representing the sum of the current 2D vector and the parameter v.

*/

Vector2D operator+(const Vector2D& v);

  

/*

Overloading the * operator to multiply a 2D vector with a scalar value.

Input: scalarValue - double

Output: a 2D vector representing the product of the current 2D vector and the given scalar value.

*/

Vector2D operator*(double scalarValue);

  

// assignment operator

Vector2D& operator=(const Vector2D& v);

  

// friend function

friend void printVectorData(const Vector2D& v);

  

// friend class

friend class Graphics;

};

  

// non-member function

Vector2D operator*(double scalarValue, const Vector2D& v);

  
  

class Graphics

{

private:

Vector2D graphicElements[20];

int noOfElements;

  

public:

Graphics(Vector2D elems[], int size);

void printAllYCoordinates();

};

```



How to run only tests (needs linking):
tests % clang tests.c ../repository/dynamic_array.c ../domain/product.c -o tests
./tests
Maria@Mac tests % ./tests


## Lecture 4 - 18 mar 2026
Reference = another name for the same memory
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


Copy constructors
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

Destructors
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

Copy constructor vs assignment operator
```
Vector2D v7=v1;  // copy constructor is called

Vector2D v8;
v8=v2; // assignment operator
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