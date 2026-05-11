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
https://stackoverflow.com/questions/44496362/does-wait0-do-anything-when-called-from-both-processes-created-from-fork
fork()
fork()
wait(0)
fork()
wait(0)

- fork() duplicates a new process (new identic copy)
- execution continues after fork()
- wait(0) default - if it is created by child, does not do anything (means child has no other children) behave differently depending on whether there are children or not -> wait dictates how many processes, not their order
- after two forks -> 4 processes
- fork() needs library unistd
- pid_t
- fork() return type is pid_t

Problem 1:
![[Pasted image 20260415153349.png]]
Problem 1 official solution:
- creates exactly n children because every child exits right away
```
#include <stdio.h> // printf, perror
#include <stdlib.h> // atoi, exit
#include <unistd.h> // fork, getpid, getppid
#include <sys/types.h> // pid_t
#include <sys/wait.h> // wait

int main(int argc, char *argv[]) {
    if(argc != 2) { 
        perror("Please provide exactly one argument");
        exit(1); // stop program with error code
    }
    int n = atoi(argv[1]); // convert argument to integer
    for(int i = 0; i < n; i++) { // create n child processes
        int f = fork(); // split current process into parent and child -> there are two processes running from now on the next lines
        if(-1 == f) { // fork failed
            perror("Error on fork"); // print why
        } else if(0 == f) { // child
            printf("Child process %d - PID: %d - PPID: %d\n", i, getpid(), getppid());
            // child prints its loop number i, its PID (getpid()), its parent PID (getppid())
            exit(0); // child stops immediately (without this, the child would continue the loop and start making its own children)
        } else { // parent -> fork() returns child PID
            printf("Parent %d - Child: %d\n", getpid(), f);
            // parent prints its own PID and its newly created child PID
        }
    }
    for(int i = 0; i < n; i++) {
        wait(NULL); // wait for each child to finish
    }
    return 0;
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

Problem 2
![[Pasted image 20260427101058.png]]

official iterative solution:
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
        } else {
            printf("Parent %d - Child: %d\n", getpid(), f);
            wait(0); // parent waits for its child to finish
            exit(0); // successfully terminate current process
            // we put exit here, not "in the child" (in the previous else if)
        }
    }
    return 0;
}
```


Problem 3
![[Pasted image 20260415154930.png]]
pr3.c
 
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
- only 2 processes: parent and child -> both keep looping
- if parent gets SIGUSR1:
	- parent handler runs
	- parent sends SIGUSR1 to child with kill
	- parent waits child
	- parent exits
- if child gets SIGUSR1:
	- child handler runs
	- child exits
	- parent later gets SIGCHILD
	- parent's zombie handler calls wait
- signal - only registers a handler
- kill - sends a signal
- SIGCHILD - for child termination cleanup
- signals are interruptions with handlers
- child death must be waited for
```
/*
 * Create a child process.
 * Both the child and parent processes will "work" an indefinite amount of time.
 * Implement a mechanism such that when the parent terminates, the child process also terminates without creating zombie processes.
 */

#include <stdlib.h> // exit
#include <sys/types.h> // process-related types
#include <sys/wait.h> // wait
#include <stdio.h> // printf, perror
#include <unistd.h> // fork, getpid, getppid, sleep, kill
int f; // global variable storing result for fork() 
// global because it helps handlers know who they are

void child_handler(int sig) { // function called when child receives SIGUSR1
  printf("Child process terminating...\n"); // child announces exit
  exit(0); // child exits
}

void parent_handler(int sig) { // function called when parent receives SIGUSR1
  printf("Parent process terminating...\n"); // parent announces exit
  kill(f, SIGUSR1); // send SIGUSR1 to child; f = child PID (in parent)
  wait(0); // collect child, avoid zombie
  exit(0); // parent exits
}

void zombie_handler(int sig) { // function called when child dies and parent gets SIGCHILD
    printf("Parent waiting for child process to terminate\n"); // debug message
    wait(0); // reap child (anti-zombie move)
}

int main(int argc, char **argv) {
  f = fork(); // create child
  if (-1 == f) { // fork failed
    perror("Error on fork"); // why failed
  } else if (0 == f) { // child
    signal(SIGUSR1, child_handler); // if child gets SIGUSR1, call function child_handler(sig - who is sig the parameter/??)
    printf("C - Child PID: %d Parent PID: %d\n", getpid(),getppid()); // child prints identity
    while(1) { // child works forever until signal arrives
      printf("Child working...\n"); // debug message
      sleep(3); // pause 3 seconds
    }
    exit(0); // technically unreachable unless loop somehow ends
  } else { // parent
    signal(SIGUSR1, parent_handler); // if parent gets SIGUSR1, call function parent_handler
    signal(SIGCHLD, zombie_handler); // when child dies, parent reaps it
    printf("P - Child PID: %d Parent PID: %d\n", f, getpid()); // parent prints identity (child PID and parent PID)
    while(1) { // parent works forever
      printf("Parent working...\n"); // debug message
      sleep(2); // pause 2 seconds
    }
  }
  return 0; // normal end if reached
}
```

Problem 5:
![[Pasted image 20260415170452.png]]

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
- pid_t -> proper type for process IDs
- array of size 10 because it is enough to store several levels
- The array idea itself is actually nice:
	- store ancestor PID
	- after each fork, store own PID
	- each child inherits previous path
	- child appends itself
So each process can know:  
**who is above me in the chain**
- example: n=3 levels
	- parent PID: 100
	- child1 PID: 200
	- child 2 PID: 300
	- child 3 PID: 400
	- ARRAY: [100, 200, 300, 400]
	- REVERSE (printed): [400, 300, 200, 100]

```
#include <unistd.h>
#include <stdio.h>
int main()
{
	int ier = 0; // hierarchy index
	pid_t levelIerarhie[10]={0}; // empty array meant to store PIDs from hierarchy
	
	// int lastNode=0;
	
	levelIerarhie[ier++]=getppid(); // store parent id, when increase index (write then move pointer)
	for(int i=0; i<5; i++)
	{
		// how to keep in mind the process number
		pid_t copil = fork(); // parent, child continue bc there is no if (copil==0), no break, no exit
		if(copil<0) {
			perror("fork");
			exit(1);
		}
		if(copil>0) {
			break;
		}
		// process count doubles every round
		levelIerarhie[ier++]=getpid(); // store current process PID in array
		//ier++; // move to next free array position
	}
	for(int i=ier-1; i>=0; i--) // the whole stored hierarchy backwards
	{
		printf("%ld ", (long)levelIerarhie[i]);
	}
	printf("\n");
	return 0;
}
```


Problem 22
![[Pasted image 20260415163008.png]]
- create all, first process 
- writes value from variable k into a file - similar to that problem from the lecture.
- page 28 ex 3 -> teaching notes
- without sync, all children sleep at same time
- with shared semaphore, one child at a time, total time ~10 seconds
lab solution without semafoare:
```
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int childCount = 0; // global counter in the parent (counts how many SIGUSR1 the parent received)
void signalHandlerCreated(int semnal) // function that runs when process receives a signal
{
	if(semnal==SIGUSR1) // check if received signal is SIGUSR1
	{
		childCount++; // increase count of children that notified parent
		if(childCount==10) // parent has heard from all 10 children
		{
			printf("Toti copiii buni\n");
		}
	}
}
int main() 
{
	signal(SIGUSR1, signalHandlerCreated); // install handler for SIGUSR1 (when parent receives SIGUSR1, run function signalHandlerCreated) -> children inherit signal dispositions after fork, so children also inherit this handler unless changed
	for(int i=0; i<10; i++)
	{
		pid_t child = fork(); 
		if( child == 0) // child
		{
			printf("Child created %ld\n", (long)getpid()); // child prints its own id
			sleep(i*2); // we are in a child - waits some time depending on loop index
			//signal();
			kill(getppid(), SIGUSR1); // child sends signal SIGUSR1 to its parent
			printf("Child notified parent: %ld\n", (long)getpid()); // child prints that it notified parent
			while(flag==0) // child waits until some flag changes
			{
				// children should pause here
				// maybe parent later changes sth
				// then children can continue
				// but flag does not exist, and even if declare globally, after fork each child would have its own copy
				sleep(1); // child keeps waiting in loop
			}
			exit(0); // child ends
		}
		else // parent
		{
			;// continue kidding (keep creating more children)
		}
	}
	for(int i=0; i<10; i++)
	{
		wait(0);
	}
}

```


official solution:
- // the semaphore can be used to synchronize processes, not just threads
- // the condition is that the same semaphore can be accessed by all the processes
- // since after fork, the child process has copies of everything the parent had until the fork, we can't simply create a semaphore and use it
- // we will instead create a shared memory segment in the parent and place the semaphore there
- // the child processes will inherit copies of the shared memory ID, but the shared memory space will remain the same
- // so we can safely say that the semaphore placed inside the shared memory segment is the same for all processes
- // generate a key first so we can create a shared memory segment
- // ftok creates a key based on a file path and a number
- // the file has to exist on the system where the program is run, and the same combination of filepath + number must be provided by all the processes that want to access the same shared memory segment
- // using the generated key, we create a shared memory segment big enough to contain one semaphore
- // we also grant read permissions to everyone
- // the IPC_CREAT flag indicates that the shared memory segment must be created if it does not exist
- `sizeof(sem_t)` → just enough space
- `0644` → permissions
- `IPC_CREAT` → create if missing
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

    sem_t *sem; // pointer to semaphore (it will live in shared memory)
    
    key_t shmkey = ftok("/dev/null", 24); // generate key for shared memory segment
    
    int shmid = shmget(shmkey, sizeof(sem_t), 0644|IPC_CREAT); // large enough for one semaphore
    
    // we now link the shared memory segment to the previously declared pointer
    sem = (sem_t*) shmat(shmid, NULL, 0); // attach shared memory to this process (sem now points to shared ared)
    
    // from here on, we treat this semaphore pointer as we would treat a regular semaphore pointer that is declared on the heap -> parent and children can refer to the same semaphore, not copies
    
    sem_init(sem, 1, 1); // initialize semaphore
    // sem - which semaphore
    // 1 - shared between processes
    // 1 - initial value 1 (only one child allowed inside at a time)

    // we create processes
    for (i = 0; i < 10; i++) { // create 10 child processes
        int f = fork(); // split
        if (f < 0) { // fork failed
            perror("Oh no! Anyway...");
        } else if (f == 0) {    // child
            // each child locks the semaphore before sleeping
            sem_wait(sem); // take semaphore - wait if another child already has the semaphore
            sleep(1); // child sleeps 1 sec while holding semaphore
            // and unlocks it once it is done
            sem_post(sem); // release semaphore
            exit(0); // child exits
        }
    }

    for (i = 0; i < 10; i++) { // parent waits
        wait(0);
    }
    
    sem_destroy(sem); // destroy the semaphore
    
    shmdt(sem); // remove the link between the semaphore pointer and the shared memory space
    
    shmctl(shmid, IPC_RMID, 0); // delete the shared memory segment, so that memory can be used by other processes freely
    
    gettimeofday(&tv2, NULL); // save finish time
    
    printf("Total time = %f seconds\n", (double)(tv2.tv_usec - tv1.tv_usec) / 1000000 + (double) (tv2.tv_sec - tv1.tv_sec)); // print elapsed seconds

    return 0;
}
```


next lab -> pipe, fifo, exec 
### Individual work after Lab 7

Process creation -> fork, exit, wait
Signals -> signal, kill, SIGUSR1, SIGCHILD
Communication/sync -> pipe, shared memory, semaphores

fork()
- after fork(), parent and child continue from the same next line 
- safe pattern: fork -> child exit(0) -> parent wait(0)
- child returns 0
- parent returns child PID
- both child and parent continue

signal()
- signal does not signal
- signal() installs a handler
- kill() is the one that sends the signal
- SIGCHILD - the parent reaps dead children and avoids zombies

pipes
- for parent/child-style communication
- interprocess communication
- closing unused pipe_ends early is essential to avoid stuck programs

shared memory
- gives one common region to multiple processes

semaphores
- synchronisation mechanisms

child code: exit 0
```
if (f == 0) {
    // child work
    exit(0);
}
```

parent code: wait 0
```
else {
    // parent work
    wait(0);
}
```

signals:
- install signal handler
```
signal(SIGX, handler)
```
- send signal
```
kill(pid, SIGX)
```

pipes:
- one end reads
- one end writes
- close what you don't use


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
- optimisation changes order of execution?
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
- inside the function you cast it to the real type you meant --??

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
int n=1; // global variable, all threads can read it bc threads share memory
void* f(void* a) { // the function each thread will execute
        for(int i=0; i<n; i++) { // EACH THREAD prints n times
                printf("%s\n", (char*)a); // interpret parameter a as a char*
        }
        return NULL;// thread ends
}

int main(int argc, char** argv) {
        pthread_t ta,tb; // handlers for the two threads ta and tb
        if(argc>1) { // optional command-line argument
                sscanf(argv[1], "%d", &n); // change how many times everything prints
        }
        pthread_create(&ta, NULL, f, "aa"); // create thread A that runs f with "aa" as arg
        pthread_create(&tb, NULL, f, "b"); // create thread B that runs f with "b" as arg
        for(int i=0; i<n; i++) {
                printf("main\n"); // main thread
        }
        pthread_join(ta,NULL);// wait for thread A to finish
        pthread_join(tb,NULL); // waint for thread B to finish
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

5) The famous &i bug
- every time you see... be suspicious.
```
pthread_create(&t[i], NULL, f, &i) 
```
- bug in argument passing
- terminal shows weird outputs like repeating numbers, missing digits, duplicates
- all threads receive the same address &i -> WRONG
	- all threads look at the same memory cell
- meanwhile main() keeps changing i
	- changes i during creation loop
	- changes i during join loop (waiting)
- threads print whatever value happens to be in that shared location
- the bug is caused by passing &i to all threads, so all threads use the same address
- you did not send 10 numbers. you sent 10 threads to the same mailbox.
```                                    
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>

