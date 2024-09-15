// Name: Hasin Shadab Rahman
// The following program is for candy machine where it prompts the user with 3 choice of candies and asks the user to enter coins such as quater(25), dime(10) and nickel(5) until entered coin is 0.Then it calculates total number of coins and checks if it is sufficient for choosen candy.
#include <stdio.h>

#define H 15 // Hershey's kisses price
#define R 25 // Reece's peanut butter price
#define S 50 // Snickers price

int main() {
    int total = 0;
    int coins;

    // prompts for number of coins until input is 0
    while (1) {
        printf("Insert coins: ");
        scanf("%d", &coins);

        // Check if the user entered 0 to stop
        if (coins == 0) {
            break;
        }

        // Check if the entered coin is a valid denomination (0, 5, 10, or 25)
        if (coins != 0 && coins != 5 && coins != 10 && coins != 25) {
            continue;
        }

        total += coins;
    }

    // prompts the user with choices
    if (total > 0) {
        printf("1 - Hershey's kisses (15 cents), 2 - Reese's Peanut Butter Cups (25 cents), 3 - Snickers (50 cents)\n");
        int choice;
        printf("Enter your choice:");
        scanf("%d", &choice);

        int change;

        if (choice == 1) {
            // validates the amount entered for choice 1
            if (total >= H) {
                // calculate the change and return back the change
                change = total - H;
                printf("Your change is %d cents", change);
            } else {
                // Invalidates the amount entered and returns the total amount
                printf("Insufficient amount, %d cents returned", total);
            }
        } else if (choice == 2) {
            // validates the amount entered for choice 2
            if (total >= R) {
                // calculate the change and return back the change
                change = total - R;
                printf("Your change is %d cents", change);
            } else {
                // Invalidates the amount entered and returns the total amount
                printf("Insufficient amount, %d cents returned", total);
            }
        } else if (choice == 3) {
            // validates the amount entered for choice 3
            if (total >= S) {
                // calculate the change and return back the change
                change = total - S;
                printf("Your change is %d cents", change);
            } else {
                // Invalidates the amount entered and returns the total amount
                printf("Insufficient amount, %d cents returned", total);
            }
        } else {
            // Invalid choice and returns the total amount
            printf("Invalid selection, %d cents returned", total);
        }
    } 

    return 0;
}
