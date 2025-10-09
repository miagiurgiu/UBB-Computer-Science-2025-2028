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

Operatii cu numere mici (< 256)? 
db - byte - 1 byte

Numere mai mari?
dw - word - 2 bytes
dd - double word - 4 bytes


ca sa imi dau seama de ce tip de declarare am nevoie trebuie de fiecare data sa calculez numerele in baza 2 si sa vad cat spatiu ocupa?

lucrezi cu al/bl? pe 8 biti
lucrezi cu ax/bx? pe 16 biti
lucrezi cu eax/ebx? pe 32 biti

