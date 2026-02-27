## Lecture 1 - 25 feb 2026


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

C:
if (choice=1) {

}