void* f(void* a) { // the function each thread will execute
    printf("%d\n", *(int*)a); // treat param a as int* -> dereference (*(int*)) -> print value
    return NULL; // nothing to return
}

int main() {
    int i;
    pthread_t t[10];// 10 thread handles (id s)

    for(i=0; i<10; i++) { // create threads loop, we want 10
        pthread_create(&t[i], NULL, f, &i); // create thread i that runs f with &i as arg
    }// all threads get the same address &i, only the value at that address changes (i), but addre>

    for(i=0; i<10; i++) { // wait threads loop, go through all threads
        pthread_join(t[i], NULL);// wait for thread i (t[i]) to finish
    }
}
```

![[Pasted image 20260415122351.png]]

6) Fix with an array
- still unordered, but at least all numbers 0...9 appear once
```
#include <stdio.h>
#include <stddef.h>
#include <pthread.h>

void* f(void* a) { // the function each thread will execute
    printf("%d\n", *(int*)a); // treat param a as int* -> dereference (*(int*)) -> print value
    return NULL; // nothing to return
}

int main() {
    int i;
    int x[10];// create storage for 10 integers
    pthread_t t[10];// 10 thread handles (id s)

    for(i=0; i<10; i++) { // create threads loop, we want 10
        x[i]=i;// each thread gets a different address (thread 0 gets &x[0] etc.)
        pthread_create(&t[i], NULL, f, &x[i]);
    }

    for(i=0; i<10; i++) { // wait threads loop, go through all threads
        pthread_join(t[i], NULL);// wait for thread i (t[i]) to finish
    }
}
```

![[Pasted image 20260415125302.png]]

7) Fix with malloc
- main allocates
- thread reads
- thread frees
- main waits until thread i is finished
- each thread has its own memory and value
- no interference from loop variable i
- free(a) inside f because the thread is the one that uses the allocated memory and after it prints that value, the memory is no longer needed
- don't free(a) after pthread_create because the thread did not use it yet
- allocate before launching. free after using. never free before thread actually reads it.
```
#include <stdio.h> // for printf
#include <stddef.h>
#include <pthread.h> // for threads
#include <stdlib.h> // for malloc and free

void* f(void* a) { // the function each thread will execute
    printf("%d\n", *(int*)a); // treat param a as int* -> dereference (*(int*)) -> print value
    free(a);// release that allocated memory
        // memory must stay alive until the thread uses it
    return NULL; // nothing to return, thread ends
}

int main(int argc, char** argv) {
    pthread_t t[10];// array of 10 thread handles (id s)
    int i;
    for(i=0; i<10; i++) { // create threads loop, we want 10
        int* x = (int*)malloc(sizeof(int)); // allocate memory for one integer
        *x = i; // write value i into that newly allocated integer
        pthread_create(&t[i], NULL, f, x);// create thread i that runs f with x as arg
    }// each thread gets its own separate memory

    for(i=0; i<10; i++) { // wait threads loop, go through all threads
        pthread_join(t[i], NULL);// wait for thread i (t[i]) to finish
    }
    (void)argc;
    (void)argv;
    return 0;
}
```

8) The Dirty Trick
- still not ordered
```
#include <stdio.h> // for printf
#include <stddef.h>
#include <pthread.h> // for threads
#include <stdlib.h> // for malloc and free

void* f(void* a) { // the function each thread will execute
    printf("%d\n", *(int*)a); // treat param a as int* -> dereference (*(int*)) -> pri>
    free(a);// release that allocated memory
        // memory must stay alive until the thread uses it
    return NULL; // nothing to return, thread ends
}

int main(int argc, char** argv) {
    pthread_t t[10];// array of 10 thread handles (id s)
    int i;
    for(i=0; i<10; i++) { // create threads loop, we want 10
        int* x = (int*)malloc(sizeof(int)); // allocate memory for one integer
        *x = i; // write value i into that newly allocated integer
        pthread_create(&t[i], NULL, f, x);// create thread i that runs f with x as arg
    }// each thread gets its own separate memory

    for(i=0; i<10; i++) { // wait threads loop, go through all threads
        pthread_join(t[i], NULL);// wait for thread i (t[i]) to finish
    }
    (void)argc;
    (void)argv;
    return 0;
}

```

9) Race condition on global n
- you run multiple times -> 1000, 1000, 1000, 910, 1000
- what's going on with that 910?
	- n++ is NOT ATOMIC (not one step)
	- alternating table (image)
	- unsynchronized access = race condition
```
#include <stdio.h>
#include <pthread.h>

int n = 0;//shared counter, all threads see and modify the same n (danger)

void* f(void* a) { // each thread runs this function
    int i;// loop variable for the thread
    for(i=0; i<(int)(long)a; i++) { // loop a times (dirty trick: void* -> long -> int>
        n++;// increase shared counter -> NOT ATOMIC (read n, add 1, write n)
    }
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t t[10];
    int i; // loop index
    int k = 1; // how many times each thread increments

    if(argc > 1) {// check if user gave argument
        sscanf(argv[1], "%d", &k);// read int from command line (ex: ./a 10 -> k=10)
    }

    for(i=0; i<10; i++) {// create 10 threads
        pthread_create(&t[i], NULL, f, (void*)(long)k); // each thread runs f with sam>
    }// 10 threads, each thread increments n k times => expected: n=10*k

    for(int i=0; i<10; i++) {
        pthread_join(t[i], NULL);
    }

    printf("%d\n", n);// print n
    return 0;
}
```

![[Pasted image 20260415135103.png]]

10) CORRECT SYNCHRONIZATION VERSION:
- MUTEX puts a tiny fence around n++. one thread enters, the others wait at the gate
	- n++ might break because it touches shared data and it breaks if two threads try to do it together
	- mutex wraps that dangerous part
	- MUTEX = KEY for one-person-only access
- i want exclusive access:
```
pthread_mutex_t m;
...
pthread_mutex_lock(&m);
```
- thank you, next:
```
pthread_mutex_t m;
...
pthread_mutex_lock(&m);
...
pthread_mutex_unlock(&m);
```
- only one thread can complete the lock at a time, others must wait until unlock
- lock/unlock inside the loop because n++ is dangerous
- "CRITICAL SECTION" = the dangerous part (n++)
```
#include <stdio.h>
#include <pthread.h>

int n = 0; // shared couter, all threads touch the same n
pthread_mutex_t m; // declaration of a mutex (mutex = one-key lock for shared data)

void* f(void* a) { // each thread starts here
    for(int i=0; i<(int)(long)a; i++) { // repeat a times (dirty trick)
        pthread_mutex_lock(&m); // take the lock (nobody else may touch protected code>
        n++; // increment shared counter (now it's protected because only one thread d>
        pthread_mutex_unlock(&m); // release the lock (thank you, next)
    }
    return NULL;
}

int main(int argc, char** argv) {
    pthread_t t[10];
    int k = 1;// how many increments each thread does

    if(argc > 1) {// if user gave command-line argument, read that into k
        sscanf(argv[1], "%d", &k); // k = how many times to increment
    }

    pthread_mutex_init(&m, NULL);// initialisation of the mutex m (default settings)

    for(int i=0; i<10; i++) {
        pthread_create(&t[i], NULL, f, (void*)(long)k); // create thread i that runs f>
    } // 10 threads, each thread loops k times, each increment protected by mutex

    for(int i=0; i<10; i++) { // wait for thread i to finish (main prints only after a>
        pthread_join(t[i], NULL);
    }
	pthread_mutex_destroy(&m); // destroy mutex when no longer needed
    printf("%d\n", n); // print final value of shared counter
}
```

11) WRAP-UP:
- thread creation:
```
pthread_t t;
pthread_create(&t, NULL, f, arg);
pthread_join(t, NULL);
```
- thread function:
```
void* f(void* a) { 
	... 
	return NULL; 
}
```
- BAD argument passing to thread function:
```
pthread_create(..., &i);
```
- CORRECT argument passing way to thread function:
```
a[i] = i; 
...
pthread_create(..., &a[i]);
```
- ANOTHER CORRECT argument passing way to thread function:
```
p = malloc(sizeof(int)); 
...
*p = i; 
...
pthread_create(..., p);
```
- HACK:
```
pthread_create(..., (void*)(long)i);
```
- BAD (race condition)
```
n++;
```
- FIXED (race condition) -> mutex
```
pthread_mutex_lock(&m);
n++;
pthread_mutex_unlock(&m);
```

**Threads exist**  
→ scheduler changes order  
→ order becomes unpredictable

**Threads share memory**  
→ passing wrong addresses breaks arguments  
→ touching same variable breaks correctness

**So:**
- for arguments: give each thread its own value/address
- for shared writes: protect with mutex

## Lecture 8 - 22 apr 2026
Thread = same process, same memory, multiple execution paths

```
pthread_mutex_t 

pthread_ -> POSIX threads library
mutex -> mutual exclusion
_t -> type
```

1) mutex = mutual exclusion (only one THREAD at the time)
- only one thread will go through the mutex, the others will wait
- has TWO MAIN OPERATIONS: lock, unlock
	- only ONE thread can complete lock
	- the others WAIT until unlock
- race conditions are solved using synchronisation mechanisms
	- critical resource = shared thing (count)
	- critical section = the code that touches it (count++)
- see tic-tac-toe example

```
// count -> "critical resource"
// count ++ -> "critical section"
// we want to wrap the critical section between mutex lock/unlock

pthread_mutex_lock(&m); // declare the mutex (m=variable name) => "make one mutex named m"
count++; 
pthread_mutex_unlock(&m);
```

WRONG:
```
int board[3][3]; // shared board
int turn = 1; // shared turn variable
pthread_mutex_t m; // one mutex protecting shared data

void* fx(void* a) { // thread function
	while(not-over) { // repeat forever
		if(turn==1) { // check if it's thread's turn
			// i am outside the mutex
			pthread_mutex_lock(&m); 
			// i am inside the mutex
			play-board; // make the move on the shared board
			turn=0; // switch turn
			// i am inside the mutex
			pthread_mutex_unlock(&m);
			// i am outside the mutex
		}
	}
	return NULL;
}
```
- why it's wrong: 
	- we have two threads, A and B
	- thread A runs that check (if), thread B runs at the same time
	- thread A and B both pass the check
	- now they both try to pthread_mutex_lock(&m)
	- now they both say "it's my turn" => not okay.
	- ! checking shared variables outside mutex is unsafe!

RIGHT:
```
int board[3][3]; // shared board
int turn = 1; // shared turn variable
pthread_mutex_t m; // one mutex protecting shared data

