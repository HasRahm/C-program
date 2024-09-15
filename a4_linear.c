//Name: Hasin Shadab Rahman
//NetID: hasinrahman
//Description: This C program reads a series of integers from the user, stores them in an array, and then allows the user to search for a specific integer within that array. If the integer is found, the program indicates its positions; otherwise, it reports that the integer is not in the array. The program uses pointer arithmetic to manage the array elements.
#include <stdio.h>

int main() {
    int n, s;  // Variables for the number of inputs and the search number
    
    while (1) {  // Infinite loop for continuous user input
        printf("Enter the number of input integers (0 to stop): ");
        scanf("%d", &n);  // Read the number of integers
        while (getchar() != '\n');

        if (n == 0) {
            break;  // Exit the loop if the user enters 0
        }
        
        if (n < 0) {
            printf("Invalid number\n");  // Prompt if the number is negative
            printf("\n");
            continue;  // Continue to the next iteration
        }
        
        int a[n];  // Declare the array with size n
        printf("Enter numbers: ");
        
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);  // Use pointer arithmetic to store numbers in the array
        }
        
        // Clear the input buffer
        while (getchar() != '\n');
        
        printf("What is the search number? ");
        scanf("%d", &s);  // Read the search number
        
        int *p;  // Pointer for traversing the array
        int found = 0;  // Flag to indicate if the number is found
        
        // Search for the number in the array
        for (p = a; p < a + n; p++) {
            if (*p == s) {
                if (found == 0) {
                    // If this is the first occurrence, print the initial found message
                    printf("Found: %d is in position %ld", s, p - a);
                    found = 1;  // Set the flag to indicate the number is found
                } else {
                    // For subsequent occurrences, print the position
                    printf(", %ld in the array.\n", p - a);
                }
            }
        }
        
        
        if (!found) {
            // If the number is not found, print the not found message
            printf("Not found: %d is not in the array.\n", s);
        }
        
        
        printf("\n");  // Print a newline for formatting
    }
    
    return 0;  // Return 0 to indicate successful execution
}


