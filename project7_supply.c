//Name: Hasin Shadab Rahman                                   //UID:U875123234
//This is a program that reads in the data (a list of supplies in random order) from a file and write the search result to the output file. The user will enter the name of the supply for searching.
#include <stdio.h>
#include <string.h>

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

// Function to search for supplies matching the given name
int search(struct supply list[], int n, struct supply result[], char *search_name) {
    int i, count = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(list[i].name, search_name) == 0) {
            strcpy(result[count].name, list[i].name);
            strcpy(result[count].color, list[i].color);
            result[count].quantity = list[i].quantity;
            count++;
        }
    }

    return count;
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

    // Arrays to store supply data and search results
    struct supply supplies[MAX_SUPPLY_ITEMS];
    struct supply search_result[MAX_SUPPLY_ITEMS];
    char search_name[MAX_NAME_LENGTH];
    int i, num_supplies, num_results;

    // Read supply data from input file
    for (num_supplies = 0; num_supplies < MAX_SUPPLY_ITEMS; num_supplies++) {
        if (fscanf(input_file, "%[^,], %[^,], %d\n", supplies[num_supplies].name,
                   supplies[num_supplies].color, &supplies[num_supplies].quantity) != 3)
            break;
    }

    // Prompt user for supply name to search
    printf("Enter supply: ");
    read_line(search_name, MAX_NAME_LENGTH, stdin);

    // Search for the given supply name
    num_results = search(supplies, num_supplies, search_result, search_name);

    // Write matching results to output file
    for (i = 0; i < num_results; i++) {
        fprintf(output_file, "%s, %s, %d\n", search_result[i].name, search_result[i].color,
                search_result[i].quantity);
    }

    printf("Results saved in result.csv\n");

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}
