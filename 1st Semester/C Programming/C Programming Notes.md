
---

## 1️⃣ Fundamente istorice și filosofice

**„The world: half tech, half philosophy.”**

### Figuri importante

- **Claude Shannon** – părintele teoriei informației → fără el nu exista noțiunea de _bit_ (0/1).
    
- **Alan Turing** – mașina Turing = model teoretic al unui calculator; conceptul de algoritm formal.
    
- **John von Neumann** – arhitectura clasică a calculatoarelor (CPU, memorie, I/O).
    
- **Dennis Ritchie** – creatorul limbajului C; a lucrat la UNIX împreună cu Thompson; contemporan cu Jobs → „băiatul din umbră” care a pus bazele lumii digitale.
    
- **Richard Stallman** – inițiatorul GNU și al mișcării _open source_; de aici vine și GCC (GNU C Compiler).
    
- **Margaret Hamilton** – a condus echipa care a scris codul pentru misiunea Apollo.
    
- (Rares Boian, Tiberiu Popovici – profii voștri, de obicei fac legătura între partea teoretică și filozofică.)
    

💬 _De aici ideea că informatica nu e doar despre cod, ci despre gândirea logică, formală, structurat-divizată („Divide et Impera”)._

---

## 2️⃣ De la logică la C

### Logica și filosofia calculului

- **Socrate** → căutarea adevărului prin întrebări.
    
- **Aristotel** → logica, silogisme, axioma dihotomiei (fie A, fie non-A).
    
- **Boole** → algebra logicii → {0,1}, AND/OR/NOT.
    
- **Turing** → a formalizat ideea de _execuție algoritmică_.
    

🧩 **Adevărurile logice = bazele instrucțiunilor dintr-un program.**

- Un program e o succesiune de propoziții logice ce se pot evalua în adevărat/fals.
    
- „Divide et Impera” = împărțirea problemei mari în bucăți mai mici → exact ce face și compilatorul sau un procesor.
    

---

## 3️⃣ Arhitectura sistemului de calcul (ASC)

### Structura generală

🖥 **SYSTEM = CPU + MEMORY + I/O**

- **CPU**: creierul, execută instrucțiuni (MOV, ADD etc.)
    
- **MEMORY**: RAM (temporar) + Storage (permanent)
    
- **I/O**: periferice, canale de comunicare cu exteriorul
    

### Registre importante (în ASM / ASC)

- **AX** – registru general, adesea pentru calcule
    
    - **AH** (high byte) și **AL** (low byte) sunt cele două jumătăți ale lui AX
        
- **BX** – registru de bază (adrese, pointeri)
    
- **CX** – contor (de exemplu în bucle)
    
- **DX** – folosit în operații de I/O
    

🧠 _ALU (Arithmetic Logic Unit)_ = componenta din CPU care face operațiile efective (sume, comparații, logică).

💡 Ce legătură are cu C?  
→ C-ul e doar un nivel de abstractizare peste aceste operații.  
Când scrii `a = b + c;`, compilatorul generează ceva gen:

`MOV AX, [b] ADD AX, [c] MOV [a], AX`

Deci fiecare instrucțiune C se traduce în mai multe instrucțiuni ASM.

---

## 4️⃣ Asamblor vs. Compilator

|Concept|Rol|Avantaje|Dezavantaje|
|---|---|---|---|
|**Asamblor**|Traduce cod ASM în cod mașină|Control total asupra CPU|Un fișier monolitic, greu de întreținut|
|**Compilator**|Traduce cod C în cod mașină (prin ASM intermediar)|Portabilitate, abstractizare|Mai puțin control direct|

💬 „Asamblorul e premergătorul compilatorului.”  
În practică, compilatorul C (ex: **GCC**) generează cod ASM, apoi îl asamblează automat.

---

## 5️⃣ UNIX, C și filosofia minimalismului

- C a fost creat odată cu sistemul **UNIX** → ideea: _„Do one thing, and do it well.”_
    
