//Name: Hasin Shadab Rahman                                         UID: U87513234
// The following programming takes text file as an input and reads the file checks each word stored in a file, if it is some string written twice in a row. For example, the words "coco", "murmur" are some strings written twice in a row ("co" for "coco", "mur" for "murmur"). But the words "boba" and "radar" are not some strings written twice in a row then write the words that are some strings written twice in a row to the output file. 
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

// Function prototype
int is_square(char *word);

int main() {
    // Array to store the input file name
    char input_file[101];
    printf("Enter file name: ");
    scanf("%100s", input_file);

    // File pointers for input and output files
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen("output.txt", "w");

    // Check if file opening was successful
    if (input_fp == NULL || output_fp == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    // Array to store words read from input file
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    // Read words from input file
    while (fscanf(input_fp, "%s", words[word_count]) == 1) {
        // Check if word is a square word, if so, write it to output file
        if (is_square(words[word_count])) {
            fprintf(output_fp, "%s\n", words[word_count]);
        }
        word_count++;
    }

    // Close files
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}

// Function to check if a word is written twice in a row
int is_square(char *word) {
    // Get length of the word
    int length = strlen(word);
    // Only even-length words can be square
    if (length % 2 != 0)
        return 0;

    // Calculate half length
    int half_length = length / 2;
    // Check if each character matches its corresponding character after halfway
    for (int i = 0; i < half_length; i++) {
        if (word[i] != word[i + half_length])
            return 0;
    }
    // If all characters match, return 1 (true)
    return 1;
}
