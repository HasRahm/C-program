#include <stdio.h>

int hasRepetition(const char *input_str) {
    while (*input_str != '\0' && *(input_str + 1) != '\0') {
        if (*input_str == *(input_str + 1)) {
            return 1; // Return 1 as soon as repetition is found
        }
        input_str++;
    }

    return 0; // Return 0 if no repetition is found
}

int main() {
    const char *string1 = "tomorrow";
    const char *string2 = "today";
    const char *string3 = "programming";

    printf("%d\n", hasRepetition(string1)); // Output: 1 (repetition of 'o')
    printf("%d\n", hasRepetition(string2)); // Output: 0 (no repetition)
    printf("%d\n", hasRepetition(string3)); // Output: 1 (repetition of 'm')

    return 0;
}