- „Great coding = Single Responsibility Principle”  
    → fiecare funcție, modul, componentă să facă **o singură chestie clară.**
    

---

## 6️⃣ Introducere practică în C

### Fișiere și compilare

- **`main.c`** → fișierul sursă (text, cu codul tău).
    
- **`main` (fără .c)** → fișierul executabil (binare).
    
- Procesul de compilare:
    
    1. Preprocesare (`#include`, `#define`)
        
    2. Compilare în cod ASM
        
    3. Asamblare
        
    4. Linking (se leagă funcțiile externe, cum e `printf`, `exit` etc.)
        

---

### Tipuri de date și dimensiuni

- `char` = 1 byte (8 biți) → cel mai mic tip întreg
    
- `int` = 4 bytes (pe majoritatea arhitecturilor)
    
- `float` = 4 bytes, `double` = 8 bytes
    

💡 Codul ASCII e o funcție bijectivă între caractere și numere (0–127).  
→ `A` ↔ 65, `B` ↔ 66 etc.

---

## 7️⃣ Exercițiu exemplu: verificarea numerelor prime

```

#include <assert.h>  
int e_prim(int x) 
{     
	if (x < 2) return 0; 
	if (x == 2) return 1;     
	if (x % 2 == 0) return 0;     
	for (int d = 3; d * d <= x; d += 2)         
		if (x % d == 0) return 0;     
			return 1; 
}  
void test_e_prim() 
{     
	assert(e_prim(-7) == 0);     
	assert(e_prim(2) == 1);     
	assert(e_prim(25) == 0);     
	assert(e_prim(3) == 1); }  
	int main() 
	{     
		test_e_prim(); 
		
	}
```

🧩 `assert()` = test logic → verifică automat că rezultatele sunt corecte.  
Dacă ceva pică, programul se oprește → debugging mai ușor.

---

## 8️⃣ De la matematică la informatică

- „Define an algebra” (Crivei):  
    Un sistem algebric e un set + două operații (ex: {0,1}, +, *).  
    Așa se definesc și porturile logice dintr-un CPU.
    
- `{0,1} × {0,1}` = toate combinațiile de biți posibile → baza logicii binare.
    

💡 „CUM definim algebric un octet?”  
→ Ca un produs cartezian de 8 ori: `{0,1}⁸`.  
Asta e tot spațiul de stări posibile pentru un byte (256 combinații).

---

## 9️⃣ Recomandări de cultură generală (din curs)

🎬 Filme & Cărți:

- _The C Programming Language_ – Ritchie & Kernighan
    
- _The Art of Computer Programming_ – Knuth
    
- _A Beautiful Mind_ – despre gândirea logică, formală
    
- _La Vita e Bella_, _The Last Dance_, _The Sting_ – pentru filosofia „umană” a tehnologiei
    

---

## 🔟 Alte informații utile

- **Cenaclul de mate-info** – sâmbăta, 14:00, sala 439
    
- **Clubul de numerică**, **Apollo GitHub 11** – probabil proiecte practice
    
- **„Caught segmentation fault”** – erori de memorie în C (ai accesat o zonă nepermisă)
    

---

24.10.2025 Lecture Flow