void* fx(void* a) { // thread function
	while(not-over) { // repeat forever
		pthread_mutex_lock(&m); // thread A and thread B want to enter, but only one can lock
		// thread A enters, thread B waits 
		// thread A is now inside the mutex
		if(turn==1) { // check if it's thread's turn
			play-board; // make the move on the shared board
			turn=0; // switch turn
		}
		pthread_mutex_unlock(&m); // called by thread A
		// thread B can now enter -> check (if) -> false (set by thread A) -> DOES NOT PLAY
	}
	return NULL;
}
```
- why it's right:
	- we have two threads, A and B
	- thread A enters ... does stuff
	- thread A gives access to thread B to enter
	- thread B enters ... cannot do stuff bc the SHARED VARIABLE "turn" was already updated by thread A inside the mutex

2) use semaphores to reduce the traffic (students exam submissions)
- semaphores - return a number, limit to one => mutex, if more => semaphore?
- semaphore = generalisation of mutex
```
sem_t sem; // declare a semaphore
pthread_mutex_t mtx[3]; // control how many threads can enter => 3 separate critical resources
```

how does a semaphore work:
```
sem_t sem; // semaphore variable
pthread_mutex_t mtx[3]; // 3 mutexes (3 critical resources)

main {
	sem_init(&sem, null, 3); // init semaphore with value 3 (max 3 threads allowed inside)
	pthread_mutex_init(&mtx[i], NULL); // init each mutex
	pthread_create ... // threads are created here
	pthread_join // wait for threads to finish
	sem_destroy // cleanup
	pthread_mutex_destroy // cleanup
}

void* kid(void* a) { // one thread = one kid
	sem_wait(&sem); // i reserve the position (if 3 threads exist already, wait)
	for(int i=0; i<3; i++) { // try all 3 resources
		// try to lock without waiting => if busy => skip (continue) => try next resource
		if(pthread_mutex_trylock(&mtx[i])<0) continue
		// access critical resource
		pthread_mutex_unlock(mtx[i]); // release resource
		break; // stop searching (we found one)
}
sem_post(&sem); // position => free one slot (another waiting thread can enter)
}
```

3) tic-tac-toe
- read write lock - asymetrical 
- simple mutex not helpful - does not guarantee that after unlock the other will put
- enforce this: my round, your round (turn) - 2 semaphores
	- solution 1: turn variable + mutex
	- solution 2: 2 mutexes (strict alternation)
- volatile
- mutex allows only one thread to come out of the function? when that one calls unlock, the other comes out? "stuck waiting for itself", but the other ?? is releasing it

```
pthread_mutex_t mx, m0;

void* fx(void* a) {
    while(not-over) {
        pthread_mutex_lock(&mx);
        play-X;
        pthread_mutex_unlock(&m0);
    }
    return NULL;
}

void* f0(void* a) {
    while(not-over) {
        pthread_mutex_lock(&m0);
        play-0;
        pthread_mutex_unlock(&mx);
    }
    return NULL;
}

```
why this works:
- thread X waits on `mx`
- thread 0 waits on `m0`
- X plays, then unlocks `m0`
- 0 plays, then unlocks `mx`
- result: strict alternation
- X → 0 → X → 0

4) Read-Write Lock (going on a trip with a bus)
- read write lock = optimisation of mutex
- mutex with 2 types of locking:
	- rdlock (read)
	- wrlock (write)
- rules:
	- as many reads as you want
	- write lock only once (only one write)
	- mutex with 2 types of locking ?
- example:
	- website: 
		- more people look than buy (many threads read)
		- one thread writes
		- while writing, nobody else can read or write
		- (while i'm looking, nobody should modify it) - sounds like a mutex (some look, some change) - only one who changes

 5) The 5 synchronisation mechanisms:
```
pthread_mutex_ t, init, destroy, lock, unlock, trylock
pthread_cond_ t, init, destroy, wait, signal, broadcast
pthread_barrier_ t, init, destroy, wait
sem_ t, init, destroy, wait, post
pthread_rwlock_ t, init, destroy, rdlock, wrlock, unlock
```

6) Barrier
- wait until everyone is here (who is everyone? define w number - wait until 15 are here, and then move on)
- define number (ex: 15 threads)
- all threads wait
- when all arrive -> all continue ?
- init function of barrier takes this nr

7) Semaphore
- semaphore controls crowds - how many to let through (init of semaphore takes a nr)
- wait -> reserve a seat
- post -> release

8) Mutex intuition (kids, toilet)
- kids = threads
- toilet = mutex
- only one thread inside
- other wait

9) trylock
- trylock = try to lock without waiting
- if busy => fail => continue
- used when you don't want blocking
- used when you try multiple resources
```
if(pthread_mutex_trylock(&m[i]) < 0) continue;
```

10) ! ALWAYS lock resources in the same order. 

11) conditional variables
- you wait until notified
- one thread signals, others wait
- a thread is signaling the conditional variable, not another thread
- STRUCTURE:
```
pthread_cond_t c;
```
- WAITER:
	- pthread_cond_wait
		- unlock
		- wait
		- lock
```
pthread_cond_wait(&c, ...);
```
- WAKER:
	- wakes one thread
```
pthread_cond_signal(&c);
```

JUICY EXAM TOPIC
```
pthread_mutex_t m; // mutex m exists
pthread_cond_t c; // condition c exists
int ok = 0;
// nobody holds the mutex yet (mutex=key)

// one thread
void* waiter(void* a) {
	pthread_mutex_lock(&m); // waiter locks mutex
	while(ok==0) { // ALWAYS WHILE, NOT IF
		pthread_cond_wait(&c, &m); // ...waits
	}
	pthread_mutex_unlock(&m);
	return NULL;
}

// another thread
void* waker(void* a) {
	pthread_mutex_lock(&m); // waker locks mutex
	ok=1; // sets
	pthread_cond_signal(&c); // signals condition
	pthread_mutex_unlock(&m); // unlocks mutex
	return NULL;
}
```
what happens:
_______________________________________________________________________
mutex m exists, condition c exists, ok=0 => nobody holds the mutex yet
___________________________________________________________________
pthread_mutex_lock(&m) => waiter locks, so it holds mutex m
						=> waker can't lock yet because the mutex is "taken"
________________________________
while => waiter enters
________________
pthread_cond_wait(&c, &m) =>waiter unlocks mutex m + waiter waits (sleeps)
						    => waker can run because the mutex is "available"
____________
pthread_mutex_lock(&m) => waker locks, so it holds mutex m
						=> waiter runs from the line it stopped at (pthread_cond_wait(&c, &m))  => waiter locks, so it holds mutex m => while ??
_________________
ok=1 => waker changes from ok=0 to ok=1
__________
pthread_cond_signal(&c) => waker signals condition c
						=> waiter is notified => waiter is ready to wake up => but waiter still holds mutex m
_________
pthread_mutex_unlock(&m) => waker unlocks mutex m
	                       => waiter can finish pthread_cond_wait(&c, &m);
_________
while => waiter can't enter because ok=1 => EXIT the while
______
pthread_mutex_unlock(&m) => waiter unlocks mutex m
________________
return NULL => waiter thread ends

- extra case: why while, not if
```
pthread_mutex_t m;
pthread_cond_t c;
int ok;

// waiter
void* waiter(void* a) {
	pthread_mutex_lock(&m);
	while(ok <= 0) {
		pthread_cond_wait(&c, &m);
	}
	pthread_mutex_unlock(&m);
	return NULL;
}

// waker
void* waker(void* a) {
	pthread_mutex_lock(&m);
	ok = rand() % 10 - 5; // can be negative or positive
	pthread_cond_signal(&c);
	pthread_mutex_unlock(&m);
	return NULL;
}
```

12) SIGNAL - wakes one
    BROADCAST - wakes all


## Lab 8 - 27 apr 2026

Processes
test 3 - fork, wait pipes, fifo

Pipes
- in unix, they are unidirectional
- data flows from write [1] -> read [0]
- you should close unused ends immediately after forking
- issues:
	- hangs
	- out of bounds read/writes
- write to pipe = write to fifo (behaves the same)
	- hangs reading end if one does not exist??

0 = stdin
1 = stdout
mypipe[0] = read end of mypipe
mypipe[1] = write end of mypipe

600 - set permisssion only to yourself
perror - reads error number (global number) and prints string interpretation of that number (tell exactly why it failed) - shortcut way of figuring out what exactly went wrong

Problem 6
![[Pasted image 20260427141824.png]]
- stdout is you writing to the user
- can you use a single pipe?
- write sth  - where to write, what to write, how much to write (order)
- ptc - parent to child (input pipe)
- ctp - child to parent (output pipe)
- try to provide all the information needed to the child
- next year at networking you'll have such an assignment
- run it in terminal with gcc -Wall -Wextra -Werror -g -o pb6 pb6.c
- they make it sleep ig 
- The parent generates N random numbers and sends both N and the array (N randomly generated integers) to the child via a pipe. The child reads the data, calculates the average, and pipes the result back to parent. The parent reads this final value and prints it, demonstrating synchronized two-way inter-process communication.
![[Pasted image 20260427142557.png]]

```
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if(argc !=2) {
		printf("Usage: p6 <N>\n);
		return 1;
	}
	const int N = atoi(argv[1]); // convert command-line string to integer (parent)
	if(N==0) { // shouldn't it be <=0 ??
		printf("invalid number\n");
		return 2;
	}
	int* numbers = (int*) malloc(N* sizeof(int)); // allocate memory for N integers
	srand(getpid()); // seed random numbers using process ID
	for(int i=0; i<N; i++) { // loop N times to fill the array
		numbers[i] = rand() % 1000; // store a random number (0-999)
	}
	int ptc[2], ctp[2]; // declare arrays for two pipe file descriptors
	pipe(ptc); // create parent-to-child pipe
	pipe(ctp); // create child-to-parent pipe
	if(fork()==0) { // child
		close(ptc[1]); // close write end of input pipe
		close(ctp[0]); // close read end of output pipe
		int sum=0; 
		int n; // variable to hold received count
		read(ptc[0], &n, sizeof(int)); // receive count n from parent
		int * nums = malloc(sizeof(int)*n); // allocate space for received numbers
		read(ptc[0],nums, sizeof(int)*n); // receive the actual array data (child)
		close(ptc[0]); // close write end of the parent to child pipe 
		for(int i=0; i<n; i++) { // loop through received numbers
			sum +=nums[i]; // add each number to total sum
		}
		const double average = sum/n; // calculate average
		write(ctp[1], &average, sizeof(double)); // send average back to parent
		close(ctp[1]); // close write end of child-to-parent pipe
		exit(0); // terminate child process
	}
	close(ptc[0]); // close read end of input pipe
	close(ctp[1]); // close write end of output pipe
	write(ptc[1], &N, sizeof(int)); // send count N to child
	write(ptc[1], numbers, sizeof(int)*N); // send array of numbers to child
	double avg; // final result
	read(ctp[0], &avg, sizeof(double)); // wait and read average from child
	close(ctp[0]); // close read end of child-to-parent pipe
	printf("Average is: %lf", avg); // print result to the screen
	return 0;
	}
```

my way:
- we use malloc because N is only known at runtime
```
#include ...

