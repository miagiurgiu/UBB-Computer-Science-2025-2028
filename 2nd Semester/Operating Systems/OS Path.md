## Lab 1 - 23 feb 2026
Attendance - have your card with you!
https://www.cs.ubbcluj.ro/apps/screenshare/rooms/L338 - screen sharing
https://www.cs.ubbcluj.ro/apps/attendance- attendance 
https://www.cs.ubbcluj.ro/~rares/course/os/ - website
https://www.cs.ubbcluj.ro/~rares/course/os/res/teaching/teaching-notes.pdf - teaching notes

4 tests, min grade 5
tests in Linux terminal
you can use the manual for the c documentation, commands

WINDOWS LINUX SETUP
Microsoft Store -> Ubuntu -> terminals -> username -> password

COMMANDS
clear - clear the screen
pwd - print working directory -  where do you execute the application from 
cd - 
mkdir - make directory
ls
which cd
provide arguments to that command
touch grass
touch - create an empty file
echo $PATH
dolphin?
ls ./ - list the current directory
ls .. - go up
ls ../
man
rm
cp
mv
search in page using / in a man page
press n
whatis printf
ctrl+c, ctrl+s, ctrl+v don't do anything in linux
^ - circumflex accent
^ shift+6
sudo 
gcc test.c -> ls -> 
executable files -> green
you can rename
fallback method -> will "macaroane" be the default folder/fallback for ??? (if the program cannot find or access the requested folder, it uses another predefined folder instead; in this context, the program first tries another folder and if that fails, it will use the folder macaroane instead)

TERMINAL WINDOWS:
C:\Users\PC instead of having C, in Linux we have \ (just a bunch of folders)

"folders in files" is up to the kernel

## Individual work after Lab1

pwd - Print Working Directory = show your current location
cd - Change Directory = go to home directory automatically
cd sth = go to sthcd ~ = cd = go to home directory automatically
ls = list the contents (files, directories) of the current directory
ls -l = long format
ls -a = show all files, including hidden (shows . and .. as well)
ls -la = long format + show hidden files
ls sth = list another folder without entering it
mkdir = make directory
mkdir -p = create parent directories (like a chain) ex: mkdir -p A/B/C
touch filename = create a file named filename
echo = print sth to the terminal
">" = send text into a file (overwrites the file)
">>" = append text to a file (keep existing content)
```
echo "hello" > file1.txt
put the text "hello" inside file1.txt
```
cat = show contents of a file
This is what ls -l does:
```
-rw--r--r-- 1 miagiurgiu miagiurgiu 16 Feb 23 18:57 file1.txt
"-" = file
rw-- = owner (the owner can read, write, not execute)
r-- = group (read, not write, not execute)
r-- = others (read, not write, not execute)
1 = number of hard links 
miagiurgiu = i own the file
16 = file size in bytes
Feb 23 18:57 = last modification time
file1.txt = the file
```
```
drwxr-xr-x 2 miagiurgiu miagiurgiu 4096 Feb 23 19:03 testdir
"d" = directory
rwx = owner (read, write, execute)
r-x = group (read, not write, execute)
r-x = others (read, not write, execute)
```
read (r) = can list files inside
write (w) = can create/delete files inside
execute (x) = can enter the directory (using cd)
cd .. = go one level up (go to parent directory)
ls . = ls
. = current directory
.. = parent directory
~ = home directory
/ = root directory
./ = look here, not in path
./program = run the file named "program" from the current directory
-a = option (flag) = everything including . and ..
-A = everything except . and ..
any file starting with . is hidden
la = ls-A
echo $PATH = see your path
: = separates directories
ls = does not look in the current directory first, it looks in the directories listed in $PATH and it searches for ls inside there -> it finds a file named ls in /usr/bin/ls -> that file is an executable file
executable file = file that contains machine code (compiled program) and has execute permission (x)
cd = bash built-in = the shell program (bash) already contains the code for cd inside itself, it does not need to search $PATH

how to write C code:
```
nano filename.c -> write code -> ctrl+O -> Enter -> ctrl+X -> back in terminal
```
how to compile C code:
```
gcc -Wall -Wextra -Werror -g -o output_file_name hello.c
gcc = compiler program
-Wall = show warnings
-Wextra = more warnings
-Werror = treat warnings as errors
-g = include debugging info
-o = output file named "output_file_name"
hello.c = source file
OR
gcc -o output_file_name hello.c
```
how to check executable file:
ls -l
```
hello.c
output_file_name -> executable (green)
```
how to run executable file:
```
./output_file_name
```

HOW DOES COMPILATION WORK
1. GCC translates C -> machine code
2. creates executable file
3. that file can be run with ./

```
int main(int argc, char** argv)
argc = number of arguments
argv = array of strings
argv[0] = program name
argv[1] = first real argument

./output_file_name test
argc = 2
argv[0] = ./output_file_name
argv[1] = test
```

man sth = manual of sth
SPACE = next page
b = previous page
/text = search for "text"
n = next match
q = quit
(1) = section 1 = user commands (ls etc.)
(2) = section 2 = system calls (open, read, write, close = kernel functions)
(3) = section 3 = C library functions (printf, malloc)
(5) = file formats
(8) = system admin commands

PIPES
| = take the output of the command on the left and give it as input to the command on the right
command1 | command2 -> "command1 feeds command2"
ls -1 puts the contents of the directory vertically
ls puts them horizontally (by default)

grep = search for lines that match a pattern
grep apple fruits.txt
grep -i Apple fruits.txt
grep apple fruits.txt | wc -l -> counts lines
grep -x apple fruits.txt -> only the exact word (apple)
```
printf "apple\nbanana\npear\napple pie\nbanana split\n" > fruits.txt\
cat fruits.txt
=>
apple
banana
pear
apple pie
banana split
grep apple fruits.txt
=> 
apple
apple pie
```

PROCESS = RUNNING PROGRAM
./hello becomes a process
ls becomes a process

LONG PROCESS

CTRL+C = cancel the unfinished command (KILLS PROCESS)
CTRL+Z = pause the process, still exists in memory, it is not running (SUSPENDS PROCESS)
WHILE LOOP in bash:
```
while CONDITION; do
    commands
done
```

PRINT EVERY SECOND:
```
while true; do date; sleep 1; done
```
ps = show process status = list running processes
```
  PID TTY          TIME CMD
 1234 pts/0    00:00:00 bash
 1300 pts/0    00:00:00 ps
 
 PID = process ID (unique number)
 TTY = terminal
 TIME = CPU time used
 CMD = command name
```
ps -f = show all processes (full format, more details)
ps aux = show everything running on system
find . -name "*.txt" = search files ending with .txt in current directory
find . -name "hello*" = recursive (searches inside subfolders)
wc = count
wc fruits.txt -> counts lines, words, bytes
wc -l fruits.txt -> only lines
head -n 5 fruits.txt -> first 5 lines
tail -n 5 fruits.txt -> last 5 lines
sort fruits.txt
sort fruits.txt | uniq -> remove duplicates
sort fruits.txt | uniq -c -> count duplicates

ABSOLUTE VS RELATIVE PATHS
ABSOLUTE: /home/miagiurgiu/lab1/file1.txt
RELATIVE: 
file1.txt
./file1.txt
../file1.txt

PERMISSIONS
see permissions: ls -l
change permission: 
chmod +x hello -> add execute
chmod -x hello -> remove execute

malloc() -> allocates memory
free() -> releases memory
"&" = address
"*" = dereference
valgrind to detect leaks?? yes.

../../../ = back


## Lecture 1 - 25 feb 2026

## Individual work after Lecture 1

valgrind - check for memory leaks
apropos printf -> all manuals containing printf
whatis printf -> gives on-line summary of manual pages

