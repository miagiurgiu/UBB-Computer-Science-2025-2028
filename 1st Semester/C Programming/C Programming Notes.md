Claude Shannon - AI founder
Denis Ritchie contemporan cu Steve Jobs - destine paralele, baietul din umbra
Richard Stallman
Margaret Hamilton
Rares Boian
Tiberiu Popovici
Cenaclul de mate-info, sambata ora 14:00, sala 439, starting from 11 oct
Clubul de numerica
Apollo GitHub 11
Great coding = Single Responsibility Principle

Asamblor vs Compilator
Asamblor - premergatorul compilatorului, con: a single ASM file
UNIX
THE WIRE movie HBO
GCC GNU C compiler
main - doar fisierul text - cu x
main.c - executabil - fara x


```
#include <assert.h>

int e_prim(int x);

/*

Functie care verifica daca numarul intreg x este prim sau nu

Input: x - numar intreg

Output: rez - true daca x nu are divizori decat pe 1 si pe el

- false altfel

*/

  

void test_e_prim()

{

assert(e_prim(-7)==0);

assert(e_prim(0)==0);

assert(e_prim(1)==0);

assert(e_prim(2)==1);

assert(e_prim(8)==0);

assert(e_prim(3)==1);

assert(e_prim(27)==1);

assert(e_prim(25)==0);

//asertiune logica evaluata doar la adv si fals

}

  

int e_prim(int x)

{

if(x<2)

return 0;

if(x==2)

return 1;

if(x%2==0)

return 0;

int d=3;

while(d*d<=x)

{

if(x%d==0)

return 0;

d+=2;

}

return 1;

}

int main()

{

test_e_prim();

}
```

## Seminar 2 (10 oct 2025)

Turing machine
Machine Van ...
Alan Turing
John von Neumann
Divide et Impera
MONOLIT (UNUM) ->D&C -> DIHOTOMA
Tautologie - un set de instante = ?
Exemplu de tautologie esuata: axioma logicii lui Aristotel (axioma dihotomiei)
ETER
ASSUME
Socrate - singurul intangibil in axiomele sale
Aristotel - logica - multimi, boolean, axioma dihotomiei
Boole
in c there is no bool

the world: half tech, half philosophy

BOOKS & MOVIES:
"The C programming Language"
"The art of computer programming"
"The sting"
"La vita e bella"
"The last dance"

cel mai mic tip intreg: 1 char = 1 byte (int pe 8 biti)
codul ascii = functie bijectiva

A (1 CHAR=1BYTE) -> ENCODE through f -> B
B -> DECODE through f^-1 -> A

{S0, S1} Occam's razor
{0,1} bit

(A, +, *)
0 - origine
1 - unitate identitate
"define an algebra" CURS CRIVEI

acel set care contine elementul netru al operatiei de adunare, respectiv de inmultire
the only thing you have to be uptill 23 is yourself
porti logica - full in ALU?

CUM definim algebric un octet?
un produs cartezian (comeniul de definitie a 2 biti)
{0,1}x{0,1}={(0,0), (0,1), (1,0), (1,1)}

(0,0), (1,1) =
(0,1) <
(1,0) >
(0,0), (0,1) <=
(1,0), (1,1) >=

this is in 2d:

