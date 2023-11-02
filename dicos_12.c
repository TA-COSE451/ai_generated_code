/*
I am trying to save each line of a text file into an array. They way I am doing it and works fine so far is this :


char *lines[40];
char line[50];
int i = 0 ;
char* eof ;
while( (eof = fgets(line, 50, in)) != NULL )
{
    lines[i] = strdup(eof); //Fills the array with line of the txt file one by one
    i++;
}
My text file has 40 lines , which I am accessing with a for loop

for( j = 0; j <= 39 ; j++) {
  //Do something to each line.
}


So far so good. My problem is that i define the size of the array lines for the a text file that has 40 lines. I tried to count the lines and then define the size but I am getting segmentation fault.

My approach:


int count=1 ; char c ;
for (c = getc(in); c != EOF; c = getc(in))
    if (c == '\n') // Increment count if this character is newline
        count = count + 1;
printf("\nNUMBER OF LINES = %d \n",count); 
char* lines[count];


Any ideas?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 50

int main() {
    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    int lineCount = 0;
    char c;

    while ((c = getc(in)) != EOF) {
        if (c == '\n') {
            lineCount++;
        }
    }

    // Reset the file pointer to the beginning of the file
    fseek(in, 0, SEEK_SET);

    printf("Number of lines: %d\n", lineCount);

    char **lines = (char **)malloc(lineCount * sizeof(char *));
    if (lines == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, in) != NULL && i < lineCount) {
        lines[i] = strdup(line);
        i++;
    }

    fclose(in);

    // Example usage: print the lines
    for (int j = 0; j < lineCount; j++) {
        printf("Line %d: %s", j + 1, lines[j]);
    }

    // Free the allocated memory
    for (int j = 0; j < lineCount; j++) {
        free(lines[j]);
    }
    free(lines);

    return 0;
}

/*
- Request:
I am trying to save each line of a text file into an array.
My text file has 40 lines , which I am accessing with a for loop.
I define the size of the array lines for the a text file that has 40 lines.

- Code to fix:
char *lines[40];
char line[50];
int i = 0 ;
char* eof ;
while( (eof = fgets(line, 50, in)) != NULL )
{
    lines[i] = strdup(eof); //Fills the array with line of the txt file one by one
    i++;
}

for( j = 0; j <= 39 ; j++) {
    // Do something to each line.
}

int count=1 ; char c ;
for (c = getc(in); c != EOF; c = getc(in))
    if (c == '\n') // Increment count if this character is newline
        count = count + 1;
printf("\nNUMBER OF LINES = %d \n",count); 

char* lines[count];

- Error:
I tried to count the lines and then define the size but I am getting segmentation fault.

- Security precautions: Please watch out for the following vulnerabilities.
NULL Pointer Dereference: A NULL pointer dereference occurs when the application dereferences a pointer that it expects to be valid, but is NULL, typically causing a crash or exit.

*/