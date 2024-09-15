// Name: Hasin Shadab Rahman                                   UID: U87513234
// The program below calculates the cost for a selected package, number of people, and duration for an event
#include <stdio.h>

int main() {
    // Display package selection prompt
    printf("Please select from three packages: 1, 2, and 3\n");
    int pack;
    int hours;
    int guests;

    // Get user input for package selection
    printf("Enter package selection:");
    scanf("%d", &pack);

    if (pack == 1) {
        // Package 1 details
        printf("Enter hours:");
        scanf("%d", &hours);

        if (1 <= hours && hours < 5) {
            // Validate hours

            // Get number of guests
            printf("Enter the number of guests: ");
            scanf("%d", &guests);

            if (5 <= guests && guests <= 20) {
                // Validate number of guests

                // Calculate and display charge for package 1
                // 150 is first hour charge after that user is charged hourly basis and based number of guests
                int charge = 150 + ((hours-1)* 100) + (guests * 25);

                if (charge >= 595) {
                    // user can be charged upto 595 even though if the calculated charge is greater than 595

                    charge = 595;
                }

                printf("Charge ($): %d\n", charge);
            } else {
                // Invalid number of guests
                printf("Invalid number of guests.");
                
            }
        }else {
            // Invalid number of hours
            printf("Invalid hours.");
            
    
        }
    } else if (pack == 2) {
        // Package 2 details

        // Get number of hours
        printf("Enter hours:");
        scanf("%d", &hours);

        if (1 <= hours && hours < 5) {
            //validate Number of hours

            // Gets number of guests
            printf("Enter the number of guests:");
            scanf("%d", &guests);

            if (8 <= guests && guests <= 30) {
                // validate number of guest

                // Calculates number of charge
                // 180 is first hour charge after that user is charged hourly basis and based number of guests
                int charge =180 + ((hours-1) * 120) + (guests * 22);

                if (charge >= 850) {
                    // user can be charged upto 850 even though if the calculated charge is greater than 850
                    charge = 850;
                }

                printf("Charge ($): %d\n", charge);
            } else {
                //Inavlids number of gusets
                printf("Invalid number of guests.");
            }
        }else {
            // Invalids number of hours
            printf("Invalid hours.");
        }
    } else if (pack == 3) {
        // Package 3 details

        // Gets the number of hours
        printf("Enter hours:");
        scanf("%d", &hours);

        if (1 <= hours && hours < 5) {
            // Validate number of hours

            // Gets number of guests
            printf("Enter the number of guests:");
            scanf("%d", &guests);

            if (10 <= guests && guests <= 40) {
                // Validate number of guests

                // Calculate the charge and display the charge
                // 200 is first hour charge after that user is charged hourly basis and based number of guests
                int charge =200 + ((hours-1) * 150) + (guests * 20);

                if (charge >= 1050) {
                    // user can be charged upto 1050 even though if the calculated charge is greater than 1050
                    charge = 1050;
                }

                printf("Charge ($): %d\n", charge);
            } else {
                // Invalid number of guests
                printf("Invalid number of guests.");
            }
        }else {
            // Invalid number of hours
            printf("Invalid hours.");
        }
    } else {
        // Invalid package selection
        printf("Invalid selection.");
    }

    return 0;
}
