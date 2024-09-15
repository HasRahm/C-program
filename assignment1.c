//Name: Hasin Shadab Rahman
//UID: U87513234
//NetId: hasinrahman
//Program Description: This program calculates the total grade using the following grade weights: Quizzes (10%), Homework (20%), Midterm Exam (30%) and FinalExam (40%).
#include <stdio.h>

int main(){
    printf("This is the total grade calculator program.\n");
    int a1, a2, a3, q1, q2, e1, e2;
    //Prompts the user for quiz1 grade
    printf("Enter Quiz1 grade: ");
    scanf("%d", &q1);
    //Prompts the user for quiz2 grade
    printf("Enter Quiz2 grade: ");
    scanf("%d", &q2);
    //Prompts the user for Homework1 grade
    printf("Enter Homework1 grade: ");
    scanf("%d", &a1);
    //Prompts the user for Homework2 grade
    printf("Enter Homework2 grade: ");
    scanf("%d", &a2);
    //Prompts the user for Homework3 grade
    printf("Enter Homework3 grade: ");
    scanf("%d", &a3);
    //Prompts the user for Midterm grade
    printf("Enter Midterm exam grade: ");
    scanf("%d", &e1);
    //Prompts the user for Final grade
    printf("Enter Final exam grade: ");
    scanf("%d", &e2);
    double q,m,f,a;
    //Calculates the quiz grade using the grade weight
    q = ((q1+q2) * 0.10)/2;
    //Calculates the Midterm grade using the grade weight
    m = e1 * 0.30;
    //Calculates the final exam grade using the grade weight
    f = e2 * 0.40;
    //Calculates the homework grade using the grade weight
    a = ((a1+a2+a3) * 0.20)/3;
    //Calculates the total grade
    double total = q+m+f+a;
    // Displays Total grade
    printf("Total grade: %.2f", total);
}