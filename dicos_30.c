/*
What is the simplest way to read a full line in a C console program The text entered might have a variable length and we can't make any assumption about its content.
*/

#include <stdio.h>

int main() {
    char buffer[1024]; // Define a character array to store the input

    printf("Enter a line of text: ");
    
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // fgets successfully read a line of input
        printf("You entered: %s", buffer);
    } else {
        // Handle the case where fgets encountered an error
        printf("Error reading input.\n");
    }

    return 0;
}
