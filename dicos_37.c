/*
I am trying to find the no of lower and uppercase characters from a input.
here's my code:


#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int k = 0,uc =0 ,lc =0 ;

    fgets(cAFirst,25,stdin);
    // printf("out: %d \n",k);

    for (size_t i = 0; i < 25; i++) {
      k = (int)cAFirst[i];
      if ((k <= 90) && (k >= 65)) {
        uc++;
      }
      if ((k >= 97) && (k <= 122)) {
        lc++;
      }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n",uc,lc );
    return 0;
}


lowercase (lc) is ok, but value of uc is randomly incremented.
I have already tried changing formatting of printf and it sometimes work, but problem is i have to submit this code with same formatting given above.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    if (fgets(cAFirst, sizeof(cAFirst), stdin) != NULL) {
        // Calculate the length of the input string
        size_t length = strlen(cAFirst);

        for (size_t i = 0; i < length; i++) {
            char c = cAFirst[i];
            if (c >= 'A' && c <= 'Z') {
                uc++;
            }
            if (c >= 'a' && c <= 'z') {
                lc++;
            }
        }

        printf("Uppercase Letters = %i\nLowercase Letters = %i\n", uc, lc);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
