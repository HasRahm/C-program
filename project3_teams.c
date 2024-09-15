//Name: Hasin Shadab Rahman                          UID: U87513234
#include <stdio.h>
#include <stdlib.h>
// Function to assign students to teams based on their accumulated points
void assign(int *points, int *team_assignment[], int n){
     for (int i = 0; i < n; i++) {
        // Calculate the absolute differences between points and team thresholds
        int b = abs(*points - 25);
        int h = abs(*points - 70);
        int e = abs(*points - 125);

        // Determine the team assignment based on the minimum difference
        if (b <= h && b <= e) {
            *team_assignment = 1; // Beginner team
        } else if (h<= b && h <= e) {
            *team_assignment = 2; // Honor team
        } else {
            *team_assignment = 3; // Excellence team
        }
}}

int main(){
    int n;
    // Prompt for the number of students
    printf("Enter number of students: ");
    scanf("%d", &n);
    // Array to store points for each student
    int points[n];
    // Array to store team assignments for each student
    int team_assignment[n];
    // Prompt for points of each student
    printf("Enter points for each student: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &points[i]);
    }
    // Call the assign function to determine team assignments
    assign(points, team_assignment, n);
    // Display Beginner team members
    printf("Beginner team: student");
    for (int i = 0; i < n; i++) {
        if (team_assignment[i] == 1) {
            printf(" %d ", i + 1);
        }
    }
    printf("\n");

    // Display Honor team members
    printf("Honor team: student ");
    
    for (int i = 0; i < n; i++) {
        if (team_assignment[i] == 2) {
            printf(" %d ", i + 1);
        }
    }
    printf("\n");
    //  Display Excellence team members
    printf("Excellence team: student");
    for (int i = 0; i < n; i++) {
        if (team_assignment[i] == 3) {
            printf(" %d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}



