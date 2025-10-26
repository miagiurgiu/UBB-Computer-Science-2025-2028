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

Lecture 2 handwritten notes:

## Lab 2
verify each input because it is not allowed to crash
E,E,Shell
Assignment 2 started

## Lecture 3
complexity, recursion, Hanoi

## Lab 3
adc, cwb ...

## Assignment 3

## Python Q & A

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

## Lab 4
**Assignment 45**

ex 14 - backtracking
14. Generate all numbers of `n` digits with the property that no number has two identical neighboring subsequences. For example, for `n=6`, `121312` is correct, and `121313` and `132132` are not correct.
ex 4 - dinamic programming   
4.Given an `n * n` square matrix with integer values, find the maximum length of a snake sequence. A snake sequence begins on the matrix's top row (coordinate `(0, i), 0 <= i < n`). Each element of the sequence, except the first one, must have a value `±1` from the previous one and be located directly below, or directly to the right of the previous element. For example, element `(i, j)` can be succeded by one of the `(i, j + 1)` or `(i + 1, j)` elements. Display the length as well as the sequence of coordinates for one sequence of maximum length.


## BACKTRACKING RECALL

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

EXAMPLE:

## Seminar 4 

## 