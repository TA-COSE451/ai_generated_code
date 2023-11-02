/*
I'm learning C and I was reading around what is the best way to take in input line by line.

Basically I want to create strings that hold a whole line of input. The question below doesn't answer how I should handle the memory allocation for the string.

How can I scan strings with spaces in them using scanf()?

Should I first detect how much space is needed? How? Should I just realloc every time I need more space?

Please show an example

Input is from a file or from stdin(both will be possible but not at the same time)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 128

int main() {
    char *line = NULL;            // Pointer to store the line
    size_t buffer_size = 0;       // Current buffer size
    size_t line_length = 0;       // Current line length
    int c;

    while ((c = getchar()) != EOF) {
        if (line_length + 1 >= buffer_size) {
            // If the line is about to exceed the buffer, reallocate memory
            buffer_size += INITIAL_BUFFER_SIZE;
            line = realloc(line, buffer_size);
            if (line == NULL) {
                perror("realloc");
                exit(EXIT_FAILURE);
            }
        }

        line[line_length++] = (char)c;

        if (c == '\n') {
            // End of line, process it here
            line[line_length] = '\0'; // Null-terminate the string

            // Do something with the line (e.g., print it)
            printf("Line read: %s", line);

            // Reset line_length for the next line
            line_length = 0;
        }
    }

    // Free allocated memory when done
    free(line);

    return 0;
}