## HOW TO USE LIMA + MAC 
- Lima is so cool because it allows you to run Linux commands on your mac system, on the existing files on it (cause generally, from what i have observed, virtual machines can't see the files on your original system)
- When you run Lima it connects to a linux vm running in the background
- okay not really because my lima config doesn't allow writing into my mac system, it only has reading properties -> altough you CAN configure Lima to mount your home as read-write (currently is read-only), but is risky

1. Command + space -> type "Terminal"
2. Command + T = new terminal
3. to access linux -> type "lima"
4. to close linux -> type "exit"
5. limactl stop default (typing exit only disconnects your shell, if you want to ACTUALLY stop the VM, you need this command)
6. top -> interactive monitoring program (see cpu usage etc)
	1. q -> quit or CTRL + C
	2. h -> help
	3. k -> kill a process
	4. P -> sort by cpu
	5. M -> sort by memory
7. to quit vim -> type :q! inside it
8. 
whoami -> lima
uname -a -> shows linux

ip for every computer in the world: 127.0.0.1 = " this computer itself"

Inside nano:
- to save: CTRL + O -> Enter
- to exit: CTRL + X
- nano -l filename.c => numbered lines


## Seminar 1 OS

- How to find all lines of a text file that contains phone numbers?
```
grep -E '[0-9]{3}[- ]?[0-9]{3}[- ]?[0-9]{4}' file.txt
```
- How to remove space at the end of each line?
```
sed -E 's/[[:space:]]+$//' file.txt

[[:space:]]+ -> one or more spaces
$ -> end of line
// -> delete them

when using d and when simply // for deletion??
```
- Remove duplicated spaces -> replace multiple spaces with one space
```
sed -E 's/[[:space:]]+/ /g' file.txt
```
- Verify email format
```
grep -E '^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$' file.txt
```

Extended regular expression rules:
![[Pasted image 20260317110312.png]]
![[Pasted image 20260317110326.png]]

Examples for rules:
```
.* -> any sequence of characters

[a-zA-Z02468] -> any lowercase, any digit, any uppercase

[ !] -> space or !

^[^0-9]+$ -> non-empty lines containing any characters except digits

\([Nn][Oo] )+ -> any refusal, no matter how insistent
```

EVERYTHING ABOUT GREP:
- searches through files using regular expressions
- option arguments:
![[Pasted image 20260317111044.png]]
- * -> zero or more
- + -> one or more (with grep -E)
- ? -> zero or one (with grep -E)
- {2,} -> at least 2 (with grep -E)
- display all lines containing "dan"
```
grep "dan"  /etc/passwd
```
- display the line of username "dan", ending in :
```
grep -i "^dan:" /etc/passwd

^dan -> line must start with da, then immediately followed by :
```
- display all users who don't have digits in their username
```
grep -E "^[^0-9:]+:" /etc/passwd
```
- display the whole line for all users who have at least two vowels in username
```
grep -i -E "^[^:]*[aeiou] [^:]*[aeiou] [^:]*:" /etc/passwd

grep -i -E "^[^:]*([aeiou] [^:]*){2,}:" /etc/passwd
([aeiou] [^:]*){2,} -> repeat this pattern at least 2 times

```
- display the lines of all users not having bash as their shell
```
grep -v "/bash$" /etc/passwd
```
- display all lines of all usernames named Ion (not Ionescu, Simion)
```
grep -E -i "^([^:]*:){4}[^:]*\<ion\>" /etc/passwd

\<ion\> -> whole word ion, not part of a larger word

```
- display non-empty lines
```
grep "." a.txt

. -> any single character except newline
```
- display empty lines
```
grep "^$" a.txt
```
- display all lines containing an odd number of characters
```
grep -E "^(..)*.$" a.txt

```
- display all lines containing an ocean name
```
grep -E -i "\<atlantic\>|\<pacific\>|\<indian\>|\<arctic\>|\<antarctic\>" a.txt

```
- display all lines containing an email addres
```
grep -E -i "\<[^@*\!?]+@[a-z0-9_-]+(.[a-z0-9_-]+)+\>" a.txt

```

## Test Prep for Test 1 
#### correct a given program

TYPES OF ERRORS:
1. CATEGORY 1: "implicit declaration of function ... "
	Solution: #include ... (see in man in which library is that function included)
	Most used: stdlib.h, string.h, stdio.h
	Ask yourself: "What header is missing?"
	
2. CATEGORY 2: pointer vs non-pointer
    "invalid operands to binary ..."
    Ask yourself: "Am I comparing a non-pointer with NULL?" (null can only be compared with pointer)
    "argument makes pointer from integer"
    Ask yourself: "Did I pass char instead of char*, or int instead of pointer?"
    "incompatible types when assigning to type ..."
    "incompatible types when returning type ..."
    Ask yourself: "Did I use pointer where plain value is expected, or vice versa?"
    Solution: add a * somewhere
    When you see: NULL, malloc, next => pointers (*)
```
struct node* add(struct node head, char* name) ERROR
struct node* add(struct node* head, char* name) CORRECT
```
3. CATEGORY 3: "." instead of "->"
	"p is a pointer, did you mean to use -> ?"
	Ask yourself: "Is this variable a pointer to struct?"
```
struct node* p;
...
strcmp(p.name, name) ERROR
strcmp(p->name, name) CORRECT

struct node x; => access using x.name
struct node* p; => access using p->name
```
4. CATEGORY 4: wrong function parameter type
	"passing argument 2 of strcmp makes pointer from integer"
	When you see: strcmp, strcpy, strlen => string => pointer => char*
```
int known(struct node* head, char name) ERROR
int known(struct node* head, char* name) CORRECT

char = one character, like 'A'
char* = string, like "Ana"
```
5. CATEGORY 5: syntax/typing mistakes
	"expected ..."
	"missing terminating ... "
	"%d", missing ";", missing "()", missing "{}"
	Ask yourself: "Did I mistype punctuation?"
6. CATEGORY 6: unitialized pointer/variable
	Every pointer that starts as "empty list/no file/nothing yet" should usually start as NULL
```
struct node* head;
if(known(head,name)) => ERROR (head was never initialized, so it contains garbage)

struct node* head = NULL => CORRECT
```
7. CATEGORY 7: memory allocation size 
	A string needs space for all characters plus the final '\0'
```
n->name = (char*)malloc(strlen(name)); ERROR (no space for the final '\0')
n->name = (char*)malloc(strlen(name)+1); CORRECT
```
8. CATEGORY 8: base-case / NULL checks in list functions
	In linked list functions, ask yourself: "what if list is empty?", "what if current node is NULL?"
```
if (head == NULL) {
	return 0;
}
```
9. CATEGORY 9: "unused variable/unused parameter"
   To be left at last!
	Delete them or use them somehow.
	Tell yourself: "Ignore until parsing errors are fixed"
	"unused parameter argc"
```
(void)argc;
```
9. CATEGORY 10: mismatch fopen-fclose, open-close
```
FILE* f = fopen("a.txt", "r");
close(f);      // wrong
```

```
int fd = open("a.txt", O_RDONLY);
fclose(fd);    // wrong
```
open vs fopen; close vs fclose

fopen, fclose => library <stdio.h> => file is being read with FILE* -> "r" .. descriptors
```
FILE* f;
f = fopen("a.txt", "r");
fclose(f);

=> used with fprintf, fscanf, fgets, fputs
```
open, close => library <fcntl.h> => file is being read with file descriptors (int) -> O_RDONLY ... descriptors
```
int fd;
fd = open("a.bin", O_RDONLY);
close(fd);

 => used with read, write, lseek
```
Conclusion:
open() -> returns int (file descriptor)
fopen() -> returns FILE*
pclose() -> expects FILE*

11. CATEGORY 11: when * and when & 
	In C there are no references, only pointers.
	&n -> address of variable n
	*n -> content pointed to by p
    * & to use when a function must write INTO my variable; DON'T USE IT with strings/arrays because in most cases they are already pointers
    * * has two meanings:
	    1. when declaring -> "this variable is a pointer"
	    2. in an expression -> "go to the pointed value"
```
WHEN DECLARING (*):
int* p; = "p points to an int"
char* s; = "s points to a char"
struct node* head; = "head points to a struct node"
FILE* f;  = "f points to FILE"

IN AN EXPRESSION (*):
int x=5;
int* p = &x;
printf("%d\n", *p); prints 5

int rows;
fscanf(f, "%d", &rows);

IN FUNCTIONS (&):
scanf("%d", &x); SCANF NEEDS ADDRESS
fscanf(f, "%d", &rows);
read(fd, &k, sizeof(int));

BUT

char name[64];
scanf("%s", name); NOT &name BECAUSE name IS ALREADY A STRING
strcmp(name, "ana");

* -> WHEN THE VARIABLE STORES AN ADDRESS
char *s;
struct node* p;
FILE* f;

"->" -> WHEN I HAVE:
struct something* p
p->next
p->name

```
12. CATEGORY 12: "control reaches end of non-void function"
	Ask yourself: "Did I forget a return?"

C error families:
- missing headers
- pointer vs non-pointer
- `.` vs `->`
- string vs char
- `malloc/free`
- forgetting `+1` for strings
- forgetting to initialize pointer to `NULL`
- `scanf` with and without `&`
- file descriptor I/O vs `FILE*` I/O

### Reference sheet (week 1-2):
HEADERS:
#include <stdio.h>    // printf scanf FILE fopen fclose
#include <stdlib.h>   // malloc free
#include <string.h>   // strlen strcpy strcmp
#include <unistd.h>   // read write close
#include <fcntl.h>    // open flags

POINTERS:
int* p;   // pointer declaration
*p        // pointed value
&x        // address of x

STRUCTS:
x.name    // struct value
p->name   // pointer to struct

FILES:
FILE* f = fopen("a.txt", "r");
fclose(f);

int fd = open("a.bin", O_RDONLY);
close(fd);

STRINGS:
char c;       // one char
char* s;      // string
strlen(s)+1   // space needed for copy

SCANF:
int x;       scanf("%d", &x);
char s[64];  scanf("%63s", s);

C:
- C functions receive copies of arguments -> call by value
- usually a function cannot modify variables in the caller
- char line[] <=> char *line
- Arrays passed to functions **decay into pointers**
- Functions can **modify the original array contents**
- This happens because the function works with a **pointer to the same memory**.
- FUNCTIONS RECEIVE ARRAYS => they can modify them
- arrays are passed as pointers
- when you make a function call like f(x), the VALUE of x is passed, not its address (so there is no way to alter x from inside f); if x is an array (char x[10]), x is an address, you are not trying to change the address
- if x is a scalar and you wanna change it, you have to pass the ADDRESS of x to f and then use it as a pointer

A struct cannot contain itself directly:
```
struct node {
    char* name;
    struct node next;
};

CORRECT (LINKED LIST PATTERN):
struct node {
    char* name;
    struct node* next;
};

=> linked lists store pointers to the next node, not to the node itself.
```

NULL is a pointer (void*)
12. CATEGORY 12:
control reaches end of non-void function
Ask yourself: Did I forget a return?

valgrind errors:
A. `Conditional jump or move depends on uninitialised value(s)`
	an `if`, `while`, `strcmp`, array index, etc. is using garbage
Ask:
- did I initialize the variable?
- did `scanf/fscanf/read` really write into it?
- did I forget `&`?
- did I initialize pointer to `NULL`?
In your case:  
`head` not initialized.

B. `Invalid write of size ...`
	you wrote where you do not own memory
Ask:
- wrong malloc size?
- array out of bounds?
- wrote to freed memory?
- wrote through bad pointer?

In your case:  
`malloc(sizeof(struct node*))` instead of `sizeof(struct node)`.

C. `Invalid read of size ...`
	you read from invalid memory
	Ask:
- pointer corrupted?
- memory freed already?
- list node malformed?
- wrong `&` in `read/fscanf`?
- uninitialized pointer?

In your case:  
corrupted node layout from bad allocation and possibly bad head handling.

D. `definitely lost`
	real leak, pointer gone
	Ask:
- where was memory allocated?
- who was supposed to free it?
- did I overwrite the pointer?
- did I forget `free`?

E. `0 bytes after a block of size X alloc'd`
	overflow exactly past the end
	Ask:
- allocated too little?
- forgot `+1` for string?
- used `sizeof(pointer)` instead of `sizeof(object)`?


Valgrind errors in this priority:
1. uninitialized values
2. invalid writes
3. invalid reads
4. leaks

Why this order?  
Because leaks are often just consequences of earlier corruption.

allocate (YOU MUST FREE BOTH ALLOCATIONS!)
```
n = malloc(sizeof(struct node));  
n->name = malloc(strlen(name)+1);
```
deallocate:
```
free(n->name);
free(n);
```

free - releases one block of memory that was allocated with malloc/calloc/realloc
```
char* s = malloc(10);
free(s);
```

HOW TO INFER PROGRAM ARGUMENTS
When you see:
```
int main(int argc, char** argv)
```
... program expects command-line arguments
argc = number of arguments
argv = array of strings
argv[0] = program name
argv[1] = first argument
argv[2] = second argument

HOW TO DETECT WHAT ARGUMENTS ARE NEEDED:
```
fopen(argv[1], "r") -> argv[1] is a FILENAME
atoi(argv[1]) -> argv[1] is a NUMBER
printf("%s", argv[1]) -> argv[1] is a STRING
```

STANDARD INPUT vs COMMAND-LINE FILE
scanf => read from standard input, not from file
run them like:
```
./program
not
./program file.txt
```

fopen => read from file, not from standard input
```
./program file.txt
not
./program
```

VALGRIND ERRORS:
command formula:
```
valgrind ./program arguments

complete:

valgrind --leak-check=full --show-leak-kinds=all  --track-origins=yes ./program arguments
```

reading strategy:
1) first error at the top -> where the problem happens
```
at function (file.c:line)
```

2) where the memory came from
```
created by ...
alloc'd at ...
freed at ...
```

3) check leak summary (at the bottom)
- "definitely lost" = memory was allocated but the pointer to it was lost
```
ex.
p = malloc(...);
p = something_else;
```
- "indirect lost" = memory reachable only through leaked memory
```
ex.
leaked a linked-list node => its name field also becomes unreachable
```
- "possibly lost" = valgrind is unsure if pointer is valid
- "still reachable" = memory was not freed, but program still had a pointer to it when exiting

4) "Conditional jump depends on unititialised value"
```
if()
while()
strcmp()
is using garbage data.

struct node* head; ERROR
struct node* head = NULL; CORRECT

scanf("%d", x); error
scanf("%d", &x); correct
```

5) "Invalid write of size ..." = writing outside allocated memory
```
malloc(sizeof(struct node*)); ERROR
malloc(sizeof(struct node)); CORRECT
malloc(strlen(name)); ERROR
malloc(strlen(name)+1); CORRECT
```

6) "Invalid read of size ..." = reading invalid memory
- pointer already freed
- corrupted pointer ?
- wrong & usage
- wrong struct layout

6) "0 bytes after a block of size X"
```
malloc(sizeof(pointer)) instead of malloc(sizeof(object))
but pointer is not an object?!
```

7) "definitely lost" -> where is the matching free?

MEMORY OWNERSHIP:
```
allocate:
n = malloc(sizeof(struct node));
n->name = malloc(strlen(name)+1);
free:
free(node->name);
free(node);
```

LINKED LIST MEMORY STRUCTURE:
```
A node:
struct node {
    char* name;
    struct node* next;
};

Memory layout:
node - name
       - next

Allocations per node:
malloc(struct node)
malloc(string)

Cleanup:
free(name);
free(node);

correct oder:
void clear(struct node* head) {
    if(head == NULL) return;
    clear(head->next);
    free(head->name);
    free(head);
}
```

Pointer issues:
```
Did I forget * ?
Did I compare struct with NULL?
Did I use . instead of -> ?
```

Input:
```
Did I forget & in scanf/fscanf/read?
```

Memory:
```
Did I allocate correct size?
Did I forget +1 for string?
Did I free everything I malloc?
```

Linked lists:
```
Did I initialize head = NULL?
Did I break the list structure?
```

"Implicit declaration of function" => missing header (#include...)

"invalid operands to binary !=" => comparing struct with NULL instead of pointer (NULL can only be compared with a pointer)
```
struct node p; ERROR
struct node* p; CORRECT
```

"passing argument from incompatible pointer type" => clear(head->name), but function expects struct node*
```
if function expects struct node* :
clear(head->next);

if you want to release a string:
free(head->name);
```

"control reaches end of non-void function" => missing return

function is int => return sth like 0,1,x
function is struct node* => return head or n
function is void => return or nothing

## Lab 3 - 9 mar 2026

https://regex101.com
- copy paste from a file -> explain live what happens (live line search)

grep, sed, awk practice problems

passwd - fisierul principal care gestioneaza userii de pe un sistem anume
wget
curl
copy link from website -> wget link ...

ps - processes from the system
ps aux

1. All usernames that logged in from "economica" on a Sunday

- with grep:
cat last.fake | grep "economica" | grep "Sun" | grep E- '^[a-z0-9]+ ' -o | sort | uniq

^[a-z0-9]+ -> regex; 
"" -> with $ at the end -> $ name of variable
'' -> everything interpreted exactly as it is; preferable
-o -> only matching our regex
uniq -> same thing one after the other -> remains only the first one
export cheese=1
echo $cheese

- with sed:
sed by default eliminates stuff
has 4 fields
[OPERATIE]/[CE_CAUTAM]/[DE_INLOCUIT]/[FLAGS]
how to delete with sed
/asdf/d
s/[CHESTIE]/[REPLACE]/[FLAGS]
dmesg | sed '/e/d' -> deletes lines which contain letter e
dmesg | sed  -E '/e/d' -> deletes lines which contain letter e or E

echo "Alex" | sed -E 's/e/3/d' -> Al3x

replace everything with username from the beginning

capturing groups
replace the whole match with the content of 1
replace with the content of capturing group 1
delete the first part
replace everything with the content of....

^[a-z]+([0-9]{4}).+$
^([a-z]+[0-9]{4}).+$

matc-ul sa nu match-uiasca doar daca are si Sun si economica in nume
^([a-z]+[0-9]{4}).+economica.+Sun.+$
a single regext that gets everything

in Kate -> find all, replace all

we cna extract the username for those using only a single sed. 
sed '^([a-z]+[0-9]{4}).+economica.+Sun.+$/\1/g' last.fake 

we can sort them / add a new sed that deletes those lines where there are more than 2 spaces

sed '^([a-z]+[0-9]{4}).+economica.+Sun.+$/\1/g' last.fake | sed -E '/ /d'  | sort | uniq | head -n1

head can skip the first line and give the next n ones ...

- with cat
cat last.fake | grep "economica" | grep "Sun" | cut -d' ' -f 1 | sort | uniq

cat last.fake | grep "economica" | grep "Sun" | awk '{print $1}'

cat last.fake | grep "economica" | grep "Sun" | awk '{print $2}'

awk matching with regex?? -> teaching notes -> tilda, BEGIN, END

BEGIN {
initialise a vecor accessed based on key column1
	useri[]
}
$3 ~ / economica.*/ && $4=="Sun" {
print $1
useri[$1]++
}
END{

}
coloana 3 matches ...

awk last.fake -f test.awk
awk last.fake | awk -f test.awk

awk -f test.awk last.fake

awk for deduplicate

THE ONLY THING EXTRA IN AWK is ~
$3 ~/economica.*/  && $4=="Sun" {
	print $1;
}

finish the rest; 
ex 2 -> give it to chat gpt -> construct another method than chat gpt (with awk for instance)

grep, sed, cat -> no need for awk
ask -> no need for the rest

complex processing -> awk

every one is needed for the exam. but for week 6 -> know awk -> regex, sed, grep.

LAB 3 WRAP-UP:

REGEX = pattern language
grep = find matching lines
sed = transform text
awk = treat text like columns and process it

grep -> searches with regex
sed -> search, replace, delete
awk -> treat input as rows/fields

```
grep Sun /etc/passwd 
grep economica /etc/passwd
grep ^[a-z0-9]+ -> from start of the line, one or more lowercase letters or digits

```

```
^ -> start of line
$ -> end of line
[a-z] -> one lowercase letter
[0-9] -> one digit
[^ ] -> one character that is NOT space (space negated)
+ -> one or more
  * -> zero or more
() -> group
| -> or
\ -> escape character
```

'' -> single quotes -> everything is taken literally (preferred for regex)
"" -> double quotes -> if regex contains $, it could create confusion

-E -> extended regex
-i -> ignore case (insensitive case)
-v -> invert match 
-o -> print only matching part

## Lecture 3 (11 mar 2026)

1) Find names of all students in group 911. Which file has the list of all students in the system? using grep.

