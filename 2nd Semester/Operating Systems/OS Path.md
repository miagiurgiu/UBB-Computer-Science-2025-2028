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
-a = option (flag)
any file starting with . is hidden
la = ls-A