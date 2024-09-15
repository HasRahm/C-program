// Name: Hasin Shadab Rahman                 UID: U87513234
// The program below uses quick sort to sort the school supplies by name and color the quick sort library function and implement the comparison function.  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUPPLY_ITEMS 200
#define MAX_NAME_LENGTH 100
#define MAX_COLOR_LENGTH 100

// Structure to represent a supply item
struct supply {
    char name[MAX_NAME_LENGTH];
    char color[MAX_COLOR_LENGTH];
    int quantity;
};

// Function to read a line from a file
int read_line(char *str, int n, FILE *stream) {
    int ch, i = 0;

    while ((ch = fgetc(stream)) != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

// Comparison function for qsort to compare supplies by name and color
int compare_supply(const void *a, const void *b) {
    const struct supply *supply_a = (const struct supply *)a;
    const struct supply *supply_b = (const struct supply *)b;

    // First compare by name
    int name_comparison = strcmp(supply_a->name, supply_b->name);
    if (name_comparison != 0) {
        return name_comparison;
    }

    // If names are the same, compare by color
    return strcmp(supply_a->color, supply_b->color);
}

// Main function
int main() {
    // Open input and output files
    FILE *input_file = fopen("supply.csv", "r");
    FILE *output_file = fopen("result.csv", "w");

    // Check if files are opened successfully
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    // Arrays to store supply data
    struct supply supplies[MAX_SUPPLY_ITEMS];
    int num_supplies;

    // Read supply data from input file
    for (num_supplies = 0; num_supplies < MAX_SUPPLY_ITEMS; num_supplies++) {
        if (fscanf(input_file, "%[^,], %[^,], %d\n", supplies[num_supplies].name,
                   supplies[num_supplies].color, &supplies[num_supplies].quantity) != 3)
            break;
    }

    // Sort the supplies array using qsort
    qsort(supplies, num_supplies, sizeof(struct supply), compare_supply);

    // Write sorted array to the output file
    for (int i = 0; i < num_supplies; i++) {
        fprintf(output_file, "%s, %s, %d\n", supplies[i].name, supplies[i].color, supplies[i].quantity);
    }

    printf("Results saved in result.csv\n");

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