- linux keeps information about all users in the following file:
```
/etc/passwd
```
- view that file using less:
```
less /etc/passwd
```
- "less" -> view the contents of a file one page at a time without editor (allows scrolling)
- result: fields are separated by ":"
- structure of the result:
```
username:password:UID:GID:comment:home_directory:shell
```
- important fields (on columns):
	- field 1 -> username
	- field 2 -> password placeholder (usually x)
	- field 5 -> comment field (person's full name and other info)
- use grep command for searching students from group 911:
```
grep -E " - 911 - " /etc/passwd

grep -> searches lines in a file
-E -> extended regular expressions
" - 911 - " -> matches the group number written between spaces and dashes
```


2) How to extract one field (column) from the file? using awk
```
grep -E " - 911 - " /etc/passwd | awk -F: '{print $5}'

| -> pipe -> send output of left command as input for right command
awk -> processes text column-by-column (extracts)
-F -> tells awk that the field separator is ":"
{print $5} -> prints the 5th field (column), the one with the student's name
```


3) Count unique students? using uniq command; 
- sort first and then run uniq on it => one student each time => nr of unique students
```
grep -E " - 91[0-9] - " /etc/passwd | awk -F: '{print $5}' | sort | uniq | wc -l

grep -E " - 91[0-9] - " -> select English section groups (910-919)
awk -> extract names
sort -> sort alphabetically
uniq -> remove duplicates (works well only on sorted input)
wc -l -> count lines
```
 

4) Find most popular names in the English section? extract just the first names
```
grep -E " - 91[0-9] - " /etc/passwd \
| awk -F: '{print $5}' \
| awk '{print $2}' \
| sort \
| uniq -c \
| sort -n -r \
| head -n 20

uniq -c -> counts occurences
sort -n -> sorts numerically
-r -> reverse order (largest first)
head -n 20 -> the top 20
```

- the comment field often looks like:
```
Lastname Firstname
Lastname.Firstname
Lastname.Firstname.Group
```

- extract the first name only => remove everything after the first dot (the first name -> up to the first dot)
```
awk -F: '{print $5}' /etc/passwd \
| grep -E " - 91[0-9] - " \
| sed -E  "s/\..*//"

'{print $5}' -> extract the 5th field
s -> substitute
/ -> separator
\. -> literal dot
.* -> everything after dot (any character, any number of times)
// -> replace with nothing (there is nothing between / and /)
```

- full pipeline:
```
awk -F: '{print $5}' /etc/passwd \
| grep -E " - 91[0-9] - " \
| sed -E  "s/\..*//" \
| sort \
| uniq -c \
| sort -n -r \ 
| head -n 20
```

- sed - command that performs search in place. 
- awk - extracts

5) How to get middle names as well? (skip last name, skip initials, extract only first and middle names)
- remove from every line everything from dash space 
- replace every - with space?
- but what if there are ppl with 2/3 last names?
- ex:
```
Giurgiu Corina Maria - 914 - ...
```

- I remove Giurgiu Corina and I am left with Maria :))
```
sed -E "s/ .*//" -> everything after the first space replace it with nothing

sed -E "s/^.* - [^ ]+[^ ]+ //"

^ -> beginning of line
.* -> anything (greedy - match as many as possible)
" - " -> literal pattern
[^ ] -> sequence of non-space characters (space negated)

awk -F: '{print $5}' /etc/passwd | grep -E " - 91[0-9] - " | sed -E "s/^.* - [^ ]+[^ ]+ //"

awk -F: '{print $5}' /etc/passwd \
| grep -E " - 91[0-9] - " \
| sed -E "s/ .*//"

Maria.Giurgiu
sed -E "s/\..*//"
```

```
Lo Monaco Marco etc. - 914 - ...
??
```

 - everything that is not a character replace it with nothing: use sed to replace character with nothing:
```
sed -E "s/[^a-z]//gi"

[^a-z] -> anything not a letter (letter negated)
g -> replace everywhere on the line
i - case insensitive
 
awk -F: '{print $5}' /etc/passwd | grep -E " - 91[0-9] - " | sed -E "s/^.* - [^ ]+[^ ]+ //" | sed -E "s/[^a-z]//gi"
```

- replace all spaces with a new line (each name on its own line):
```
sed -E "s/ +/\n/g"

 + -> one or more spaces
```

- remove short names (initials):
```
grep -E -v "^.{,2}$"

-v -> i dont show it (exclude)
^.{,2}$ -> strings of length <=2
exclude lines that have length <=2;
```
0
- count most frequent names:
- sort numerically in reverse?
```
sort | uniq -c | sort -n -r | head -n 20

awk -F: '{print $5}' /etc/passwd | grep -E " - 91[0-9] - " | sed -E "s/^.* - [^ ]+[^ ]+ //" | sed -E "s/[^a-z]//gi" | sed -E "s/ +/\n/g" | grep -E -v "^.{,2} | sort | uniq -c | sort -n -r | head -n 20
```

6) escape character: every character has 2 meanings:
n - normal meaning
\n - special meaning
\ - escape character (used to break long commands)
ex:
```
"." -> normal meaning: dot character
    -> regex meaning: any character ??!
"\." -> the actual dot
```

- how to write a command on > lines:
![[Pasted image 20260311183657.png]]

7) script - stop the student processes running more than ... . How to kill any non-root process? using kill. using process id. (2nd column)
- kill students' processes
- show all processes in the system:
```
ps -e 
```
- usernames' processes:
```
ps -u rares
```
- terminate a process (PID = process id, second column of ps output):
```
kill PID
cat
```

8) how to find the age of a process?
- process = program in execution (task manager)
- iterate through processes -> find age
```
man ps
```

- select which columns to display:
```
-o -> what columns to show
ps -o etime PID

etime -> elapsed time since the process started
```

- formats:
```
MM:SS
HH:MM:SS
DD-HH:MM:SS
```

9) script: detect long running processes:
```
ps -ef | grep -E -v "^root\>" | awk '{print $2}' | tail -n +2

ps -ef -> all processes, full information (user, PID, parent PID etc.)
```

- kick out everything starting with root (remove processes owned by root)
```
grep -E -v "^root\>"

-v -> invert match (exclude)
```
- extract PID column
```
awk '{print $2}'
```
- i need to get rid of the header (skip header line)
```
tail -n +2
```
- how to test if a string is empty? using test
- expr -> perform arithmetic in shell (meaning what?)

in terminal:
```
./watch.sh a
ps -ef | grep -E -v "^root\>" | awk '{print $2}' | tail -n +2
chmod 700 a.sh
./a.sh
expr  1+1
expr 3*5
expr 3 \* 5

* must be excaped: \* (otherwise shell treats it as ??)
```


a.sh: (aproximativ)
- read process IDs from `ps.fake`, ignore processes owned by `root`, get each process’s elapsed running time, skip times already containing hours, convert `MM:SS` to seconds, and print the processes that have been running more than 3600 seconds.
```
#!/bin/bash
for P in `ps -ef | grep -E -v "^root\>" | awk '{print $2}' | tail -n +2`; do
	T = `ps -o etime process_id | tail -n +2` -> duration of the process (minutes, seconds)
	if test -z "$T" || echo $T | grep -E -q ".*:.*:"; then
		continue
	fi
	M = `echo $T | sed -E ""` -> echoing the time and replacing so that i am left eith the minutes
	S = `` -> echoing the time and replacing so that i am left eith the seconds
	echo $P $M $S
	X = `expr $M \*60 +$S` -> not echo $(( -> newer syntax specific to bash
	if test $X -gt 3600; then
		echo $S $T $M $S $X
	fi
	echo $P $M $S $X
done



likely better?
#!/bin/bash

grep -v '^root[[:space:]]' ps.fake | awk 'NR > 1 {print $2}' | while read -r pr; do
    t=$(ps -p "$pr" -o etime=)

    [ -z "$t" ] && continue

    total=0

    if echo "$t" | grep -q '^[0-9]\+:[0-9]\+:[0-9]\+$'; then
        h=$(echo "$t" | cut -d: -f1)
        m=$(echo "$t" | cut -d: -f2)
        s=$(echo "$t" | cut -d: -f3)
        total=$((h * 3600 + m * 60 + s))
    elif echo "$t" | grep -q '^[0-9]\+:[0-9]\+$'; then
        m=$(echo "$t" | cut -d: -f1)
        s=$(echo "$t" | cut -d: -f2)
        total=$((m * 60 + s))
    else
        continue
    fi

    if [ "$total" -gt 3600 ]; then
        echo "$pr $t $total"
    fi
done
```

```
ps -o etime process_id | tail -n +2
```

awk - extracts
expr - arithmetic in the command line

10) Nothing happens simultaneously (processes - they are just very fast, one after the other) - except on mac m4 fast 
- n++ NOT ATOMIC: you may lose cpu during a n++ operation -> it's 3 assembly operations (load value from n to register, increment register, store value back to n) and during these operations, cpu might get lost

10) Implement a script and then a c file; Reads a number from file, increments it and writes it back to file
- run one time -> 200 -> run one more time -> 400 -> ...
- file example:
```
echo 0 > x
```
- terminal:
```
./a.sh
echo 0 >x
cat x
./b.sh x
cat x
./b.sh x & -> does what??! runs script in background.
chmod 700 
```
- script:
```
#!/bin/bash

f=$1
N =0
while test $N -lt 200; do
	K=`cat $F`
	K=`expr $K+1`
	echo $K > $F
	N=`expr $N +1`
done


better:

It adds 1 **200 times** because of the loop

#!/bin/bash

f=$1
n=0
while [ $n -lt 200 ]; do
        k=$(cat $f)
        k=$(($k+1))
        echo $k > $f
        n=$(($n+1))
done

if number2.txt contains 2, it will overwrite 2+200 = 202 inside number2.txt



```
- run multiple scripts simultaneously:
```
#!/bin/bash
echo 0> x

./b.sh x &
./b.sh x &
./b.sh x &
```
- & runs script in the background
- PROBLEM: all scripts read the same value at the same time 
	- K=0; each process reads 0 -> increments -> writes 1; 
	- expected result: 600; 
	- actual result: smaller number
	- reason: "race condition" (= processes overwrite each other's results)
- what is the value of k in the 3 processes? 0
- it can be interrupted (everyone reads, writes, overwrites) -> they act based on how things get scheduled and they don't interfere with each other ?

12) the same thing in C
- increments a number stored in a file
- the lower chances to interfere -> worst case
- the higher chances to interfere -> ?
```
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    int f, k, i;
    f = open(argv[1], O_RDWR);
    if(argc > 2 && strcmp(argv[2], "reset") == 0) {
        k = 0;
        write(f, &k, sizeof(int));
        close(f);
        return 0;
    }
    for(i = 0; i < 200; i++) {
        lseek(f, 0, SEEK_SET);
        read(f, &k, sizeof(int));
        k++;
        lseek(f, 0, SEEK_SET); // move pointer to start of file
        write(f, &k, sizeof(int));
    }
    close(f);
    return 0;
}
```
- this program suffers from "race conditions" if multiple instances run simultaneously
- open() opens a file descriptor
- read() reads bytes from file
- write() writes bytes to file
- lseek() moves the file pointer
```
#!/bin/bash
echo 0> x
```

- display file content in hexa (to see raw binary data written by C programs -> how integers are stored inside the file)
```
xxd y
```

./d y
expr 12 \*16 + 8
xxd y
expr 256+9 \*16
xxd y
expr 2 \* 256+5\*16 +8
./e.sh

## Individual work after Lecture 3, Lab 3

REGEX = PATTERN ("find text that looks like this pattern")
"dan" means: find dan
"^dan:" means: find lines that start with dan:
"^[0-9]+$" means: find full lines that contain no digits at all

grep -> searches through files using regular expressions
-E -> extended regex
-v
-i
-c
-o

#### Grep/Sed/Awk practice problems
https://www.cs.ubbcluj.ro/~rares/course/os/res/practice/gsa/index.html

