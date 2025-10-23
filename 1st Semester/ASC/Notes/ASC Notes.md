## Lab 1
[https://www.cs.ubbcluj.ro/~diana.sotropa/teaching/asc/](https://www.cs.ubbcluj.ro/~diana.sotropa/teaching/asc/ "https://www.cs.ubbcluj.ro/~diana.sotropa/teaching/asc/")

- any base -> base 10
$$

1101101
= 1*2^0 + 0*2^1 + 1*2^2 +1*2^3 +0*2^4 +1*2^5+1*2^6$$
- Base 10 -> base 2
![[obsidianubb/Note references/Pasted image 20250930181920.png]]
- Base 10 -> base 16
![[obsidianubb/Note references/Pasted image 20250930181807.png]]

- Good to know:
![[obsidianubb/Note references/Screenshot 2025-09-30 at 18.20.43 1.png]]
- 1000...0 | -1 => 0111...1
- How do we check if a number x is a power of 2? 
We check if it has just one bit = 1. 
How? We compare x and (x-1) bit by bit. 
Using what? '&' = [[obsidianubb/Note references/bitwise AND]]. 
Any power of 2 looks like 10000...0 in binary.

1=0001 (2^0)
2=0010 (2^1) etc.

1000...0 = x
0111...1 = x-1

```
if(x&(x-1)==0)
```

- Grey code using mirror method
```
0.                 00
1                   01
2                   11
3                   10
```
```
0                    000
1                     001
2                     011
3                     010
4                     110
5                     111
6                     101
7                     100

```

- bit vs byte = 8 bits
- complements vs negatives

the negative number of 89
+89 = 01011001
-89 = 10100110


**1's complement method
01011001 -> the complement: 10100110
but 00000000 = +0 and 11111111 = -0
(0 stands for positive, 1 stands for negative)
con: there are 2 zeroes

**2's complement method
01011001 -> 1's complement : 10100110 + 1 -> 2's complement: 10100111
pro: there is only one zero

or

01011001 -> the complement: 10100111 (from right to left copy it as it is and after you encounter the first 1, put the opposite)

- how is bool represented behind the scenes
bool -> unsigned char (1 byte)
CPU's operate with bytes, not bits
```
bool a = true; // stored as 00000001
bool b = false; //stored as 00000000
```

bitset<n> allows us to work with individual bits
```
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> v; // 8 bits, all initialized to 0
    v[3] = 1;    // set bit #3
    v[2] = 1;    // set bit #2

    cout << v << endl; // prints 00001100 (bit 3 and 2 set)
}

```
## B10 -> B2 -> B16

45 / 2 = 22 rest 1  
22 / 2 = 11 rest 0  
11 / 2 = 5 rest 1  
5 / 2 = 2 rest 1  
2 / 2 = 1 rest 0  
1 / 2 = 0 rest 1

45 = 101101 = 0010 1101 = 2D

$$
0010 = 0 *2^3 + 0*2^2 +1*2^1 + 0*2^0 = 2
$$

$$
1101 = 1*2^3 + 1*2^2 + 0*2^1 + 1* 2^0 = 13 = D

$$
## ==Lab 1 - proposed problems==

1. B10 -> B2 -> B16
4/2=2 r0
2/2=1 r0
1/2=0 r1

4(10)=100(2)=0100(2)=4(16)

$$
0100=0*2^3+1*2^2+0*2^1+0*2^0 = 4
$$
10/2=5 r0
5/2=2 r1
2/2=1 r0
1/2=0 r1

10(10)=1010(2)=A(16)
$$
1010 = 1*2^3+ 0*2^2 + 1*2^1 + 0 *2^0=10=A

$$
15/2=7 r1
7/2=3 r1
3/2=1 r1
1/2=0 r1

15(10)=1111(2)=F(16)
$$
1111=1*2^3+1*2^2+1*2^1 +1*2^0=15=F
$$
32/2=16 r0
16/2=8 r0
8/2=4 r0
4/2=2 r0
2/2=1 r0
1/2=0 r1

32(10)=100000(2)=0010 0000=20(16)
$$
0010=0*2^3 +... +1*2^1+0*2^0 = 2
$$
$$
0000=0

$$
2. B10 -> B16 -> B2

3<16 -> 3(10)=3(16) => 0011(2)

11<16 . 1011(2)
1=0001
1=0001

16=16 => 16(10)=10(16) => 00010000(2)=10000(2)
1=0001
0=0000

17>16 => 17(10)=100001(2) => 00010001(2)=11(16)

3. B2->B16
1010(2)=B(16)
0111(2)=7(16)
1111(2)=F(16)
10001010(2)= 1000 1010 (2)= 8A(16)
110101111(2)= 0001 1010 1111 (2)= 1AF(16)

4. B16->B2
3(16)=0011(2)
A(16)=1010(2)
F(16)=1111(2)
2B(16)=0010 1011 (2)
2F8(16)=0010 1111 1000 (2)

5. operations in B2
1+1 = 10(2)
10+10 = 100(2)
111+1 = 1000(2)
1010-1= 1001(2)
1000-10=110(2)

6. operations in B16

$$
17(16)=1*16^1+7 = 23(10)
$$
9+1=A
B+2=D
F+1=10
10(16)-2(16)=16(10)-2(10)=14(10)=E(16)
B-3=11-3=8


7. complementarity methods

![[obsidianubb/Note references/Pasted image 20250930211635.png]]

2 bytes = 16 bits -> 2^16 - 1 free

(9A7D)16 = 1001 1010 0111 1101
(7583)16 = 0111 0101 1000 0011


(6583)16
(9A7D)16

D + 3 = 13 + 3 = 16(10) = 10(16) -> F, carry 1
7 + 8 + 1 carried = 16(10) = 10(16) -> F, carry 1
A + 5 + 1 carried = 16(10) = 10(16) -> F, carry 1
9 + 7 + 1 carried = 16(10) = 10(16) -> F, carry 1 but we only have 16 bits


![[obsidianubb/Note references/Pasted image 20250930212902.png]]

4 bytes = 32 bits -> 2^32 - 1 free
(000F095D)16 = 000 1111 0 1001 0101 1101
(FFF0F6A3)16 = 1111 1111 1111 0 1111 0110 1010 0011


D + 3 = 10(16) 

D = 1101
5= 0100
9=1001
F=1111
A=1010
0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111


EX 7 ~~not~~ understood

7,8,9 continued:

![[A1 ex7,8,9 1 1.pdf]]

https://github.com/miagiurgiu/UBB-Computer-Science-2025-2028/blob/0b8e5d0fff0cb5b3734c9835a2511bca63c28cc0/1st%20Semester/ASC/A1%20ex7%2C8%2C9.pdf



## Lab 2

```
bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
    ; aici declari variabilele
    a db 5       ; un byte cu valoarea 5
    b dw 123     ; un word cu valoarea 123
    c dd 1000    ; un double word (4 bytes)
    d db ?       ; un byte neinițializat
    x resb 1     ; rezervi 1 byte fără valoare

segment code use32 class=code
start:
    mov eax, [c]    ; încarcă valoarea din variabila c
    add eax, 10     ; adună 10
    mov [c], eax    ; scrie rezultatul înapoi în memorie

    push dword 0
    call [exit]


```

Operatii cu numere mici (mai mici decat 256)? 
db - byte - 1 byte

Numere mai mari?
dw - word - 2 bytes
dd - double word - 4 bytes


ca sa imi dau seama de ce tip de declarare am nevoie trebuie de fiecare data sa calculez numerele in baza 2 si sa vad cat spatiu ocupa?

lucrezi cu al/bl? pe 8 biti
lucrezi cu ax/bx? pe 16 biti
lucrezi cu eax/ebx? pe 32 biti

### 1) Tre’ să declar variabile în `segment data` sau pot lucra direct în `segment code`?

Profesional vorbind, **ambele variante sunt corecte**, depinde ce vrei:

- Dacă doar „testezi” 1+9, 3*4 etc., poți lucra **direct în registre** (fără variabile) și te uiți în registrele AL/AX/EAX în debugger.
    
- Dacă vrei să **păstrezi rezultatele** (sau ai expresii cu a,b,c,d din temă), atunci **declari variabile** în `segment data`, le încarci în registre, calculezi și scrii rezultatul înapoi în memorie (ca să-l poți urmări ușor în Olly).


1+9:
```
segment data use32 class=data
a db 1
b db 9
rez db 0

segment code use32 class=code
start:
mov al, [a]
add al, [b]
mov rez, al
```

### Defining data in memory

These LABELS create space in RAM:
they are used depending on their size

db (1 byte)
dw (2 bytes)
dd (4 bytes)
dq (8 bytes)

```
a db 5 // a has 1 byte
b dw 100 // b has 2 bytes
```

### Defining in processor

These REGISTERS take up space in the CPU
the processor has a fixed set of registers

eax - arithmetic operations
ebx - basic register
ecx - contor
edx - extension for eax (mul, div)
esi - string source
edi - string destination

```
a db 5
...
mov al, [a] // a e db, deci merge cu al
add al, 3
mov [a], al
```

al, bl, cl, dl ~ db (1 byte)
ax, bx, cx, dx ~ dw (2 bytes) -> old
eax, ebx, ecx, edx ~ dd (4 bytes) -> 32-bit program


### Take up space without initialisation
when you want an empty memory zone

resb
resw
resd
resq

```
resb 10 // reserves 10*1 byte = 10 bytes
resd 4 // reserves 4*4 bytes = 16 bytes

```
ax -> ah, al - inferior part of eax
ax - 2 bytes of eax
	ah - superior byte of ax
	al - inferior byte of ax
example: eax = 0x12345678 => ax = 0x5678, ah = 0x56, al=0x78

esp - stack pointer
ebp - base pointer
eip - instruction pointer
eflags - biti de stare

sp = inferior part of esp
xor - the fastest way to put 0 in a register

variables = adresses in memory

little endian (intel): 12345678h -> 78 56 34 12
big endian: -> 12 34 56 78

[a] the value
a the adress

mov eax, [a] takes the value
mov eax, a takes the adress

operands need to have the same size:
mov eax, ebx yep
mov al, bx nope

eax, ebx... - doubleword (32 bit = 4 byte)
eax -> ax -> ah+al

movzx = move with zero-extend = converts an 8-bit value to a 32-bit value (automatically fills with zeroes)

## ASC TEST PREP Questions

1) pentru a sti care dintre db, dw, dd, dq sa folosesc trebuie mereu convertit in b2? sau aplic [-127, 128] pt byte? invat intervalele pt fiecare? 

