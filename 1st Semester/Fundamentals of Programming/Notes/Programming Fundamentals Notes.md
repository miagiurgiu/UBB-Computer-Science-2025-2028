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
-

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
2. OBJECT - instance of a class
	- Mia is an object:
		- with properties (name Mia, age 19)
		- with behaviours (walking, talking, breathing)
	- Magda is an object:
		- with properties (name Magda, age 52)
		- with behaviours (walking, running, eating)
3. CONSTRUCTOR (_____init_____) - sets fields of the object
4. ENCAPSULATION - ' _ ' or ' _  _ '
5. INHERITANCE - pass another class as a parameter
6. INSTANCE
	- an object that is built from a class and 

```
_data -> internal, cannot be used directly from exterior (there is no "private" in python, so kinda private)
__data -> name-mangling, can be used only inside the class

```

THE 4 KEY CONCEPTS OF OOP IN PYTHON:
- encapsulation
	- bundle attributes and behaviours in a class
- inheritance (class inheritance)
	- a class can inherit attributes and methods from another class (parent class)
	- hierarchical relationships between classes
	- a subclass can inherit attributes and methods from a parent class
	- this reduces duplicate code
- abstraction
	- hide implementation details
	- expose only the essential functionality of an object
- polymorphism ?
	- trat objects of different types as instances of the same base type 

How to create a class:

```
class Employee:
	def __init__ (self, name, age): # declare which attributes each instance of the class should have
		self.name = name
		self.age = age

```
How to create an object:
- by instatiating a class -> calling the class name followed by parentheses

```
book = Book("1", "Mircea Cartarescu", "Solenoid")

```



How to call a method from the parent class:
- by using super() -> extends/modifies inherited behaviour


## Lab 9
test Modular + Procedural programming

## Seminar 9

## Lecture 10

## Lab 10

## Seminar 10
