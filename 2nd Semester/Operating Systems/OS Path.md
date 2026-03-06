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
pwd - working directory -  where do you execute the application from 
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
fallback method -> will "macaroane" be the default folder/fallback for ???

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
valgrind to detect leaks??

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
2. CATEGORY 2: pointer vs non-pointer
    "invalid operands to binary ..."
    "incompatible types when assigning to type ..."
    "incompatible types when returning type ..."
    Solution: add a * somewhere
    When you see: NULL, malloc, next => pointers (*)
```
struct node* add(struct node head, char* name) ERROR
struct node* add(struct node* head, char* name) CORRECT
```
3. CATEGORY 3: "." instead of "->"
	"p is a pointer, did you mean to use -> ?"
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
6. CATEGORY 6: unitialized pointer/variable
	Every pointer that starts as "empty list/no file/nothing yet" should usually start as NULL
```
struct node* head;
if(known(head,name)) => ERROR (head was never initialized, so it contains garbage)

struct node* head = NULL => CORRECT
```
