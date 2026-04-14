#ifndef PRODUCT_H
#define PRODUCT_H
// if the header is included > times, the compiler should not define multiple times the same structure.

// define a new datatype called Product
// typedef because after this we can write directly Product p instead of struct Product p
typedef struct {
    char name[50];
    char category[20];
    int quantity;
    int expiration_day;
    int expiration_month;
    int expiration_year;
} Product;

// declaration of the function that returns a newly created Product
Product create_product(char name[], char category[], int quantity, int day, int month, int year);

// Product* p means the address of a Product; throough this pointer the original product can be modified.
char* get_name(Product* p);
char* get_category(Product* p);
int get_quantity(Product* p);
int get_expiration_day(Product* p);
int get_expiration_month(Product* p);
int get_expiration_year(Product* p);
void set_quantity(Product* p, int new_quantity);
void set_expiration_date(Product* p, int day, int month, int year);

#endif // PRODUCT_H