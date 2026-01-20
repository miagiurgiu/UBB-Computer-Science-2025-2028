## Lecture 1
PyCharm, Python, GitHub
https://github.com/cs-ubbcluj-ro/FP/tree/main\**https://github.com/cs-ubbcluj-ro/FP/blob/main/src/lecture/livecoding/lecture_1.py ** what we coded in the first lecture

git clone - clone repository - to computer
git commit - save changes to computer
git push - save changes to github.com

c/c++ - statically typed - well defined type; compiled language
`int a;`
`char *p;`
python - default datatypes; declare variables but the variables can change their type; no point in defining its type?


a -> integer
b -> integer
a+b -> integer

a -> integer
b ->string
a+b -> error

compiling vs linking:
linking error:
2 int main()'s - compiling is fine, but linking nope.

main module = python file

print("Hello World")  
user_input = input ("Enter a string: ") #reading a string  
  
a=5 # a - new variable; a has to be an integer; its value its 5  
a="5" # ?  
a=abcd # a - new variable; a has to be a string; its value its abcd  
  
#built-in type() function

list vs set
- **list** = vector → păstrează ordinea, permite duplicate, are index.
    
- **set** = mulțime → doar elemente unice, ordinea nu e garantată, fără index.

"""
Problem statement:
    1. Read a string from the program's console
    2. Divide the string into numbers, words (using space)
    3. Build a list of primes, a list of negative numbers, a list of the rest of the numbers, a list
    of capitalized names
    4. Print out all primes numbers etc. in ascending order, without duplicates :)
"""
Problem solving:
```
"""
Problem statement:
    1. Read a string from the program's console
    2. Divide the string into numbers, words (using space)
    3. Build a list of primes, a list of negative numbers, a list of the rest of the numbers, a list
    of capitalized names

    4. Print out all primes numbers etc. in ascending order, without duplicates :)
"""
print("Hello World")


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n ** 0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


user_input = "55 -6 67 90 9 56 -2 56 -6 -6" #input("Enter a string: ")
# built-in type() function
# print(type(user_input))
tokens = user_input.split()
print(tokens)

prime_numbers = []
negative_numbers = []
other_numbers = []

for token in tokens:
    try:
        int_token = int(token)
    except ValueError:
        continue
    if is_prime(int_token):
        prime_numbers.append(int_token)
    elif int_token < 0:
        negative_numbers.append(int_token)
    else:
        other_numbers.append(int_token)

negative_numbers = sorted(list(set(negative_numbers)))

print("primes ",prime_numbers)
print("negative ",negative_numbers)
print("other ",other_numbers)
```

## Lab 1 
**Assignment 1** in git for next time (choose one problem from each set)

GitHub commands:
```
git clone <url> # for the first use
git pull origin main
git push origin main
f/add* (feature sth)
pull request
git status # either "staged for commit", or "nothing, no changes"
git add<files>
git commit - m "Added new files"
git push origin main
```



## Seminar 1 (6 oct 2025)

programming = a human activity ...


## Lecture 2

#recursion
#complexities

Lecture 2 slides:
![[L02.Recursion. Computational complexity (1).pdf]]

Lecture 2 handwritten notes: none.

## Lab 2
**Assignment 2** started

Exchange Sort, Exponential Sort, Shell Sort

## Lecture 3
#complexity
#recursion 
#Hanoi

Lecture 3 slides:
![[L03.Searching.Sorting.pdf]]

Lecture 3 handwritten notes:
![[FP Lecture 3 (16 oct 2025)_251018_105808.pdf]]
## Lab 3
adc, cwb ...
**Assignment 3 started**
- print out execution time in tables
- calculate the complexity mathematically

##### Python Q & A

1) when / and when // as division?
/ - float division (5/2=2.5)
// - int division (5//2=2)

2) local vs global declaration
local declaration - defined in a function - the variable exists only inside it
global declaration - outside a function - the variable is available anywhere
global variable in a function: 
```
global x
```
3) initialisation
initialisation = declaration
the variable exists only when it has an assigned value
4) functions that return multiple values; void vs return functions; returning an array functions

function that returns multiple values:
```
def f()
	return 1,2,3
a,b,c=f()
```

void function:
```
def f():
	print("hey")
x=f()
```

return function:
```
def f():
	return 10
print(f())
```

returning an array function:
```
def get_numbers():
	return [2,4,6,8]
nums=get_numbers()
print(nums) # [2,4,6,8]
print(get_numbers()) # [2,4,6,8]
print(nums[1]) # 4
```

5) printing
```
print("The value is: ", x) 
# x
```

```
print("Numbers are: ", a,b,c) 
# a,b,c
```

```
print("Numbers are: ", a,b,c, sep=",") 
# a,b,c
```

```
print("a=",a," hot") 
# a=a hot
```

```
print("a=", a, end=' ')
print("b=", b, end=' ')
print("c=", c, end=' ')
# a=1 b=2 c=3
```

```
print(1,2,3,sep="\n")
`
1
2
3
`
```

```
print("a")
print("b")
`
a
b
`
```

```
print("a", end=' ')
print("b")
# a b
```

```
print (f"a={a}, b={b}, c={c}")
# a=1, b=2, c=3
```

```
for i in range (1,6)
	print(i, end=' ')
# 1 2 3 4 5
# end = '\n ' by default
```

```
for i in range (1,6)
	print(i, end=',')
# 1, 2, 3, 4, 5
```

6) always value val = function() before printing out the result? No.
7) don't need a copy when palindrome? 
if by palindrome you mean "oglindit", no. 
if you mean palindrome = n whose "oglindit" = n, yes.
8) printing multiple things on the same line
```
for i in range (1,6)
	print(i, end=' ')
# 1 2 3 4 5
# end = '\n ' by default
```

9) endl on a new line or after printing stuff on the same line?
endl by default
if you want sth.else -> sep="sth.else"
```
print(1,2,3,sep='\n')

```

10) while True, while False, while not
```
while True:
	....
	break
# infinite steps until breaks
```

```
while False:
	...
# 0 steps (never enters)
```

```
while a==False <= > while not a

while not (x>10 and y<5)
# repeats until the condition becomes True
```

11) for token in tokens
```
tokens = ["55", "-6", "67", "90"]
for token in tokens:
	print(token)
'
55
-6
67
90
'
```

```
tokens = ["55", "-6", "67", "90"]
for token in enumerate(tokens):
	print(i,token)
'
0 55
1 -6
2 67
3 90
'
```

12) 
```
pairs = all_pairs(n)
if pairs: # if len(pairs)>0 checks if the list is empty
	for p1,p2 in pairs:
		return p1,p2 # first pair
p1,p2=...(n)
```

13) list vs array vs set
LIST - [ ]
	 - allows duplicates
	 - order counts
	 - indexabile
	 - modifyable
	 - numbers=[1,2,2,3]

SET - { }
	- no duplicates
	- no order
	- non-indexabile
	- eliminates duplicates

ARRAY - efficient
	    - NumPy

sort() can be applied on both sets and lists? only on lists, not on sets.
list.sort() - just on lists
```
nums=[1,2,3]
nums.sort()
```
sorted() - on sets, strings etc -> new list

```
set={1,2,3}
new_set=sorted(set)
```

14) for loops
```
for i in range (n)

for i in range(start, stop, pas)

for i in [1,2,3]

for ch in "Alex"
	print(ch)
'
A
l
e
x
'

for i, name in enumerate(names)
'
0 Alex
1 Bob
2 Mia
'

for i in range(n)
	if i==2:
		continue # salt
```