1.
![[Pasted image 20260315145110.png]]

Method 1. Using grep.
- 1. keep only lines that contain "economica"
```
grep 'economica' last.fake
```
- 2. from those lines, keep only lines that contain "Sun"
```
grep 'economica' last.fake | grep 'Sun'

| -> sends those lines to the next command
```
- 3. from those lines, extract the username
```
grep 'economica' last.fake | grep 'Sun' | awk '{print $1}'

awk -> splits each line into "columns" separated by spaces by default
$1 -> the first field (column)
{print $1} -> prints onlt that first field (column)
```
- 4. remove duplicates
```
grep 'economica' last.fake | grep 'Sun' | awk '{print $1}' | sort | uniq
```

Method 2. Using grep + regex
1. keep only lines that contain "economica"
```
grep 'economica' last.fake
```
- 2. from those lines, keep only lines that contain "Sun"
```
grep 'economica' last.fake | grep 'Sun'

| -> sends those lines to the next command

```
- 3. extract the username from the beginning
```
grep 'economica' last.fake | grep 'Sun' | grep -E -o '^[a-z0-9]+'

-E -> grep used with regex
-o -> print only the part that matches
```
- 4. remove duplicates
```
grep 'economica' last.fake | grep 'Sun' | grep -E -o '^[a-z0-9]+' | sort | uniq

sort -> put identical usernames together
uniq -> remove repeated adjacent lines
```

Method 3. Using awk
~ -> special regex operator -> "matches regex"
```
awk '$3~/economica/ && $4=="Sun" {print $1}' last.fake | sort | uniq

awk -> read file line by line, field by field (column by column), using spaces
$3~/economica/ && $4=="Sun" -> logical test 
$3~/economica/ -> column 3 CONTAINS "economica"

```

Method 4. Using sed
General form of sed:
```
sed -E 's/REGEX/REPLACEMENT/'

s/ -> substitute
find text matching REGEX
replace it with REPLACEMENT
-E -> extended regex like + and ()
```

```
echo 'piir1546 pts/5 economica.ubbclu Sun Mar 2' | sed -E 's/^([a-z]+[0-9]{4}).*$/\1/'

s/ -> substitute
^([a-z]+[0-9]{4}).*$/ -> find text matching this regex
	-> () -> capturing group 1
	-> ^ -> start of line
	-> ([a-z]+[0-9]{4}) -> one or more lowercase letters, followed by exactly 4 digits
	-> .* -> rest of the line
	-> $ -> end of line
\1 -> replace capturing group 1 with itself. 
```

2.
![[Pasted image 20260315163151.png]]

Method 1. Using awk only.
- remove last line of the file (not valid data)
```
head -n -1 last.fake
```
- find what was asked
```
head -n -1 last.fake | awk '$7 >= "23:00" {print $1}' | sort | uniq
```

Method 2. Using awk only.
```
head -n -1 last.fake | awk 'substr($7,1,2)>=23 {print $1}' | sort | uniq

'substr($7,1,2)>=23 {print $1}' -> take field 7, start at character 1, take 2 characters

ex: if $7 is 23:10 -> substr($7,1,2) is 23.
```

Method 3. Using awk + sed and given recommendation:
- extract username and login time:
```
head -n -1 last.fake | awk '{print $1, $7}'
```
- replace ":" with " ":
```
head -n -1 last.fake | awk '{print $1, $7}' | sed 's/:/ /'
```
- show only the hours >=23 (second column now)
```
head -n -1 last.fake | awk '{print $1, $7}' | sed 's/:/ /' | awk '$2 >= 23'
```
- show only the usernames for those hours -> sorted, non-duplicate format
```
head -n -1 last.fake | awk '{print $1, $7}' | sed 's/:/ /' | awk '$2 >= 23 {print $1}' | sort | uniq
```

Method 4. Using awk + grep.
```
head -n -1 last.fake | grep -E ' 23:[0-9]{2} | awk '{print $1}' | sort | uniq
```

3.
![[Pasted image 20260315165900.png]]

Method 1. using grep + awk
- search for line starting with "m":
```
grep '^m' passwd.fake 
```
- extract only the ids (the 3rd column) that are divisible with 7:
```
grep '^m' passwd.fake | awk -F: '$3%7==0 {print $5}'
```

Method 2. using only awk
```
awk -F: '$1 ~ /^m/ && $3 % 7 == 0 {print $5}' /etc/passwd

-F: -> separator is ":", not space (by default is space)
$1 -> username
~ -> ?
/^m/ -> starts with m
&& -> and
$3 % 7 == 0 -> third field (column) (id) divisible with 7
{print $5} -> print full name
```


4.
![[Pasted image 20260315203839.png]]

Method 1. on my own processes list.
- get the process list
```
ps -ef
```
- keep processes owned by root
```
ps -ef | grep '^root'
```
- how to find out name of headers? -> count the columns
```
ps -ef | head
```
- solution
```
ps -ef | grep '^root' | awk '{print $6}' | sort | uniq
```

Method 2. on a file processes list.
-  keep processes owned by root
```
grep '^root' ps.fake 
```
- extract the 6th field (tty)
```
grep '^root' ps.fake | awk '{print $6}' | sort -u
```
- same thing but with uniq:
```
grep '^root' ps.fake | awk '{print $6}' | sort | uniq
```


5.
![[Pasted image 20260315205552.png]]
Method 1. grep + awk
- search usernames ending in 88:
```
grep '88:' passwd.fake
```
- take their full names
```
grep '88:' passwd.fake | awk -F: '{print $5}'
```

Method 2. with awk only
begin nothing:
if $1 ~ 88 print $5
https://regex101.com

```
awk -F: '$1 ~ /88$/ {print $5}' /etc/passwd
```

Method 3. with sth else:
- use sed when you want to match a pattern and extract part of the line at the same time
- capturing groups 
	-> defined with parantheses ()
	-> referenced in replacement with: 
		\1 -> first group
		\2 -> second group
```
sed -E 's/(pattern1)(pattern2)/\2/'
```
- sed options:
	- -E -> enable extended regex
	- -n -> don't print all lines automatically
	- p -> print only lines where pattern matched
```
sed -nE 's/regex/\1/p'
```
- greedy vs lazy quantifiers:
	- greedy (default): .* matches as much as possible, then goes backwards (backtracking)
	- lazy (non-greedy): .*? matches as little as possible
		- they are not part of the standard POSIX regex, so sed does not work with lazy quantifiers
```
[^:]* -> prefered
.* -> not recommended

```
- extract only using sed because there exists a regex on the same line 
- very specific regexes
- greedy mode take from the beginning till the end and go back until you find what you are looking for. this is why lazy mode is slower (more steps)
- pag 13, could work in one way (-p, -e) 

- GREEDY QUANTIFIER:
```
.+ -> will match almost the entire line because it keeps consuming characters until reaching the end; then, if sth later in the regex fails, it backtracks (gives characters back)

. -> any character
+ -> one or more times
greedy -> tries to match as much of the line as possible

```
^.+:
![[Pasted image 20260316151532.png]]

- LAZY QUANTIFIER:
```
.+?
. -> any character
+ -> one or more
  ? -> lazy mode

lazy = match as little as possible (instead of taking the whole line like greedy does, it stops as soon as the regex can succeed)
```

![[Pasted image 20260316151609.png]]

Method x. using capturing group:

- match usernames ending in 88:
```
^[a-z0-9]+88:

^ -> beginning of line
[a-z0-9] -> letters or digits
88 -> ends in 88
: -> next field separator
```
- skip the next 4 fields:
```
([a-z0-9A-Z -]+:){4}

[a-z0-9A-Z -]+ -> characters allowed in fields
: -> field separator
{4} -> repeat 4 times
=> the last captured part becomes field 5
```
- the full matching regex:
```
^[a-z0-9]+88:([a-z0-9A-Z -]+:){4}.+$

username ending in 88
skip 4 fields
match the rest of the line
```
- grep command:
```
cat passwd.fake | grep -E 'regex'

??
```
- sed command with capturing group
```
sed -E 's/regex/\1/g'

\1 refers to ([a-z0-9A-Z -]+:)

cat passwd.fake | grep -E '^[a-z0-9]+88:([a-z0-9A-Z -]+:){4}.+$' | sed -E 's/^[a-z0-9]+88:([a-z0-9A-Z -]+:){4}.+$/\1/g'

```
- cleaner version using -n and p:
```
sed -nE '/regex/ s//\1/p'
```
- match a line with at least 6 fields separated by :
```
^([a-z0-9A-Z -]+:){5}(.+)$

=> skip first 5 fields, then capture the rest of the line
```
- match a line with at least 6 fields separated by : but without capturing the last part
```
^([a-z0-9A-Z -]+:){5}.+$
 
=> skip first 5 fields, ensure sth exists afterwards, used for matching, not extracting
```
- match users whose username ends in 88
```
^[a-z0-9]+88:([a-z0-9A-Z -]+:){4}.+$ 

=> match username ending in 88
=> SKIP NEXT 4 FIELDS
=> reach field 5 (full name)
```
- equivalent of 5 capturing groups:
```
([a-z0-9A-Z -]+:){5}

([a-z0-9A-Z -]+:)([a-z0-9A-Z -]+:)([a-z0-9A-Z -]+:)([a-z0-9A-Z -]+:)([a-z0-9A-Z -]+:)
```
- solution
```
cat passwd.fake | grep -E '^[a-z0-9]+88:([a-z0-9A-Z -]+:){4}.+$' | sed -E 's/^[a-z0-9]+88:([a-z0-9A-Z -]+:){4}.+$/\1/g'
```
- cleaner solution
```
sed -nE '/^[a-z0-9]+88:([a-z0-9A-Z -]+:){4}.+$/ s//\1/p' passwd.fake

```

backslash in sed:
\1 -> content of capturing group 1 
\2 -> content of capuring group 2

![[Pasted image 20260316152749.png]]

?: -> TRANSFORMS ( ) from capturing group to non-capturing group

6.
![[Pasted image 20260315211400.png]]
- choose UIDs
```
awk -F: '$3 ~ /^23[0-9]$/ {print $5}' 
-F: -> fields separated by ":"
$3 -> UID
/^23[0-9]$/ -> exactly 3 digits, starting with 23
{print $5} -> print full name
```

remove everything before the space:
```
s/^.* //
```

remove everything after the space:
```
s/-.*//
```

#### TEMPLATES:
"Remove everything after a pattern"
```
sed 's/pattern.*//'
```
-> ex: remove everything after the first dot:
```
sed 's/\..*//'
s/ -> serch
\..*/-> replace everything after literal dot ...
/ -> ... with nothing
```

"Remove everything before a pattern"
```
sed 's/^.*pattern//'
```
-> ex: extract the first name from Giurgiu Corina Maria => Corina Maria
```
sed 's/^.* //'
```

"Replace sth with sth else"
```
sed 's/old/new'
```
-> ex: convert "-" into space " "
```
sed 's/-/ /'
```

??
```
awk -F: '{print $5}' passwd.fake \
| sed 's/^.* //' \
| sed 's/-.*//'
```

??
```
sed -E 's/^.* ([^-]+)-.*/\1/'
```

## Lab 4 - 16 mar 2026

11. - Irina

![[Pasted image 20260316210106.png]]

Method 1:
- extract the second column (PID):
```
cat ps.fake | cut -d " " -f2 

cat ps.fake -> prints the file
cut -> extract a column
-d " " -> the separator is space
-f2 -> take field 2
```
problem: ps output has too many spaces
- replace multiple spaces with a single space
```
cat ps.fake | sed "s/ +/ /g" -E

sed -> edits text
s/../../  -> substitutes
+ -> one or more spaces
/ -> replace with one space
g -> do it for the whole line
-E -> enable extended regex ??

```
- extract PID after fixing spaces
```
cat ps.fake | sed "s/ +/ /g" -E | cut -d " " -f2
```
- remove empty lines
```
cat ps.fake | sed "s/ +/ /g"-E |  cut -d " " -f2 | sed "/^ *$/d"

^ -> beginning of line
* -> any number of spaces
$ -> end of line
d -> delete them
```
- remove header
```
cat ps.fake | sed "s/ +/ /g" -E |  cut -d " " -f2 | sed "/^ *$/d" | sed "/PID/d"
```
- put all numbers on one line
```
cat ps.fake | sed "s/ +/ /g" -E |  cut -d " " -f2 | sed "/^ *$/d" | sed "/PID/d" | xargs
```
- turn spaces into addition signs
```
cat ps.fake | sed "s/ +/ /g" -E |  cut -d " " -f2 | sed "/^ *$/d" | sed "/PID/d" | xargs | sed "s/ /+/g"
```
- calculate the sum
```
cat ps.fake | sed "s/ +/ /g" -E |  cut -d " " -f2 | sed "/^ *$/d" | sed "/PID/d" | xargs | sed "s/ /+/ g" | bc
```

bc = basic calculator
uniq -c => count
wc -
xargs -> puts all numbers on one line

Method 2. Using awk:
- we need the second column:
```
cat ps.fake | awk -f ex11.txt
```
- inside ex11.txt we have {print $2}
```
BEGIN {  // (runs before reading the file)
suma = 0  // sum of PIDs
count = 0  // nr of rows
}
{ // for each line ...
	suma +=$2 // add PID to the sum
}
END {
	print NR // nr of rows
	print suma // total of PIDs
	print suma/count // average PID
}
```
- run it:
```
mv ex11.txt ex11.awk
cat ps.fake | awk -f ex11.awk
```
- using command:
```
ps -ef | awk 'NR>1 {sum += $2; count++} END {print sum/count}'

NR>1 -> skip header
$2 -> PID column
sum +=$2 -> add PID
count++ -> count rows
END -> after processing
sum/count -> compute average
```
- NR = nr of rows
- NF = nr of fields

