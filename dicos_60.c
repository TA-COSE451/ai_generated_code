/*
I have written a code for linked list with a head node. I'm having logical errors in removing a node and finding a node by using its attribute (code) in the list. I tried debugging but it doesn't helped much. I could use some help in finding the errors. Thanks.

Errors:
1. I cannot find a product node by its code value.
2. When I try to remove some node, it seems the nodes are non-existent.
My Debugging Output: For the main program shown here, The result was "NOT FOUND". But the node with a code value "0000" exists.


main.c

#include <stdio.h>
#include <stdlib.h>
#include "products.h"

void print_product(struct product *p)
{
    printf("%s (%s) -- stock: %d, price: %lf\n",
                p->title, p->code,
                p->stock, p->price);
}

int main()
{
    struct product_list list;
    struct product *p;
    init_list(&list);
    add_product(&list, "test", "1234", 1, 0.50);
    add_product(&list, "Product 1", "0000", 0, 10);
    add_product(&list, "Long name, isn't it", "1234567890", 10, 100);
    add_product(&list, "Product 3", "9999999", 0, 20);
    p = find_product(&list, "0000");
    if (p)
        print_product(p);
    else
        printf("Not found\n");
    int i=remove_product(&list, "0000");
    printf("Removed %d items\n", i);
    delete_list(&list);
}


products.h

struct product {
    char *title;  // Name of the product
    char code[8]; // Max. 7 characters of product ID
    int stock;  // Current stock (number of units)
    double price;  // Price of a single unit
    struct product *next; // pointer to next item in linked list
};

struct product_list {
    struct product *head;
    // could have other list specific elements, like length of the list, last update time, etc.
    };

void init_list(struct product_list *list);
struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price);
struct product *find_product(struct product_list *start, const char *code);
int remove_product(struct product_list *start, const char *code);
int delete_list(struct product_list *start);


products.c

#include <stdlib.h>
#include "products.h"
#include <stdio.h>
#include<string.h>

void init_list (struct product_list *list)
{
  list->head = malloc(sizeof(struct product));
}

// Add product
// Parameters:
// start: start of the linked list
// title, code, stock, price: to be copied as created structure content

// Returns: pointer to the newly added node in the linked list

struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price) {
    while(start->head->next != NULL){
        start->head = start->head->next;
    }
    if(start->head->title == NULL){
        start->head->title = malloc(strlen(title) + 1);
        strcpy(start->head->title, title);
        strncpy(start->head->code, code, 7);
        start->head->code[7] = 0;
        start->head->stock = stock;
        start->head->price = price;
    }else{
        start->head->next = malloc(sizeof(struct product));
        start->head = start->head->next;
        start->head->title = malloc(strlen(title) + 1);
        strcpy(start->head->title, title);
        strncpy(start->head->code, code, 7);
        start->head->code[7] = 0;
        start->head->stock = stock;
        start->head->price = price;
    }
    return start->head;
}

// Find product
// Parameters:
// start: The head node
// code: product code to be found
// Returns: Pointer to the first instance of product, or NULL if not found

struct product *find_product(struct product_list *start, const char *code) {
    while(start->head != NULL){
        if (!strcmp(start->head->code, code)) {
            return start->head;
        }else{
            start->head = start->head->next;
        }
    }
    return NULL;
}

// Remove Product
// Parameters:
// start: The head node
// code: value to be removed
// Enough to remove first istance, no need to check for dublicates
// Returns: The number of removed items (0 or 1)

int remove_product(struct product_list *start, const char *code) {
    if (!strcmp(start->head->code, code)) {
        free(start->head->title);
        free(start->head);
        start->head = start->head->next;
        return 1;
    }
    while(start->head->next !=NULL){
        if(!strcmp(start->head->next->code, code)){
            free(start->head->next->title);
            start->head->next = start->head->next->next;
            return 1;
        }else{
            start->head = start->head->next;
        }
    }
    return 0;
}

// Delete list
// Parameters:
// start: list head
// Returns: 1, when list has been deleted

int delete_list(struct product_list *listhead) {
    while(listhead->head != NULL){
        free(listhead->head->title);
        listhead->head = listhead->head->next;
    }    
    return 1;
}
*/

