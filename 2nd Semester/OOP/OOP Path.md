## Lecture 1 - 25 feb 2026

## Lab 1 - 26 feb 2026
https://github.com/cs-ubbcluj-ro/a1-miagiurgiu-1
I received problem 11.

## HOW TO CLONE IN VISUAL STUDIO 2022 (WINDOWS)
 1. Main page -> Clone a repository
 2. Repository location (copy-paste link from browser)
 3. Browse -> Documents -> GitHub -> New -> Folder -> a1-oop -> Clone
 4. File -> New -> Project -> Empty Project (C++)
 5. Project name: a1
 6. Location: the folder of the cloned repo (C:\Users\Maria\Documents\GitHub\a1-oop)
 7. Right click on Source Files -> Add -> Existing Item -> select the .c file from a1-oop -> Add

## HOW TO CLONE IN VISUAL STUDIO CODE (MAC)
1. Source Control -> Changes -> 3 dots -> Clone -> copy-paste link from browser -> New File -> .c
2. CTRL + ` 

Very big dilemmas:
- why do we need stuff like & and * in C but in C++ we did not?

Address vs Value in C:
- in C there exist only pointers (addresses) and values (copies)
- if you want a function to modify a variable from the outside of that function, you give its address -> pointer -> &len
- since when calling you did &len, inside the function you do *len so that you can go to the value from that address and write the new value in there
- * does two things:
		1. in a declaration (int *ptr) => "this is a pointer" => address
		2. in an expression (*ptr = 5) => "go to the address of ptr and put 5 (value)"

&x = WHERE is x in memory ? -> give me that location
*x = WHAT is stored at the address p? -> go to that location

pointer to a datatype -> int* vs pointer to a variable *p
- scanf needs address

### Try-Except Python vs C:

PYTHON:
if choice == 1:
    read_vector()
elif choice == 2:
    solve_a()
elif choice == 3:
    solve_b()
elif choice == 4:
    print("Exiting...")
else:
    print("Invalid option")

C method 1:
if (choice == 1) {
	read_vector(v, &len);
}
else if (choice == 2) {
	solve_a();
}
else if (choice == 3) {
	solve_b(v, len);
}
else if (choice == 4) {
	printf("Exiting...\n");
	return;
}
else {
	printf("Invalid option\n");
}

C method 2:
int len = 0;
...
switch (choice) {
	case 1:
		read_vector(v, &len);
		break;
	case 2:
		solve_a();
		break;
	case 3:
		solve_b(v, len);
		break;
	case 4:
		printf("Exiting...\n");
		return;
	default:
		printf("Invalid option\n");
}
