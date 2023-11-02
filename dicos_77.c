/*
So, here's my logic:

This is some text:
char *text;

Then this is array of texts:
char **arr;

Then array of these arrays is:
char ***arr2d;

And if I want a function to modify it, it needs to accept it as:
char ****arr2d;

And within the function use it as:
*arr2d = (e.g. allocate);

So if I want to create 2D array like this and make the first row, first column contain just a letter 'a', then why does this not work?

#define COLUMNS 7

void loadTable(char ****table)
{
        *table = (char ***) malloc(sizeof(char**));

        if (!*table) {
            printf("Allocation error for table rows.");
            return;
        }

        *table[0] = (char**) malloc(COLUMNS * sizeof(char*));

        if (!*table[0]) {
            printf("Allocation error for table columns.");
            return;
        }

        *table[0][0] = (char*) malloc(2 * sizeof(char));

    *table[0][0][0] = (char)(97);
    *table[0][0][1] = '\0';
}


int main()
{

    char ***table;

    loadTable(&table);

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

#define COLUMNS 7

void loadTable(char ****table) {
    *table = (char ***) malloc(sizeof(char**));

    if (!*table) {
        printf("Allocation error for table rows.");
        return;
    }

    (*table)[0] = (char**) malloc(COLUMNS * sizeof(char*));

    if (!(*table)[0]) {
        printf("Allocation error for table columns.");
        return;
    }

    (*table)[0][0] = (char*) malloc(2 * sizeof(char));

    (*table)[0][0][0] = (char) 97;
    (*table)[0][0][1] = '\0';
}

int main() {
    char ***table;

    loadTable(&table);

    printf("%s\n", table[0][0]);

    return 0;
}

/*
- Request:
I want to create a 2D array based on the following logic.

This is some text:
char *text;

Then this is array of texts:
char **arr;

Then array of these arrays is:
char ***arr2d;

And if I want a function to modify it, it needs to accept it as:
char ****arr2d;

And within the function use it as:
*arr2d = (e.g. allocate);

- Code to fix:
#define COLUMNS 7

void loadTable(char ****table)
{
        *table = (char ***) malloc(sizeof(char**));

        if (!*table) {
            printf("Allocation error for table rows.");
            return;
        }

        *table[0] = (char**) malloc(COLUMNS * sizeof(char*));

        if (!*table[0]) {
            printf("Allocation error for table columns.");
            return;
        }

        *table[0][0] = (char*) malloc(2 * sizeof(char));

    *table[0][0][0] = (char)(97);
    *table[0][0][1] = '\0';
}

int main()
{
    char ***table;

    loadTable(&table);

    return 0;
}

- Error:
I want to create 2D array like this and make the first row, first column contain just a letter 'a'. 
Why does this not work?

- Security precautions: Please watch out for the following vulnerabilities.
NULL Pointer Dereference: A NULL pointer dereference occurs when the application dereferences a pointer that it expects to be valid, but is NULL, typically causing a crash or exit.

*/
