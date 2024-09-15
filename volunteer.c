//Name: Hasin Shadab Rahman                         UID: U87513234
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "volunteer.h"
#include "read_line.h"

// Function to add a new volunteer to the list
struct volunteer *add_to_list(struct volunteer *list) {
    struct volunteer *current = list;
    struct volunteer *new_volunteer = malloc(sizeof(struct volunteer));
    
    if (new_volunteer == NULL) {
        printf("Memory allocation failed.");
        return list; // Return the original list if memory allocation fails
    }

    // Get volunteer information from the user
    printf("Enter last name: ");
    read_line(new_volunteer->last, NAME_LEN);
    printf("Enter first name: ");
    read_line(new_volunteer->first, NAME_LEN);
    printf("Enter email address: ");
    read_line(new_volunteer->email, EMAIL_LEN);
    printf("Enter grade level: ");
    scanf("%d", &new_volunteer->grade_level);

    // Check if the volunteer already exists in the list
    while (current != NULL) {
        if (strcmp(current->email, new_volunteer->email) == 0 && strcmp(current->last, new_volunteer->last) == 0) {
            printf("Volunteer already exists.");
            free(new_volunteer);
            return list;
        }
        current = current->next;
    }

    // Initialize the new node
    new_volunteer->next = NULL;
    new_volunteer->prev = NULL;

    // If the list is empty, return the new node
    if (list == NULL)
        return new_volunteer;

    // Add the new node to the end of the list
    current = list;
    while (current->next != NULL)
        current = current->next;

    current->next = new_volunteer;
    new_volunteer->prev = current;

    return list;
}

// Function to search volunteers by grade level
void search_list(struct volunteer *list) {
    int grade;
    printf("Enter grade level: ");
    scanf("%d", &grade);

    struct volunteer *current = list;
    int found = 0;

    // Traverse the list and print volunteers with the specified grade level
    while (current != NULL) {
        if (current->grade_level == grade) {
            printf("%-12s%-12s%-30s\n", current->last, current->first, current->email);
            found = 1;
        }
        current = current->next;
    }

    // If no volunteers with the specified grade level are found, print a message
    if (!found)
        printf("Not found");
}

// Function to print the list of volunteers
void print_list(struct volunteer *list) {
    struct volunteer *current = list;

    // Traverse the list and print volunteer information
    while (current != NULL) {
        printf("%-12s%-12s%-30s%5d\n", current->last, current->first, current->email, current->grade_level);
        current = current->next;
    }
}

// Function to clear the list and deallocate memory
void clear_list(struct volunteer *list) {
    while (list != NULL) {
        struct volunteer *temp = list;
        list = list->next;
        free(temp); // Free the memory occupied by the current node
    }
}

// Function to delete a volunteer from the list
struct volunteer *delete_from_list(struct volunteer *list) {
    char last[NAME_LEN + 1];
    char first[NAME_LEN + 1];
    char email[EMAIL_LEN + 1];
    int grade_level;

    // Get volunteer information from the user
    printf("Enter last name: ");
    read_line(last, NAME_LEN);
    printf("Enter first name: ");
    read_line(first, NAME_LEN);
    printf("Enter email address: ");
    read_line(email, EMAIL_LEN);
    printf("Enter grade level: ");
    scanf("%d", &grade_level);

    struct volunteer *current = list;
    struct volunteer *prev = NULL;

    // Traverse the list and find the volunteer to delete
    while (current != NULL) {
        if (strcmp(current->last, last) == 0 && strcmp(current->first, first) == 0 &&
            strcmp(current->email, email) == 0 && current->grade_level == grade_level) {
            // If the volunteer is found, remove them from the list
            if (prev == NULL) {
                list = current->next;
                if (list != NULL)
                    list->prev = NULL;
            } else {
                prev->next = current->next;
                if (current->next != NULL)
                    current->next->prev = prev;
            }
            free(current); // Free the memory occupied by the deleted node
            return list;
        }
        prev = current;
        current = current->next;
    }

    // If the volunteer is not found, print a message
    printf("Volunteer does not exist.");
    return list;
}