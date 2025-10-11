
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
