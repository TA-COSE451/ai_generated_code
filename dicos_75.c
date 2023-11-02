/*
I am trying to store an array of char pointer to another array of char pointer. I am getting segmentation fault for the same.

int main(int argc, const char* argv[])
{   
    int argcCpy = argc;
    char* argvCpy[10] = {};

    for(argcCpy = argc; argcCpy>0; argcCpy--)
    {   
        argvCpy[argcCpy] = (char *) malloc(strlen(argv[argcCpy]));
        memcpy(argvCpy[argcCpy], argv[argcCpy], strlen(argv[argcCpy]));
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }
    return 0;
}

I spent more than enough time to make this work but I am not able to do it. Also, the same kind of question is already asked which is also left unanswered. If anybody can let me know the working code for the same, it would be really so helpful.
Hoping this to be answered.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[])
{
    int argcCpy = argc;
    char* argvCpy[10] = {};

    for (argcCpy = argc - 1; argcCpy >= 0; argcCpy--)
    {
        argvCpy[argcCpy] = (char*)malloc(strlen(argv[argcCpy]) + 1);
        strcpy(argvCpy[argcCpy], argv[argcCpy]);
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }

    // Cleanup: free the allocated memory
    for (argcCpy = argc - 1; argcCpy >= 0; argcCpy--)
    {
        free(argvCpy[argcCpy]);
    }

    return 0;
}


/*
- Request:
I am trying to store an array of char pointer to another array of char pointer.

- Code to fix:
int main(int argc, const char* argv[])
{   
    int argcCpy = argc;
    char* argvCpy[10] = {};

    for(argcCpy = argc; argcCpy>0; argcCpy--)
    {   
        argvCpy[argcCpy] = (char *) malloc(strlen(argv[argcCpy]));
        memcpy(argvCpy[argcCpy], argv[argcCpy], strlen(argv[argcCpy]));
        printf("\nCount: %d, string: %s", argcCpy, argvCpy[argcCpy]);
    }
    return 0;
}

- Error:
Segmentation fault

- Security precautions: Please watch out for the following vulnerabilities.
Improper Restriction of Operations within the Bounds of a Memory Buffer: The product performs operations on a memory buffer, but it can read from or write to a memory location that is outside of the intended boundary of the buffer. 

*/
