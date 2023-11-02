/*
I am trying to create a program that contains a structure, say "myStruct", that contains a string array "char* array". Then a function to allocate the memory and then print the output, followed by a main function like below:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct { char *array; } str1;

void display(str1 *p1) {
  char *array;
  array = (char *)malloc(10 * sizeof(char));
  printf("%s", p1->array);
  free(array);
}

int main(void) {
  str1 s1;
  strcpy(s1.array, "Damn");
  return 0;
}


However I expect "Damn" as output but I am getting nothing in output. However during compiling, shows the following warning:


user@localhost: ~ $ clang struct.c -Weverything
struct.c:7:6: warning: no previous prototype for function 'display' [-Wmissing-prototypes]
void display(str1 *p1) {
     ^
1 warning generated.


That means function is not called. I need some help both syntactically and semantically in this case. I am not sure how to call the function display().
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct myStruct {
    char *array;
} str1;

void display(str1 *p1); // Function prototype

int main(void) {
    str1 s1;
    strcpy(s1.array, "Damn");
    display(&s1); // Call the display function
    return 0;
}

void display(str1 *p1) {
    char *array;
    array = (char *)malloc(10 * sizeof(char));
    printf("%s", p1->array);
    free(array);
}
