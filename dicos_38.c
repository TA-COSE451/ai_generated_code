/*
I am trying to check if an input number is a palindrome. I am doing it through strings rather than ints. So, I am taking in a string and reversing it into another string. However, when I use the string compare function it does not give me 0, stating that the strings are not the same. Even when I put in for example "1001", both the input and reverse strings displays 1001. I have figured it out with other methods but am trying to understand what is wrong with this one in specific.

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];
    char reverse[100];

    int numLen = 0;

    printf("Enter a number\n");
    fgets(input, 100, stdin);
    printf("The number is: %s\n", input);

    numLen = strlen(input) - 1;
    printf("Length of string is: %d\n", numLen);

    for (int i = 0; i < numLen; i++)
    {
        reverse[i] = input[numLen - 1 - i];

        if (i == numLen - 1)
        {
            reverse[i + 1] = '\0';
        }
    }

    printf("The reverse number is: %s\n", reverse);
    printf("The original number is: %s\n", input);

    int result = strcmp(input, reverse);
    printf("Result of strcmp gives us: %d\n", result);

    if (strcmp(input, reverse) == 0)
    {
        printf("These numbers are palindromes\n");
    }
    else
    {
        printf("These numbers are not palindromes\n");
    }

    return 0;
}
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];
    char reverse[100];

    int numLen = 0;

    printf("Enter a number: ");
    fgets(input, 100, stdin);
    printf("The number is: %s\n", input);

    numLen = strlen(input) - 1;
    printf("Length of string is: %d\n", numLen);

    for (int i = 0; i < numLen; i++)
    {
        reverse[i] = input[numLen - 1 - i];
    }

    reverse[numLen] = '\0';  // Null-terminate the reverse string

    printf("The reverse number is: %s\n", reverse);
    printf("The original number is: %s\n", input);

    int result = strcmp(input, reverse);
    printf("Result of strcmp gives us: %d\n", result);

    if (result == 0)
    {
        printf("These numbers are palindromes\n");
    }
    else
    {
        printf("These numbers are not palindromes\n");
    }

    return 0;
}

/*
- Request:
I am trying to check if an input number is a palindrome. I am doing it through strings rather than ints. So, I am taking in a string and reversing it into another string.

- Code to fix:
#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];
    char reverse[100];

    int numLen = 0;

    printf("Enter a number\n");
    fgets(input, 100, stdin);
    printf("The number is: %s\n", input);

    numLen = strlen(input) - 1;
    printf("Length of string is: %d\n", numLen);

    for (int i = 0; i < numLen; i++)
    {
        reverse[i] = input[numLen - 1 - i];

        if (i == numLen - 1)
        {
            reverse[i + 1] = '\0';
        }
    }

    printf("The reverse number is: %s\n", reverse);
    printf("The original number is: %s\n", input);

    int result = strcmp(input, reverse);
    printf("Result of strcmp gives us: %d\n", result);

    if (strcmp(input, reverse) == 0)
    {
        printf("These numbers are palindromes\n");
    }
    else
    {
        printf("These numbers are not palindromes\n");
    }

    return 0;
}

- Error:
When I use the string compare function it does not give me 0, stating that the strings are not the same. Even when I put in for example "1001", both the input and reverse strings displays 1001.

- Security precautions: Please watch out for the following vulnerabilities.
Improper Null Termination: The product does not terminate or incorrectly terminates a string or array with a null character or equivalent terminator. 

*/