int main(int argc, char **argv) {
	if(argc !=2) {
		printf("Usage: ./p6 <N>\n");
		return 1;
	}
	
	int N=atoi(argv[1]); // convert argument to integer
	
	if(N<=0) {
		printf("Invalid number\n");
		return 2;
	}
	
	int p2c[2];
	int c2p[2];
	
	pipe(p2c);
	pipe(c2p);
	
	if(fork()==0) { // child
		close(p2c[1]);
		close(c2p[0]);
		
		int n;
		read(p2c[0], &n, sizeof(int));
		
		int *v=malloc(n*sizeof(int)); // allocate vector
		read(p2c[0], v, n*sizeof(int)); // read vector
		
		int sum=0;
		for(int i=0; i<n; i++)
			sum +=v[i];
		
		double avg = (double)sum/n; // compute average
		
		write(c2p[1], &avg, sizeof(double)); // send average to parent
		
		free(v);
		close(p2c[0]);
		close(c2p[1]);
		exit(0);
	}
	// parent
	close(p2c[0]);
	close(c2p[1]);
	
	int *numbers = malloc(N*sizeof(int));
	
	srand(getpid());
	
	for(int i=0; i<N; i++) {
		numbers[i]=rand() %1000;
		printf("%d", numbers[i]);
	}
	printf("\n");
	
	write(p2c[1], &N, sizeof(int));
	write(p2c[1], numbers, N*sizeof(int));
	
	double avg;
	read(c2p[0], &avg, sizeof(double));
	
	printf("Average is: %lf\n", avg);
	
	free(numbers);
	close(p2c[1]);
	close(c2p[0]);
	wait(0);
	return 0;
}
```

Problem 7a
![[Pasted image 20260427144446.png]]
- if you have 10 - both sides should stop (one side receives 10 -> the other side should stop)
- mkfifo(pathname, mode)

![[Pasted image 20260427151542.png]]
![[Pasted image 20260427151551.png]]
![[Pasted image 20260427151608.png]]

a.c:
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    // Process A
    // FIFO creation

    if (mkfifo("a2b", 0600) < 0) {
        perror("Failed to create a2b fifo");
        exit(1);
    }

    if (mkfifo("b2a", 0600) < 0) {
        perror("Failed to create b2a fifo");
        unlink("a2b");
        exit(1);
    }

    int a2b, b2a;

    a2b = open("a2b", O_WRONLY);
    if (a2b == -1) {
        perror("Failed to open a2b");
        unlink("a2b");
        unlink("b2a");
        exit(2);
    }

    b2a = open("b2a", O_RDONLY);
    if (b2a == -1) {
        perror("Failed to open b2a");
        unlink("a2b");
        unlink("b2a");
        exit(2);
    }

    srand(getpid());

    while (1) {
        int num = rand() % 10 + 1;

        write(a2b, &num, sizeof(int));

        if (num == 10) {
            break;
        }

        read(b2a, &num, sizeof(int));
        printf("A: %d\n", num);

        if (num == 10) {
            break;
        }
    }

    close(a2b);
    close(b2a);

    unlink("a2b");
    unlink("b2a");

    return 0;
}

```

b.c:
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    // Process B

    int a2b, b2a;

    a2b = open("a2b", O_RDONLY);
    if (a2b == -1) {
        perror("Failed to open a2b");
        exit(2);
    }

    b2a = open("b2a", O_WRONLY);
    if (b2a == -1) {
        perror("Failed to open b2a");
        close(a2b);
        exit(2);
    }

    srand(getpid());

    while (1) {
        int num = rand() % 10 + 1;

        write(b2a, &num, sizeof(int));

        if (num == 10) {
            break;
        }

        read(a2b, &num, sizeof(int));
        printf("B: %d\n", num);

        if (num == 10) {
            break;
        }
    }

    close(a2b);
    close(b2a);

    return 0;
}
```

my way:
a.c
```
#include ...
int main() {
	mkfifo("a2b", 0600);
	mkfifo("b2a", 0600);
	
	int a2b=open("a2b", O_WRONLY);
	int b2a=open("b2a", O_RDONLY);
	
	if(a2b<0 || b2a <0) {
		perror("open");
		exit(1);
	}
	
	srand(getpid()); // different random numbers for a
	
	while(1) {
		int num = rand()%10 +1; // 0-9 + 1 -> 1-10
		
		printf("A sends: %d\n", num);
		write(a2b, &num, sizeof(int)); // send random number to b
		
		if(num==10)
			break;
		
		if(read(b2a, &num, sizeof(int))<=0) // receive random number from b
			break;
		
		printf("A received: %d\n", num);
		
		if(num==10)
			break;
	}
	// what we actually used in a
	close(a2b);
	close(b2a);
	
	unlink("a2b"); // delete fifo file
	unlink("b2a"); // delete fifo file
	
	return 0;
}
```

b.c
```
#include ...