mv =  rename
mv ex11.txt ex11.awk

- average only for odd rows:
```
BEGIN {
   suma = 0
   count = 0
}

{
   if (NR % 2 == 1)
   {
      suma += $2
      count++
   }
}

END{
   print count
   print suma
   print suma/count
}
```
- average only if the first character is vowel
```
$1 ~ /^[aeiou]/ {}\

$1 -> first column
~ -> matches regex
/^[aeiou]/ -> line starts with vowel
^ -> beginning of word
[aeiou] -> any vowel
```
- ex11.awk:
```
  GNU nano 7.2                                                   ex11.awk
 BEGIN {
   suma = 0
   count = 0
}

{
   if(NR % 2 == 0 && $1 ~ /^[aeiou]/)
   {
     print $0
     suma += $2
   }

   #print $2
   #suma += $2
}

END{
   print NR
   print suma
   print suma/NR
}
```


Extra:
Show each login shell from cat /etc/passwd and out of these users who are allowed to log in in the system?
```
cat /etc/passwd | awk -f trabant.awk -F: 

-F: -> separator is :
$7 -> shell column
fr[$7]++ -> frequency vector: count each shell
for (i in fr)  print i, fr[i] -> print each shell and its count
```
- BEGIN is optional
- de cate ori apare fiecare shell
- e gol pt ca awk foloseste spatiu ca separator. 
- inside trabant.awk:
```
BEGIN {
	count=0
}
{
	fr[$7]++ // counts occurrences of each shell
}
END {
for (i in fr)
{
        count++ // counts how many distinct shells exist
        print i, fr[i] // prints shell count
        print count
}
}
```
- display the shell of every user:
```
{
print $7
}
```
- display the distinct shells used in the system:
```
{
fr[$7]++
}
END {
for (i in fr)
{
        print i
}
}
```

10.
![[Pasted image 20260316214356.png]]
- sa ramana r si sa sterg toate celelalte
- sed -> replace everything except r with nothing
- global mode at sed
```
cat passwd.fake | sed -E 's/[^r]//g' | sort | uniq
```

8.
![[Pasted image 20260316214514.png]]
```
cat ps.fake | grep -E "^r" | cut -d' ' -f1 | sort | uniq | sed -E 's/([aeiou])/\1\1/g'  
```

cat ps.fake | grep -E "^r"
![[Pasted image 20260316153215.png]]

7.
![[Pasted image 20260317101239.png]]
- using awk:
```
cat last.fake | awk '$1 ~ /^t/ && $2 == "pts/9" {print $1}' | sort | uniq
```
- using .awk nano file:
```
ex7.awk:

BEGIN {

}
{
        if ($1 ~ /^t/ && $2 == "pts/9")
        {
                print $1
        }
}
END {

}

```
- run it:
```
cat last.fake | awk -f ex7.awk | sort | uniq
```

9.
![[Pasted image 20260317101320.png]]
- using sed:
```
cat passwd.fake | sed -E 's/[a-z0-9A-Z ]//g' | sort | uniq

or

sed -E 's/[a-zA-Z0-9 ]//g' passwd.fake | sort | uniq

g-> globally apply on each line
```
- using awk:
```
cat passwd.fake | awk '{gsub(/[a-zA-Z0-9 ]/, ""); print}' | sort | uniq

gsub -> global substitution like sed s///g
```

## Seminar 2- 17 mar 2026

1) Shell = command line interpreter; 
- their role is to INTERPRET and provide a user interface to the OS kernel
- interactive command language - executes commands as you type them
- scripting language - beside regular commands, we can have scripts (text files with commands)
- run commands => scripts run by sb else
- emulator to connect to server - users interact via terminal emulators (ssh = secure shell is used for remote server access)
- script language
- any program runnable on computer - a shell is just a program that hides kernel details

2) Shell variants
sh (Bourne Shell) 
-> does not allow navigation or history on that line 
-> prompt is usually $ (user) or # (root)

bash (Bourne Again Shell) 
-> newer version of shell (i have the navigation history)
-> the prompt is more descriptive -> path $ or # 
-> autocomplete 
```
less f [TAB] -> autocompletes the filename, the common part
```
-> different colors for different file types (directories vs files)
-> C - shell (csh)
-> K - shell (ksh)

3) Core features
-  wildcards - similar to regular expressions
	- filename wildcarding (*, ?) helps select groups or files

- pipes -> interprocess communication
	- redirects the output of the left part to the input of the right part
	- output of left hand side
```
cat a.txt
```
- wanna scroll?
```
cat a.txt | less

creates an in-memory pipe mechanism that allows those two commands to communicate
```

ps -> processes (process status)
```
ps -ef -> every process with full details
ps -U 
```
- all processes with their ancestors (which processes created which)
```
ps -fax  -> processes in a tree format showing ancestors (parent-child relationships)
ps -aux  -> all processes running on system with user info
```

4) Redirection and Substitutions
- here docs (<<)
	- local document where we have
	- provide a local document/block of text to a command
```
command << EOF
command <<HERE
...
HERE
... -> local document given to the command
```

```
command << EOF
text here
EOF
```
- command substitution 
```
 $(command) or `command` -> executes the command and substitutes the output into the line
```
- quotes
'' -> single quotes -> literal strings -> everything is taken literally (preferred for regex)
"" -> double quotes -> allows variable expansion -> if regex contains $, it could create confusion

'$(command)' -> execute, will display result as it is -> it will display the characters (command)
"$(command)" -> command substitution -> substitute the part inside quotes with the output/result of that command (with the value of variables like $VAR of the result of command substitutions)

5) Development environment
variables
control structures -> allows branching, looping etc.
- paths 
```
/bin -> contains standard system commands
/usr/bin -> contains standard system commands
...
other files containing /bin
```
- custom commands -> any program that we create is also a command
```
int main() { return 0; }
a.c 

gcc a.c => a.out => execute it => also a command
gcc -Wall -o myp a.c => compiles c code into an executable named myp
```

```
gcc does not work with .cpp

int main() { return 0; }
a.cpp

g++ ... => used for .cpp files
```
- package managers
```
yum, apt -> for installing stuff
```

6) Scripts
SCRIPT = text file that contains Unix commands and shell directives
- .sh suffix -> naming convention for humans (interpreter knows it's a proper file for the compiler, meaning that Unix ignores extensions and looks directly at permissions/headers)
- readable, modifiable, easy to give as parameter to an interpreter
- In UNIX, no meaning of "extension": we can have a.b.c.d
- How to run a script:
```
prompt:
$ ls -> is found in /bin
$ a.out -> "command or filename not found" -> located in PATH -> absolute vs relative
PATH -> environment variable telling the shell where to look for commands
```

```
./a.out -> executes from the current folder (requires . in path or explicit path)

. -> current folder
/ -> path separator

../../a.out -> if a.out is in grandparent folder
```
- not recommended:
```
PATH ./
$ a.out
```

- if we have multiple a.out files, it executes the closest ones -> use either relative/absolute path to make sure you execute the correct file -> this is how the interpreter finds the files

- Redirections:
```
< -> input redirection
<< -> appending to input redirection
> -> output redirection (if does not exist, write it -> overwrites)
>> -> if output file exists, append to it
```

How to produce from C -> assembly code
- preprocessor directives?
- #include <stdio.h> -> editing step


SHELL vs C
shell -> interpreted (shell) because it interprets line by line, slower than sth that is from memory -> if you want to do sth not so many times, small (size)

c -> compiled (gcc) because it translates whole code at once -> do sth many times

STRUCTURE OF A SCRIPT - how to work with it:
- 1) first line directive telling the os which interpreter to use
```
#! -> SHEBANG -> directive given to shell
#! /bin/sh -> use this interpreter
#! /bin/bash -> use this interpreter (bash is better, newer)
```
- 2) arguments
```
echo Hello World -> receives two arguments (Hello and World)

echo "Hello World" -> receives one argument (the whole string)
```
- 3) give permission
- 4) run it
- 5) see result in terminal
- include comments in your scripts for the exam!
- variables
- assignment:
		- no space between identifier and "=" and before and after value
```
VAR=value
```
- access:
		- how to get this variable inside memory:
```
echo $VAR
```
- readonly variables:
		- prevents further changes
```
VAR="MyVar" -> readonly VAR
```
- delete the variable (release the memory -> like free with malloc)
```
unset VAR
```

1) local variables -> in functions
2) environment variables -> ex: PATH 
```
export VAR -> make variable global for child processes
xport VAR -> VAR becomes a global variable for every sub-process (child process) started from this shell
```
3) shell variables -> same meaning in any shell

- how to see all command variables?
```
printenv or env
```
when we get started with Putty:
```
.bashrc

/etc/environment -> place such commands
```

command line parameters in C:
```
int main() {}

int main(int argc, char argv[])
-> i have the argument count (argc, how many arguments)
-> i have the list of arguments as list of strings (argv)

int main(int argc, char **argv[])

int main(int argc, char **argv, char **envp)
-> envp holds environment variables
```

command line arguments
```
$1 - $9 -> command line arguments, positional arguments
${10}, ${11} -> braces required for double digits
newer shells -> continue after line between braces (${10}, ${11})
$0 -> name of the command being run, name of the script
$* -> all arguments
$@ -> all arguments
$? -> exit status of the last command (0=success)
return 0 -> success from the shell's perspective
```

shift (arguments to the left) -> with no parameter -> one argument to the left
	-> ex: shifts $2 into $1
```
./a.out
echo $?
```

7) Logic and Loops

REPLY -> default delimiter (space), default variable if no name is provided
READ command -> -d

message for the user, result put in that variable
```
read -p "Enter sth: " VAR
-> displays a message and saves input to VAR
```

Process Environment:
- standard way: ./script.sh -> shell creates a child process (a sub-shell) and the script runs there. when it's done, the child dies. if the script changed a directory (cd) or a variable, those changes disappear when you return to your main prompt
- the source way (source script.h or . script.sh) tells the current shell: "don't start a child, read these lines and execute them in here, in this memory space"
- if you want the changes made by the script (like cd or variable assignments) to persist in your current terminal session, then instead of ./script.sh use source or . :
```
sh.             script.sh
source.     script.
```
- How to run scripts in current shell:
```
source script.sh
. script.sh
-> changes persist in current terminal
```

- there are 3 spaces in there:
![[Pasted image 20260317152538.png]]

