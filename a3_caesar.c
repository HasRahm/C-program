//Name: Hasin Shadab Rahman
//NetID: hasinrahman
// Description: The a3_caesar.c program encrypts messages using the Caesar cipher. It repeatedly prompts the user to enter a message (up to 150 characters) and a shift amount (1-25). The program then outputs the encrypted message. The process repeats until the user enters a shift amount of 0.
#include <stdio.h>

int main(void) {
    while (1) {
        char ch, message[150] = {0};
        int i, shift_amount;

        // Prompt the user to enter a message to be encrypted
        printf("Enter message to be encrypted: ");

        // Read the message character by character, up to a maximum of 150 characters
        for (i = 0; (ch = getchar()) != '\n'&& i<150; i++) {
         
                message[i] = ch;
            
        }

        // Prompt the user to enter a shift amount (1-25)
        printf("Enter shift amount (1-25, enter 0 to stop): ");
        scanf("%d", &shift_amount);

        // Clear the input buffer to remove any leftover newline character
        while ((ch = getchar()) != '\n' && ch != EOF);

        // Check if the user wants to stop the encryption
        if (shift_amount == 0) {
            break;
        }

        // Print the encrypted message
        printf("Encrypted message: ");
        for (i = 0; i < 150 && message[i] != '\0'; i++) {
            // Check if the character is an uppercase letter
            if (message[i] >= 'A' && message[i] <= 'Z') {
                // Encrypt the character using the Caesar cipher formula
                message[i] = ((message[i] - 'A') + shift_amount) % 26 + 'A';
            }
            // Check if the character is a lowercase letter
            else if (message[i] >= 'a' && message[i] <= 'z') {
                // Encrypt the character using the Caesar cipher formula
                message[i] = ((message[i] - 'a') + shift_amount) % 26 + 'a';
            }
            printf("%c", message[i]);
        }
        printf("\n");
    }

    return 0;
}


