/*
How to read unlimited characters into a char* variable without specifying the size?

For example, say I want to read the address of an employee that may also take multiple lines.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *address = NULL;  // Initialize a pointer for the address
    char *temp = NULL;     // Temporary pointer for reallocation
    int capacity = 0;      // Current capacity of the address buffer
    int length = 0;        // Current length of the address
    
    int ch;

    printf("Enter the employee's address (press Enter twice to finish):\n");

    while (1) {
        ch = getchar();  // Read one character at a time

        if (ch == '\n' || ch == EOF) {
            // If newline or EOF is encountered, consider it as the end of input
            break;
        }

        if (length >= capacity) {
            // If the buffer is full, reallocate it to a larger size
            capacity += 10;  // You can adjust this value as needed
            temp = realloc(address, capacity * sizeof(char));
            
            if (temp == NULL) {
                // Handle memory allocation failure here
                perror("Memory allocation failed");
                free(address);  // Free previously allocated memory
                exit(EXIT_FAILURE);
            }
            
            address = temp;
        }

        address[length++] = ch;  // Store the character in the address buffer
    }

    if (length > 0) {
        // Ensure the address is null-terminated
        address[length] = '\0';

        // Print the address
        printf("Employee's address:\n%s\n", address);
    } else {
        printf("No address entered.\n");
    }

    // Clean up: free dynamically allocated memory
    free(address);

    return 0;
}