15) def is_prime(n:int) - just a hint, does not do any conversion
16) print(type(user_input)) always specify the type when printing?
it shows us the type (string/char...)
17) try functions?
```
try:
	# code that might cause errors
except:
	# what to do if an error occurs
else
	# no problem, it runs, what do do if there is no error
finally
	# it's over, runs anyway
	
# Example:
try:
	x=int(input("Nr: "))
	print(10/x)
except ValueError:
	print("Should be a number")
except ZeroDivisionError:
	print("You can't divide by 0")

```

18) PULL vs PUSH vs COMMIT
pull - from github to computer
push - from computer to github
commit - save changes made on computer

make changes on both computers -> error
19) datatypes

## Lecture 4

Lecture 4 slides:
![[L03.Searching.Sorting.pdf]]
![[L04.Problem solving methods.pdf]]

## Searching Algorithms:

**Sequential search, iterative**:
```
def search_iter(data: list, key):
    for i in range(len(data)):
        if data[i] == key:
            return i
    return -1
```

**Sequential search, recursive**
```
def search_rec(data: list, key, pos: int = 0):
    if len(data) > 997:
        # The initial execution of the current module and
        # initial method call are already on the stack, so we have fewer than
        # 1000 recursive calls available in the default Python implementation ;)
        raise ValueError("Will overflow the Python stack")

    if 0 > pos or pos >= len(data):
        return -1
    if data[pos] == key:
        return key
    return search_rec(data, key, pos + 1)

```

**Complexity for sequential search**
BC: search key is the first element checked, so T (n) = 1 ∈ Θ(1)
WC: search key is not found, so T (n) = n ∈ Θ(n)
AC: let’s assume 50% of searches end with the element not found, and when the element is found, it has the same probability of being on any position in the list. This time, we simulate 2 ∗ n runs; during n runs, the element is not found, and during the remaining runs, it is found on each of the list’s n positions; 
![[Pasted image 20251026173704.png]]

**Binary search, iterative**
```
def binary_search_iter(data: list, key):
    left = 0
    right = len(data) - 1

    while left <= right:
        middle = (left + right) // 2
        if data[middle] > key:
            right = middle - 1
        if data[middle] < key:
            left = middle + 1
        if data[middle] == key:
            return middle
    return -1

```


**Binary search, recursive**
```
def binary_search_rec(data: list, key):
    """
    Binary search, recursive implementation
    :param data: List in which search is performed in
    :param key: Search key
    :return: Position of element, -1 if element was not found
    """
    return binary_search_impl(data, key, 0, len(data) - 1)


def binary_search_impl(data: list, key, left: int, right: int):
    """
    This is an implementation method. _ means that the method should not be called from other modules.
    """
    if right < left:
        return -1
    m = (left + right) // 2
    if data[m] > key:
        return binary_search_impl(data, key, left, m - 1)
    if data[m] < key:
        return binary_search_impl(data, key, m + 1, right)
    if data[m] == key:
        return m

```

**Another binary search?? - binary search adapted for exponential search**
```
# NOTE Take a look at this method
def test_binary_search():
    binary_search_alg = [binary_search_iter, binary_search_rec]

    for bs_alg in binary_search_alg:
        data = list(range(1000))
        for i in range(0, 1000):
            assert i == bs_alg(data, i)
        assert -1 == bs_alg(list(range(100)), 101)
        assert -1 == bs_alg(list(range(100)), -1)

test_binary_search()

```

BC: search key is the first element checked, so T (n) = 1 ∈ Θ(1)
WC: search key is not found. Each time halving the array in O(1) time. Since we can do this log2n times, the complexity in the average and worst cases is Θ(log2n)

