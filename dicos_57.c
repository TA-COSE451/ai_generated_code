/*
I know it may sound sci-fi but I truly want to call a function x times, by using an array of function pointers to it and without involving a loop or anything that may slow down the target program. Is that possible and if yes, how exactly?
*/

#include <stdio.h>

// Define a function pointer type
typedef void (*FunctionPtr)();

// Define your functions
void Function1() {
    printf("Function 1 called\n");
}

void Function2() {
    printf("Function 2 called\n");
}

void Function3() {
    printf("Function 3 called\n");
}

int main() {
    // Create an array of function pointers
    FunctionPtr functions[] = {Function1, Function2, Function3};

    int numCalls = 5; // Change this to the desired number of function calls
    int i;

    // Call the functions in the array 'numCalls' times
    for (i = 0; i < numCalls; i++) {
        functions[i % (sizeof(functions) / sizeof(functions[0]))]();
    }

    return 0;
}
