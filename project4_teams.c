//Name: Hasin Shadab Rahman                                                                      //UID:U87513234
#include <stdio.h>
#include <stdlib.h>
//The following program assign to team based on their accumulated points by calculating the difference between points and team threshold and Determines the team assignment based on the minimum difference
// Function to assign students to teams based on their accumulated points
void assign(int *points, int *team_assignment, int n) {
    int *p_points = points;
    int *p_team_assignment = team_assignment;

    for (int i = 0; i < n; i++, p_points++, p_team_assignment++) {
        // Calculate the absolute differences between points and team thresholds
        int b = abs(*p_points - 25);
        int h = abs(*p_points - 70);
        int e = abs(*p_points - 125);

        // Determine the team assignment based on the minimum difference
        if (b <= h && b <= e) {
            *p_team_assignment = 1; // Beginner team
        } else if (h <= b && h <= e) {
            *p_team_assignment = 2; // Honor team
        } else {
            *p_team_assignment = 3; // Excellence team
        }
    }
}

int main() {
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
    for (int *p = points; p < points + n; p++) {
        scanf("%d", p);
    }

    // Call the assign function to determine team assignments
    assign(points, team_assignment, n);

    // Display Beginner team members
    printf("Beginner team: student");
    for (int i = 0; i < n; i++) {
        if (team_assignment[i] == 1) {
            printf(" %d", i + 1);
        }
    }
    printf("\n");

    // Display Honor team members
    printf("Honor team: student ");
    for (int i = 0; i < n; i++) {
        if (team_assignment[i] == 2) {
            printf(" %d", i + 1);
        }
    }
    printf("\n");

    // Display Excellence team members
    printf("Excellence team: student");
    for (int i = 0; i < n; i++) {
        if (team_assignment[i] == 3) {
            printf(" %d", i + 1);
        }
    }
    printf("\n");

    return 0;
}