Nu trebuie mereu convertit in b2, dar trebui stiute intervalele.

db - define byte - 8 bits - [-128, 127] signed - [0,255] unsigned
dw - define word - 16 bits - [-32768, 32767] signed - [0, 65535] unsigned
dd - define doubleword - 32 bits
dq - define quadword - 64 bits

Generalizare: 
db pentru valori mici
dw pt valori medii
dd pt nr mari sau adrese
dq pentru nr foarte mari

2) cand folosesc eax si cand ebx, ecx, edx, esi, edi ?

EAX - acumulator (calcule) - cand faci calcule sau vrei rezultatul unei functii
EBX - base (pointer la date) - cand ai nevoie de un registru auxiliar
ECX - counter (for loops, counting) - cand ai bucle/shift-uri/repetitii
EDX - data (extensie pentru EAX) - cand ai nevoie de extensie de 64 bits (mul/div)
ESI - source index (sursa, stringuri) - copieri, citiri din memorie
EDI - dest index (destinatie, stringuri) - scrieri in memorie
EBP - base pointer (baza stiva) - stack only
ESP - stack pointer (varf stiva) - stack only


3) in ce situatii concrete am nevoie de resb, resw, resd, resq?

Directivele astea rezerva spatiu in memorie, fara a initializa valoarea.