int main() {
	int a2b = open("a2b", O_RDONLY);
	int b2a=open("b2a", O_WRONLY);
	
	if(a2b<0 || b2a<0) {
		perror("open");
		exit(1);
	}
	
	srand(getpid()); // different random numbers for b
	
	int num;
	
	while(1) {
		if(read(a2b, &num, sizeof(int))<=0)
			break;
		printf("B received: %d\n, num);
		
		if(num==10)
			break;
		
		num = rand()%10+1;
		
		printf("B sends: %d\n", num);
		write(b2a, &num, sizeof(int));
		
		if(num==10)
			break;
	}
	// what we actually used in b
	close(a2b);
	close(b2a);
	return 0;
}
```

How to debug stuff in C:
- crashing code:
![[Pasted image 20260427153023.png]]
- type bt?
![[Pasted image 20260427153251.png]]

- file a.out -> stripped/unstripped (does it have debugging symbols or not)
- valgrind ./a.out arguments
- gdb ./a.out arguments - attempt to execute as an actual command so don't feed arguments here
- gdb ./a.out -> opens sth -> type backtrace in that file -> how to see backtrace to see the place where it crashed -> type bt
- compile with -g 
- ctrl + c -> where the hang happened
- set breakpoints in gdb
```
gcc test.c -g
file ./a.out
gdb ./a.out
run
bt
break 9 -> breakpoint to line 9 (if it can't, it will break at the closest line posible)
info locals
r -> see the values
step
info locals -> see the values (updated bc it was run)
continue -> hangs because it's doing the read thing
bt
help info
info locals
print c -> print a variable
info variables
info variables c


=> "with debug info, not stripped" => everything okay
```

Problem 9

![[Pasted image 20260427153957.png]]
- dup - copy to the first available descriptor that's not currently opened
- dup(2) - copy old argument to new argument
- popen = fork + dup2 + redirection
```
dup2(pipe[1],1)
```

Process A:
- creates fifo
- reads commands from keyboard
- stops when "stop"
- executes each command
- sends command output to b
- deletes fifo at the end
Process B:
- opens fifo for reading
- keeps reading text from fifo
- prints everything it receives

a.c:
```
#include ...

int main() {
	mkfifo("fifo", 0600);
	int fd_write=open("fifo", O_WRONLY);
	
	int(fd_write <0) {
		perror("open");
		exit(1);
	}
	
	char cmd[256]; // command read from keyboard
	char buffer[256]; // output chunks from command
	
	while(1) {
		printf("Command: ");
		fgets(cmd, 256, stdin); // read full command line
		
		cmd[strlen(cmd)-1]='\0'; // remove '\n' from fgets
		
		if(strcmp(cmd, "stop")==0)
			break;
		
		FILE *p = popen(cmd, "r"); // execute command and read its input ??!
		
		if(p==NULL) {
			perror("popen");
			continue;
		}
		
		while(fgets(buffer, 256, p)!=NULL) { // read command output line by line??
			int n = strlen(buffer); // output length
			write(fd_write, buffer, n*sizeof(char)); // send output to b
		}
		
		pclose(p);
	}

close(fd_write);
unlink("fifo");
return 0;
}
```
b.c:
```
#include ...

int main() {
	int fd_read=open("fifo", O_RDONLY);
	
	if(fd_read<0) {
		perror("open");
		exit(1);
	}

	char buffer[256];
	int n;
	
	while(1) {
		n=read(fd_read, buffer, 255*sizeof(char)); // read from fifo
		
		if(n<=0) 
			break;
		
		buffer[n]='\0';
		
		printf("%s", buffer);
	}
	close(fd_read);
	return 0;
}

```

exam question: in which scenario can it print potato? how to make this break
- how can I cause a problem s.t potato does not get printed? how to make execlp fail?
	- no room to make child
	- p = path => mangle the path => you can manipulate environment variables (env)
		- export PATH=
		- I just broke my shell
		- repair: PATH= ./a.out
- sticky bit: chmod +s ./a.out
- make this shell use a specific path
```
#include <unistd.h>
#include <stdio.h>

int main() {
	execlp("ls", "ls", NULL);
	printf("potato");
}

```


DUP2 and exec to the next test! (one)


## Lecture 9 - 29 apr 2026

mechanisms of synchronisation:
1) mutex
2) semaphore - dijkstra
- extention of mutex
- has a field holding a number - that number tells how many threads will go through
- wait() method
- open() system semaphores
- =1 => binary semaphore = mutex
3) read-write lock
- specialisation of mutex
- some read, some modify => no matter how many reads/writes
- lock for reading - any number of locks
- lock for writing - like the mutex lock
4) conditional variable
- wait until telling you to continue
- wait if the condition is true but pay attention check again bc from telling you to do it and actually doing it maybe the condition changed


Metaphorical problems:

1. lift in a building - simulate this situation
- lift
	- limited capacity (kg) - don't let inside the lift too many kg
- who are threads?
	- people
	- they are allowed to enter that zone if they have space
	- a variable saying how many kg the thread has
- what are the mechanisms?
	- semaphore - you have to know with what value to initialise it
		- initialize semaphore with max kg
		- a semaphore reserves an empty position
		- a thread has (kg_of_thread) empty positions
			- if i have 50 kg, semaphore will have 50 empty positions
	- mutex + conditional variable - how many kg 
		- initialise variable with max kg
		- this number is protected with a mutex

- what if 2 sumo men (+200kg each) want to enter a lift if 400kg max capacity?
	- should enter one men, the other should wait
	- how to prevent threads from blocking while reserving their kg?
		- using mutexes
		- reserving kg for threads is not atomic (there are more threads reserving at the same time)
- wrap-up: 
	- more threads want to reserve multiple resources at the same time
	- you have to synchronise them

2. children jumping on trambuline
- who are threads?
	- children
	- we should not let too many children jump
- what mechanisms?
	- 2 semaphores:
	- semaphore limiting the number of children, initialised with the max children capacity (5 children max at once)
	- semaphore limiting the number of kg

3. "thread safe" = classes that can be used simultaneously ?
- you will use libraries in life - you have to know which of those methods from those libraries are "thread-safe"

4. implement a "lista simplu inlantuita" (singly linked list?) care sa fie "thread-safe"?
- adding in list is not "thread-safe" (modifying the list structure is not thread-safe)
- add+delete methods - WRITER?
- add+modify methods - READER?
- modifying the value of a node -> is it thread-safe?
	- from the perspective of the structure of the list, that is just READING
- if some threads want to modify the same value at the same time? how to protect value of each node?
	- make a mutex/node
- how to make a dictionary "thread-safe"?

5. in a forest we have "stupi si ursi" - stupi-ursi-padurari - cand ursul se trezeste, ... aduce miere din depozit, padurarul doarme si se trezeste cand nu mai este miere -> protectia mierii, trezitul padurarului
- 3 types of threads: -> void* stup, void* urs, void* padurar
	- stup - one thread
	- ursi - another thread
	- padurar - another thread
		- when he wakes up, prints "^"
		- when he goes to sleep, prints "v"
- variables:
	- honey - it is a quantity, a variable (n=0 in the beginning)
- cat produc stupii? 
- cat mananca un urs?
- how to protect the honey?
	- using a mutex -> pthread_mutex_t m
- who wakes the padurar?
	- ursii
		- if they have enough honey, they eat it, if not, they wake the padurar
- albinele (stup)
	- produc miere
	- lock/unlock
=> it writes a bunch of characters in a file
=> de la semnalare pana la trezire trece totusi un pic de vreme
=> see paterns in that file (perioada de foamete - a lot of !, padurar wakes up and goes to sleep ^v)
- more than 3 bears can't eat at the same time
	- solve this using a semaphore
	- where should the semaphore be blocked? where to put sem_wait and sem_block?
	- can i protect a single line using semaphores or can i protect more?
	- i could protect all the while
	- are voie ursul sa se planga daca nu are voie sa manance? nu. harsh.
	- sem_post(&s);
	- use printf, not debugger for this case (no chance with dbg)
- no bears can eat until all bears have washed their hands
	- pthread_barrier_ t b


Implementare silvică (final):
```
#include <stdio.h>
#inckude <pthread.h>
#include <semaphore.h>

#define S 10
#define U 7

int miere=0;
pthread_mutex_t m;
pthread_cond_t c;
sem_t s;

void* stup(void* a) {
	while(1) {
		pthread_mutex_lock(&m);
		miere++;
		printf("+");
		pthread_mutex_unlock(&m);
	}
	(void)a;
	return NULL;
}

void* urs(void* a) {
	while(1) {
		pthread_mutex_lock(&m);
		if(miere <5) {
			pthread_cond_signal(&c);
			printf("!");
			pthread_mutex_unlock(&m);
			continue;
		}
		miere -=5;
		printf("-");
		pthread_mutex_unlock(&m);
	
	}
	return NULL;
}

void* padurar(void* a) {
	while(1) {
		pthread_mutex_lock(&m);
		while(miere >=5) {
			printf("v"); // enough honey, go to sleep
			pthread_cond_wait(&c, &m);
			printf("^");
		}
		printf("@");
		miere +=20;
		pthead_mutex_unlock(&m);
	}
	(void)a;
	return NULL;
}

int main(int argc, char** argv) {
	pthread_t stupi[S], ursi[U], padu;
	(void)argc;
	(void)argv;
	return 0;
}

```

pasi:
- initial state of thread functions:
![[Pasted image 20260429101647.png]]
- create thread functions:
![[Pasted image 20260429101227.png]]
- urs and padurar threads:
![[Pasted image 20260429101306.png]]
- sem_init library: ![[Pasted image 20260429101815.png]]

- now we wanna use semaphores - how many lines can the semaphore protect?
![[Pasted image 20260429101950.png]]



- main:
- pass NULL to pthread_mutex_init and pthread_cond_init !
![[Pasted image 20260429102528.png]]


- sem_post(&s) is dangerous - it will block - use a "thread safe" instead ?
![[Pasted image 20260429102219.png]]


- main that solves the problem with "3 bears can't eat at the same time"
- sem_init(&s, 0,3);
![[Pasted image 20260429102317.png]]


- run the program and look at templates
![[Pasted image 20260429102354.png]]




- how could we use the semaphore between processes?
	- the semaphore lacks a ... so we can use it between processes?
	- ce are fifo si nu are pipe? a NAME. 
	- it does not have a name, it has a number. 
- flow of solving this prolem (photos)
	- create 3 threads


### Test 3 prep - processes

##### Theory:
1) FIFO = NAMED PIPE
- special file on the disk
- used for communication between unrelated processes
- pipes don't persist after processes exit
- FIFOs persist after processes exit
- CREATE FIFO:
```
mkfifo("my_fifo", 0600)
```
- OPEN FIFO for reading:
```
open("my_fifo", O_RDONLY) // waits for a reader
```
- OPEN FIFO for writing:
```
open("my_fifo", O_WRONLY); // waits for a writer
```
- TRANSFER:
```
read() -> means "blocking" -> if one process hasn't sent the data yet, the current process pauses at that line
	 > 0 => SUCCESSFUL READING
	 =0 => EOF => NO MORE DATA 
	 <0 => ERROR => PERROR
write() -> means "blocking" -> if buffer is full or no reader ready, process pauses at that line
	 > 0 => SUCCESSFUL WRITE (bytes written)
	 =0 => NOTHING WRITTEN (rare)
	 <0 => ERROR => PERROR (no reader -> sigpipe/epipe)
```
- CLOSE:
```
close() -> closes file descriptor -> releases FIFO endpoint -> frees resources and allows other processes to detect termination
	reader closes -> writers may get SIGPIPE/EPIPE on write()
	writer closes -> readers get 0 (EOF) on read()
```
2) 

##### Problem 1:
Write multiple C programs that can be labeled as A,B,C
Process A: 
- will read from keyboard lowercase strings (scanf)
- that can contain alphanumerical characters
- until X is written (strcmp)
- will send them to process B using FIFOs (write a2b)
Process B:
- will receive the string from process A
- will initiate a vector V with 11 zeroes
- it will iterate over it character by character checking if the character is a digit or not
- it will increment an index of the vector 
- this frequency vector for the digits + non-digits found in the string will be send to process A and process C
Process C:
- will receive the frequency vector from the process B
- will sum up all the values 
- will send back to process A 
- process A will print it on the screen
Implement the processes communication schema
Programs are responsible to check if the fifo exists and create it if it is not already.
![[Pasted image 20260430194129.png]]

FIFO Solution:
A.c:
```
#include <stdio.h> // printf, scanf
#include <stdlib.h> // exit
#include <string.h> // strlen, strcmp
#include <unistd.h> // read, write, close
#include <fcntl.h> // open
#include <sys/stat.h> // mkfifo

int main() {
	mkfifo("a2b", 0600); // fifo A->B, permission only to myself
	mkfifo("b2a", 0600); // fifo B->A (send vector to A)
	mkfifo("c2a", 0600); // fifo C->A (send sum to A)
	
	// ORDER OF RUNNING IN TERMINAL: b->c->a
	int a2b=open("a2b", O_WRONLY); // i wanna send data from a to b
	int b2a=open("b2a", O_RDONLY);
	int c2a=open("c2a", O_RDONLY);
	
	if(a2b<0 || b2a < 0 || c2a < 0) { // open failed
		perror("open");
		exit(1);
	}
	
	char s[100]; // input
	int n, v[11]; // vector
	int sum; // "process A will print it on the screen"
	
	while(1) {
		printf("Give from keyboard lowercase strings (type X to exit):" );
		scanf("%s", s); // read string with no spaces
		
		n = strlen(s); // compute its length
		
		if(strcmp(s, "X")==0)
			break;
		
		write(a2b, &n, sizeof(int)); // send length to B
		write(a2b, s, n); // send string to B
		
		read(b2a, v, 11*sizeof(int)); // receive vector from B
		read(c2a, &sum, sizeof(int)); // receive sum from C
		
		// vector after summing up in C all the values from the vector from B
		printf("Vector: ");
		for(int i=0; i<11; i++) 
			printf("%d", v[i]);
		printf("\n");
		prinf("Sum received is: %d\n", sum);
		
	}
	close(a2b);
	close(b2a);
	close(c2a);
	return 0;
}
```

B.c:
```
#include ...

int main() {
	mkfifo("a2b", 0600);
	mkfifo("b2a", 0600);
	mkfifo("b2c", 0600);
	
	int a2b=open("a2b", O_RDONLY);
	int b2a=open("b2a", O_WRONLY);
	int b2c=open("b2c", O_WRONLY);
	
	if(a2b<0 || b2a<0 || b2c<0) {
		perror("open");
		exit(1);
	}
	
	char s[100];
	int n;
	
	while(1) { // process A sends multiple strings until X is typed
		if(read(a2b, &n, sizeof(int))<=0)
			break;
		if(read(a2b, s, n)<=0)
			break;
		
		int v[11]={0}; // reset for each iteration (we are in a while)
		
		for(int i=0; i<n; i++) {
			if(s[i]>='0' && s[i]<='9')
				v[s[i]-'0']++; // convert character to integer and 
			else
				v[10]++;
		}
		write(b2a, v, 11*sizeof(int));
		write(b2c, v, 11*sizeof(int));
	}
	close(a2b);
	close(b2a);
	close(b2c);
	return 0;
}
```

C.c:
```
#include ...

int main() {
	mkfifo("b2c", 0600);
	mkfifo("c2a", 0600);
	
	int b2c=open("b2c", O_RDONLY);
	int c2a=open("c2a", O_WRONLY);
	
	if(b2c<0 || c2a<0) {
		perror("open");
		exit(1);
	}
	
	int v[11];
	
	while(1) {
		if(read(b2c, v, 11*sizeof(int))<=0) // program stops and waits for exactly 11 integers
			break;
		int sum = 0;
		for(int i=0; i<11; i++)
			sum +=v[i];
		write(c2a, &sum, sizeof(int)); // send result to a
	}
	close(b2c);
	close(c2a);
	return 0;
}
```

Pipes solution:
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int a2b[2];
	int b2a[2];
	int b2c[2];
	int c2a[2];
	
	pipe(a2b);
	pipe(b2a);
	pipe(b2c);
	pipe(c2a);
	
	if(fork()==0) { // child process C
		close(b2c[1]); // c never writes to b
		close(c2a[0]); // c never reads from a
		close(a2b[0]); // c never uses a->b
		close(a2b[1]);
		close(b2a[0]); // c never uses b->a
		close(b2a[1]);
		
		int v[11]; // vector received from b
		
		while(1) {
			if(read(b2c[0], v, 11*sizeof(int))<=0) // read from b 
				break;
			int sum=0;
			for(int i=0; i<11; i++)
				sum +=v[i];
			write(c2a[1], &sum, sizeof(int)); // send to a
		}
		
		close(b2c[0]); // close read end from b
		close(c2a[1]); // close write end to a
		exit(0); // child (c) finishes
	}
	
	if(fork()==0) { // child process B
		close(a2b[1]);
		close(b2a[0]);
		close(b2c[0]);
		close(c2a[0]);
		close(c2a[1]);
		
		char s[100]; // string received from a
		int n;
		
		while(1) {
			if(read(a2b[0], &n, sizeof(int))<=0) // read string length
				break;
			if(read(a2b[0], s, n*sizeof(char))<=0) // read string chars
				break;
				
			int v[11] = {0};
			
			for(int i=0; i<n; i++) {
				if(s[i]>='0' && s[i]<='9')
					v[s[i]-'0']++;
				else
					v[10]++;
			}
			write(b2a[1], v, 11*sizeof(int)); // send to a
			write(b2c[1], v, 11*sizeof(int)); // send to c
		} 
		// what we actually used for B
		close(a2b[0]);
		close(b2a[1]);
		close(b2c[1]);
		exit(0);
	}
	close(a2b[0]);
	close(b2a[1]);
	close(c2a[1]);
	close(b2c[1]);
	close(b2c[0]);
	 
	char s[100]; // keyboard input
	int n; // string length
	int v[11]; // vector received from b
	int sum; // sum received from c
	
	while(1) {
		printf("Insert string or X to exit: ");
		scanf("%s", s);
		
		n=strlen(s);
		
		if(strcmp(s, "X")==0)
			break;
		
		write(a2b[1], &n, sizeof(int)); // send string length to b
		write(a2b[1], s, n*sizeof(char)); // send string to b
		
		read(b2a[0], v, 11*sizeof(int)); // receive vector from b
		read(c2a[0], &sum, sizeof(int)); // receive sum from c
		
		printf("Vector: ");
		for(int i=0; i<11; i++) 
			printf("%d", v[i]);
		printf("\n");
		printf("Sum received is: %d\n", sum);
	}
	// what we actually used for A
	close(a2b[1]);
	close(b2a[0]);
	close(c2a[0]);
	
	wait(0);
	wait(0);
	return 0;
}
```

##### Problem 2:
Write a C program that will read from keyboard some strings (until X is written).
The main process will start two types of child processes: A and B started every time a string is read from keyboard
Child Process A:
- parent will send the string to the created child A process using pipes
- each child process (A) will receive the string and it will iterate over it character by character checking if the character is an uppercase/lowercase letter
	- if uppercase letter -> add letter in vector U
	- if lowercase letter -> add letter in vector L
	- if not letter -> increment shared variable S
- send S to the parent using pipes, parent will print it on the screen
- send L, U to Process B
Child Process B:
- will receive L, U from Child Process A with a pipe
- will sum up their sizes and print the result on the screen

! S is not a global variable although it says "shared variable" because pipes are themselves the sharing mechanism
![[Pasted image 20260501125147.png]]

Pipes Solution:
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	int p2a[2];
	int a2p[2];
	int a2b[2];
	
	pipe(p2a);
	pipe(a2p);
	pipe(a2b);
	
	if(fork()==0) { // child A
		close(p2a[1]);
		close(a2p[0]);
		close(a2b[0]);
		
		char s[256]; // keyboard string
		char l[256]; // lowercase
		char u[256]; // uppercase
		int n; // keyboard string length
		
		while(1) {
			if(read(p2a[0], &n, sizeof(int))<=0) // read length from p
				break;
			if(read(p2a[0], s, n)<=0) // read string from p
				break;
			
			int S=0; // shared variable S (nr of non-letters)
			int j=0; // size of L
			int k=0; // size of U
			
			for(int i=0; i<n; i++) { 
				if(s[i]>='a' && s[i]<='z')  // lowercase
					l[j++]=s[i];
				else if(s[i]>='A' && s[i]<='Z') // uppercase
					u[k++]=s[i];
				else
					S++;
			}
			write(a2p[1], &S, sizeof(int)); // send S to p
			
			write(a2b[1], &j, sizeof(int)); // send size of L to b
			if(j>0) 
				write(a2b[1], l, j*sizeof(char)); // send lowercase vector
			
			write(a2b[1], &k, sizeof(int));
			if(k>0)
				write(a2b[1], u, k*sizeof(char)); // send uppercase vector
		} 
		// what we actually used in child A
		close(p2a[0]);
		close(a2p[1]);
		close(a2b[1]);
		exit(0);
	}
	if(fork()==0) { // child B
		close(p2a[0]);
		close(p2a[1]);
		close(a2p[0]);
		close(a2p[1]);
		close(a2b[1]);
		
		char l[256]; // lowercase vector L received from a
		char u[256]; // uppercase vector U received from a
		int j; // size of L
		int k; // size of U
		
		while(1) {
			if(read(a2b[0], &j, sizeof(int))<=0) // read size of lowercase vector L
				break;
			
			if(j>0)
				if(read(a2b[0], l, j*sizeof(char))<=0) // read vector L
					break;
			
			if(read(a2b[0], &k, sizeof(int))<=0) // read size of uppercase vector U
				break;
			
			if(k>0)
				if(read(a2b[0], u, k*sizeof(char))<=0) // read vector U
					break;
			
			printf("The sizes are: %d\n", j+k); // total letters
		}
		// what we actually used in child B
		close(a2b[0]);
		exit(0);
	}
	// parent process
	close(p2a[0]);
	close(a2p[1]);
	close(a2b[0]);
	close(a2b[1]);
	
	char s[256];
	
	while(1) {
		printf("Insert string of X to exit: ");
		scanf("%s", s);
		
		if(strcmp(s, "X")==0)
			break;
		
		int n=strlen(s);
		
		write(p2a[1], &n, sizeof(int)); // send length to a
		write(p2a[1], s, n*sizeof(char)); // send string to a
		
		int S; // result from A
		read(a2p[0], &S, sizeof(int)); // read count from a
		printf("S is: %d\n", S);  // parent prints S
	}
	// what we actually used in parent P:
	close(p2a[1]);
	close(a2p[0]);
	
	wait(0);
	wait(0);
	return 0;
}

```

##### Problem 3:
Write 3 C programs, A,B,C using FIFOs
Process C:
- reads strings from keyboard until X is written
- sends each string to process A
- receives from A a vector with 26 positions
- prints the frequency of each lowercase letter a to z
Process A:
- receives a string from process C
- computes vector v[26], where
	- v[0] = number of a
	- v[1] = number of b
	- ...
	- v[25] = number of z
- sends this vector to B
- sends the same vector back to C
Process B:
- receives vector from A
- computes the total number of lowercase letters
- prints this sum

FIFO Solution:
a.c:
```
#include <sys/stat.h>

int main() {
	int c2a, a2b, a2c;
	
	mkfifo("c2a", 0600);
	mkfifo("a2b", 0600);
	mkfifo("a2c", 0600);
	
	c2a=open("c2a", O_RDONLY);
	a2b=open("a2b", O_WRONLY);
	a2c=open("a2c", O_WRONLY);
	
	if(c2a<0 || a2b<0 || a2c<0) {
		perror("open");
		exit(1);
	}
	
	int n;
	char s[100];
	
	while(1) {
		if(read(c2a, &n, sizeof(int))<=0)
			break;
		if(read(c2a, s, n*sizeof(char))<=0)
			break;
			
		int v[26]={0};
		
		for(int i=0; i<n; i++) {
			if(s[i]>='a' && s[i]<='z')
				v[s[i]-'a']++;
		}
		write(a2b, v, 26*sizeof(int));
		write(a2c, v, 26*sizeof(int));
	}
	close(c2a);
	close(a2b);
	close(a2c);
	
	return 0;
}
```

b.c:
```
#include ...

int main() {
	int a2b;
	
	mkfifo("a2b", 0600);
	
	a2b=open("a2b", O_RDONLY);
	
	if(a2b<0) {
		perror("open");
		exit(1);
	}
	
	int v[26];
	
	while(1) {
		if(read(a2b, v, 26*sizeof(int))<=0)
			break;
		int sum=0;
		for(int i=0; i<26; i++)
			sum +=v[i];
		printf("Sum is: %d\n", sum);
	}
	close(a2b);
	return 0;
}
```

c.c:
```
#include ...

int main() {
	int c2a, a2c;
	
	mkfifo("c2a", 0600);
	mkfifo("a2c", 0600);

	c2a=open("c2a", O_WRONLY); // writes to a
	a2c=open("a2c", O_RDONLY); // reads from a
	
	if(c2a<0 || a2c<0) { // <0 => ERROR AT FIFO
		perror("open");
		exit(1);
	}
	
	char s[100];
	int n;
	int v[26];
	
	while(1) {
		printf("Insert a string or x to exit: ");
		scanf("%s", s);
		
		if(strcmp(s, "x")==0)
			break;
			
		n=strlen(s);
		
		write(c2a, &n, sizeof(int));
		write(c2a, s, n*sizeof(char));
		
		if(read(a2c, v, 26*sizeof(int))<=0)
			break;
		
		for(int i=0; i<26; i++)
			printf("%c -> %d\n", 'a'+i, v[i]);
	}
	close(c2a);
	close(a2c);
	
	return 0;
}
```

Pipes Solution:
- PRINTS SUM WEIRDLY
```
#include ...


int main() {
	int c2a[2];
	int a2c[2];
	int a2b[2];
	
	pipe(c2a);
	pipe(a2c);
	pipe(a2b);
	
	if(fork()==0) { // child b
		close(a2b[1]);
		close(c2a[0]);
		close(c2a[1]);
		close(a2c[0]);
		close(a2c[1]);
		
		int v[26];
		
		while(1) {
			if(read(a2b[0], v, 26*sizeof(int))<=0)
				break;
			
			int sum = 0;
			for(int i=0; i<26; i++)
				sum +=v[i];
			printf("Sum is: %d\n", sum);
		}
		// what we actually used in b
		close(a2b[0]);
		exit(0); // bc it's a child
	}
	if(fork()==0) { // child a
		close(c2a[1]);
		close(a2c[0]);
		close(a2b[0]);
		
		int n;
		char s[100];
		
		while(1) {
			if(read(c2a[0], &n, sizeof(int))<=0)
				break;
			if(read(c2a[0], s, n*sizeof(char))<=0)
				break;
			
			int v[26]={0};
			
			for(int i=0; i<n; i++) {
				if(s[i]>='a' && s[i]<='z')
					v[s[i]-'a']++;
			}
			
			write(a2c[1], v, 26*sizeof(int));
			write(a2b[1], v, 26*sizeof(int));
		}
		// what we actualy used in a
		close(c2a[0]);
		close(a2c[1]);
		close(a2b[1]);
		exit(0);
	}
	// process c (parent)
	close(c2a[0]);
	close(a2c[1]);
	close(a2b[0]);
	close(a2b[1]);
	
	char s[100];
	int n;
	int v[26];
	
	while(1) {
		printf("Insert string or x to exit: ");
		scanf("%s", s);
		
		if(strcmp(s, "x")==0)
			break;
		
		n=strlen(s);
		
		write(c2a[1], &n, sizeof(int)); // send length to a
		write(c2a[1], s, n*sizeof(char)); // send string to a
		
		if(read(a2c[0], v, 26*sizeof(int))<=0) // no data was read successfully
			break;
		
		for(int i=0; i<26; i++)
			printf("%c -> %d\n", 'a'+i, v[i]);
		
		fflush(stdout);
		usleep(1000);
	}
	// what we actually used in c
	close(c2a[1]);
	close(a2c[0]);
	
	wait(0);
	wait(0);
	return 0;
}
```

##### Problem 4:
Write 2 C programs, A, B using one FIFO
Process A:
- receives two numbers as command-line arguments (nr1, nr2)
- creates two child processes
	- first child computes the sum (nr1 + nr2)
	- second child computes the product (nr1 * nr2)
- both children send their result to process B through the FIFO

Process B:
- receives the FIFO name as command-line argument
- reads the two numbers sent by A
- computes their GCD
- prints the GCD

FIFO Solution:
a.c:
```
#include ...

int main(int argc, char **argv) {
	if(argc!=3) {
		printf("Please give 2 numbers\n");
		exit(1);
	}
	
	mkfifo("fifo", 0600); // create fifo if it does not exist
	
	int nr1 = atoi(argv[1]); // first number
	int nr2 = atoi(argv[2]); // second number
	
	int fd_write = open(argv[3], O_WRONLY); // open fifo for writing
	
	if(fd_write<0) {
		perror("open");
		exit(1);
	}
	
	if(fork()==0) { // first child
		int sum = nr1+nr2;
		write(fd_write, &sum, sizeof(int)); // send to b
		close(fd_write);
		exit(0);
	}
	
	if(fork()==0) {
		int prod = nr1*nr2;
		write(fd_write, &prod, sizeof(int));
		close(fd_write);
		exit(0);
	}
	
	wait(0);
	wait(0);
	close(fd_write);
	return 0;
}
```

b.c:
```
#include ...

int main(int argc, char **argv) {
	if(argc!=2) {
		printf("Please give FIFO name\n");
		exit(1);
	}
	
	mkfifo(argv[1], 0600);
	
	int fd_read = open(argv[1], O_RDONLY);
	
	if(fd_read<0) {
		perror("open");
		exit(1);
	}
	
	int x,y;
	
	if(read(fd_read, &x, sizeof(int))<=0) { // read first value (nr1)
		perror("read");
		close(fd_read);
		exit(1);
	}
	
	if(read(fd_read, &y, sizeof(int))<=0) { // read second value (nr2)
		perror("read");
		close(fd_read);
		exit(1);
	}
	
	int a=x; // copy first received value
	int b=y; // copy second received value
	
	while(b!=0) { // euclid algorithm for GCD
		int r = a%b;
		a=b;
		b=r;
	}
	
	printf("GCD of %d and %d is: %d\n", x,y,a);
	close(fd_read);
	return 0;
}
```

##### Problem 5:
Write a C program that creates two processes, A and B, using pipes
Process A:
- generates a random number between 50 and 199
- if number is odd, make it even
- send the number to B
- receive numbers back from B
- while the received number is greater than 5
	- print it
	- if odd, make it even
	- send it again to B
Process B:
- receives number from A
- divides it by 2
- sends the result back to A
- repeats until pipe closes

```
#include ...

int main() {
	int a2b[2];
	int b2a[2];
	int n;
	
	pipe(a2b);
	pipe(b2a);
	
	if(fork()==0) { // process A
		close(a2b[0]);
		close(b2a[1]);
		
		srand(time(NULL)^getpid());
		
		n=rand()%150+50; // 0-149 -> 50-199
		printf("Generated number: %d\n, n);
		
		if(n%2==1)
			n++;
			
		write(a2b[1], &n, sizeof(int)); // send first number to b
		
		while(1) { 
			if(read(b2a[0], &n, sizeof(int))<=0) // receive from b
				break;
			if(n<=5)
				break;
			printf("N is %d\n",  n);
			if(n%2==1)
				n++;
			write(a2b[1], &n, sizeof(int));
		}
		// what is actually used in child a
		close(a2b[1]);
		close(b2a[0]);
		exit(0);
	}
	
	// process B = parent
	close(a2b[1]);
	close(b2a[0]);
	
	while(1) {
		if(read(a2b[0], &n, sizeof(int))<=0) // receive from a
			break;
		n=n/2;
		write(b2a[1], &n, sizeof(int)); // send to a
	}
	// what is actually used in process b
	close(a2b[0]);
	close(b2a[1]);
	wait(0);
	return 0;
}
```

##### Problem 1/UNIX processes
![[Pasted image 20260502214239.png]]
```
// write a program that creates n child processes
// each child process will print its PID and its parent PID
// parent process will print its PID and the PID of each of the child processes
#include <unistd.h> // fork, getpid, getppid
#include <stdio.h> // printf, perror
#include <stdlib.h> // atoi, exit
#include <sys/wait.h> // wait

int main(int argc, char **argv) {
	if(argc !=2) {
		perror("Usage: ./p1 <n> ");
		exit(1);
	}
	int n=atoi(argv[1]);
	for(int i=0; i<n; i++) {
		pid_t f=fork();
		if(f<0){
			perror("fork");
			exit(1);
		}
		if(f==0) {
			printf("child %d: PID=%ld, PPID=%ld\n", i, (long)getpid(), (long)getppid());
			exit(0);
		}
		else {
			printf("parent %ld: created child %ld\n", (long)getpid(), (long)f);
		}
	}
	for(int i=0; i<n; i++) {
		wait(0);
	}
	return 0;
}
```

##### Problem 6/UNIX processes
![[Pasted image 20260502220556.png]]
```
// generate n random integers
// create a child
// send numbers via pipe
// child calculates the average and sends the result back to parent

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char **argv) {
	if(argc!=2) {
		printf("Usage: ./p6 <n> ");
		exit(1);
	}
	int n=atoi(argv[1]);
	int p2c[2];
	int c2p[2];
	pipe(p2c);
	pipe(c2p);
	
	int *v= malloc(n*sizeof(int));
	srand(getpid());// different each run
	for(int i=0; i<n; i++) {
		v[i]=rand()%1000; // 0-999
	}

	printf("\n");

	pid_t f=fork();

	if(f<0) {
		perror("fork");
		exit(1);
	}
	// child
	if(f==0) { // child
		close(p2c[1]);
		close(c2p[0]);
		read(p2c[0],&n,sizeof(int));
		int *child_v=malloc(n*sizeof(int));
		read(p2c[0],child_v,n*sizeof(int));

		double avg;
		int sum=0;
	
		for(int i=0; i<n; i++){
			sum +=child_v[i];
		}
		avg=(double)sum/n;

		write(c2p[1], &avg, sizeof(double));
		free(child_v);
		close(p2c[0]);
		close(c2p[1]);
		exit(0);
	}
	// parent
	close(c2p[1]);
	close(p2c[0]);

	write(p2c[1], &n, sizeof(int));
        write(p2c[1], v, n*sizeof(int));

	double avg;
	read(c2p[0],&avg,sizeof(double));
	printf("average: %f\n",avg);
	free(v);
	close(c2p[0]);
	close(p2c[1]);
	wait(0); 
	return 0;
}

```

##### Problem 33/UNIX processes
![[Pasted image 20260502233428.png]]
```
// create 2 child processes
// parent reads one string from keyboard (no whitespaces)
// parent sends to both children that string
// child a extracts all vowels from received string -> send to parent
// child b extracta all the digits from received string -> send to parent
// parent prints the strings received from children
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

int main() {
	int p2a[2];
	int a2p[2];
	int p2b[2];
	int b2p[2];
	pipe(p2a);
	pipe(a2p);
	pipe(p2b);
	pipe(b2p);
	char s[256];
	scanf("%s",s);
	int n=strlen(s);
	pid_t f=fork();
	if(f<0) {
		perror("fork");
		exit(1);
	}
	if(f==0) { // child a
		close(p2a[1]);
		close(a2p[0]);
		close(p2b[0]);
		close(p2b[1]);
		close(b2p[0]);
		close(b2p[1]);

		read(p2a[0],&n,sizeof(int));
		read(p2a[0],s,n*sizeof(char));

		char *vowels=malloc((n+1)*sizeof(char));
		int k=0;

		for(int i=0; i<n; i++) {
			char ch=tolower(s[i]);
			if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
				vowels[k++]=s[i];
		}
		vowels[k]='\0';

		write(a2p[1],&k,sizeof(int));
		write(a2p[1],vowels,k*sizeof(char));

		free(vowels);
		close(a2p[1]);
		close(p2a[0]);
		exit(0);
	}
	pid_t g=fork();
	if(g<0) {
		perror("fork");
		exit(1);
	}
	if(g==0) { // child b
		close(p2b[1]);
		close(b2p[0]);
		close(p2a[0]);
		close(p2a[1]);
		close(a2p[0]);
		close(a2p[1]);

		read(p2b[0],&n,sizeof(int));
                read(p2b[0],s,n*sizeof(char));

		char *digits=malloc((n+1)*sizeof(char));
		int j=0;

		for(int i=0; i<n; i++) {
			if(s[i]>='0' && s[i]<='9')
				digits[j++]=s[i];
		}
		digits[j]='\0';

		write(b2p[1],&j,sizeof(int));
		write(b2p[1],digits,j*sizeof(char));

		free(digits);
		close(b2p[1]);
		close(p2b[0]);
		exit(0);
	}
	//parent
	close(p2a[0]);
	close(p2b[0]);
	close(a2p[1]);
	close(b2p[1]);

	write(p2a[1], &n, sizeof(int));
	write(p2a[1], s, n*sizeof(char));

	write(p2b[1], &n, sizeof(int));
        write(p2b[1], s, n*sizeof(char));

	close(p2a[1]);
	close(p2b[1]);

	int k;
	char vowels[256];

	read(a2p[0],&k,sizeof(int));
	read(a2p[0],vowels,k*sizeof(char));
	vowels[k]='\0'; // in parent as well!

	printf("Vowels: %s\n",vowels);

	int j;
	char digits[256];

	read(b2p[0],&j,sizeof(int));
	read(b2p[0],digits,j*sizeof(char));
	digits[j]='\0';

	printf("Digits: %s\n",digits);

	close(a2p[0]);
	close(b2p[0]);

	wait(0);
	wait(0);
	return 0;
}
```

##### Problem 10/UNIX processes
![[Pasted image 20260503083346.png]]
```
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	int a2b[2];
	int b2a[2];
	pipe(a2b);
	pipe(b2a);
	pid_t f=fork();
	if(f<0) {
		perror("fork");
		exit(1);
	}
	if(f==0) { // process A
		close(a2b[0]);
		close(b2a[1]);
		int n;
       		srand(getpid());
        	n=rand()%151+50;
		if(n%2==1){
			n=n+1;
		}
		printf("A sends: %d\n",n);
		write(a2b[1],&n,sizeof(int));
		while(1) {
			if(read(b2a[0],&n,sizeof(int))<=0)
				break;
			printf("A received: %d\n", n);
			if(n<5)
				break;
			if(n%2==1)
				n++;
			write(a2b[1],&n,sizeof(int));
		}
		close(b2a[0]);
		close(a2b[1]);
		exit(0);
	}
	// process B
	close(a2b[1]);
	close(b2a[0]);
	int n;
	while(1) {
		if(read(a2b[0],&n,sizeof(int))<=0)
			break;
		printf("B received: %d\n",n);
        	n=n/2;
		printf("B sends: %d\n",n);
        	write(b2a[1],&n,sizeof(int));

	}
	close(a2b[0]);
	close(b2a[1]);
	wait(0);
	return 0;
}
```

##### Problem 7a/UNIX processes
![[Pasted image 20260503090443.png]]

p7a.c
```
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	mkfifo("a2b",0600);
	mkfifo("b2a",0600);
	int a2b=open("a2b", O_WRONLY);
	int b2a=open("b2a", O_RDONLY);
	if(a2b<0 || b2a<0) {
		perror("open");
		exit(1);
	}
	srand(getpid());
	int n;
	while(1){
		n=rand()%10+1;
		printf("A sends: %d\n", n);
		write(a2b,&n,sizeof(int));
		if(n==10)
			break;
		if(read(b2a,&n,sizeof(int))<=0)
			break;
		printf("A received: %d\n",n);
		if(n==10)
			break;
	}
	close(a2b);
	close(b2a);
	unlink("a2b");
	unlink("b2a");
	return 0;
}

