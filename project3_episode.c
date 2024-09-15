//Hasin Shadab Rahman                          UID:87513234
#include <stdio.h>

int main() {
    int n;
    // Propmpts the user with number episodes in the show
    printf("Enter number of episodes: ");
    scanf("%d", &n);
    // Store number of episodes watched
    int arr[n];
    // Prompts the user with the each number of episodes
    printf("Enter episodes watched: ");
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = 1; // Assuming the episodes start from 1
    printf("Missing episode: ");

    for (int i = 1; i <= n; i++) {
        int found = 0;
        // Iterate through watched episodes to see if current episode is present
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                found = 1;
                
            }
        }
        // prints the missing episode i.e the episode not watched
        if (!found) {
            printf("%d", i);
            
        }
    }

    return 0;
}


