//Hasin Shadab Rahman
// UID: U87513234
#include <stdio.h>
#include <ctype.h>
// The following program get an input from and validates. input characters are command line arguments.The inputs can contain only All alphabetic letters are lower case, Non alphabetic letters like digits, white space, exclamation point, question mark, or period using pointer

// Function prototype
int isValidInput(char *input);

int main(int argc, char *argv[]) {
    // Check if the number of arguments is greater than 2
    int allValid = 1; // Flag to track overall validity
    if (argc <= 2) {
        printf("invalid number of arguments\n");
        return 1; // Return non-zero to indicate an error
    }

    // Validate each command line argument
    for (int i = 1; i < argc; i++) {
        if (!isValidInput(argv[i])) {
            printf("invalid\n");
            allValid = 0;
            break; // Exit the loop on first invalid argument
        }
    
    
    }
    if (allValid) {
    printf("valid\n"); // Print "valid" only if all arguments were valid
  }
    

    return 0;
}

// Function to validate input based on given conditions
int isValidInput(char *input) {
    char *ptr = input;
    int isValid = 1; // Assume input is valid initially

    while (*ptr != '\0') {
        char c = *ptr;

        // Validate the character based on conditions
        if (!(islower(c) || isdigit(c) || c == ' ' || c == '?' || c == '!' || c == '.')) {
            isValid = 0; // Mark as invalid if any condition is not met
            break;
        }

        ptr++;
    }

    return isValid;
}
