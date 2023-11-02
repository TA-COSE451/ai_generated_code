/*
I'm working in C, and I have to concatenate a few things.
Right now I have this:

message = strcat("TEXT ", var);

message2 = strcat(strcat("TEXT ", foo), strcat(" TEXT ", bar));


Now if you have experience in C I'm sure you realize that this gives you a segmentation fault when you try to run it. So how do I work around that?
*/

#include <stdio.h>
#include <string.h>

int main() {
    char var[] = "Variable";
    char foo[] = "Foo";
    char bar[] = "Bar";

    char message[100];  // Make sure this buffer is large enough to hold the result.

    strcpy(message, "TEXT ");
    strcat(message, var);

    printf("message: %s\n", message);

    char message2[100];  // Make sure this buffer is large enough to hold the result.

    strcpy(message2, "TEXT ");
    strcat(message2, foo);
    strcat(message2, " TEXT ");
    strcat(message2, bar);

    printf("message2: %s\n", message2);

    return 0;
}
