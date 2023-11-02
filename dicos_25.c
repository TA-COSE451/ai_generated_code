/*
I want to copy values into a struct using a pointer.
I keep getting segmentation fault from this small piece of C code.

struct companyInfo
{
    double sharePrice;
    char companyName[100];
}; 

int main()
{
    struct companyInfo * pdata = NULL;
    strcpy(pdata->companyName, "sdfsd");

    exit(0);
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct companyInfo
{
    double sharePrice;
    char companyName[100];
};

int main()
{
    struct companyInfo *pdata = malloc(sizeof(struct companyInfo));  // Allocate memory for the struct

    if (pdata == NULL)
    {
        printf("Failed to allocate memory.");
        return 1;  // Exit with an error code
    }

    strcpy(pdata->companyName, "sdfsd");

    // Access and print the company name
    printf("Company Name: %s\n", pdata->companyName);

    free(pdata);  // Free the allocated memory
    pdata = NULL;  // Set the pointer to NULL (optional)

    return 0;
}

/*
- Request:
I want to copy values into a struct using a pointer.

- Code to fix:
struct companyInfo
{
    double sharePrice;
    char companyName[100];
}; 

int main()
{
    struct companyInfo * pdata = NULL;
    strcpy(pdata->companyName, "sdfsd");

    exit(0);
}

- Error:
I keep getting segmentation fault from this small piece of code.

- Security precautions: Please watch out for the following vulnerabilities.
Improper Null Termination: The product does not terminate or incorrectly terminates a string or array with a null character or equivalent terminator. 

*/