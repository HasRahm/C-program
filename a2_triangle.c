// Name: Hasin Shadab Rahman
// Net Id : hasinrahman
//Description:a program that uses brute-force computing to determine the integer sets of Pythagorean triples up to a limit set by the user. The user inputs a maximum integer length of the hypothenuse side of the triangle.
#include <stdio.h>

int main() {
    int a, b, c, k;

    while (1) {
        // prompts the user for the length of hypothenuse
        printf("Enter a length of hypothenuse (enter 0 to stop): ");
        scanf("%d", &k);
        // program ends if length is zero
        if (k == 0) {
            break;
        }
        // checks if the value is less than 4
        if (k <= 4) {
            printf("Enter an integer larger than 4.\n");
            continue;
        }
        // The for loops are used to iterate over all possible values of a, b, and c
        for (c = 1; c <= k; c++) {
            for (a = 1; a < c; a++) {
                for (b = a; b < c; b++) {
                    if (c * c == a * a + b * b) {
                        printf("a=%d, b=%d, c=%d\n", a, b, c);
                        if (a != b) {
                            printf("a=%d, b=%d, c=%d\n", b, a, c);
                        }
                    }
                }
            }
        }
    }

    return 0;
}