```

p7b.c:
```
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	int a2b=open("a2b",O_RDONLY);
	int b2a=open("b2a",O_WRONLY);
	if(a2b<0 || b2a<0) {
		perror("open");
		exit(1);
	}
	srand(getpid());
	while(1) {
		int n;
		if(read(a2b,&n,sizeof(int))<=0)
			break;
		printf("B received: %d\n",n);
		if(n==10)
			break;
		n=rand()%10+1;
		printf("B sends: %d\n",n);
		write(b2a,&n,sizeof(int));
		if(n==10)
			break;
	}
	close(a2b);
	close(b2a);
	return 0;
}
```

##### Problem 13/UNIX processes
![[Pasted image 20260503133442.png]]
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char	**argv) {
	int a2b[2];
	int b2c[2];
	int c2a[2];
	pipe(a2b);
	pipe(b2c);
	pipe(c2a);
	//process A
        if(argc!=2) {
        	printf("Usage: ./p13 <n>");
                exit(1);
       	}
        int n=atoi(argv[1]);
        int *v=malloc(n*sizeof(int));
       	for(int i=0; i<n; i++) {
        	scanf("%d",&v[i]);
        }
	printf("Process A sends these numbers: ");
        for(int i=0; i<n; i++)
		printf("%d ",v[i]);
	printf("\n");
	pid_t f=fork();
	if(f<0) {
		perror("fork");
		exit(1);
	}
	if(f==0) { // process b
		close(a2b[1]);
		close(b2c[0]);
		close(c2a[0]);
		close(c2a[1]);
		int n;
		read(a2b[0],&n,sizeof(int));
		int *v=malloc(n*sizeof(int));
		read(a2b[0],v,n*sizeof(int));
		printf("Process B receives these numbers: ");
		for(int i=0; i<n; i++)
			printf("%d ",v[i]);
		printf("\n");
		srand(getpid());
		for(int i=0;i<n;i++) {
			int rnr=rand()%4+2;
			v[i]=v[i]+rnr;
		}
		printf("Process B sends these numbers: ");
		for(int i=0; i<n; i++)
			printf("%d ",v[i]);
		printf("\n");
		write(b2c[1],&n,sizeof(int));
		write(b2c[1],v,n*sizeof(int));
		free(v);
		close(a2b[0]);
		close(b2c[1]);
		exit(0);
	}
	pid_t g=fork();
	if(g<0) {
		perror("fork");
		exit(1);
	}
	if(g==0) { // process c
		close(a2b[1]);
		close(a2b[0]);
		close(b2c[1]);
		close(c2a[0]);
		int n;
		read(b2c[0],&n,sizeof(int));
		int *v=malloc(n*sizeof(int));
		read(b2c[0],v,n*sizeof(int));
		printf("Process C receives these numbers: ");
		for(int i=0; i<n; i++)
			printf("%d ",v[i]);
		printf("\n");
		int sum=0;
		for(int i=0; i<n; i++)
			sum +=v[i];
		printf("Process C sends this sum: %d\n",sum);
		write(c2a[1],&sum,sizeof(int));
		free(v);
		close(b2c[1]);
		close(c2a[1]);
		exit(0);
	}
	// back to process a
	close(c2a[1]);
	close(a2b[0]);
	close(b2c[0]);
	close(b2c[1]);
	write(a2b[1],&n,sizeof(int));
	write(a2b[1],v,n*sizeof(int));
	close(a2b[1]);
	int sum=0;
	read(c2a[0],&sum,sizeof(int));
	printf("Process A received sum: %d",sum);
	free(v);
	close(c2a[0]);
	wait(0);
	wait(0);
	return 0;
}
```


