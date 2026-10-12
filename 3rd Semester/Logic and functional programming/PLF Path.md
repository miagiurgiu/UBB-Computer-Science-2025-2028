
## Seminar 1
## Lab 1

problem 1

R1 
- recursive math model
- implementation (python/c++)

![[Pasted image 20261011103305.png]]


![[Pasted image 20261011103356.png]]

### HOW TO run SWIPL locally

METHOD 1 (Visual Studio Code as text editor)
- visual studio code -> new file (not text file!) -> save as -> .pl
- swipl-win -> consult('path').
- write a query
- halt. to close the app

METHOD 2 (directly in console)
- [user].
- write code line by line yourself
- CTRL+D
- save in a separate file ?
- make.

commands:
- listing(rev).
- halt.
- make.
- consult().
- [user].

### R1 & P1 - what I learned
- in a math model, a function returns a value
- in prolog, a predicate returns a boolean
- variables must start with uppercase
- '=:=' compares
- 'is' assigns
- if you use an auxiliary variable in the recursive call, it should be computed before the call
- "in rest face altceva" does not exist in Prolog (for example, if a brach checks b=:=0, the other branch must have b=\=0)
- the order in which you write the predicates does not matter (you can write gcd lower than the function that uses it)
- ; means OR
- , means AND
- 