- conditionals:
```
`if [ $# -ne 1 ]; then ... fi` -> CORRECT

`if [$# -ne 1]; then ... fi` -> CRASH

[ ] -> alias for test; YOU MUST HAVE A SPACE AFTER [  AND A SPACE BEFORE ]
```

- loops:
```
for f in $(ls); do
    echo $f
done
```

8) Others:

- $() cause you are younger?
- how to create a 0 size file? using touch.
- \t\v -> all 3 are considered spaces ?

Count all lines of code in C files in the directory given as a command line argument, excluding lines that are empty or contain only blank spaces:
![[Pasted image 20260317153015.png]]
- S=0 (sum initialised with 0)
- f -> variable in this list 
- $1 first argument after the command main
- ; -> common separator not always?
- count the lines that are not empty
- ^ \t -> not space or horizonthal ... -> refers to regex used with grep -> targets lines starting with space or tab
- $f
- wc -l -> count the lines
- add to the sum the value of that variable
- do <-> done
- display
- double quotes whenever a variable might contain spaces or be empty
```
FILE="My Doc.txt" 
-> ls $FILE -> look for two files: "My" and "Doc.txt"
-> ls "$FILE" -> look for one file: "My Doc.txt"
```


- Brace expansion: creates all combinations that exist between those two sets (cartesian product) -> useful for creating many directories at once: mkdir -p
```
echo {A,B}{1,2} => A1 A2 B1 B2

```
![[Pasted image 20260317153232.png]]

- validate your arguments and give comments in exam! check nr of parameters, check their type.


## Lecture 4 - 18 mar 2026

1) Issue about having the same resource modified by two things (last lecture)
(n++) -> steps:
L - load n from memory to a register ; n is a variable; last time -> file
M - modify
S - store
```
mov ax, n
inc ax
mov n, ax
```
Issue: 
-> when 2 programs A and B run at the same time, program A might get interrupted after the "Load" or "Modify" step but before the "Store" step. 
-> program B then runs, reads the old value, increments it, saves it
-> when program A resumes, it saves its own version, accidentally overwriting Program B's work
-> = RACE CONDITION

| T (time) | A (program) | B (program) |
| -------- | ----------- | ----------- |
| 0        | L           |             |
| 1        |             | L           |
| 2        | M           |             |
| 3        |             | M           |
| 4        | S           |             |
| 5        |             | S           |
2) learn how to create processes in linux. using fork()
-> the only way to create a new process is by duplicating an existing process using fork()
- PARENT = ORIGINAL PROCESS
- CHILD = CLONE created by fork()
-> how to tell the difference:
- CHILD -> fork() returns 0
- PARENT -> fork() returns the PID (process id) of the new child
-> the child gets a full copy of the parent's memory at the moment of the fork()
-> child and parent are independent after the fork()
-> if child changes variable -> parent stays the same

What happens when you run a program:

fork instruction 
	- original -> parent -> PID -> needs to see the pid of the child
	- clone -> child? -> 0 = copy
	- returns a value
	- create a new process in Unix 
	- child gets copy of heap, stack, variables
every process can get its pid

3) ANATOMY OF A PROCESS:
- STACK 

| Context                                               |     |
| ----------------------------------------------------- | --- |
| Sources (you can think of it as Source Segment ASC)   |     |
| Constant                                              |     |
| Variables (you can think of them as global variables) |     |
| heap (down)                                           |     |
|                                                       |     |
|                                                       |     |
| stack (up)                                            |     |
|                                                       |     |

4) everything down from variables -> cloned
- nano code.c
```
#include <stdio.h> // needed for printf
#include <unistd.h> // needed for fork(), getpid() and getppid()
int main(int argc, char** argv) {
        printf("a %d %d \n",getpid(),getppid()); // return process id of the current process and parent process id (terminal/bash shell that started the program)
        fork(); // after this, we have two processes
        printf("b %d %d\n",getpid(),getppid()); // 
        (void) argc;
        (void) argv;
        return 0;
}
```
- run it in terminal
```
gcc -Wall -Wextra -Werror -g -o code code.c
./code
```
- result:
```
a 3075 2942 
b 3075 2942
b 3076 3075


a 3798 2887 
b 3802 3798
b 3799 3798
b 3800 3798
b 3798 2887
b 3804 3800
b 3801 1893
b 3803 1893
```

5) FORK BOMB:
- will become unusable (produces processes exponentially fast)
- pointless to "kill"
- tree
- result: system runs out of PID or memory => won't be able to run a simple kill command because the system can't start any more processes
```
while(1) {
	fork();
}
```

![[Pasted image 20260318183105.png]]

 - parent never executes exit()
 - everyone forks
 - i=0 => parent forks => 2 processes => both print "c"
 - i=1 => both fork => 4 processes => all 4 print "c"
 - i=2 => all 4 fork => 8 processes => all 8 print "c"
 - result: TREE OF PROCESSES
	 - exit() is not called => all children stay alive => fork on children
	 - produces processes exponentially fast
```
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
        printf("a %d %d \n",getpid(),getppid());
        for(int i=0; i<3; i++) {
                fork();
                printf("c %d %d %d \n",getpid(),getppid(),i);
        }
        printf("b %d %d\n",getpid(),getppid());
        (void) argc;
        (void) argv;
        return 0;
}
```

6) CONTROLLED CODE - CORRECT WAY to create 3 children
- parent only iterates 3 times
- recursive?? no.
- every process has its own i -> meaning that after the child (copy) is made, the two processes become independent 
	- ex: if the child changes i=5, the parent's i stays at 1
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char** argv) {
        printf("a %d %d \n",getpid(),getppid());
        for(int i=0; i<3; i++) { // exactly 3 children
                if(fork()==0) { // only the child can go inside here
                        printf("c %d %d %d \n",getpid(),getppid(),i);
                        exit(0); // child's job is done, dissapears now
                }
        }
        printf("b %d %d\n",getpid(),getppid());
        (void) argc;
        (void) argv;
        return 0;
}
```
- result:
```
a 12116 2887 
c 12117 12116 0 
c 12118 12116 1 
c 12119 12116 2 
b 12116 2887

```
- how to get a process:
```
while(1) {
	get request
	process
	respond
}

// maybe put SIG_IGN instead of f (ignore)
// SIG_DFL (default)
signal(SIGCHILD,f); // added
while(1) {
	get request
	if (fork()==0) {
		process
		respond
		exit(0)
	}
	//wait -> the parent will stay here until the child finishes, not getting any new request; you call wait only when you know the process finished (cause it's right there??)
}

// maybe give this up 
void f(int sgn) {
	wait(0);
}
```

3) Zombie process
- when a child process finishes (exit(0)), it does not disappear immediately
	- system keeps the child's exit code and PID in the process table so that the parent can read them -> ps ->defunct
	- solution: parent must call wait(0) -> allows the system to delete the zombie and reuse its PID
- deleted child -> keep its pid, then cleans the process?
- parents wait for children to finish execution
- wait() returns error if there are no child processes
- zombies are bad -> if you have a server that creates thousands of children but never "waits" for them, the system will eventually hit its process limit -> can't start anything new
```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char** argv) {
        printf("a %d %d \n",getpid(),getppid());
        for(int i=0; i<3; i++) {
                if(fork()==0) {
                        printf("c %d %d %d \n",getpid(),getppid(),i);
                        exit(0);
                }
        }
        for(int i=0; i<3; i++) { // 3 times because i created 3. 
                wait(0);
        }
        printf("b %d %d\n",getpid(),getppid());
        (void) argc;
        (void) argv;
        return 0;
}


```
- result:
```
a 12804 2887 
c 12805 12804 0 
c 12806 12804 1 
c 12807 12804 2 
b 12804 2887
```

```
while true; do ps -u mia-giurgiu | grep -E "\./b|defunct"; sleep(1); clear; done
```

- run in terminal
```
./b
```
- if the processes are all "zombied up" you cannot add more processes

4) Interrupts and Signals
Signals -> "software interrupts" -> force process to stop -> run special function called "handler"
- wires = interrupts -> designed to signal "division by 0"
- software interrupts -> not through wires, but through sth else (signals)
- ex: ctrl+c -> sends a signal to the process -> "STOP" -> stop the processes execution -> execute the code associated to ctrl+c
- signal does not signal
- send a signal -> use kill -> function kill

SIGINT (2): sent when I press CTRL+C => stops program
SIGKILL(9): kernel kills the process
SIGCHILD: sent to parent automatically whenever a child process stops or terminates
signal() -> "when you sent me SIGINT, don't kill me - run my function f instead"

```
cat
ctrl+z
bg
```

- program that does stuff with signals:
```
  GNU nano 7.2                         signals.c                                   
#include <stdio.h>
#include <signal.h>

void f(int sgn) {
        printf("you wish...\n");
        (void)sgn;
}

int main(int argc, char** argv) {
        signal(SIGINT,f);
        while(1);
        (void)argc;
        (void)argv;
        return 0;
}
```

- to see the processes -> take that_number
```
ps -u mia-giurgiu
```
- kill that_number
- SIGKILL
- value 9???
- kill -9 that_number

## Lecture 5 - 25 mar 2026

- system calls (apeluri de system)
- 1. execlp -> no need for absolute path
- 2. execvp -> no need for absolute path
- 3. execv -> array -> call that function
- 4. execl -> array -> call that function
PATH -> environment variable telling the shell where to look for commands
how to see environment variables:
```
env
```

1) This code demonstrates **process branching**.
- **`fork()`** creates a duplicate child process.
- In the **child**, **`execl()`** replaces the running code with `/bin/echo` to print "C".
- The **parent** continues independently, printing "B", then uses **`wait()`** to pause until the child finishes.

code1.c:
```
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
        printf("A %d\n", getpid());
        execl("/bin/echo", "/bin/echo", "C", NULL);
        printf("B %d\n", getpid());
        (void)argc;
        (void)argv;
        return 0;
}
```

result:
```
A 12326
C

```

```
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
        printf("A %d\n", getpid());
        if (fork()==0) {
	        if(execl("/bin/echo", "/bin/echo", "C", NULL)<0) {
		        perror("execl did not work");
		        exit(1);
	        }
        }
        printf("B %d\n", getpid());
        wait(0);
        (void)argc;
        (void)argv;
        return 0;
}
```

```
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
        printf("A %d\n", getpid());
        if (fork()==0) {
	        if(execl("/bin/ls", "/bin/ls", "C", "-a", "/sadfif", NULL)<0) {
		        perror("execl did not work");
		        exit(1);
	        }
        }
        printf("B %d\n", getpid());
        wait(0);
        (void)argc;
        (void)argv;
        return 0;
}
```


```
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
        int p2a[2],a2b[2],b2p[2],n;
        
        pipe(p2a);
        pipe(a2b);
        pipe(b2p);
        
        // A child -> closes the borders it does not need asap
        if(fork()==0){
	        close(p2a[1]);
	        close(a2b[0]);
	        close(b2p[0]);
	        close(b2p[1]);
	        while(1) {
		        if(read(p2a[0],&n,sizeof(int))<=0) break;
		        if(n<=0) break;
		        printf("A: %d\n",n);
		        n--;
		        write(a2b[1],&n, sizeof(int));
	        }
	        close(p2a[0]);
	        close(a2b[1]);
	        exit(0);
        }
        
        // B child
        if (fork() ==0) {
	        close(p2a[0]);
	        close(p2a[1]);
	        close(a2b[1]);
	        close(b2p[0]);
	        while(1) {
		        if(read(a2b[0],&n,sizeof(int))<=0) break;
		        if(n<=0) break;
		        printf("A: %d\n",n);
		        n--;
		        write(b2p[1],&n, sizeof(int));
	        }
	        close(a2b[0]);
	        close(b2p[1]);
	        exit(0);
	    }
	    
	    close(p2a[0]);
	    close(a2b[0]);
	    close(a2b[1]);
	    close(b2p[1]);
	    n=7;
	    while(1) {
		    if(read(b2p[0],&n,sizeof(int))<=0) break;
		    if(n<=0) break;
		    printf("A: %d\n",n);
		    n--;
		    write(p2a[1],&n, sizeof(int));
	    }
	    close(a2b[0]);
	    close(b2p[1]);
	    wait(0);
	    wait(0);
        (void)argc;
        (void)argv;
        return 0;
}

```

```
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
        int a[4]={1,2,3,4};
        // p[2];
        // pipe(p);
        if(fork()==0) {
	        a[2]+=a[3];
        }
        (void)argc;
        (void)argv;
        return 0;
}

```


## Lab 5 - 26 mar 2026

![[Pasted image 20260326102915.png]]


![[Pasted image 20260326103621.png]]

![[Pasted image 20260326104731.png]]

![[Pasted image 20260326104819.png]]

![[Pasted image 20260326105141.png]]


![[Pasted image 20260326105339.png]]

remove coma at the end:
![[Pasted image 20260326105357.png]]

another method: ![[Pasted image 20260326105513.png]]

![[Pasted image 20260326110432.png]]


![[Pasted image 20260326110459.png]]

![[Pasted image 20260326110539.png]]


![[Pasted image 20260326111732.png]]


![[Pasted image 20260326112309.png]]


![[Pasted image 20260326112622.png]]

![[Pasted image 20260326113001.png]]


watch n 05
![[Pasted image 20260326113717.png]]


![[Pasted image 20260326113728.png]]

![[Pasted image 20260326114237.png]]

![[Pasted image 20260326114650.png]]

### Shell problems 
1.
![[Pasted image 20260330102249.png]]

```
#!/bin/bash
currentlyConnected=$(cat who.fake | cut -d' ' -f1 | sort | uniq)
#echo "$currentlyConnected"
#echo '$currentlyConnected' 
#echo $currentlyConnected  
for userLI in $currentlyConnected; do
        numeComplet=$(grep "$userLI" passwd.fake | cut -d':' -f 5)
        numarProcese=$(grep "^$userLI" ps.fake | wc -l)
        echo "$userLI $numeComplet $numarProcese"
done
```

2.
![[Pasted image 20260330102353.png]]

```
!/bin/bash
if [ $# -lt 1 ]; then
        echo "Insufficient arguments"
        exit 1
fi
count=2
while IFS=read -r f; do
        if [ $(wc -l < "$f") -gt 500 ]; then
                echo "$f"
                count=$((count-1))
                if [ $count -eq 0 ]; then
                        break
                fi
        fi
done < <(find  "$1" -type f -name "*.c")
```

3.
![[Pasted image 20260330103351.png]]

```
#!/bin/bash
if [ $# -eq 0 ]; then
        echo "No args given"
        exit 1
elif [ $# -eq 1 ]; then
        if [ -d "$1" ]; then
                directory="$1"
        else
                echo "We need an existing directory"
                exit 1
        fi
else
        directory='./'
fi
#echo "$directory"
files=($(find "$directory" -name "*.log"))
echo "${files[@]}"
for file in "${files[@]}"; do
        sort $file -o $file
done
echo
echo "${files[@]}"
```

4.
![[Pasted image 20260330104223.png]]
```
#!/bin/bash

if [ $# -eq 0 ]; then
        echo "We need arguments"
elif [ $# -eq 1 ]; then
        if [ -d "$1" ]; then
                directory="$1"
        else
                echo "We need existing directory"
                exit 1
        fi
else
        directory='./'
fi
paths=($(find "$directory"))
#echo "${paths[@]}"
for path in "${paths[@]}"; do
        echo "Checking: $path"
        if [ -L "$path" ]; then
                echo " symlink"
                if ! [ -e "$path" ]; then
                        echo " broken -> $path"
                fi
        fi
done

```

5.
![[Pasted image 20260330105242.png]]

```
#!/bin/bash
if [ $# -eq 1 ]; then
        danger=$1
else
        echo 'Give the name of the dangerous program as an argument'
        exit 1
fi

while ((1>0)); do
        processes=($(ps -ef | grep "$danger" | awk '{print $2}' | head -n -3))
        echo "${processes[@]}"
        for pr in "${processes[@]}"; do
                if [ $$ != $pr ]; then
                        echo "$danger" was killed
                        kill "$pr"
                fi
        done
        sleep 1
done
```

