//Name: Hasin Shadab Rahman
//NetId: hasinrahman
//Description: program that reads a series of numbers between 0 and 200 inclusive.program displays distinct numbers.

#include <stdio.h>

int main() {
    while (1) {
        int n;

        // Prompt user to enter the number of input integers
        printf("Enter the number of input integers (0 to stop): ");
        scanf("%d", &n);

        // Check if input is invalid
        if (n < 0) {
            printf("Invalid number\n");
            continue; // Skip to the next iteration
        } else if (n == 0) {
            break; // Exit the loop
        }

        // Create an array to store the input integers
        int a[n];
        int valid_count = 0;

        // Prompt user to enter numbers
        printf("Enter numbers (0 - 200): ");

        // Read the input numbers
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            if (num >= 0 && num <= 200) {
                a[valid_count++] = num;
            } else {
                printf("%d: invalid and ignored\n", num);
            }
        }

        // Ensure at least three valid numbers
        while (valid_count < 3) {
            
            int num;
            scanf("%d", &num);
            if (num >= 0 && num <= 200) {
                a[valid_count++] = num;
            } else {
                printf("%d: invalid and ignored\n", num);
            }
        }

        // Array to track printed numbers (using integer flags)
        int printed[201] = {0}; // 0 means not printed, 1 means printed

        // Print only distinct numbers
        printf("Unique numbers: ");
        int first_unique = 1; // Flag to handle commas properly
        for (int i = 0; i < valid_count; i++) {
            if (printed[a[i]] == 0) {
                printed[a[i]] = 1; // Mark the number as printed

                // Print the number with comma and space if not the first number
                if (!first_unique) {
                    printf(", ");
                }
                printf("%d", a[i]);
                first_unique = 0; // Clear the flag after printing the first number
            }
        }
        printf("\n"); // Newline after printing all unique numbers
        
    }

    return 0;
}

    

    
        
   


