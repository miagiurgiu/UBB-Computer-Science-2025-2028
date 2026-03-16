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
cd sth = go to sth
cd ~ = cd = go to home directory automatically
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

grep -E " - 91[0-9] -> select English section groups (910-919)
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
.* -> everything after dot
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
sed -E "s/^.* - [^ ]+[^ ]+ //"

^ -> beginning of line
.* -> anything
" - " -> literal pattern
[^ ] -> sequence of non-space characters (space negated)

awk -F: '{print $5}' /etc/passwd | grep -E " - 91[0-9] - " | sed -E "s/^.* - [^ ]+[^ ]+ //"
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
```

- remove short names (initials):
```
grep -E -v "^.{,2}$"

-v -> i dont show it (exclude)
^.{,2}$ -> strings of length <=2
```

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
```

```
ps -o etime process_id | tail -n +2
```

awk - extracts
expr - arithmetic in the command line

10) Nothing happens simultaneously (processes - they are just very fast, one after the other)
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

 