resb n - rezerva n bytes (resb 10 => rezerva 10 bytes => 10*8 = 80 bits)
resw n - rezerva n words
resd n - rezerva n doublewords
resq n - rezerva n quadwords

Generalizare:
- cand vrem variabile care vor fi umplute in timpul executiei

resb n vs n db 0
- dacă ai nevoie de **o valoare inițială → `db/dw/dd/dq`**
    
- dacă ai nevoie de **spațiu pentru date care se vor completa ulterior → `resb/resw/resd/resq`**
n db 0 
- definesc si initializez 
- memoria contine deja 0

resb n
- rezerv spatiu

4) cum operez cu ax, ah, al?

32 bits = EAX = partea HIGH + partea LOW = ceva + AX = ceva + (AH + AL) = 16 + 8 + 8

MOV AL, 5
MOV AH, 2

2 in hexa: 02h -> AL
5 in hexa: 05h -> AH
AX: 0205h

5) ce fac eip, eflags?

EIP 0


6) sp ce face?
7) xor ce face?
8) memorie - variabilele arata catre array-ul de memorie? cum arata in memorie variabilele? sunt una dupa cealalta? cum sunt valorile adaugate in adresa?
9) little endian vs big endian
10) cand adresa, cand valoare
11) mov [a], 5 e bine?
12) subregisters?
13) unsigned vs signed
 Fiecare cifra in hexa = 4 cifre in binar (a DB 12h  - - - - - - - - 1 byte)
 14) de ce as folosi de exemplu dx in loc de bx daca tot 16 biti are?
 15) a, b - daca in operatii se obtin valori negative acelea cum se reprezinta? de exemplu  a - b, unde a, b – byte. sa zicem ca in data segment dau a=1 si b=9. rezultatul va fi negativ. cum urmaresc in ollydbg rezultatul negativ? trebuie sa stiu dinainte ca va fi negativ pentru a face sbb? are legatura sbb cu asta sau nu? valoarea de minus cum e reprezentata in memorie? primul bit de la stanga la dreapta sa fie 1? si daca nu incape valoarea in bitul acela?
 16) daca adun doua doubleword-uri a + b, unde a, b – dword atunci o sa dea ceva mai mare gen quadword? si trebuie rezultatul sa stiu de dinainte ca trebuie sa il declar ca fiind quadword? si daca fac a-b rezultatul ramane doubleword sau poate trece la un rang mai mic daca am zerouri in fata?
 17) (a + b) – (c + 10), unde a, b, c – byte pot lucra pe acelasi registru pentru aceasta operatie sau trebuie pus separat a+b, separat c+10 si la final scazute registrele?
 18) a adresa, [a] valoare. in lucrul cu registrii/ce or fi in ce situatii ne trebuie adresa si nu valoarea? si in ce situatii ne trebuie valoarea si nu adresa?
 19) ![[Pasted image 20251022195218.png]] - pai daca depaseste un octet nu pot lua un resgistru din ala mai mare? de ce ne mai trebuie