1. Ce sunt RAM-ii?
unitatea de masura a memoriei: BYTE, nu bit. fiecare byte are un index. acel index e defapt adresa. adresa e un numar. adresa e relativa la cati octeti sunt inaintea mea in memorie. aici intervine notiunea de variabila. unde? cati octeti ocup? astea sunt defapt puteri ale lui 2: char: 2^0 bytes, short int 2^1 bytes, int 2^2 bytes, long(long) 2^3 bytes, float is 32 bits, and double in 64 bits. how much is void though?aici intervine notiunea de pointer. un pointer e o zona de memorie care contine in interiorul ei o variabila care e interpretata la alta adresa de memorie. which is basically a loop? idk, answer this. void e un pointer la orice. nu ne pasa deloc ce e acolo. e o alta variabila de tipul pointer? numarul acela e labelul asignat unei adrese.un pointer nu este, ci ARE o adresa, deci are in el un numar care e defapt o adresa.variabila poate fi reprezentata cu little endian sau big endian. datatype - abstract datatype dar asta vom discuta mai incolo. care a fost the first OS? UNIX, fondat de compania AT&T. fondatorii limbajului c: Denis Richie si Ken Thomson. tips: facem o variabila locala, nu globala, dam denumiri dugestive, la printf mereu incheiem cu \n sau \0, altfel nu da flash. ce inseamna flash? answer this. intrebare: int*, char*, void*, a* ce dimensiuni au? au aceeasi dimensiune care depinde de procesor. gen o adresa are forma asta daca e x32 procesorul 0x23555i89? si 0x123456789jghgh4d daca e x64 procesorul? fiecare cifra hexa e 4 cifre nu? sau 0x sau adresa de memorie are aceeasi dimensiune? sau dimmensiunea adresei? clarify this. tips: intotdeauna initializam variabilele. int*val=&nr . prin asta lui nr ii luam adresa de unde se afla in memorie.

```
int main()
{
	int numar = 247777216;
	// tipul de data = pointer la void
	void* pointer_la_numar = &numar // asta retine defapt adresa, in hexa
	// alegem pointer la char pt ca un char = 2^0 = 1 si ne permite sa vedem adresa fiecarui ?byte? bit? numar? idk, clarify this
	char* pointer_la_octetul_0 = &numar	
	char* pointer_la_octetul_1 = char* pointer_la_octetul_0 + 1
	// atentie, e +1, nu ++. daca faceam ++ atunci la adresa se adunau cati biti are un int, adica 4 si crestea valoarea, dar scopul nostru e sa vedem bitii? byte-ii? adresele fiecarui byte? deci facem adresa + 1 ca sa creasca valoarea; primeam code segmentation error daca faceam ++ pt ca atunci se trecea la o zona de memorie "interzisa" din ram, gen "groapa marianelor" , si acea zona interzisa e practic sistemuld e operare i guess?
	char* pointer_la_octetul_2 = char* pointer_la_octetul_1 + 1
	char* pointer_la_octetul_3 = char* pointer_la_octetul_2 + 1
	printf("%p\n", *pointer_la_numar);//arata unde e 247777216 in adresa
	printf(format: "%p\n", &numar)
	// experimentam:
	*(pointer_la_octetul_1)++
	*(pointer_la_octetul_3)--
	return 0;
}
```

*void - inseamna orice, ia oricat.
*nr e diferit de int * pentru ca inseamna dereferentiere. ce e dereferentierea unui pointer? vede adresa -> ia de acolo 4 octeti (ca int ul are 2^2 bytes) -> interpreteaza. cum? explicit: mergi la adresa - cat e tipul pointerului?

```
int nr=7
int *pointer_la_nr = &nr
// & pt ca altfel ar baga valoarea in memorie
// & pt ca altfel ar fi segmentation error
// int* se schimba efectiv tipul de data
char* pointer_la_octetul_0 = &nr
char* pointer_la_octetul_1 = pointer_la_octetul_0 + 1
// -16776953 idk what is this supposed to mean? 7 in hexa? the adress? in binay this number is 11111111.... complete with the rest - i think it should be 11111111 00000000 00000000 00000111 -  calculul with 7 + 2^16+... complete with the rest based on the context
// ne ducem in int care e little endian, aveam initial 7 0 0 0, unde 0 de la dr la stanga e octet 3 sau octet 0? octetul 2 e ..., octetul 1 e ... octetul 0 e... -> acest 7 0 0 0 e pointer la char - dereferentiem => char* pointer la octetul 1 
```

operatii cu pointeri:
"++": adresa + cati octeti are tipul ala de data => creste valoarea, nu adresa
"+1": adresa + 1 => creste adresa, nu valoarea

pointer la int - iei 4 octeti - convert la ceva mai mic? la ce? la char?
pointer la char - iei un octet 
dupa cum am spus mai devreme, pointer la int si pointer la char ocupa la fel de mult

=> little endian (cam toate acum)

int