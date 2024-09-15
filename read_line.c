// Name: Hasin Shadab Rahman                 UID: U87513234
#include <ctype.h>
#include "read_line.h"

// Function to read a line of input
int read_line(char str[], int n) {
    int ch, i = 0;
    while (isspace(ch = getchar()))
        ; // Skip leading whitespace characters

    str[i++] = ch; // Store the first non-whitespace character

    // Read the remaining characters until a newline is encountered
    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch; // Store the character if there's enough space
    }
    str[i] = '\0'; // Null-terminate the string
    return i; // Return the number of characters read
}