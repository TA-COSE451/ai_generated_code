/*
I need to count how many strings there is in a "string list". Each string ends as usual with a NUL char ('\0'), and the list ends with two NUL chars in succession.

I wrote a function but I keep getting a segmentation fault:

int numStrsInList(const char* strList) {
    int count = 0;
    int flag = 0;
    if(!(*strList))
        return -1;

    while (flag != 2) {
        if (!(*strList)) {
            count++;
            flag++;
        }
        else
            flag = 0;
        strList++;
    }
    return count;
}

*/

#include <stdio.h>

int numStrsInList(const char* strList) {
    int count = 0;
    int flag = 0;

    if (strList == NULL || !(*strList))
        return -1;

    while (*strList != '\0' || flag < 2) {
        if (*strList == '\0') {
            flag++;
        } else {
            flag = 0;
        }
        strList++;
    }

    return count;
}

int main() {
    const char strList[] = "string1\0string2\0string3\0\0";
    int numStrings = numStrsInList(strList);

    printf("Number of strings in the list: %d\n", numStrings);

    return 0;
}

/*
- Request:
I need to count how many strings there is in a "string list". Each string ends as usual with a NUL char ('\0'), and the list ends with two NUL chars in succession.

for example:
const char* empty = "\0";
const char* one = "Hell0 \t\n\v\f\rw0r1d\0";
const char* two = "Hello\0 \t\0";
const char* simple = "Hello\0world\0!\0";

numStrsInList(empty)
numStrsInList(one)
numStrsInList(two)
numStrsInList(simple)

for this strings the output should be:
0
1
2
3

- Code to fix:
int numStrsInList(const char* strList) {
    int count = 0;
    int flag = 0;
    if(!(*strList))
        return -1;

    while (flag != 2) {
        if (!(*strList)) {
            count++;
            flag++;
        }
        else
            flag = 0;
        strList++;
    }
    return count;
}

- Error:
Segmentation fault

- Security precautions: Please watch out for the following vulnerabilities.
Improper Restriction of Operations within the Bounds of a Memory Buffer: The product performs operations on a memory buffer, but it can read from or write to a memory location that is outside of the intended boundary of the buffer. 

*/