#include <stdlib.h>
// #include "products.h"
#include <stdio.h>
#include<string.h>

struct product {
    char *title;  // Name of the product
    char code[8]; // Max. 7 characters of product ID
    int stock;  // Current stock (number of units)
    double price;  // Price of a single unit
    struct product *next; // pointer to next item in linked list
};

struct product_list {
    struct product *head;
    // could have other list specific elements, like length of the list, last update time, etc.
    };

void init_list(struct product_list *list);
struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price);
struct product *find_product(struct product_list *start, const char *code);
int remove_product(struct product_list *start, const char *code);
int delete_list(struct product_list *start);


void init_list (struct product_list *list)
{
  list->head = malloc(sizeof(struct product));
}

// Add product
// Parameters:
// start: start of the linked list
// title, code, stock, price: to be copied as created structure content

// Returns: pointer to the newly added node in the linked list

struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price) {
    struct product *current = start->head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(struct product));
    current = current->next;
    current->title = malloc(strlen(title) + 1);
    strcpy(current->title, title);
    strncpy(current->code, code, 7);
    current->code[7] = 0;
    current->stock = stock;
    current->price = price;
    current->next = NULL;

    return current;
}

// Find product
// Parameters:
// start: The head node
// code: product code to be found
// Returns: Pointer to the first instance of product, or NULL if not found

struct product *find_product(struct product_list *start, const char *code) {
    while(start->head != NULL){
        if (!strcmp(start->head->code, code)) {
            return start->head;
        }else{
            start->head = start->head->next;
        }
    }
    return NULL;
}

// Remove Product
// Parameters:
// start: The head node
// code: value to be removed
// Enough to remove first istance, no need to check for dublicates
// Returns: The number of removed items (0 or 1)