##### Problem8/UNIX processes
![[Pasted image 20260503145238.png]]

p8a.c:
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc,char **argv) {
	mkfifo("a2b",0600);
	mkfifo("b2a",0600);
	int a2b=open("a2b",O_WRONLY);
	int b2a=open("b2a",O_RDONLY);
	for(int i=1;i<argc;i++){
		int len=strlen(argv[i]);
		write(a2b,&len,sizeof(int));
		write(a2b,argv[i],len);
	}
	close(a2b); // done sending

	char result[256]="";
	int len;
	while(read(b2a,&len,sizeof(int))>0) {
		char s[256]={0};
		read(b2a,s,len);
		strcat(result,s);
		strcat(result," ");
	}
	printf("Result: %s\n",result);
	close(b2a);
	unlink("a2b");
	unlink("b2a");
	return 0;
}

```

p8b.c:
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
int main() {
	int a2b=open("a2b",O_RDONLY);
	int b2a=open("b2a",O_WRONLY);
	int len;
	while(read(a2b,&len,sizeof(int))>0) {
		char *s=malloc(len+1);
		read(a2b,s,len);
		s[len]='\0';
		for(int i=0;i<len;i++) {
			s[i]=toupper(s[i]);
		}
		write(b2a,&len,sizeof(int));
		write(b2a,s,len);
		free(s);
	}
	close(a2b);
	close(b2a);
	return 0;
}
```