6.
![[Pasted image 20260330105929.png]]

```
#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Give exactly one directory"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "The argument must be a directory"
    exit 1
fi

for file in $(find "$1" -type f -perm -222); do
    before=$(stat -c "%A" "$file")
    echo "$file : before = $before"

    chmod a-w "$file"

    after=$(stat -c "%A" "$file")
    echo "$file : after  = $after"
done  
```

7.

![[Pasted image 20260330110942.png]]

```
#!/bin/bash
email=""
while read i; do
        grep -q "^$i:" passwd.fake
        if [ $? -eq 0 ]; then
                emailAddress="$i@scs.ubbcluj.ro"
                emails="$emails$emailAddress,"
        fi
done <theFisier
echo $emails | head -c -2
echo
```

8.

![[Pasted image 20260330112407.png]]

solve8.awk
```

        # awk automatically treats 476M as 476 and 82% as 82
        # when used in a numeric comparison
        size_mb=$2+0
        use_percent=$5+0
        # condition 1: smaller than 1gb (1024 mb)
        # condition 2: less than 20% free space (use>80%)
        if (size_mb < 1024 || use_percent > 80){
                print $6
        }
}
```

USAGE IN TERMINAL:
cat df.fake | awk -f solve8.awk

9.

![[Pasted image 20260330112722.png]]

```
#!/bin/bash
# check arguments
if [ $# -eq 0 ]; then
        directory="." # set current working directory
elif [ $# -eq 1 ]; then
        if [ -d "$1" ]; then
                directory="$1"
        else
                echo "We need an existing directory!"
                exit 1
        fi
else
        echo "Too many arguments!"
        exit 1
fi
# find all regular files
allFiles=$(find "$directory" -type f)

# compute checksum + size + path for every file
fileData=$(while read -r file; do
        cksum "$file"
done <<< "$allFiles")

# take only the checksum and size pairs that appear more than once
duplicateKeys=$(echo "$fileData" | awk '{print $1, $2}' | sort | uniq -d)
echo "Files that have duplicates:"
# for every duplicate checksum, display all file paths having that checksum
while read -r sum size; do
        echo  "---"
        echo "$fileData" | awk -v s="$sum" -v sz="$size" '$1==s && $2==sz {prin>
done<<<"$duplicateKeys"

```

10.

![[Pasted image 20260330114122.png]]

```
#!/bin/bash
sessionSnapshot=$(cat last.fake)
#echo "$sessionSnapshot" | sed -E 's/ +/ /g' | cut -d ' ' -f 4
#echo "$sessionSnapshot" | awk '{print $4}'
theUsers=$(while read  i; do
        #echo "$i"
        ziuaJoined=$(echo $i | awk '{print $4}')
        #echo "$ziuaJoined"
        if [ "$ziuaJoined" = "Sun" ]; then
                echo "$i" | grep -o -E "^[^ ]+ "
        fi
done <<< "$sessionSnapshot" | sort | uniq)
for userI in $theUsers; do
        numberSessions=$(echo "$sessionSnapshot" | grep "^$userI " | wc -l)
        theFullName=$(grep "^$userI" passwd.fake | cut -d':' -f 5)
        echo "$numberSessions $userI $theFullName"
done | sort -n -r -k 1

```
## Lab 6 - test

## Lab 7 - 6 apr 2026

1) How many processes does this have? What is the flow graph for it? Draw them. 8.
stackoverflow alex kiraly: does wait do anything when called from both processes careated from fork?
fork()
fork()
wait(0)
fork()
wait(0)

- fork() duplicates a new process (new identic copy)
- execution continues after fork()
- wait(0) default - if it is created by child, does not do anything (means child has no other children) behave differently depending on wether there are children or not -> wait dictates ho many processes, not their order
- after two forks -> 4 processes
- fork() needs library unistd
- pid_t
- fork() return type is pid_t

official solving:
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {

        perror("Please provide exactly one argument");

        exit(1);

    }

    int n = atoi(argv[1]);

    for(int i = 0; i < n; i++) {

        int f = fork();

        if(-1 == f) {

            perror("Error on fork");

        } else if(0 == f) {

            printf("Child process %d - PID: %d - PPID: %d\n", i, getpid(), getppid());

            exit(0);

        } else {

            printf("Parent %d - Child: %d\n", getpid(), f);

        }

    }

    for(int i = 0; i < n; i++) {

        wait(NULL);

    }

    return 0;

}

```


pr1.c (lab solution)
```
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main() 
{
	int n=3;
	// pid urile copiilor intr ul array
	pid_t copiiiMei[3]={0};
	for(int i=0; i<n; i++)
	{
		// fork(); // 2^3 processes
		pid_t theCopil=fork();
		if(theCopil==0)
		{
			printf("Copil: %ld %ld\n", getpid(), getppid());
		}
		else
		{
			copiiiMei[i]=theCopil;
		}
	}
	printf("Parinti: %ld - ", getpid());
	for(int i=0; i<n; i++)
	{
		prinf("%ld, ", copiiiMei[i]);
	}
	printf("\n");
	// exit la copil
}
```

corrected (lab solution):
```
#include <unistd.h> // fork(), getpid(), getppid()
#include <stdio.h> // printf
#include <stdlib.h> // exit()
int main()
{
	int n = 3;
	
	pid_t copiiMei[3] = {0}; // array ot type pid_t
	for (int i=0; i < n;i++) // loops 3 times to create 3 children
	{
		pid_t theCopil = fork();
		if (theCopil == 0)
		{
			printf("C: %ld %ld\n", getpid(), getppid());
			exit(0);
		}
		else
		{
			copiiMei[i] = theCopil;
		}
	}

	printf("P %ld - ",getpid());
	for (int i=0; i < n;i++)
	{
		printf("%ld, ",copiiMei[i]);
	}
	printf("\n");
}
```

pr3.c
3. Write a C program that creates a child process. Both the parent and the child processes will run until they receive a SIGUSR1 signal. Implement signal handling such that if the parent receives the SIGUSR1 signal first, it sends it to the child process as well. If the child process receives a SIGUSR1 signal without the parent receiving the same signal, it will terminate and then the parent should correctly call wait for the child process.  

- both processes will run until receiving signal SIGUSR1
- signal handler
- default if you don't have signal handler -> kill process
- there is a file somewhere in linux that: linux/include/uapi/asm-generic/signal.h
- how to instal signal handler in both processes
- you don't know from whom you receive the signal from (THAT'S THE PROBLEM)
- how do identify child receives signal but parent doesn't?
- maybe the child should receive SIGUSR2
- their implementation might not make sense at first sight
- maybe install signal handler after.
- man 3p kill -> synopsis

lab solution
```
#include <unistd.h>
#include <signal.h>
#include <syswait>
pid_t theCopil; // global variable
void branza(int semnal)
{
	if(semnal == SIGUSR1)
	{
		if(theCopil==0)
		{
			// setam flag de exit
		}
		else
		{
			kill(theCopil, semnal);
		}
	}
}
int main() 
{
	signal(SIGUSR1, branza);
	theCopil = fork();
	//getchar(); // waits tfor you to write stuff from keyboard
	sleep(60); // you can't fall back asleep once you've been woken up
	
	if( theCopil != 0)
	{
		sleep(60);
		wait(0);
		//signal(SIGUSR2, branza);
	}
	else
	{
		sleep(60);
		signal(SIGUSR1, branza);
		wait(0);
	}
}

```

official solution:
```
/*
 * Create a child process.
 * Both the child and parent processes will "work" an indefinite amount of time.
 * Implement a mechanism such that when the parent terminates, the child process also terminates without creating zombie processes.
 */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int f;
void child_handler(int sig) {
  printf("Child process terminating...\n");
  exit(0);
}

void parent_handler(int sig) {
  printf("Parent process terminating...\n");
  kill(f, SIGUSR1);
  wait(0);
  exit(0);
}

void zombie_handler(int sig) {
    printf("Parent waiting for child process to terminate\n");
    wait(0);
}

int main(int argc, char **argv) {
  f = fork();
  if (-1 == f) {
    perror("Error on fork");
  } else if (0 == f) {
    signal(SIGUSR1, child_handler);
    printf("C - Child PID: %d Parent PID: %d\n", getpid(),getppid());
    while(1) {
      printf("Child working...\n");
      sleep(3);
    }
    exit(0);
  } else {
    signal(SIGUSR1, parent_handler);
    signal(SIGCHLD, zombie_handler);
    printf("P - Child PID: %d Parent PID: %d\n", f, getpid());
    while(1) {
      printf("Parent working...\n");
      sleep(2);
    }
  }
  return 0;
}

```

pb5:
 Write a C program that implements the boltz game. Exactly N processes (numbered 1 to N, where N is given) take turns incrementing a number, starting from 1, and sending it to the next process. Process 1 starts the game by incrementing the number and sends it to process 2, which increments and sends it to process 3 and so on. Process N will send the number back to process 1, ant the cycle starts again. Each process must print the number it sends, unless the number contains the digit 7 or is divisible by 7, in which case it must print "boltz". Implement so that each process has a 1 in 3 chance to fail printing "boltz" when it should, in which case the game stops.

official solution with recursion:
```
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

// self-explanatory function name
// functie cu nume sugestiv
int contains_7_or_is_multiple_of_7(int nr) {
    if(nr % 7 == 0) {
        return 1;
    }
    while(nr > 0) {
        if(nr % 10 == 7) {
            return 1;
        }
        nr = nr / 10;
    }
    return 0;
}

// Definim o functie care va gestiona atat crearea de noi procese cat si partea de joc;
// -- Partea de joc poate fi extrasa intr-o alta functie pentru o mai buna organizare a codului;
// Pasam functiei un sir de pipes, un index si numarul N
// index va fi folosit atat ca o variabila prin care controlam cate procese sunt create, cat si ca un ID
// pentru fiecare proces, pentru a putea identifica cu care pipe(s) va interactiona
//
// Define a function that will manage both child process creation as well as playing the game;
// -- The game playing could be extracted in its own function for a cleaner code;
// We pass to the function an array of pipes, an index and the number N
// index will serve as a way to limit the number of processes to be created, as well as an ID
// for each process, to determine with which pipe(s) it will interact
void fork_and_communicate(int pipes[][2], int index, int n) {
    // verificam daca mai putem crea inca un proces
    // check if we can create one more process
    if (index + 1 < n) {
        // daca da, incercam sa cream inca un proces
        // if yes, try to create one more process
        int f = fork();
        if (0 > f) {
            // oh no, an error
            perror("Error on creating child");
            return;
        } else if (0 == f) {
            // procesul fiu este responsabil sa apeleze recursiv functia,
            // incrementand parametrul index ca sa contorizam cate procese au fost create
            // the child process must call recursively the function,
            // incrementing the index parameter so we can keep track of how many processes were created
            fork_and_communicate(pipes, index + 1, n);
            return;
        }
    }
    // indiferent daca procesul curent trebuie sa creeze un proces nou sau nu, trebuie sa participe la joc
    // regardless if the current process must create a new process, if definitely has to play the game
    int nr = 1, i;
    // folosim index pe post de ID in proces
    // use index as an ID in the process

    // impunem ca un proces sa citeasca din pipes[index][0] si sa scrie in pipes[index+1][1]
    // impose that a process reads from pipes[index][0] and writes to pipes[index+1][1]
    int read_idx = index % n;
    // modulo n trateaza cazul ultimului proces, cu index == n - 1, care trebuie sa comunice cu procesul initial, cu index == 0
    // modulo n handles the case of the last process, where index == n - 1, which must communicate with the original process, where index == 0
    int write_idx = (index+1) % n;
    // inchidem toate canalele de comunicare cu exceptia pipes[index][0], pipes[index+1][1]
    // close all pipes except pipes[index][0], pipes[index+1][1]
    for (i = 0; i < n; i++) {
        if(i == read_idx) {
            close(pipes[i][1]);
        } else if (i == write_idx) {
            close(pipes[i][0]);
        } else {
            close(pipes[i][0]);
            close(pipes[i][1]);
        }
    }
    // consideram ca procesul original porneste jocul
    // consider that the initial process starts the game
    if(index == 0) {
        printf("%d - start\n", nr);
        if(0 > write(pipes[write_idx][1], &nr, sizeof(int))) {
            perror("Error on writing number");
        }
    }
    // fiecare proces joaca pana cand conditia de esuare se indeplineste
    // each process plays until the fail condition is met
    while(nr >= 1) {
        if(0 > read(pipes[read_idx][0], &nr, sizeof(int))) {
            perror("Error on reading number");
        }
        // jocul porneste de la 1, consideram ca daca numarul este egal cu 0, trebuie sa incheiem
        // the game starts from 1, consider that if the number is equal to 0, we should stop
        if(nr != 0) {
            nr++;
            // alegem un numar random dintre 0, 1, 2
            // pick a random number from 0, 1, 2
            int success = random() % 3;
            // verificam daca avem conditie de boltz
            // check if the boltz condition is true
            if(contains_7_or_is_multiple_of_7(nr)) {
                // daca da, verificam rezultatul de la random, daca este 0 -> procesul va "gresi" si jocul se incheie
                // if yes, we check the result from random, if it is 0 -> the process will make a "mistake" and the game ends
                if(!success) {
                    printf("%d - fail\n", nr);
                    nr = 0;
                } else {
                    printf("Boltz!\n");
                }
            } else {
                printf("%d\n", nr);
            }

            if(0 > write(pipes[write_idx][1], &nr, sizeof(int))) {
                perror("Error on writing number");
            }
        } else {
            // in caz de incheiere, procesul curent este singurul care are un canal de comunicare deschis cu procesul index + 1, deci este responsabil de propagarea mesajului de stop
            // if it is time to close, the current process is the only one that has an open pipe to process index + 1, so it is responsible of propagating the stop message
            if(0 > write(pipes[write_idx][1], &nr, sizeof(int))) {
                perror("Error on writing number");
            }
            break;
        }
    }
    wait(0);
    // inchidem restul de canale
    // close the rest of the pipes
    close(pipes[read_idx][0]);
    close(pipes[write_idx][1]);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Provide an integer argument!\n");
        exit(1);
    }
    int n = atoi(argv[1]), i;
    // folosim un sir de pipes, fiecare pereche de pipes consecutive ar trebui sa asigure ca un proces poate citi numarul si poate sa scrie numarul
    // use an array of pipes, each pair of consecutive pipes should ensure that a process can read the number and can write the number
    int pipes[n][2];
    for (i = 0; i < n; i++) {
        if (0 > pipe(pipes[i])) {
            perror("Error on opening pipe");
            exit(1);
        }
    }
    srandom(time(NULL));
    fork_and_communicate(pipes, 0, n);
    return 0;
}
```

official solution without recursion:
```
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int contains_7_or_is_multiple_of_7(int nr) {
    if(nr % 7 == 0) {
        return 1;
    }
    while(nr > 0) {
        if(nr % 10 == 7) {
            return 1;
        }
        nr = nr / 10;
    }
    return 0;
}

