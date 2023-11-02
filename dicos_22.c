/*
I need to make an array of strings for a program in one of my CS classes. We are to just assume that the length of all the strings is no more than 50 (this accounts for the null character).

I need use malloc() or calloc() to allocate the proper amount of memory for the array, but I am new to C and I don't really know how to use those functions.

The real question I guess is how much memory to I need do allocate for an array of x strings of 50 characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x = 5; // Number of strings in the array
    char** arrayOfStrings = (char**)malloc(x * sizeof(char*));

    if (arrayOfStrings == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < x; i++) {
        arrayOfStrings[i] = (char*)malloc(51 * sizeof(char)); // Allocate space for each string
        if (arrayOfStrings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for string %d.\n", i);
            return 1;
        }
        // You can initialize or copy strings into arrayOfStrings[i] here if needed.
    }

    // Now, you have an array of x strings, each with a maximum length of 50 characters.

    // Don't forget to free the allocated memory when you're done with it.
    for (int i = 0; i < x; i++) {
        free(arrayOfStrings[i]);
    }
    free(arrayOfStrings);

    return 0;
}