**Exponential search**
```
def binary_search_impl(data: list, key, left: int, right: int):
    """
    This is an implementation method. _ means that the method should not be called from other modules.
    """
    if right < left:
        return -1
    m = (left + right) // 2
    if data[m] > key:
        return binary_search_impl(data, key, left, m - 1)
    if data[m] < key:
        return binary_search_impl(data, key, m + 1, right)
    if data[m] == key:
        return m
# ?? from ex10_binary_search import binary_search_impl 

def exponential_search(data: list, key):
    if len(data) == 0 or data[0] > key or data[-1] < key:
        return -1

    if data[0] == key:
        return 0

    i = 1
    while i < len(data) and data[i] <= key:
        i = i * 2

    return binary_search_impl(data, key, i // 2, min(i, len(data)-1)

```
 
 **Exponential search complexity**
 We need log2n steps to determine whether the element is in the list; we apply further log2n steps to find its position between indices i, 2 ∗ i (complexity can be determined based on indices i, but for ease of understanding we used n as upper bound, so complexity is O(log2n)

## Sorting algorithms:
https://www.toptal.com/developers/sorting-algorithms

Notions:
streaming sort = data becomes available sequentially
in-place sort = transforms the input data into the output, uses small additional space
stable sort = ?
space = memory complexity

**Insertion sort**
- everything on the left of our current index is sorted already
- Very good for short lists, or lists that are nearly sorted (with only a few elements out of place)
```
def insertion_sort(data: list):
    for i in range(1, len(data)):
        val = data[i]
        j = i - 1
        while (j >= 0) and (data[j] > val):
            data[j + 1] = data[j]
            j = j - 1
            data[j + 1] = val
    return data
```

![[Pasted image 20251026175049.png]]

**Binary Insertion sort - optimised Insertion sort**
```
def binary_search(arr, val, start, end):
    # we need to distinguish whether we should insert before or after the left boundary. imagine [0] is the last
    # step of the binary search and we need to decide where to insert -1
    if start == end:
        if arr[start] > val:
            return start
        else:
            return start + 1

    # this occurs if we are moving beyond left's boundary meaning the left boundary is the least position to find a
    # number greater than val
    if start > end:
        return start

    mid = (start + end) // 2
    if arr[mid] < val:
        return binary_search(arr, val, mid + 1, end)
    elif arr[mid] > val:
        return binary_search(arr, val, start, mid - 1)
    else:
        return mid


def binary_insertion_sort(data: list):
    for i in range(1, len(data)):
        val = data[i]
        j = binary_search(data, val, 0, i - 1)
        # This is O(n) space complexity, but it can be simplified by moving elements one by one
        data = data[:j] + [val] + data[j:i] + data[i + 1:]
    return data

```
![[Pasted image 20251026175752.png]]

**Quick sort**
- based on divide and conquer
divide and conquer:
- divide: partition array into 2 sub-arrays such that elements in the lower part ≤ elements in the higher part.
- conquer: recursively sort the 2 sub-arrays.
- combine: trivial since sorting is done in place.

**Quick sort complexity**
- need to update
![[Pasted image 20251026180239.png]]

**Merge sort**
- based on divide and conquer
- The list to be sorted is divided in two sub-lists that are sorted separately. The sorted sub-lists are then merged
- Each sub-list is sorted using the same approach until we get to sub-lists of length 1, which we know are sorted.
- pros: Merge sort has good time complexity and it’s easy to write an implementation that works well..
- cons: 
	- It has non-constant extra-space complexity 
	- Time is wasted when merging very short lists (length 1, 2,4...)

![[Pasted image 20251026180501.png]]

~={red}The most efficient sorting algorithms are generally hybrid versions that combine more sorting methods =~

**Intro sort**
- An optimization of quicksort’s worst case - when pivot selection leads to worst case behavior
- hybrid sorting algorithm

**Tim sort**
- Built on merge sort, it uses binary insertion sort for small sections of the list
- takes advantage of cache
- the newest (2002)

The original TimSort: 
https://svn.python.org/projects/python/trunk/Objects/listsort.txt)
source code (https://github.com/python/cpython/blob/main/Objects/listobject.c)

![[Pasted image 20251026181101.png]]
Lecture 4 handwritten notes:
![[FP Lecture 4 (23 oct 2025)_251023_114828.pdf]]

## Lab 4
**Assignment 4*

ex 14 - backtracking
14. Generate all numbers of `n` digits with the property that no number has two identical neighboring subsequences. For example, for `n=6`, `121312` is correct, and `121313` and `132132` are not correct.


## BACKTRACKING RECALL for lab4

"GENERARE"

Helps us generate all (or most of) the solutions of a problem
Time complexity: exponential/factorial
Time complexity: O(nr_of_elements ^ nr_of_positions)
Backtracking is as efficient as you make it
Not backtracking, but brute force is inefficient

Optimisations:
- we don't continue to generate using the current solution if we cannot get to a final solution that is correct
- validations - at each step, we make some validations which assure us that we could continue generating in order to obtain a correct final solution
- if the current solution is invalid (it cannot help us get to a correct solution), there is no point in continuing the generating process

 Recursive backtracking - at each step, we try to occupy a position in the solution using the elements of the set

TEMPLATE FOR BACKTRACKING:

```
def valid():
{
	# conditions that might cancel the valitidy
		# return 0 for each contidion that might cancel the validity 
	# return 1 at the end
}
def btrack(int gap, (2) int sum,...):
	for(element_in_the_set) # we go through the set
		# we add the element_in_the_set to the current gap
		# (1) optional: some instructions related to adding the element to the current gap
		# for example we might need the current sum of the elements: sum+=element_in_the_set
		if(valid): # check if the solution build by now is valid
			if(final_of_solution): # if we have a final solution, we print it and stop generating
				# printing
			else: # keep on generating
				btrack(gap+1, (2) sum+element_in_the_set, ...)
		# (1)	if we had such instructions, we need to cancel them
		# for example might have to do: sum-=element_in_the_set
		# the element is no longer on the current gap, so we have to make sure of this
		# (2) if we don't want to cancel every time, we could use local parameters
```

## Seminar 4 
![[FP Seminar 4 (24 oct 2025)_251031_145252.pdf]]

## Lab5
**Assignment 5**

ex 4 - dinamic programming   
4.Given an `n * n` square matrix with integer values, find the maximum length of a snake sequence. A snake sequence begins on the matrix's top row (coordinate `(0, i), 0 <= i < n`). Each element of the sequence, except the first one, must have a value `±1` from the previous one and be located directly below, or directly to the right of the previous element. For example, element `(i, j)` can be succeded by one of the `(i, j + 1)` or `(i + 1, j)` elements. Display the length as well as the sequence of coordinates for one sequence of maximum length.

## DYNAMIC PROGRAMMING RECALL for Lab5




## Lecture 5 
#dynamicprogramming
![[L04.Problem solving methods.pdf]]

## Seminar 5
![[FP Seminar 5 (31 oct 2025)_251102_171225.pdf]]

## Lecture 6 (14 nov 2025)

### Procedural Programming

## Seminar 6 (7 nov 2025)
#dictionaries
#proceduralprogramming

## Lab 6

Assignment 6 started.

## Lecture 7 (13 nov 2025)
### Modular Programming
#modules 
#packages
#calculator

A section of programming in the large - syntax made for humans, not computers
Modules & Packages overview
Modules, packages and functions help break programs into smaller, easier, reusable pieces.

Programming paradigms (in the large):
1. PROCEDURAL programming
	- program = functions calling each other
	- handling exceptions gracefully (try... except)
2. MODULAR programming 
	- program split into interchangeable modules (one module = one .py file)
	- each module is responsible for one aspect of the program
	- continuation of procedural programming
	- independent + interchangeable - the ui should work in the same way even if ... ?
3. OOP
	- program = interacting objects

 
MODULAR Programming:

Pros:
- allows working on programs by > programmers without github conflicts
- breaks down large programs into smaller pieces
- easy reuse across projects
- helps avoid name conflicts
- makes reading the program structure easier (IDE, GitHub, Finder, Explorer)
- many programmers can work on the same code -> fewer merge conflicts
Cons:
- issues with circular imports, unclear namespaces, duplicate imports, overwriting names
- requires knowledge to keep modules independent

Modules in python:
A module is a .py file containing:
- module docstring (""" """)
- executable statements (function definitions, constants, init code)
How to create a python module?
1. write a .py file
2. (optional) write a C extension module (CPython) -> CPython is the default implementation of Python. This module calls the C code behind Python -> THIS IS WHY when we tested runtime for sorting algorithms the sorted() function performed much faster (because we called a function that is written in C and that is FAST)
commit - local operation on my computer
two programmers working on the same project -> push -> conflict
interpreter - runs the last function
3. built-in modules (python -> settings -> interpreter -> install numpy/texttable etc.)

Module Docstring (Documentation)
- Documentation (""" """ block in the function or press "add parameters to docstring" on the name of the function) should live next to the code in the same module, so that they are updated and can work together
- there are tools that allow to export to human-readable formats like pdf/html -> markdown -> see how the program works

```
def add_rational(q1, q2):  
    """  
    Return the sum of rational numbers q1 and q2    #DOCSTRING
    """    
    gn = get_numerator  # Python functions are first-class citizens :)  
    gd = get_denominator  
    # first-class citizens == can be used just like variables (send as parameters, return, assignment)  
    # type of gn after the assignment is function    
    # gn is not called unless we use the call operator ->  ()    
    return create_rational(gn(q1) * gd(q2) + gn(q2) * gd(q1), gd(q1) * gd(q2))

```

How to import a python module?
- you can import anywhere you want, but not recommended inside functions
- catch ImportError is dangerous
- **import** does the following: loads the module -> adds names into local symbol table -> accessible via **spam.something**

```
import spam
from spam import is_prime
from spam import is_prime as p # as alias
from spam import * # not recommended because it could cause name collisions

# examine imported names:
dir(spam) # names
help(spam) # documentation
pydoc/pdoc # generates HTML docs
```

```
from pdoc import pdoc
 allows us to get a html -> html file in pycharm -> open in browser

"""
>>> add_rational(create_rational(1), create_rational(3))
"""
```



Modules in C/C++:
- header files: .h (signatures, documentation for all the methods that are public, not compiled)
- want a list? list.h (stuff, public) and list.c (implementation, private?) 
- c is much older -> separate stuff from program implementation
- **include** take the header file and copy pastes-in into the current file
.cpp ?

parallel: masina cu servo-directie






Packages in PyCharm:
A package is a directory containing:
1. modules
2. an _____init_____.py   file

Packages solve name-collision between modules, not inside them.

```
mypackage/
__init__.py
moduleA.py
moduleB.py

```

How to import packages?
```
import mypackage.moduleA
from mypackage.moduleB import foo

```

Virtual environments & Packages in PyCharm:
- venv - virtual environment to isolate dependencies (pycharm can automatically create venvs)
- != projects => != package versions

- faker -> create random data, cities, names
- they group modules in order to avoid name conflicts
- like an address -> country.city.street.nr.person_name
- from lecture.examples.ex30_modules.rational.rational_dict import create_rational, get_numerator, get_denominator (example from FP repo)
- numpy - used to working with arrays

IDE's: a set of rules -> need linker/compiler/interpreter to run it
compiler for python? interpreter for python?

modules:
rational_as_dict.py
rational_as_list.py
calc.py 
-> new "main" module
-> we can import modules like rational_as_dict.py, rational_as_list.py in != ways

```
from rational_as_list import *
import rational_as_list
import rational_as_dict
import rational_as_list as rl # with alias 
import rational_as_list 
import create_rational as newq, to_str, add_rational # recommended, the added modules are automatically put in a dictionary
import *

# we use these with dot "."
import rational_as_list
...
rational_as_list.create_rational
rational_as_dict.create_rational

# 
from rational_as_list import create_rational
...
create_rational()

```

The _____main_____ guard
prevents code from executing when module is imported
```
__main__ -> the module used to start the python program
MAIN GUARD in python
```

"Private functions"
prefix with _ to signal they are internal
If we don't want our function to be accessed by other modules (kind of private, good practice not to use)
```
def _super_secret_function():
# those functions won't be visible in the documentation or in the generic import
```

pdoc interpreter

when running the program -> we can run != things -> choose "run ui"

"raise" and "return" aren't actual "printing functions", you can have them in other modules

take a look at how history works!

### 

## Seminar 7 (13 nov 2025) Tic Tac Toe game

1) board.py
- handles the game board
- NO `input()` or `print()` here
- functions:
    
    - `create_board`
    - `move_board`
    - `is_won_board`
    - `is_full_board`
    - `get_cell_board'
    - `to_str`
2) game.py
- logic for using board functions
- handles _moves_:
    - `human_move`
    - `computer_move`
- also NO `print()` / `input()`
1) ui.py
- only place with:
    
    - `print`
    - `input`
        
- loop:
    
    1. show board
    2. ask human move
    3. make computer move
    4. check win/full
    5. end program
    6. 


## Lecture 8 (20 nov 2025)
#classes
#objects

ex31_modular_calculator
has a feature add numbers
has a feature to undo -> until it gets to the initial values

livecoding -> rational.py

What is an OBJECT?
- a thing created from a class
- it has a state(attributes/data) and behaviour (methods/functions)
- it occupies memory

What is a CLASS?
- a template/blueprint/plan used to create objects
- a definition for a data type
- a collection of state (attributes/fields) and behaviour (functions, methods)

```
class Rational:
    ...
=> Rational becomes a new data type

```

What is a CONSTRUCTOR?
- allocates memory -> calls the original one -> **create an instance called "self"**
- in python, the constructor is always ____init____
- with constructors, we are not allowed to the return sth, its job is to return a reference/pointer from the original object. if you return "none", you destroy the way the constructor works
- it implicitly returns a reference to the new created object (you should not write return here)

```
class Rational:
    def __init__(self, numerator: int, denominator: int = 1):
        if denominator == 0:
            raise ValueError("Cannot have 0 denominator")
        self.numerator = numerator
        self.denominator = denominator


```

usage:

```
q = Rational(5)
print(type(q))
print(q.numerator, q.denominator)

q.denominator = 0  # BAD – should not modify directly


```

How to better use a class:

```
def to_str(self) => str:
	return str(self.numerator) + "/" + str(self.denominator)

def __str__(self):
	return str(self.numerator) + "/" + str(self.denominator)

print(q)

```
In python - only one "init" function called with "init"
Java/c++ - the name of the constructor: "Rational"

3 keywords:
- private (by convention, you should not modify them from outside the class)
- protected
- public (accessible from anywhere)

PUBLIC attributes:

```


```

the attributes are public:
```
"""
simplest class that we can write in python

"""
class Rational:
	def __init__(self,numerator:int, denominator: int=1): # constructor
	self.numerator = numerator
	if denominator == 0:
		raise ValueError("Cannot have 0 denominator")
	self.denominator = denominator

q = Rational(5) # returns the object that was created, not none
print(type(q))
print(q.numerator, q.denominator)
q.denominator = 0 # not good
```

What if someone tries to change the denominator to 0? -> BAD -> private/protected/private

the next atributes are public
```

self.numerator = numerator
self.denominator = denominator
```


the next attributes are private:
```
...
self._numerator = numerator
self._denominator = denominator
...
print(q._numerator, q._denominator)

```

from .... import ...  * -> import everything except what is with underscore


the next attributes are still private, but mangling - can be modified, but only inside the class?
```
self.__numerator = numerator
self.__denominator = denominator
...
print(q.__numerator, q.__denominator)

```

How to access python class methods:
print(q.get_numerator())
print(Rational.get_numerator(q)) # we assume q is rational
q.set_numerator(q.get_numerator()+1)

@property - combine getters and setters

the setting method on class Rational
- count how many rational numbers we created


```
from ... import Rational

class CalculatorError(Exception):
	"""
	a kind of exception
	Exception is the error that python returns implicitly
	"""

class Calculator:
	def __init__(self):
		self._value = Rational(0)
		# history of the calculator's operations
		self._history = []
    def add_number(self, value):
	     #record the value in the undo list
	     self._history.append(self.value)
	     #update calculator value
	     self._value + = value
	     
	# a value to print
	
	@property
	def value(self):
		return self._value
	def undo(self):
		if len(self._history)==0:
			raise calculatorError("No operations to undo")
		self._value = self._history.pop() # removes and returns the last element from a list


c= Calculator()
print(c.value)

# outside the class, so it does not need self
def test_calculator():
	c = Calculator()
	try:
		c.undo()
		assert False # if we dont rise and exception
	except CalculatorError:
		# what we expected
		assert True
	except Exception
		# we expect a CalculatorError, not any kind of error
		assert False
	
```

1. Call the rational class constructor
	- raises an exception => steps 2, 3 no longer take place
2. Type of rational object transfered to q0
3. Value of rational object transfered to q0

Why  would you need a class for errors instead of ValueError?
- check easier what type of errors arrise
- translate from one language to another -> silly strings?
-

how to use pdoc in terminal:
```
(.venv) Maria@Mac a8-miagiurgiu % export PYTHONPATH=/Users/Maria/PycharmProjects/a8-miagiurgiu

(.venv) Maria@Mac a8-miagiurgiu % pdoc src/repository/repository.py -o docs

(.venv) Maria@Mac a8-miagiurgiu % ls docs
index.html      repository      search.js
(.venv) Maria@Mac a8-miagiurgiu % open docs/index.html
(.venv) Maria@Mac a8-miagiurgiu % 

```


## Lecture 9

#### OOP STRUCTURE AND THEORY

STRUCTURE OF AN OOP PROGRAM:
1. Domain (Book/Flight etc. )
2. Repository (main functionalities)
3. Service (repo functionalities + extra)
4. UI (Console) (menu, input)
5. main (links them all)

FLOW:
UI -> SERVICE -> REPOSITORY -> DOMAIN

CONCEPTS:
1. CLASS - blueprint
	- classes allows me to create user-defined data structures
	- classes define functions called methods
	- these methods identify the behaviours and actions of an object
	- a blueprint for how to define sth
	- it does not contain any data
	- ex: an employee class specifies that a name and age are necessary, but does not contain any name or age of any employee -> it's just the pattern
	- like a form/questionnaire
	- advantage: instances are guaranteed to have the attributes we expect (all Emplouee instances have .species, .name, .age attributes)
	

```
class A(object):
	def __init__(self):
		self.__a = 10
	def m(self):
		return "A"
	
- in this case, class A inherits from class object
- all python classes (except object) inherit from object (either directly or transitively) => all non-private fields and methods of class object also appear in class A
  
  
class B(A):
	def __init__(self):
		super().__init__() # this if how we call the constructor of the base class in python
	def m(self):
		res = super().m() # access the initial method from class A
		print(res
		# print(super().m())
		return "B"
		
- method m() in class B overrides method m() from class A
  
a = A()
print(str(a))
print(a.__str__())
print(a.m())

b = B()
print(b.__str__())
print(b.m())


```
2. OBJECT - instance of a class
	- custom object are mutable by default
	- a built-in Python class
	- the root of the Python inheritance tree
	- an object is mutable if you can alter it dynamically (sth do to with private/public?)
	- lists, dictionaries -> mutable
	- strings, tuples -> immutable
	- Mia is an object:
		- with properties (name Mia, age 19)
		- with behaviours (walking, talking, breathing)
	- Magda is an object:
		- with properties (name Magda, age 52)
		- with behaviours (walking, running, eating)
3. CONSTRUCTOR (_____init_____) - sets fields of the object
4. ENCAPSULATION - ' _ ' or ' _  _ '
5. INSTANTIATION
	 - creating a new object from a class
	
```
class Employee:
	pass

a = Employee() # we instantiated the Employee class -> address1
b = Employee() # -> address2
a == b # prints out False because they are 2 distinct object in memory (address1 != address2)
```

6. INHERITANCE - pass another class as a parameter
		- one of the pillars of OOP
7. INSTANCE
	- an object that is built from a class and contains real data
	- an instance of the employee class is not a blueprint anymore, but an actual employee with a name
	- the form/questionnaire is filled out with information
8. INSTANCE ATTRIBUTES:
	- attributes created in init
	- their value are specific to a particular instance of the class (ex: all employees have a name and age, but the values differ depending on the instance) -> information in form/questionnaire
	- used to defining properties that vary between instances
9. CLASS ATTRIBUTES:
	- attributes that have the same values for all instances -> the form/questionnaire
	- define them by assigning to them a value outside init
	- defined immediately after the first line of the class name
	- they must have an initial value
	- flow: create an instance of the class -> python creates and assigns class attributes to their initial values
	- used for defining properties that do not vary between instances
 10. INSTANCE METHODS
	 - functions defined inside a class
	 - they can only call on an instance of that class
	 - always self as their first parameter

```
class Employee:
	def __init__ (self, name, age):
		self.name = name 
		self.age = age
	def description(self): # instance method that returns a string (not pythonic)
		return f"{self.name} is {self.age} years old"
	def speak (self, sound): # instance method that returns a string based on the parameter
		return f"(self.name) says {sound}"
```

```
Mia = Employee("Mia", 19)
Mia.description() # Mia is 19 years old
Mia.speak("Hello") # Mia says Hello
Mia.speak("Goodbye") # Mia says Goodbye

```

```
names = ["Mia", "Magda"]
print(names)

# ['Mia', 'Magda']

print(Mia) # address -> we want that value -> we need __str__ method

```

String method:
- useful for printing useful stuff instead of weirdo addresses
- that .description method was not pythonic -> replace it with str
- init, str are dunder methods
```
class Employee:
	def __init__ (self, name, age):
		self.name = name 
		self.age = age
	def __str__(self):
		return f"{self.name} is {self.age} years old"
	def speak (self, sound): # instance method that returns a string based on the parameter
		return f"{self.name} says {sound}"

```

```
Mia = Employee("Mia", 4)
print("Mia")
# 'Mia is 4 years old'

```

```
_data -> internal, cannot be used directly from exterior (there is no "private" in python, so kinda private)
__data -> name-mangling, can be used only inside the class

```

THE 4 KEY CONCEPTS OF OOP IN PYTHON:
- encapsulation
	- bundle attributes and behaviours in a class
	- (bundling state and behaviour together and selecting what to expose to the outside world)
- inheritance (class inheritance)
	- a class can inherit attributes and methods from another class (parent class)
	- hierarchical relationships between classes
	- a subclass can inherit attributes and methods from a parent class
	- this reduces duplicate code
	- (reuse code, specialize code, allow us to change things further down the line)
- abstraction
	- hide implementation details
	- expose only the essential functionality of an object
- polymorphism ?
	- treat objects of different types as instances of the same base type 
	- (changing the way objects react to messages)

How to create a class:
- use CamelCase

```
class Employee:
	def __init__ (self, name, age): # declare which attributes each instance of the class should have
		# instance attributes:
		self.name = name # creates an attribute called "name" (left) and assigns the value of the "name" (parameter) to it (right)
		self.age = age # creates an attribute called "age" and assigns the value of the "age" parameter to it

```

How to create an object:
- by instatiating a class -> calling the class name followed by parentheses

```
book = Book("1", "Mircea Cartarescu", "Solenoid") # this is an object
```

The init method:
- inside we define properties that all Employee objects must have
- sets the initial state of the object by assigning the values of the object's properties
- init initializes each new instance of the class
- can have any number of params, but the first one should be always "self"
- should pe properly indented
- dunder method

What does self do:
- when we create a new class instance (like book above), that instance is passed to the self parameter in init -> python can define new attributes on the object

How to call a method from the parent class:
- by using super() -> extends/modifies inherited behaviour

INSTANCE ATTRIBUTES vs CLASS ATTRIBUTES:

```
class Employee:
	species = "Homo Sapiens" # class attribute
	def __init__(self, name, age):
		self.name = name # instance attribute
		self.age = age
Employee() # error

# create 2 Employee instances:
# we don't use the first parameter because that one is "self"
Mia = Employee("Mia", 19)
Magda = Employee("Magda", 52)
```

How to access instance attributes:
- using dot notation

```
Mia.name # Mia
Mia.age # 19

Magda.name # Magda
Magda.age # 52

Mia.name = Ioana 
Mia.name # Ioana

Mia.species = "Felis silvestris"
Mia.species # Felis silvestris

```

How to access class attributes:

```
Mia.species # Homo Sapiens
Magda.species # Homo Sapiens
```


## Lab 9
test Modular + Procedural programming

## Seminar 9
extensive discussion about the origins of computer science, ladies at ENIAC and economical breakthroughs.

## Lecture 10 - Layered architecture
bakery
https://github.com/cs-ubbcluj-ro/FP/tree/main/src/lecture/livecoding/bakery

Layered Architecture - **What is it?**

- It is a design pattern (a way to organize code) for writing large programs
- The program is made up of layers
    - Each layer has access to classes in its own layer, or the layer immediately below
- What layers are there usually?
    1. Presentation layer (at the top, user interface)
        - All the user interaction (reading data, presenting data to the user, presenting error information etc.)
        - Classes like _BakeryUI_
        - This layer talks only with the service layer
    2. Service layer (or controller layer)
        - Each entity in the domain should have its own service class
        - Classes like _RecipeService_, _ProductService_ etc.
        - No user input/output here, just parameters and raising exceptions
        - Talks only with the data persistence layer
    3. Data persistence layer (or repository layer)
        - Its job is to persist the entitites in the problem domain
        - Might use memory (v1), binary/text files (v2), databases (SQL/noSQL) (v3)
    4. Domain
        - The domain contains the classes from the problem domain (e.g., _Product_, _Recipe_, _Ingredient_, etc.)
        - Classes from the domain do not know about any other layer
        - All other layer can use classes from the domain


## Lab 10
a9 layered architecture

## Seminar 10
https://github.com/Mathew-H7/Seminar-9-FP

## Lecture 11 (11 dec 2025)

#### The service layer. Design patterns.

! keep in mind:
in Python, functions are "first-class-citizens" => they can be used like any other variable,
so functions can be:
	- assigned
	- we can give them as parameters

Design patterns:
- many problems in writing software keep repeating
- = templates, generic solutions that when implemented, can help
- a common way to solve common problems
-  patterns repeating over and over again
- design patterns = generic solutions

Examples of Design patterns:
1. ITERATOR
		- traverses a collection so that we visit each element only once
		- iterator (bakery -> repo -> memory_repo -> repository iterator) 
			- traverses a data structure
			- https://refactoring.guru/design-patterns/iterator
		- You can obtain the memory repository form the repository iterator
		- example:
```
class RepositoryIterator:  
    def __init__(self, elements):  
        self._elements = list(elements)  
        self._pos = -1  
  
    def __next__(self):  
        self._pos += 1  
        if self._pos >= len(self._elements):  
            raise StopIteration()  
        return self._elements[self._pos]

```
2. LAYERED ARCHITECTURE (= design pattern)
		- high-level pattern, a way of organising large code
		- program organised into layers (ui->service->repo)
		- each layer talks with itself/the layer immediately below (ex: service talks to itself + repo; ui talks to itself + service)
		- layered architecture 
			- programs organised into layers
			- each layer talks within itself / the level immediately below
			- week 10 lecture notes (bakery example)

3. MEMENTO (= design pattern)
		- remember the state of an object and revert to it when needed
		- memory-consuming
		- we use it when copying the list of entities for undo/repo 
		- memento
			- remember the state of an object, revert to it when needed
			- when copying the list of entities for undo
			- https://refactoring.guru/design-patterns/memento
4. COMMAND (= design pattern)
		- remember an operation + its parameters and carry it out sometime later
		- we use it when we want to implement undo/redo


Uml diagram 
- IngredientAmount is a value object because it does not have an id, it is defined by its own attributes and does not depend on BakeryObject, but is part of the domain still.
- White triangle arrow = inheritance

Abstract_text_file_repo:
- see abstract text file repo -> encodes the behaviour of when to load/save file
one underscore -> protected
- abstract = should not be instantiated. 
- we use it to figure out when save_file, load_file must be called
```
from lecture.livecoding.bakery.domain.bakery_object import BakeryObject
from lecture.livecoding.bakery.repo.memory_repo import MemoryRepository


class AbstractTextFileRepo(MemoryRepository):
    """
    This is an abstract class (abstract = it cannot/should not be instantiated)
    Its job is to figure out when save_file and load_file must be called
    Derived classes should implement those methods for storing BakeyObject instances
    """

    def __init__(self, file_name: str):
        super().__init__()
        self._file_name = file_name
        self._load_file()

    def store(self, element: BakeryObject):
        super().store(element)
        # self._save_file()

    def remove(self, element: BakeryObject):
        super().remove(element)
        # self._save_file()

    def _load_file(self):
        raise NotImplementedError("Must be implemented in subclasses")

    def _save_file(self):
        raise NotImplementedError("Must be implemented in subclasses")

```


Conclusion:
1. UML diagram for layered architecture more entities than needed https://github.com/cs-ubbcluj-ro/FP/blob/main/src/lecture/livecoding/bakery/Bakery_uml_class_diagram.png
2. how to implement statistics using data transfer object move between layers
3. implement undo/redo using command desgin pattern
4. review of the design patterns that we have already seen (memento, layered architecture, iterator, command design pattern for undo/redo)

Observations;
- we need a different repo for each ingredient/product/recipe because we need different load file for each entity
- transmit the repos as constructor parameters -> recipe_service
- percent of salt statistics -> low_salt_recipes
- local history

How to run with coverage:
- right click on test folder -> run all tests with coverage

How to see coverage report in terminal:

```
pip install coverage
coverage run -m unittest discover -s tests
coverage report -m
```

How to save what you do in terminal:
```
script session.txt

```


Observations:
1) id, name properties are read-only (once we create the object, we cannot change its id)
2) This is an abstract class (abstract = it cannot/should not be instantiated)
    Its job is to figure out when save_file and load_file must be called
    Derived classes should implement those methods for storing BakeryObject instances
3) For layered architecture !!
        - Transmit the repositories as constructor parameters, as this allows us to change the type of repository we use
        without changing the service class source code
        - Early form of "dependency injection"
4) Observations about writing PyUnit tests:
        -> PyUnit is a member of the xUnit testing tools (the first was probably JUnit for Java)
        -> Unit tests should be placed in their own directory/package (usually called "test")
        -> Unit test classes must be derived from unittest.TestCase (gives us access to assertXXX methods)
        -> test method names must start with "test_"
        -> test methods are run separately from running the program
        Test discovery:
            -> the testing framework must be able to autoamtically find and run all unit tests
            -> right-click on test package -> Run all tests ...
        How do I know I've written enough tests? !?
        => we use "code coverage" (how much of the application's source code, expressed in percents, was executed
        while running the tests)
            - the idea is not to miss classes, functions, code sections
        => more code coverage is generally better than less, but not perfect :(
        => 100% code coverage does not mean the application does not have bugs :(


When to import and when not to import a class in another class:
- why don't we import the validation class? can we just use it by the _validator attribute? how does it know how to instantiate with that method from the validate_assignment class?? Because the validator is **created in `main()` and injected into the service**, not instantiated inside it.

`AssignmentService` does **not need to import or create** `AssignmentValidator`; it only uses `self._validator`, which already **is** an `AssignmentValidator` instance passed via the constructor (dependency injection).


How to add a new sth to the dictionary:


A11: game Planes 


Questions for Alex:

Syntax questions

1. public vs protected vs private (name-mangling) ?
public ? 
```
self.numerator = numerator
self.denominator = denominator
```

private - since it's a "convention", this means that the following attributes could actually be accesses from outside the class, but should not? If i want to access them in another class i need a @property?
```
...
self._numerator = numerator
self._denominator = denominator
...
print(q._numerator, q._denominator)

```

private, but name mangling - can be accessed, but only inside the class? If i want to access them in another class i need a @property?
```
self.__numerator = numerator
self.__denominator = denominator
```

2. polymorphism =  treat objects of different types as instances of the same base type (I don't understand the definition and can't associate it with an example)
3. if the _cell_state function returns a tuple, then why do we access this function like this self.__cell_state(row, column)[0] == 9 inside the click function ?

```
def _cell_state(self, row, column):  
        val = self.__data[row][column]  
        if val < 10:  
            return val, False # why return a tuple like this? how will this be accessed further?
        else:
	        return val, True
	        
def click(self, row: int, column: int):
        if not (0 < row < self.__rows) or not (0 < column < self.__columns):
            raise MinefieldException(f"User clicked out of bounds: ({row},{column})")
        self.__lay_mines(row, column)

        if self.__cell_state(row, column)[0] == 9:
            raise MinefieldException(f"Game over, there is a mine on ({row},{column})")
        self.__reveal(row, column)


```

4. why a list of lists and not a matrix? list of lists = matrix in python? in the context of creating the field for a minesweeper game

```
class Minefield:
    def __init__(self, rows: int, columns: int, mines: int):
        self.__rows = rows
        self.__columns = columns
        self.__mines = mines

        # We did not lay the mines
        self.__mines_laid = False

        self.__data = [[0 for i in range(columns)] for j in range(rows)] # for each element in the column creates a row or for each element in the row creates a column?

```

5. what's the point of an iterator (ex: repository iterator below) ? traverses a data structure? meaning a dictionary/list/matrix/list of lists? couldn't we do that using a for loop with the help of getters/setters/property?

```
class RepositoryIterator:  
    def __init__(self, elements):  
        self._elements = list(elements)  
        self._pos = -1  
  
    def __next__(self):  
        self._pos += 1  
        if self._pos >= len(self._elements):  
            raise StopIteration()  
        return self._elements[self._pos]

```

6. what's the point of an abstract text file repo? when to load/save file?

```
from lecture.livecoding.bakery.domain.bakery_object import BakeryObject
from lecture.livecoding.bakery.repo.memory_repo import MemoryRepository


class AbstractTextFileRepo(MemoryRepository):
    """
    This is an abstract class (abstract = it cannot/should not be instantiated)
    Its job is to figure out when save_file and load_file must be called
    Derived classes should implement those methods for storing BakeyObject instances
    """

    def __init__(self, file_name: str):
        super().__init__()
        self._file_name = file_name
        self._load_file()

    def store(self, element: BakeryObject):
        super().store(element)
        # self._save_file()

    def remove(self, element: BakeryObject):
        super().remove(element)
        # self._save_file()

    def _load_file(self):
        raise NotImplementedError("Must be implemented in subclasses")

    def _save_file(self):
        raise NotImplementedError("Must be implemented in subclasses")

```

7. what's the point of a DTO (data transfer object) and how does it work, when to use? i don't see the difference at least in terms of structure?

this is a dto class:

```
class GradeDTO:

    def __init__(self,id_grade,id_student,id_subject,value):
        self.__id_grade = id_grade
        self.__id_student = id_student
        self.__id_subject = id_subject
        self.__value = value

    @property
    def id_grade(self):
        return self.__id_grade
    @property
    def id_student(self):
        return self.__id_student
    @property
    def id_subject(self):
        return self.__id_subject
    @property
    def value(self):
        return self.__value

```

this is a normal class:
```
class Student:

    def __init__(self, id_student, name):
        self.__id_student = id_student
        self.__name = name

    @property
    def id_student(self):
        return self.__id_student
    @property
    def name(self):
        return self.__name
    @name.setter
    def name(self, value):
        self.__name = value

    def __str__(self):
        return f'{self.id_student},{self.name}'

```


OOP questions

Layered Architecture questions
1. structure of a program. is there a template/structure for layered architecture code with repo, service, ui, start, tests. clarify the structure. clear in general, but if i have binaryrepo, textrepo etc it gets complicated. ce structure imi recomanzi? main - ul ar trebui sa fie intr-un package separat de "start" sau on its own? pentru undo ar trebui sa am un package separat sau sa bag undo_service in package-ul services? si restul modulelor pentru commands? should the ui and start (with main) be separated from each other in different packages?

![[Pasted image 20251221120507.png]]
![[Pasted image 20251221120550.png]]
![[Pasted image 20251221120617.png]]
![[Pasted image 20251221120653.png]]
![[Pasted image 20251221120710.png]]
![[Pasted image 20251221120824.png]]
![[Pasted image 20251221120848.png]]

![[Pasted image 20251221121027.png]]
![[Pasted image 20251221121050.png]]

![[Pasted image 20251221121119.png]]

![[Pasted image 20251221121140.png]]

![[Pasted image 20251221121205.png]]

2. when to have a validator class? the teacher in the seminar insisted on having a validator class, but in the example given by him the validator class does nothing, it is just passed to the service as an attribute

grades_service.py:

```
class GradesService:

    def __init__(self,students_repo,subjects_repo,grades_repo,grade_validator):
        self.__students_repo = students_repo
        self.__subject_repo = subjects_repo
        self.__grades_repo = grades_repo
        self.__grade_validator = grade_validator
	...

```

grade_validator.py:

```
class GradeValidator:

    def validate(self, grade):
        pass
```

3. UML diagram understood? https://github.com/cs-ubbcluj-ro/FP/blob/main/src/lecture/livecoding/bakery/Bakery_uml_class_diagram.png
4. difference between memento design pattern and command design pattern for undo/redo is that memento uses lists to store previous states and command uses parameters to retain information? concrete example?
5. how does command design pattern work

Minesweeper questions:

**2. polymorphism =  treat objects of different types as instances of the same base type (I don't understand the definition and I can't associate it with an example) overriding is a polymorphism**


KeyboardInterrupt inside/outside loops:
OUTSIDE LOOP: YOU CAN PRINT

```
def run(self):  
    try:  
        self._service.place_computer_planes()  
        self._ui_place_user_planes()  
        self._game_loop()  
    except KeyboardInterrupt:  
        print("Program interrupted by the user")
```


INSIDE LOOP: YOU CANNOT PRINT - JUST raise

```
def _ui_place_user_planes(self):  
    print("Place your planes on the board giving HEAD and TAIL coordinates (ex: A3 D3):")  
    for i in range (1,4): #plane1, plane2, plane3  
        while True:  
            try:  
                coordinates = input(f"Plane {i}:").strip()  
                if not coordinates:  
                    raise ValueError("You must enter two coordinates")  
                parts = coordinates.split()  
                if len(parts) != 2:  
                    raise ValueError("You must enter two coordinates")  
                head = parts[0]  
                tail = parts[1]  
                if not self._validation.validate_coordinates(head) or not self._validation.validate_coordinates(tail):  
                    raise ValueError("Invalid coordinates format (A1-J10)")  
                # UI sends raw strings to service (head=A3, tail = D3)  
                self._service.place_user_planes(head, tail)  
                self._print_user_board()  
                break  
            except ValueError as e:  
                print("Error: ", e)  
            except KeyboardInterrupt:  
                raise
```

### HOW TO UNDO/REDO Command Design pattern

PROGRAM STRUCTURE:
domain/
repository/
service/
	-> undo_service.py
	-> students_service.py
ui/

service/undo_service.py:
```
class FunctionCall:
	def __init__(self, function, *params)
		self._function = function
		self._params = params
		
	def call(self):
		self._function(*self._params)

class Operation:
	def __init__(self, undo_call: FunctionCall, redo_call: FunctionCall)
		self._undo = undo_call
		self._redo = redo_call
	
	def undo(self):
		self._undo.call()
	
	def redo(self):
		self._redo.call()

class CascadedOperation:
	def __init__(self):
		self._operations = []
	
	def add(self, operation: Operation):
		self._operations.append(operation)
	
	def undo(self):
		for op in reversed(self._operations):
			op.undo()
	
	def redo(self):
		for op in self._operations:
			op.redo()

class UndoService:
	def __init__(self):
		self._undo_stack = []
		self._redo_stack = []
	
	def record(self, operation):
		self._undo_stack.append(operation)
		self._redo_stack.clear()
	
	def undo(self):
		if not self._undo_stack:
			raise Exception("Nothing to undo")
		op = self._undo_stack.pop()
		op.undo()
		self._redo_stack.append(op)
		
	def redo(self):
		if not self._redo_stack:
			raise Exception("Nothing to redo")
		op = self._redo_stack.pop()
		op.redo()
		self._undo_stack.append(op)
		
```

service/students_service.py:
```
class StudentsService:
	def __init__(self, repo, undo_service):
		self._repo = repo
		self._undo_service = undo_service
	
	def add_student(self, student):
		redo = FunctionCall(self._repo.add, student)
		undo = FunctionCall(self._repo.remove, student.id)
		
		redo()
		self._undo_service.record(Operation(undo, redo))
	
	def remove_student(self, student_id) # cascaded removal
		cascade = CascadedOperation()
		student = self._repo.find(student_id)
		
		undo_student = FunctionCall(self._repo.add, student)
		redo_student = FunctionCall(self._repo.remove, student_id)
		
		cascade.add(Operation(undo_student, redo_student))
		
		grades = self._grades_repo.find_by_student(student_id)
		for grade in grades:
			undo_grade = FunctionCall(self._grades_repo.add, grade)
			redo_grade = FunctionCall(self._grades_repo.remove, grade.id)
			cascade.add(Operation(undo_grade, redo_grade))
		
		redo_student.call()
		for grade in grades:
			self._grades_repo.remove(grade.id)
		self._undo_service.record(cascade)
		
```

ui/
```
def undo(self):
	self._undo_service.undo()
def redo(self):
	self._undo_service.redo()
```

### HOW TO work with text files:

WRITE TO FILE:
```
def write_text_file(file_name, persons):
    f = open(file_name, "w")
    try:
        for p in persons:
            person_str = str(p.id) + ";" + p.family_name + ";" + p.given_name + "\n"
            f.write(person_str)
        f.close()
    except Exception as e:
        print("An error occurred -" + str(e))


def __write_students_to_file(self):
        with open(self.__file_name, "w") as f:
            for student in self._data.values():
                line = f"{student.id},{student.name},{student.group}\n"
                f.write(line)

```

READ FROM FILE:
```
def read_text_file(file_name):
    result = []
    try:
        f = open(file_name, "r")
        line = f.readline().strip()
        while len(line) > 0:
            line = line.split(";")
            result.append(Person(int(line[0]), line[1], line[2]))
            line = f.readline().strip()
        f.close()
    except IOError as e:
        """
            Here we 'log' the error, and throw it to the outer layers 
        """
        print("An error occured - " + str(e))
        raise e

    return result

def __read_students_from_file(self):
        with open(self.__file_name, "r") as f:
            self._data.clear() # clear the dictionary each time
            for line in f:
                line = line.strip()
                if line != "":
                    raw_parts = line.split(",")
                    parts = []
                    for p in raw_parts:
                        parts.append(p.strip())
                    student_id = int(parts[0])
                    name = parts[1]
                    group = int(parts[2])
                    student = Student(student_id, name, group)
                    self._data[student_id] = student # adds it 
```

### HOW TO work with binary files (pickle)

WRITE TO FILE:
```
def write_binary_file(file_name, persons):
    f = open(file_name, "wb")
    pickle.dump(persons, f)
    f.close()

def __write_students_to_file(self):
    with open(self.__file_name, "wb") as f:
        pickle.dump(self._data, f)
```

READ FROM FILE:
```
def read_binary_file(file_name):
    try:
        f = open(file_name, "rb")
        return pickle.load(f)
    except EOFError:
        """
            This is raised if input file is empty
        """
        return []
    except IOError as e:
        """
            Here we 'log' the error, and throw it to the outer layers 
        """
        print("An error occured - " + str(e))
        raise e
        
def __read_students_from_file(self):
    try:
        with open(self.__file_name, "rb") as f:
            self._data = pickle.load(f)
    except (FileNotFoundError, EOFError):
        self._data = {}
```

### HOW TO work with texttable

```
def build_table():
	table = Texttable()
	table.add_row(["Case", "Result"])
	table.add_row([value, result])
	return table

if __name__ == "__main__":
	print(build_table().draw())
```

### HOW TO work with json

### Seminar 8 Jan - Hints for the practical exam

- implement the domain entities
- look at the first graded functionality (repo -> service -> UI)
- 

Abstract Text File Repo 
- extends MemoryRepository
- adds WHEN is the file loaded
- adds When is the file saved
- does not know how the file looks like

Ingredient Text File Repo, Product Text File Repo, Recipe Text File Repo
- each of these repos knows the format of the file
- 

### FP WRITTEN EXAM PREP

##### 1. Python elements
INSTRUCTIONS:
	=
	==
	IF
	WHILE
	FOR
PREDEFINED DATA TYPES:
	INTEGER
	REAL
	STRING
	LIST
	DICTIONARY
	TUPLE
	
FUNCTIONS:
	DEFINING
	PARAMETER TRANSMISSION
	SPECIFICATION
EXCEPTIONS:
	DEFINING EXCEPTION TYPES
	RAISING
	CATCHING
LAMBDA EXPRESSIONS:

##### 2. Algorithms
- "Implement and test the function having the following specification"
1.
![[Pasted image 20260118173333.png]]




- "Specify and test the following function"
![[Pasted image 20260118173352.png]]
![[Pasted image 20260118172114.png]]
![[Pasted image 20260118173222.png]]

- "Implement and specify the function it tests"
![[Pasted image 20260118172909.png]]

![[Pasted image 20260118173103.png]]

![[Pasted image 20260118173305.png]]
- "Given the following code fragment what is the result of the execution?"

![[Pasted image 20260118172002.png]]
a
aba
ababa

![[Pasted image 20260118172215.png]]
1
3
[2,3]

![[Pasted image 20260118172308.png]]
id(y) == id(z) -> same object in memory?
z[0:2] -> first 2 elements of z
list [1] != integer 1 

output:
False
False
True


![[Pasted image 20260118172346.png]]
Y
Y
X
Y
Y
X

![[Pasted image 20260118172651.png]]
f f f0


![[Pasted image 20260118172707.png]]
BC = O(1)
AC = O(n^2)
WC = O(n^2)
Extra space = O(n^2)

![[Pasted image 20260118173017.png]]
True
False
True
True

![[Pasted image 20260118173205.png]]
8 [1,2,3] [1,2,3]

1. Recursion
2. Complexities

- "Analyse the time complexity of the following function"
![[Pasted image 20260118172439.png]]
T(n) = n^3 * log n
BC=AC=WC=O(n^3 * log n)
extra space: O(1)

![[Pasted image 20260118172517.png]]
BC=O(1) when n<=1
reccurence: T(n) = T(n/2)+n
AC=WC = O(n)
extra space: O(log n)
	data -> data +=[n] is executed once/call , we have log n elements for each call => log n executions of that modification of data
	recursion stack -> log n calls = log n levels = log n recursive calls = the number of times i can split a list in half

![[Pasted image 20260118172539.png]]
BC=AC=WC=O(2^n)
Recc=T(n)=2*T(n-1)+1
Time complexity: O(2^n)
Extra space: O(1) without the stack space, O(n) with the stack space


![[Pasted image 20260118172825.png]]
BC=O(1)
AC=WC=O(n^2)
Extra space=O(n^2)
	- recursive stack O(n)
	- slicing O(n^2)

![[Pasted image 20260118173041.png]]
BC=AC=WC=O(n^2 * log n)
extra space = O(1)


![[Pasted image 20260118173240.png]]

1. Searching
2. Sorting
3. Problem Solving Methods

DIVIDE AND CONQUER
- Implement and test a recursive function that determines the number of even elements found on odd positions in a list of natural numbers. Use a divide and conquer implementation that divides the list into halves. 
V1 - The easiest one, using list slicing (data[0:m])
V2 - Replace list slicing with the use of indices
V3 - Replace the recursive implementation with an iterative one. (simulate the stack using a list or queue)

- - Calculate the r-th root of a given number x with a given precision p
        - Recursive Python 3 function using divide and conquer that returns the number of even numbers placed on odd positions
        in a list of natural numbers .
        Return None in case there is no such number
            V1 - using Python list slicing, divide the list into halves [time + extra space complexity]
            V2 - using indices, no list slicing [time + extra space complexity]
            V3 - eliminate recursion [time + extra space complexity]

DYNAMIC PROGRAMMING
-  A stair can be climbed by going up 1, 2 or 3 steps at once. Determine in how many ways we can go up a staircase of 10 stairs.
1 stair = 1 way
2 stairs = 2 ways (1+1, 2)
3 stairs = 4 ways (1+1+1, 1+2, 2+1, 3)
V1 - naive implementation
V2 - dynamic programming

- Coin Change Problem
    V1 - Find the fewest number of coins needed to make a specific total

    V2 - Find the total number of ways to make a specific total

    say we have coins 1, 3 and 4
    the total sum is 8
    => take a look at the Excel file in the same folder as this source

- A stair can be climbed by going up 1, 2 or 3 steps at once. Determine in how many ways we can go up a staircase
        of "n" stairs
        
-  Coin Change Problem
            V1 - Find the fewest number of coins needed to make a specific total (Greedy + DP)
            V2 - Find the total number of ways to make a specific total (naive + DP)
            
- Given an array of integers, calculate the longest decreasing subsequence of primes contained in it

BACKTRACKING
- A Latin square is an n × n square filled with n different symbols, each occurring exactly once in each row and
    exactly once in each column. Generate all the N x N Latin squares for a given number N.
-  Variant: generate all the "reduced" Latin squares (these are squares where the letters in the first row and column are ordered).

5. Procedural Programming (test 1 lab)
6. Modular Programming
7. Unit Tests
8. Exceptions
9. Classes, objects
10. Design Patterns
11. UML Diagrams
12. TextFiles, BinaryFiles
13. Layered architecture
14. Inheritance
15. Testing (lec11)