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
Assignment in git for next time (choose one problem from each set)

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


## Assignment 01 - Introduction

[](https://github.com/cs-ubbcluj-ro/a1-miagiurgiu#computer-assignment-01---introduction
[](https://github.com/cs-ubbcluj-ro/a1-miagiurgiu#problem-statements)

### First Set

[](https://github.com/cs-ubbcluj-ro/a1-miagiurgiu#first-set)

1. ~~Generate the first prime number larger than a given natural number `n`.~~
2. ~~Given natural number `n`, determine the prime numbers `p1` and `p2` such that `n = p1 + p2` (check the Goldbach hypothesis).~~
3. ~~For a given natural number `n` find the minimal natural number `m` formed with the same digits. (e.g. `n=3658, m=3568`).~~
4. For a given natural number `n` find the largest natural number written with the same digits. (e.g. `n=3658, m=8653`).
5. Generate the largest prime number smaller than a given natural number `n`. If such a number does not exist, a message should be displayed.

### Second Set

[](https://github.com/cs-ubbcluj-ro/a1-miagiurgiu#second-set)

6. Determine a calendar date (as year, month, day) starting from two integer numbers representing the year and the day number inside that year (e.g. day number 32 is February 1st). Take into account leap years. Do not use inbuilt date/time functions.
7. ~~Determine the twin prime numbers `p1` and `p2` immediately larger than the given non-null natural number `n`. Two prime numbers `p` and `q` are called twin if `q - p = 2`.~~
8. Find the smallest number `m` from the Fibonacci sequence, defined by `f[0]=f[1]=1`, `f[n]=f[n-1] + f[n-2]`, for `n > 2`, larger than the given natural number `n`. (e.g. `for n = 6, m = 8`).
9. ~~Consider a given natural number `n`. Determine the product `p` of all the proper factors of `n`.~~
10. ~~The palindrome of a number is the number obtained by reversing the order of its digits (e.g. the `palindrome of 237 is 732`). For a given natural number `n`, determine its palindrome.~~
11. The numbers `n1` and `n2` have the property `P` if their writing in base 10 uses the same digits (e.g. `2113 and 323121`). Determine whether two given natural numbers have property `P`.

### Third Set

[](https://github.com/cs-ubbcluj-ro/a1-miagiurgiu#third-set)

12. Determine the age of a person, in number of days. Take into account leap years, as well as the date of birth and current date `(year, month, day)`. Do not use Python's inbuilt date/time functions.
13. ~~Determine the `n-th` element of the sequence `1,2,3,2,5,2,3,7,2,3,2,5,...` obtained from the sequence of natural numbers by replacing composed numbers with their prime divisors, without memorizing the elements of the sequence.~~
14. ~~Determine the `n-th` element of the sequence `1,2,3,2,2,5,2,2,3,3,3,7,2,2,3,3,3,...` obtained from the sequence of natural numbers by replacing composed numbers with their prime divisors, each divisor `d` being written `d` times, without memorizing the elements of the sequence.~~
15. ~~Generate the largest perfect number smaller than a given natural number `n`. If such a number does not exist, a message should be displayed. A number is perfect if it is equal to the sum of its divisors, except itself. (e.g.  `6 is a perfect number, as 6=1+2+3`).~~


## Seminar 1

