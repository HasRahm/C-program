//Name: Hasin Shadab Rahman  
// UID: U87513234
// Following program encrypts message using pointer arithmetic For example, a message “brb” will be encrypted as “brrbbb”.
#include <stdio.h>

// Maximum length of String Variable
#define STRLEN 1000

// Function prototype
void decrypt(char *input, char *output);

int main() {
    // Declare necessary variables
    char input[STRLEN + 1] = {}, output[STRLEN + 1] = {}, ch;
    int i = 0;

    // User inputs encrypted message
    printf("Enter message: ");
    while ((ch = getchar()) != '\n') {
        input[i++] = ch;
    }

    // Ensure the input string is properly terminated
    input[i] = '\0';

    // Decrypt the message
    decrypt(input, output);

    // Print the decrypted output
    printf("Output: %s\n", output);

    return 0;
}

void decrypt(char *input, char *output) {
    // Initialize index for decryption
    int i = 0;

    // Iterate through the input characters until null character is encountered
    while (*input != '\0') {
        // Calculate the index based on the Triangular sequence formula
        int index = (i * (i + 1)) / 2;

        // Check if the index is within the bounds of the array
        if (index < STRLEN) {
            // Access the character at the calculated index and store it in the output
            *output++ = *(input + index);
        } else {
            // Break the loop if the index is out of bounds
            break;
        }

        // Move to the next character in the input
        i++;
    }

    // Add the null character at the end of the decrypted output
    *output = '\0';
}









