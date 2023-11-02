/*
As mentioned in the title, I'm looking for a way to convert a char* (coming from argv) to a uint16_t. The command line argument is a port number, and so, can't be > to 65535, nor negative.

Currently, I did this (compiling with -std=gnu99):

#include <stdbool.h>
#include <errno.h>
#include <stdint.h>
#include <inttypes.h>

// Converts a string to an unsigned int and stores the result in "res".
bool str_to_uint(const char* str, unsigned long int* res) {
    if (str[0] == '-')
        return false;
    char* first_wrong_character;
    uintmax_t result = strtoumax(str, &first_wrong_character, 10);
    if ((result == UINTMAX_MAX) && (errno == ERANGE))
        return false; // Overflow)
    if ((*str != '\0') && (*first_wrong_character != '\0'))
        return false; // Not everything has been converted
    if ((result == 0) && (str == first_wrong_character))
        return false; // Nothing to convert
    *res = result;
    return true;
}

// Converts a string to an uint16_t and stores the result in "res".
bool str_to_uint16(const char* str, uint16_t* res) {
    unsigned long uint;
    if (!str_to_uint(str, &uint))
        return false;
    if (uint > UINT16_MAX)
        return false;
    *res = (uint16_t)uint;
    return true;
}

I'm not sure it's the best way to do it, so if you could tell me what is the good way ?
*/

#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

// Converts a string to a uint16_t and stores the result in "res".
bool str_to_uint16(const char* str, uint16_t* res) {
    char* endptr;
    unsigned long int val = strtoul(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        // The entire string was not converted or there are extra characters.
        return false;
    }

    if (val > UINT16_MAX) {
        // Value is too large to fit in a uint16_t.
        return false;
    }

    *res = (uint16_t)val;
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        return 1;
    }

    uint16_t port;
    if (str_to_uint16(argv[1], &port)) {
        printf("Port number: %u\n", port);
    } else {
        printf("Invalid port number: %s\n", argv[1]);
    }

    return 0;
}