20) ![[Pasted image 20251022195430.png]] - unde e cea mai mica adresa si cea mai mare adresa 
21) ![[Pasted image 20251022195628.png]] - cum a facut conversia din 10 in 16\
22) ![[Pasted image 20251022195739.png]] - de ce sunt mai multe valori bagate in acelasi registru
23) ![[Pasted image 20251022195907.png]] - rezervarea de spatiu nu se facea cu resb, resq etc?
24) daca eu vreau sa fac operatii cu a si b si nu stiu daca rezultatul va fi pozitiv sau negativ atunci e mai safe sa fac rezultatul de tip signed? si cum fac asta? trebuie aplicat signed peste toate operatiile, chiar daca unele vor fi unsigned? adica daca de exemplu fac (a+b)+(a-b) e ok daca fac adunarea normala a+b cu "add", dar fac a-b cu "?" pentru ca poate e negativ? dar daca a, b sunt negative din start? atunci fac doar cu "?"
25) ![[Pasted image 20251022200434.png]] - de ce e incorecta logic?
26) fisierul executabil ce este?
27) cand trebuie pus tipul de data (byte, word, dword, qword) inainte de sursa?
28) ![[Pasted image 20251022200713.png]] - de ce a si a+1? se stocheaza a si b unul in continuarea celuilalt? de ce b e inainte de a? pentru ca e little-endian? little-endian e valabil si la adunare? adica baga valoarea pe care o adun inainte la ce era deja acolo?
29) ![[Pasted image 20251022201004.png]] - care-i faza cu b+1?
30) ![[Pasted image 20251022201103.png]] - de ce e corect in al si nu in ax?
31) mul a , daca a e db atunci se inmulteste a la registrul al si rezultatul va fi in ax ? si cum mai exact arata acum ax dupa inmultire? aici trebuie impartite cazurile cu signed si unsigned? mul b, daca b e dw, atunci se inmulteste b la registrul ax si rezultatul va fi in dx: ax. de ce dx:ax si nu bx:ax sau cx:ax? dx e special pentru asta? mul c, daca c e dd, atunci se inmulteste c la registrul eax si rezultatul va fi in edx:eax? o reprezentare concreta, un exemplu?
32) div a, daca a e db atunci se imparte ax la a si catul va fi in al, restul in ah (deci restul inaintea catului in memorie); div b, daca b e dw atunci se imparte dx:ax la b si catul va fi in ax, iar restul in dx; div c, daca c e dd atunci se imparte edx:eax la c si catul va fi in eax, iar restul in edx
33) ca sa folosesc imul si idiv inseamna ca stiu de dinainte ca rezultatul va fi signed?
34) ![[Pasted image 20251022203016.png]] 0180h e doubleword. prin mul ah facem mul de partea high a lui 0180h adica 01h. fiindca 01h e db, se inmulteste la registrul al. si acolo cum are loc conversia aia 128*1=128=0080h?
35) ![[Pasted image 20251022203414.png]] -la imul cum si-a dat seama ca 80h e -128? mai inainte era +128. analog pentru idiv de ce -128?
36) ![[Pasted image 20251022203702.png]] - putem explica asta? incearca sa imparta ax (16 biti) la bl (8 biti) si ar trebui catul sa fie in al si restul in ah. dar pentru ca se imparte exact, restul e 0 si ramane 512 sa il reprezentam pe un singur byte, ceea ce nu e posibil. asta se numeste "division overflow"
37) cum adica nu exista instructiuni de conversie fara semn. din ce in ce ar trebui sa converteasca? in ce consta convertirea? in zeroizare? se tot adauga zerouri pana ajunge la nr de biti corespunzator unui word/doubleword etc?
38) a+b, unde a=10 e byte si b=1122h e word, mutam [a] in al (16 biti), completam cu 0 byte-ul high, apoi adaugam [b] la ax; 
39) din word in doubleword nu merge numai din ax in dx:ax, nu in eax
40) cbw, signed, intotdeauna al -> ax. conversia consta in completarea cu bitul de semn in fata byte-ului initial. aia nu ar veni numai un bit in plus? nu pare a fi suficient pana la a atinge un word.
41) cwd, signed, intotdeauna ax -> dx:ax. conversia consta in completarea cu bitul de semn in fata byte-ului initial. again, nu pare a fi suficient pana la a atinge un word.
42) cwde, signed, ax -> eax. care e diferenta intre asta si cwd?
43) cdq, signed, eax -> edx:eax
44) ![[Pasted image 20251022212254.png]] - 
45) adc, sbb, de unde stiu cand e cu carry si cand nu? asta implica sa fac eu operatia pe foaie de dinainte? 
46) stivele 
47) ![[Pasted image 20251023071333.png]] - de explicat linie cu linie