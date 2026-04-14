#include <stdio.h>
#define MAXV 100 // maximum size of vector
#define MAXPAIRS 1000 // max nr of pairs

/// prints the menu options
/// returns nothing, has no parameters
void menu() { 
    printf("1. Read a vector of numbers from the console\n");
    printf("2. Solve a)\n");
    printf("3. Solve b)\n");
    printf("4. Exit\n");
}

/// checks if x is prime
/// returns 1 if x is prime, 0 otherwise
/// x is passed by value (copy), this function works on a copy of x, not the original x
int is_prime(int x){ 
    if (x<2)
        return 0;
    if (x==2)
        return 1;
    if (x%2==0)
        return 0;
    for (int d=3; d*d<=x; d+=2)
        if (x%d==0)
            return 0;
    return 1;
}

/// read and discard characters until newline or EOF
void clear_line() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/// reads a vector v and its length len from console
/// int v[] becomes int *v -> a pointer to first element => the function receives the address of the first element of the array
/// len is int* -> a pointer -> stores the address of an int => use pointer because we wanna change len from 0 (in run) to the value given by the user
void read_vector(int v[], int *len) {
    printf("Give n: ");
    if (scanf("%d", len)!=1) { // scanf needs address where to write the number -> len is already an address (int*), so len is enough
        printf("Invalid input.\n");
        *len=0;
        return;
    } 
    if (*len < 0) 
        *len = 0;
    if (*len > MAXV) {
        printf("Too many numbers, max is %d.\n", MAXV);
        *len = MAXV;
    }
    printf("Enter %d numbers:\n", *len); // go to that address and read the int value stored there (without *, i would print the address, not the value)
    for (int i = 0; i < *len; i++) { // loop len times
        if (scanf("%d", &v[i]) != 1){
           printf("Invalid input.\n");
           *len = i; // keep what was read so far
           return;
        }
    }
    clear_line(); // clear the rest of the line after reading the numbers (in case we write n+1 numbers instead of n)
}

/// generates twin primes and stores them in p and q, returns the number of pairs generated
int generate_twin_primes(int n, int p[], int q[], int max_pairs){
    int cnt = 0;
    int x=2;
    if (n<=0 || max_pairs <=0)
        return 0;
    while (cnt < n && cnt < max_pairs) {
        if (is_prime(x) && is_prime(x+2)) {
            p[cnt] = x;
            q[cnt] = x+2;
            cnt++;
        }
        x++;
    }
    return cnt;
}

/// the first n pairs of twin numbers (p,q are twins if q-p=2)
int solve_a(int n, int p[], int q[], int max_pairs){
    return generate_twin_primes(n, p, q, max_pairs);
}

/// finds the longest decreasing contiguous subsequence in v of length len, returns its start index and length via pointers
void longest_decreasing_contiguous(int v[], int len, int *best_start, int *best_len){
    int current_start = 0, current_len = 1;
    if (len<=0) {
        *best_start = 0;
        *best_len = 0;
        return;
    }
    *best_start = 0;
    *best_len = 1;
    for (int i=1; i<len; i++){ // start from 1 because we compare with previous element
        if (v[i] < v[i-1]) { // srictly decreasing
            current_len++; // extend current subsequence
        } else {
            current_len = 1; // reset length
            current_start = i; // start new subsequence from current index
        }
        if (current_len > *best_len) { // update only if strictly better
            *best_len = current_len;
            *best_start = current_start;
        }
    }
}

/// function that solves part b) by calling longest_decreasing_contiguous
/// passes the vector and its length, and receives the best start and length via pointers
void solve_b(int v[], int len, int *best_start, int *best_len){
    longest_decreasing_contiguous(v, len, best_start, best_len);
}

/// main menu loop, runs until user chooses to exit
void run(){
    int choice;
    int v[100]; // local vector, static allocation, memory is created automatically, it can hold 100 integers, it disappears when run() finishes, stack memory
    int len=0; // local size, normal integer
    while(1){
        printf("Menu:\n");
        menu();
        printf("Enter option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid option.\n");
            clear_line();
            continue;
        }
        switch (choice) { // branching: chooses which block to execute
            case 1:
                read_vector(v, &len); // v passed as address automatically, &len to allow read_vector to modify len in run()
                break; // out of switch, back to menu (while)
            case 2: {
                int n;
                printf("Give n (nr of pairs):");
                if (scanf("%d", &n) != 1) {
                    printf("Invalid input.\n");
                    break; // out of switch, back to menu (while)
                }
                int p[MAXPAIRS], q[MAXPAIRS]; // local arrays for twin primes, static allocation, memory is created automatically, they disappear when run() finishes, stack memory 
                int cnt = solve_a(n, p, q, MAXPAIRS); // solve_a returns the number of pairs generated
                printf("First %d pairs of twin primes:\n", cnt);
                for (int i=0; i<cnt; i++) {
                    printf("(%d, %d)\n", p[i], q[i]);
                }
                if (cnt < n) {
                    printf("Only %d pairs were generated due to max_pairs limit.\n", cnt);
                }
                break; // out of switch, back to menu (while)
            }
            case 3: {
                if (len <= 0 ) {
                    printf("Vector is empty. Please read a vector first.\n");
                    break; // out of switch, back to menu (while)
                }
                int best_start, best_len;
                solve_b(v, len, &best_start, &best_len); // v passed as address automatically, len passed by value (copy)
                printf("Longest decreasing contiguous subsequence has length %d:\n", best_len);
                for (int i=best_start; i<best_start+best_len; i++) {
                    printf("%d ", v[i]);
                }
                printf("\n");
                break; // out of switch, back to menu (while)
            }
            case 4:
                printf("Exitingg...\n");
                return; // out of while, leaves run()
            default: // runs when none of the cases match
                printf("Invalid option\n");
        }
    }
}
/// main function, entry point of the program
int main() {
    run(); // start the menu loop
    return 0;
}