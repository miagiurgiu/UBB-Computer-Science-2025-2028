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
```
printf "apple\nbanana\npear\napple pie\nbanana split\n" > fruits.txt\
cat fruits.txt
grep apple fruits.txt
=> 
apple
apple pie
```