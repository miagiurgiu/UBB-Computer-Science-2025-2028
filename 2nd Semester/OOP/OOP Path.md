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

Vector

