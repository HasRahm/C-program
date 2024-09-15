// Name: Hasin Shadab Rahman
// Net Id : hasinrahman
// Description: a program that asks the user to enter a fraction, then reduces the fraction to lowest terms
#include <stdio.h>

int main(){
    int i, a, b;
    
    while(1){
    // prompts the user for fraction
    printf("Enter a fraction (enter 0 to stop): ");
    scanf("%d/%d", &a, &b);
    if(a == 0 || b== 0){
        break;
    }
    // if the remainder is 0 then it will the absolute of a/b
    if((a%b)==0){
        printf("In lowest terms: %d\n",a/b);
        continue;
    }
    int sign = (a * b) / (abs(a*b)); // Determine the sign of the fraction
        a = abs(a); // Make numerator positive
        b = abs(b); // Make denominator positive

        int originalA = a;
        int originalB = b;

        // Simplify the fraction
        while (a != 0 && b != 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }

        int gcd = a + b; // The remaining value is the GCD

        a = originalA / gcd;
        b = originalB / gcd;

        printf("In lowest terms: %d/%d\n", sign * a, b);
    }

    

    
  return 0; } 


