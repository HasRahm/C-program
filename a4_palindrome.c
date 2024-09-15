//Name: Hasin Shadab Rahman
//NetID: hasinrahman
//Description: This C program reads a message from the user, filters out non-alphabetic characters, checks if the filtered message is a palindrome, and asks the user if they want to continue or stop.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100
// Function to check if a given string is a palindrome
int is_palindrome(char *start, char *end) {
    while (start < end) {
        if (tolower(*start) != tolower(*end)) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Is a palindrome
}

// Function to check if the input contains at least one alphabetical character
int contains_alpha(char *message) {
    while (*message) {
        if (isalpha(*message)) {
            return 1; // Found an alphabetical character
        }
        message++;
    }
    return 0; // No alphabetical character found
}

int main() {
    char message[MAX_LENGTH + 1]; // Array to store the input message (+1 for null-terminator)
    char filtered_message[MAX_LENGTH + 1]; // Array to store the filtered message
    char *p, *q;
    char continue_choice[MAX_LENGTH + 1]; // Array to store continue choice
    int c = 0;
    do {
        printf("Enter a message: ");
        // Read the message from the user, skipping newline characters initially
        p = message;
        q = filtered_message;
        // Continue reading until at least one alphabetical character is encountered
        while (1) {
            *p = getchar();
            if (*p == '\n') {
                continue; // Skip newline characters
            }
            if (isalpha(*p)) {
                *q++ = tolower(*p); // Copy only letters to the filtered message in lowercase
                break; // Exit loop once an alphabetical character is read
            }
        }
        // Continue reading the rest of the message
        while ((p - message) < MAX_LENGTH && (*p = getchar()) != '\n') {
            if (isalpha(*p)) {
                *q++ = tolower(*p); // Copy only letters to the filtered message in lowercase
            }
            p++;
        }
        *q = '\0'; // Null-terminate the filtered message
        // Check if the filtered message contains at least one alphabetical character
        if (!contains_alpha(filtered_message)) {
            continue; // Prompt again if no alphabetical characters found
        }
        // Check if the filtered message is a palindrome
        if (is_palindrome(filtered_message, q - 1)) {
            printf("Palindrome\n\n");
        } else {
            printf("Not a palindrome\n\n");
        }
        printf("Do you want to continue (N to stop)? ");
        // Prompt to continue or stop, keep asking until valid input is received
        do {
            fgets(continue_choice, MAX_LENGTH + 1, stdin); // Read input as a string
            // Check if 'n' is present in the input
            if (strchr(continue_choice, 'n') || strchr(continue_choice, 'N')) {
                c = 0; // Stop condition
                break;
            } else if (continue_choice[0] == '\n') {
                continue; // Skip empty line
            } else {
                c = 1; // Continue condition
                break;
            }
        } while (1);

        if (c == 1) {
            continue;
        } else {
            break;
        }

    } while (1);  

    return 0;
}