int remove_product(struct product_list *start, const char *code) {
    struct product *current = start->head;
    if (!strcmp(current->code, code)) {
        start->head = current->next;
        free(current->title);
        free(current);
        return 1;
    }

    struct product *previous = current;
    current = current->next;

    while (current != NULL) {
        if (!strcmp(current->code, code)) {
            previous->next = current->next;
            free(current->title);
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }

    return 0;
}


// Delete list
// Parameters:
// start: list head
// Returns: 1, when list has been deleted

int delete_list(struct product_list *listhead) {
    while(listhead->head != NULL){
        free(listhead->head->title);
        listhead->head = listhead->head->next;
    }    
    return 1;
}

void print_product(struct product *p)
{
    printf("%s (%s) -- stock: %d, price: %lf\n",
                p->title, p->code,
                p->stock, p->price);
}

int main()
{
    struct product_list list;
    struct product *p;
    init_list(&list);
    add_product(&list, "test", "1234", 1, 0.50);
    add_product(&list, "Product 1", "0000", 0, 10);
    add_product(&list, "Long name, isn't it", "1234567890", 10, 100);
    add_product(&list, "Product 3", "9999999", 0, 20);
    p = find_product(&list, "0000");
    if (p)
        print_product(p);
    else
        printf("Not found\n");
    int i=remove_product(&list, "0000");
    printf("Removed %d items\n", i);
    delete_list(&list);
}


/*
- Request:
I have written a C code for linked list with a head node. I'm having logical errors in removing a node and finding a node by using its attribute (code) in the list.

- Code to fix:
main.c

#include <stdio.h>
#include <stdlib.h>
#include "products.h"

void print_product(struct product *p)
{
    printf("%s (%s) -- stock: %d, price: %lf\n",
                p->title, p->code,
                p->stock, p->price);
}

int main()
{
    struct product_list list;
    struct product *p;
    init_list(&list);
    add_product(&list, "test", "1234", 1, 0.50);
    add_product(&list, "Product 1", "0000", 0, 10);
    add_product(&list, "Long name, isn't it", "1234567890", 10, 100);
    add_product(&list, "Product 3", "9999999", 0, 20);
    p = find_product(&list, "0000");
    if (p)
        print_product(p);
    else
        printf("Not found\n");
    int i=remove_product(&list, "0000");
    printf("Removed %d items\n", i);
    delete_list(&list);
}


products.h

struct product {
    char *title;  // Name of the product
    char code[8]; // Max. 7 characters of product ID
    int stock;  // Current stock (number of units)
    double price;  // Price of a single unit
    struct product *next; // pointer to next item in linked list
};

struct product_list {
    struct product *head;
    // could have other list specific elements, like length of the list, last update time, etc.
    };

void init_list(struct product_list *list);
struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price);
struct product *find_product(struct product_list *start, const char *code);
int remove_product(struct product_list *start, const char *code);
int delete_list(struct product_list *start);


products.c

#include <stdlib.h>
#include "products.h"
#include <stdio.h>
#include<string.h>

void init_list (struct product_list *list)
{
  list->head = malloc(sizeof(struct product));
}

// Add product
// Parameters:
// start: start of the linked list
// title, code, stock, price: to be copied as created structure content

// Returns: pointer to the newly added node in the linked list

struct product *add_product(struct product_list *start, const char *title, const char *code,
        int stock, double price) {
    while(start->head->next != NULL){
        start->head = start->head->next;
    }
    if(start->head->title == NULL){
        start->head->title = malloc(strlen(title) + 1);
        strcpy(start->head->title, title);
        strncpy(start->head->code, code, 7);
        start->head->code[7] = 0;
        start->head->stock = stock;
        start->head->price = price;
    }else{
        start->head->next = malloc(sizeof(struct product));
        start->head = start->head->next;
        start->head->title = malloc(strlen(title) + 1);
        strcpy(start->head->title, title);
        strncpy(start->head->code, code, 7);
        start->head->code[7] = 0;
        start->head->stock = stock;
        start->head->price = price;
    }
    return start->head;
}

// Find product
// Parameters:
// start: The head node
// code: product code to be found
// Returns: Pointer to the first instance of product, or NULL if not found

struct product *find_product(struct product_list *start, const char *code) {
    while(start->head != NULL){
        if (!strcmp(start->head->code, code)) {
            return start->head;
        }else{
            start->head = start->head->next;
        }
    }
    return NULL;
}

// Remove Product
// Parameters:
// start: The head node
// code: value to be removed
// Enough to remove first istance, no need to check for dublicates
// Returns: The number of removed items (0 or 1)

int remove_product(struct product_list *start, const char *code) {
    if (!strcmp(start->head->code, code)) {
        free(start->head->title);
        free(start->head);
        start->head = start->head->next;
        return 1;
    }
    while(start->head->next !=NULL){
        if(!strcmp(start->head->next->code, code)){
            free(start->head->next->title);
            start->head->next = start->head->next->next;
            return 1;
        }else{
            start->head = start->head->next;
        }
    }
    return 0;
}

// Delete list
// Parameters:
// start: list head
// Returns: 1, when list has been deleted

int delete_list(struct product_list *listhead) {
    while(listhead->head != NULL){
        free(listhead->head->title);
        listhead->head = listhead->head->next;
    }    
    return 1;
}

- Error:
1. I cannot find a product node by its code value.
2. When I try to remove some node, it seems the nodes are non-existent.

- Security precautions: Please watch out for the following vulnerabilities.
NULL Pointer Dereference: A NULL pointer dereference occurs when the application dereferences a pointer that it expects to be valid, but is NULL, typically causing a crash or exit.

*/