void play(int pipes[][2], int index, int n) {
    int nr = 1, i;
    int read_idx = index % n;
    int write_idx = (index+1) % n;
    for (i = 0; i < n; i++) {
        if(i == read_idx) {
            close(pipes[i][1]);
        } else if (i == write_idx) {
            close(pipes[i][0]);
        } else {
            close(pipes[i][0]);
            close(pipes[i][1]);
        }
    }
    if(index == 0) {
        printf("%d - start\n", nr);
        if(0 > write(pipes[write_idx][1], &nr, sizeof(int))) {
            perror("Error on writing number");
        }
    }
    while(nr >= 1) {
        if(0 > read(pipes[read_idx][0], &nr, sizeof(int))) {
            perror("Error on reading number");
        }
        if(nr != 0) {
            nr++;
            int success = random() % 3;
            if(contains_7_or_is_multiple_of_7(nr)) {
                if(!success) {
                    printf("%d - fail\n", nr);
                    nr = 0;
                } else {
                    printf("Boltz!\n");
                }
            } else {
                printf("%d\n", nr);
            }

            if(0 > write(pipes[write_idx][1], &nr, sizeof(int))) {
                perror("Error on writing number");
            }
        } else {
            if(0 > write(pipes[write_idx][1], &nr, sizeof(int))) {
                perror("Error on writing number");
            }
            break;
        }
    }
    wait(0);
    close(pipes[read_idx][0]);
    close(pipes[write_idx][1]);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Provide an integer argument!\n");
        exit(1);
    }
    int n = atoi(argv[1]), i;
    int pipes[n][2];
    for (i = 0; i < n; i++) {
        if (0 > pipe(pipes[i])) {
            perror("Error on opening pipe");
            exit(1);
        }
    }
    srandom(time(NULL));
    for(i = 0; i < n; i++) {
        int f = fork();
        if(f < 0) {
            perror("Oh no my child!");
        } else if (f > 0) {
            //break in the parent so we don't create more processes;
            break;
        } else {
        // let the child run one for cycle so it creates another child
        // after it creates the child, it will also break from the for
        }
    }
    if(i < n)
        play(pipes, i, n);
    return 0;
}
```

lab solution:
- construct a binary hierarchical structure 
- for each fork we need to keep in mind the parents above using an array
- how to keep in mind the process number. can we calculate how many processes we have up till now? 
- when creating -> 2k+1 is the child if 2k is the parent
- how to find out they are the last nodes? makes no sense bc all will come to an end
	fork();
	fork();
	fork(); // 8 processes
	fork();
	fork(); // 32 processes (2^5 forks)
```
#include <unistd.h>
#include <stdio.h>
int main()
{
	int ier = 0;
	pid_t levelIerarhie[10]={0};
	
	int lastNode=0;
	
	lev[ier++]=getppid();
	for(int i=0; i<5; i++)
	{
		// how to keep in mind the process number
		pid_t copil = fork();
		lev[ier]=getpid();
		ier++;
	}
	for(int i=1; i>=0; i--)
	{
		printf("%d ", lev[i]):
	}
	printf()
}
```

22. Write a C program that creates 10 child processes and synchronizes their execution. Each process will sleep for 1 second and then exit. Time the execution of the processes. (If all goes well, the total time should be a little over 10 seconds).
- create all, first process 
- writes value from variable k into a file - similar to that problem form the lecture.
- page 28 ex 3 -> teaching notes
lab solution without semafoare:
```
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <syswait>
#incude <stdio.h>

int childCount = 0;
void signalHandlerCreated(int semnal)
{
	is(semnal==SIGUSR1)
	{
		childCount++;
		if(childCount==10)
		{
			printf("Toti copiii buni\n");
		}
	}
}
int main() 
{
	signal(SIGUSR1, signalHandlerCreated);
	for(int i=0; i<10; i++)
	{
		pid_t child = fork();
		if( child == 0)
		{
			printf("Child created %ld\n", getpid());
			sleep(i*2); // we are in a child
			//signal();
			kill(getppid(), SIGUSR1));
			printf("Child notified parent: %ld\n, getpid());
			while(flag==0)
			{
				sleep(1);
			}
			exit(0);
		}
		else
		{
			;// continue kidding
		}
	}
	for(int i=0; i<10; i++)
	{
		wait(0);
	}
}

```


official solution:
```
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <semaphore.h>

int main(int argc, char *argv[]) {
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    int i;
    // the semaphore can be used to synchronized processes, not just threads
    // the condition is that the same semaphore can be accessed by all the processes
    // since after fork, the child process has copies of everything the parent had until the fork, we can't simply create a semaphore and use it
    // we will instead create a shared memory segment in the parent and place the semaphore there
    // the child processes will inherit copies of the shared memory ID, but the shared memory space will remain the same
    // se we can safely say that the semaphore placed inside the shared memory segment is the same for all processes
    sem_t *sem;
    // generate a key first so we can create a shared memory segment
    // ftok creates a key based on a file path and a number
    // the file has to exist on the system where the program is run, and the same combination of filepath + number must be provided by all the processes that want to access the same shared memory segment
    key_t shmkey = ftok("/dev/null", 24);
    // using the generated key, we create a shared memory segment big enough to contain one semaphore
    // we also grant read permissions to everyone
    // the IPC_CREAT flag indicates that the shared memory segment must be created if it does not exist
    int shmid = shmget(shmkey, sizeof(sem_t), 0644|IPC_CREAT);
    // we now link the shared memory segment to the previously declared pointer
    sem = (sem_t*) shmat(shmid, NULL, 0);
    // from here on, we treat this semaphore pointer as we would treat a regular semaphore pointer that is declared on the heap
    sem_init(sem, 1, 1);

    // we create processes
    for (i = 0; i < 10; i++) {
        int f = fork();
        if (f < 0) {
            perror("Oh no! Anyway...");
        } else if (f == 0) {    
            // each child locks the semaphore before sleeping
            sem_wait(sem);
            sleep(1);
            // and unlocks it once it is done
            sem_post(sem);
            exit(0);
        }
    }

    for (i = 0; i < 10; i++) {
        wait(0);
    }
    // destroy the semaphore
    sem_destroy(sem);
    // remove the link between the semaphore pointer and the shared memory space
    shmdt(sem);
    // delete the shared memory segment, so that memory can be used by other processes freely
    shmctl(shmid, IPC_RMID, 0);
    gettimeofday(&tv2, NULL);
    printf("Total time = %f seconds\n", (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec));

    return 0;
}
```


next lab -> pipe, fifo, exec 

## Lecture 6 - 
Processes
## Lecture 7 - 8 apr 2026
Threads

1) work with shared memory. how can we have a piece of memory mapped in a ??
- shared memory will have a number that will be unique in the system
- 644 - default permissions
- give permissions only to yourself!
- problem: instead of creating an array of bytes, use a structure because we want to work with integers, strings etc. 
command line:
```
ipcs
ipcmk

ipcmk -M 10 => 10 kilobytes
```

2) how to delete a shared memory/ipc?
```
ipcrm
```

3) create a structure used by both programs - header file
- key, size, flags
- shmget, shmat, shmdt, shmctl
- one of the programs creates, the other uses
a.h
```
#include <stdio.h>
#include <sys/shm.h>

struct absp {
	int a;
	int b;
	int s;
	int p;
}
```

b.c
- permissions, flags, size
- the other program will keep calculating the sum and the product??
- 1234 = identifier of the ipc
- IPC_CREAT -> if it does not exist, create it
- 0600 -> set permissions to it
- not like fifo which waited for ... 
```
#include <stdlib.h>
#include "a.h"

int main(int argc, char** argv) {
	int shm = shmget(1234, sizeof(struct absp), IPC_CREAT | 0600); // like a file handler
	struct absp* x = shmat(shm, 0, 0); // pointer to this area of shared memory
	
	x->s = 1;
	x->p = 2;
	while(1) {
		x->a = rand();
		x->b = rand();
		if(x->s == x->p) break;
	}
	
	shmdt(x);
	shmctl(shm, IPC_RMID, NULL);

	(void)argc;
	(void)argv;
	return 0;
}
```

- %1000 somewhere 
```
#include "a.h"

int main(int argc, char** argv) {
	int shm = shmget(1234, 0,0);
	struct absp* x = shmat(shm, 0, 0); // pointer to this area of shared memory
	
	while(1) {
		x->s = x->a + x->b ;
		x->p = x->a * x->b;
		printf("%d + %d = %d.    %d * %d = %d\n", x->a, x->b, x->a + x->b, x->a, x->b, x->a * x->b);
		if(x->s == x->p) break;
	}
	
	shmdt(x);
	shmctl(shm, IPC_RMID, NULL);

	(void)argc;
	(void)argv;
	return 0;
}
```

- printed 989 instead of 1000 -> race condition -> n++ previous lectures
- optimisation changes order of executions?
- run with optimisation 
- syncronization mechanisms - mutex
- pthread_mutex_init
- pthread_mutex_lock(&m) and unlock
- atomic/non-atomic
- n++ might not be atomic on each processor
- do n++ on local, not global, turn to global only after computation at local

Conclusion: syncronisation makes things correct, but slow. 
fast result+correct: n+=(int)(long)a; and comment everything else in f except return NULL.

### Individual work after Lecture 7
Process = separate memory
Thread = same process, same memory, multiple execution paths

0) Shared memory (IPC shared memory)
- two different programs can access the same region of memory using:
	- shmget = create/get shared memory
	- shmat = attach shared memory to my process
	- shmdt = detach shared memory from my process
	- shmctl = control/delete shared memory
- shared memory objects live in the OS until deleted:
	- ipcs = shows all the shared memory objects
	- ipcrm = deletes all the shared memory objects
		- if you forget to ipcrm, the OS can refuse to create new IPCs later
- shared memory gives common data, not coordination => two processes may read/write at the wrong moment => shared memory without sync is guaranteed to cause trouble

1) Threads
- roommates in the same apartment: same house, different actions, shared fridge, possible chaos
- cheaper to create
- easier to communicate with
- easier to break because they share variables
- threads share memory naturally 
- threads are created with **pthread_create**
- threads are waited with **pthread_join**
- shared memory between processes is powerful but dangerous without synchronization
- race conditions appear when multiple threads touch the same data without protection -> fix with **mutex**
- main() is one execution path
- pthread_create(function_given_as_parameter) starts another execution path -> routine -> a function given as parameter
- main() and pthread_create() run at the same time
- the OS scheduler decides who runs when
- output order is not fixed

2) Thread function syntax:
```
void* f(void* a); // this is a thread function
```
- return type void*
- generic pointer void* (so you can pass anything as parameter)
- inside the function you cast it to the real type you meant

3) main operations:
- variable that stores thread
```
pthread_t t -> variable that stores thread
```
- start thread
```
pthread_create(&t, NULL, f, arg) -> start thread
```
- wait until thread ends
```
pthread_join(t, NULL) -> wait until thread ends
```
- compile
```
gcc -Wall -Wextra -Werror -g -o a a.c -pthread
```

4) First simple thread demo: order is non-deterministic
- global variable n = 1
- thread function f
- two threads created with "aa" and "b"
- main prints "main"
- intention: shows that threads run in unpredictable order
```
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>

int n = 1;

void* f(void* a) {
    for(int i=0; i<n; i++) {
        printf("%s\n", (char*)a);
    }
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t ta, tb;

    if(argc > 1) {
        sscanf(argv[1], "%d", &n);
    }

    pthread_create(&ta, NULL, f, "aa"); // thread aa
    pthread_create(&tb, NULL, f, "b"); // thread b

    for(int i=0; i<n; i++) {
        printf("main\n");
    }

    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
}
```

![[Pasted image 20260415121826.png]]
- result: 
	- sometimes is main b aa
	- sometimes is aa b main
	- sometimes is main main main b b b aa aa aa
- try to run it with ./a 
- try to run it with ./a 10
- try to run it with ./a 100

5) The famo