##### Problem 9/UNIX processes !!!!
![[Pasted image 20260503155912.png]]
###### solution with fifos, popen
p9a.c:
```
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
	mkfifo("a2b",0600);
	int a2b=open("a2b",O_WRONLY);
	if(a2b<0) {
		perror("open");
		exit(1);
	}
	char cmd[256];
	char buffer[256];
	while(1) {
		printf("Command: ");
		fgets(cmd,256,stdin);
		cmd[strlen(cmd)-1]='\0';
		if(strcmp(cmd,"stop")==0)
			break;
		FILE *p=popen(cmd,"r");
		if(p==NULL) {
			perror("popen");
			continue;
		}
		while(fgets(buffer,256,p)!=NULL) {
			write(a2b,buffer,strlen(buffer));
		}
		pclose(p);
	}
	close(a2b);
	unlink("a2b");
	return 0;
}


```
p9b.c:
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int a2b=open("a2b",O_RDONLY);
	if(a2b<0) {
		perror("open");
		exit(1);
	}
	char buffer[256];
	int n;
	while((n=read(a2b,buffer,255))>0) {
		buffer[n]='\0';
		printf("%s",buffer);
	}
	close(a2b);
	return 0;
}
```

###### solution with fork + pipes + dup2 + execlp !!!
p9b1.c
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

int main() {
	mkfifo("a2b", 0600);
	int a2b=open("a2b", O_WRONLY);
	if(a2b<0) {
		perror("open");
		exit(1);
	}
	char cmd[256];
	char buffer[256];
	while(1) {
		printf("Command: ");
		fgets(cmd,256,stdin);
		cmd[strlen(cmd)-1]='\0';
		if(strcmp(cmd,"stop")==0)
			break;
		int p[2];
		pipe(p);
		pid_t f=fork();
		if(f<0) {
			perror("fork");
			exit(1);
		}
		if(f==0) {
			close(p[0]);
			dup2(p[1],1); // stdout goes into pipe
			close(p[1]);
			execlp("sh","sh","-c",cmd,NULL);
			perror("execlp");
			exit(1);
		}
		close(p[1]);
		int n;
		while((n=read(p[0],buffer,255))>0) {
			write(a2b,buffer,n);
		}
		close(p[0]);
		wait(0);

	}
	close(a2b);
	unlink("a2b");
	return 0;
}


```

p9b2.c:
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
	int a2b=open("a2b",O_RDONLY);
	if(a2b<0) {
		perror("open");
		exit(1);
	}
	char buffer[256];
	int n;
	while((n=read(a2b,buffer,255))>0) {
		buffer[n]='\0';
		printf("%s",buffer);
	}
	close(a2b);
	return 0;
}


```

##### Problem 4/UNIX processes !!!
![[Pasted image 20260503165833.png]]
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char **argv) {
	if(argc<2) {
		printf("Usage: ./p4 <command>\n");
		exit(1);
	}
	struct timespec start,end;
	clock_gettime(CLOCK_MONOTONIC,&start);
	pid_t f=fork();
	if(f<0) {
		perror("fork");
		exit(1);
	}
	if(f==0) {
		execlp("sh", "sh", "-c", argv[1],NULL);
		perror("execlp");
		exit(1);
	}
	wait(0);
	clock_gettime(CLOCK_MONOTONIC,&end);
	double time=(end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1e9;
	printf("Execution time: %f seconds\n",time);
	return 0;
}


```

##### Problem 26/UNIX processes - FROM FILE
![[Pasted image 20260503172242.png]]
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char **argv) {
	if(argc!=2) {
		printf("Usage: ./p26 <file>\n");
		exit(1);
	}
	int p[2];
	pipe(p);
	pid_t f=fork();
	if(f<0) {
		perror("fork");
		exit(1);
	}
	if(f==0) {
		close(p[0]);
		int fd=open(argv[1],O_RDONLY);
		if(fd<0){
			perror("open");
			exit(1);
		}
		char c;
		int transform=0;
		while(read(fd,&c,1)>0) {
			if(c=='.') {
				transform=1;
			}
			else if(transform) {
				if(islower(c)){
					c=toupper(c);
					transform=0;
				}
				else if(!isspace(c)){
					transform=0;
				}
			}
			write(p[1],&c,1);
		}
		close(fd);
		close(p[1]);
		exit(0);
	}
	close(p[1]);
	char c;
	while(read(p[0],&c,1)>0) {
		printf("%c",c);
	}
	close(p[0]);
	wait(0);
	return 0;
}


```

##### Problem 25/UNIX processes
![[Pasted image 20260503215439.png]]
```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int a2d[2];
	//int b2a[2];
	//int c2a[2];
	int b2d[2];
	int c2d[2];
	pipe(a2d);
	//pipe(b2a);
	//pipe(c2a);
	pipe(b2d);
	pipe(c2d);

	pid_t f=fork();
	if(f<0) {
		perror("fork");
		exit(1);
	}
	if(f==0) { // child b
		close(b2d[0]);
		//close(b2a[0]);
		close(c2d[0]);
		//close(c2a[1]);
		close(c2d[1]);
		//close(c2a[1]);
		close(a2d[0]);
		close(a2d[1]);
		srand(getpid());
		while(1) {
			int nrb=rand()%200+1;
			printf("B sends: %d\n",nrb);
			write(b2d[1],&nrb,sizeof(int));
			sleep(1);
		}
		close(b2d[1]);
		exit(0);
	}
	pid_t g=fork();
	if(g<0) {
		perror("fork");
		exit(1);
	}
	if(g==0){ // child c
		close(c2d[0]);
                //close(c2a[0]);
                close(b2d[0]);
                close(b2d[1]);
                //close(b2a[0]);
                //close(b2a[1]);
		close(a2d[0]);
		close(a2d[1]);
                srand(getpid());
		while(1) {
                	int nrc=rand()%200+1;
			printf("C sends: %d\n",nrc);
                	write(c2d[1],&nrc,sizeof(int));
			sleep(1);
		}
                close(c2d[1]);
		exit(0);
	}
	pid_t t=fork();
	if(t<0) {
		perror("fork");
		exit(1);
	}
	if(t==0) {//child d
		close(a2d[1]);
		close(b2d[1]);
		close(c2d[1]);
		int rnr;
		read(a2d[0],&rnr,sizeof(int));
		printf("D received random number from A: %d\n", rnr);
		while(1) {
			int nrb,nrc;
			read(b2d[0],&nrb,sizeof(int));
			read(c2d[0],&nrc,sizeof(int));
			int dif=abs(nrb-nrc);
			printf("D received B=%d C=%d diff=%d\n",nrb,nrc,dif);
			if(dif<=rnr) {
				printf("Condition met: %d <=%d\n",dif,rnr);
				break;
			}
		}
		close(b2d[0]);
		close(c2d[0]);
		close(a2d[0]);
		exit(0);
	}
	close(a2d[0]);
	close(b2d[0]);close(b2d[1]);
	close(c2d[0]);close(c2d[1]);
	srand(getpid());
        int rnra=rand()%11+10;
	printf("A sends limit: %d\n", rnra);
	write(a2d[1],&rnra,sizeof(int));
	close(a2d[1]);
        waitpid(t,NULL,0);
	kill(f,SIGTERM);
	kill(g,SIGTERM);
	waitpid(f,NULL,0);
	waitpid(g,NULL,0);
	return 0;
}
```


### Lab 11 - 11 may 2026
thread

pb24.
![[Pasted image 20260511142722.png]]
- one child process using fork()
- n threads in the parent process
- pipe so threads can send data to child
- mutex so only one thread writes to the pipe at a time
- metoda geto - arg=value?
- how to deduce the function format (tha line, from manual)
- different id for each thread (not getpid() - that returns the same thing, 5)
- race condition if two threads want to send numbers through pipe => sync with mutex
- methods of giving pointer:
	- 1. &(arrayThreads[i])
	- 2. (arrayThreads+1)
```
void* potato(void* args, int x)
```

- each thread generates 
```
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd>

int pip[2];
int n=1;  // int n=8; 

void copil(int pip[2]) { // send pipe as parameter (does not make sense if it is declared globally, but yeah)
	close pip[1];
	for(int i=0; i<n; i++){
		int rec[3];
		read(pip[0],rec,sizeof(int)*3);
		printf("%d %d %d\n", rec[0],rec[1],rec[2]);
	}
}

// thread
void* thread(void* args){
	// receives a unique id from the parent
	// geto method
	// cast it to long because it's 8 bytes
	// close(pip[0]);  // should not be here because if it was here it would be called as many times as threads are.
	long theID=(long)args; // this is casting
	int a,b;
	a=(rand()%100)+1;
	b=(rand()%100)+1;
	
	//printf("%d %d %ld\n",a,b,theID);
	
	// send via pipe
	int toSend[3];
	toSend[0]=a;
	toSend[1]=b;
	toSend[2]=theID;
	write(pip[1],toSend,sizeof(int)*3);
	//write(pip[1],toSend,sizeof(toSend));
}

int main() {
	int n=1; // read from keyboard
	
	//int pip[2];
	srand(time(NULL));
	pipe(pip);
	
	int theCopil=fork();
	if(theCopil!=0){ // parent
			// define the array of threads statically/dinamically
		pthread_t arrayThreads[n];
		for(long i=0; i<n; i++){ // long, not int
			// pthread_create(&(arrayThreads[i]))
			pthread_create(arrayThreads+i, NULL, thread, (void*)i);
		}
		for(long i=0; i<n; i++){ // long, not int
			pthread_join(arrayThreads[i],NULL); // if it was not null - pointer to another pointer=what the function that gives the thread returns?
			//pthread_join(*(arrayThreads+i));
		}
	}
	else {
		copil(pip);
	}
	
}
```
- after running this version, it works without synchronisation. why? 
	- only one call in pipe -> atomic
	- read, write -> might return an integer who says how much they managed to read/write
	- child only reads from pipe, it does not know there might be more threads
	- if more reading -> mutex

official method (with sync):
```
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd>

int pip[2];
int n=8; 
pthread_mutex_t y = PTHREAD_MUTEX_INITIALIZER; // mutex initialised directly at compile time

void copil(int pip[2]) { // send pipe as parameter (does not make sense if it is declared globally, but yeah)
	close pip[1];
	for(int i=0; i<n; i++){
		int rec[3];
		read(pip[0],rec,sizeof(int)*3);
		printf("%d %d %d\n", rec[0],rec[1],rec[2]);
	}
}

// thread
void* thread(void* args){
	// receives a unique id from the parent
	// geto method
	// cast it to long because it's 8 bytes
	// close(pip[0]);  // should not be here because if it was here it would be called as many times as threads are.
	long theID=(long)args; // this is casting
	int a,b;
	a=(rand()%100)+1;
	b=(rand()%100)+1;
	
	//printf("%d %d %ld\n",a,b,theID);
	
	// send via pipe
	int toSend[3];
	toSend[0]=a;
	toSend[1]=b;
	toSend[2]=theID;
	
	pthread_mutex_lock(&y);
	write(pip[1],toSend,sizeof(int)*3);
	pthread_mutex_unlock(&y);
	//write(pip[1],toSend,sizeof(toSend));
}

int main() {
	int n=1; // read from keyboard
	
	//int pip[2];
	srand(time(NULL));
	pipe(pip);
	
	int theCopil=fork();
	if(theCopil!=0){ // parent
			// define the array of threads statically/dinamically
		pthread_t arrayThreads[n];
		for(long i=0; i<n; i++){ // long, not int
			// pthread_create(&(arrayThreads[i]))
			pthread_create(arrayThreads+i, NULL, thread, (void*)i);
		}
		for(long i=0; i<n; i++){ // long, not int
			pthread_join(arrayThreads[i],NULL); // if it was not null - pointer to another pointer=what the function that gives the thread returns?
			//pthread_join(*(arrayThreads+i));
		}
	}
	else {
		copil(pip);
	}
	
}
```
- print average - do it yourself!

final version:
```
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int pip[2]; // 
int n = 8;
pthread_mutex_t y = PTHREAD_MUTEX_INITIALIZER;

void copil(int pip[2])
{
    close(pip[1]);
    for (int i=0; i<n;i++)
    {
        int rec[3];
        read(pip[0], rec, sizeof(int) * 3);
        printf("%d %d %d\n",rec[0],rec[1],rec[2]);
    }
}

void* thread(void* args)
{

    long theID = (long)args;
    int a,b;
    a = (rand() % 100) + 1;
    b = (rand() % 100) + 1;
```