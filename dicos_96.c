/*
I'm a beginner in C and I don't understand why my code isn't working. The aim is simply just to reverse a string.

char word[20];
int i, len;

printf("Enter word: ");
    scanf("%s", &word);

len = strlen(word);

printf("String reversed: "); 
for (i = len-1; i >= 0; i--){
    printf("%s", word[i]);
}
*/

#include <stdio.h>
#include <string.h>

int main() {
    char word[20];
    int i, len;

    printf("Enter word: ");
    scanf("%s", word);

    len = strlen(word);

    printf("String reversed: "); 
    for (i = len - 1; i >= 0; i--) {
        printf("%c", word[i]);
    }
    printf("\n");  // Print a newline after reversing the string

    return 0;
}

/*
- Request:
Please fix the below C program.
The aim is simply just to reverse a string.

- Code to fix:
char word[20];
int i, len;

printf("Enter word: ");
    scanf("%s", &word);

len = strlen(word);

printf("String reversed: "); 
for (i = len-1; i >= 0; i--){
    printf("%s", word[i]);
}

- Error:
I don't understand why my code isn't working.

- Security precautions: Please watch out for the following vulnerabilities.
Buffer Copy without Checking Size of Input ('Classic Buffer Overflow'): The product copies an input buffer to an output buffer without verifying that the size of the input buffer is less than the size of the output buffer, leading to a buffer overflow.

*/
