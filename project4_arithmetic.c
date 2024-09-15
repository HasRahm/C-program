//Name: Hasin Shadab Rahman                .                   //UID:U87513234
#include <stdio.h>
// The following program helps to find out if an array is in arithmetic sequence or not using pointers,
int is_arithmetic_sequence(int *sequence, int n) {
    if (n <= 2) {
        return 1; // A sequence with 0 or 1 elements is always arithmetic
    }

    int difference = *(sequence + 1) - *sequence;

    for (int *p = sequence; p < sequence + n - 1; p++) {
        if (*(p + 1) - *p != difference) {
            return 0; // Not an arithmetic sequence
        }
    }

    return 1; // It's an arithmetic sequence
}

int main() {
    int N;

    // Read the length of the arithmetic sequence
    //prompts user for the length of sequence
    printf("Enter length of the sequence: ");
    scanf("%d", &N);

    int a[N];

    // Read the elements of the sequence
    //prompts user for each element and stores
    printf("Enter numbers of the sequence: ");
    for (int *s = a; s < a + N; s++) {
        scanf("%d", s);
    }

    int arth = is_arithmetic_sequence(a, N);

    if (arth) {
        printf("yes");
    } else {
        printf("no");
    }

    return 0;
}
