//Name: Hasin Shadab Rahman
//NETID: hasinrahman
/* This program reads a CSV file containing weather data with columns for month, day, and temperature.
 * It calculates the average temperature for each month and writes the statistics to an output file.
 * The output file is named based on the input CSV file with a .txt extension.
 * Only the first occurrence of each month-day combination is used for calculations.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DAYS 31
#define MAX_MONTHS 12

// Structure to hold the statistics for each month
typedef struct {
    int days;                // Number of measured days in the month
    double total_temperature; // Total temperature for the month
} MonthStats;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // Check if the program is called with the correct number of arguments
        printf("Usage: %s <csv filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        // Check if the file can be opened
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    MonthStats months[MAX_MONTHS] = {0};    // Array to hold statistics for each month
    int used[MAX_MONTHS][MAX_DAYS] = {0};   // Array to track which days have been used
    char line[256];

    // Read and ignore the header line
    fgets(line, sizeof(line), file);

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        int month, day;
        double temperature;

        // Parse the line to extract month, day, and temperature
        if (sscanf(line, "%d,%d,%lf", &month, &day, &temperature) != 3) {
            continue; // Skip lines that do not match the expected format
        }

        // Validate the month and day values
        if (month < 1 || month > 12 || day < 1 || day > 31) {
            continue; // Skip invalid dates
        }

        // Check if the day has already been used for this month
        if (used[month - 1][day - 1] == 0) {
            used[month - 1][day - 1] = 1; // Mark the day as used
            months[month - 1].days++;    // Increment the count of days for the month
            months[month - 1].total_temperature += temperature; // Add the temperature to the total
        }
    }

    fclose(file);

    // Create the output file name
    char output_filename[256];
    snprintf(output_filename, sizeof(output_filename), "%s.txt", argv[1]);
    FILE *output_file = fopen(output_filename, "w");

    int total_days = 0, measured_months = 0;
    double total_temperature = 0.0;

    // Write statistics for each month to the output file
    for (int i = 0; i < MAX_MONTHS; i++) {
        if (months[i].days > 0) {
            fprintf(output_file, "***** %s *****\n", 
                (const char*[]){"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}[i]);
            fprintf(output_file, "Measured days: %d\n", months[i].days);
            fprintf(output_file, "Average temperature: %.2f\n\n", months[i].total_temperature / months[i].days);
            
            total_days += months[i].days;
            total_temperature += months[i].total_temperature;
            measured_months++;
        }
    }

    // Write total statistics to the output file
    fprintf(output_file, "***** Total *****\n");
    fprintf(output_file, "Measured months: %d\n", measured_months);
    fprintf(output_file, "Measured days: %d\n", total_days);
    fprintf(output_file, "Average temperature: %.2f\n\n", total_temperature / total_days);
    

    fclose(output_file);

    return 0;
}
