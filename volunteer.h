//Name: Hasin Shadab Rahman                     UID:U87513234
#ifndef VOLUNTEER_H
#define VOLUNTEER_H

// Macros defining the maximum length for email and name
#define EMAIL_LEN 100
#define NAME_LEN 30

// Structure to store volunteer information
struct volunteer {
    char first[NAME_LEN + 1]; // First name
    char last[NAME_LEN + 1];  // Last name
    char email[EMAIL_LEN + 1]; // Email address
    int grade_level; // Grade level
    struct volunteer *next; // Pointer to the next node in the linked list
    struct volunteer *prev; // Pointer to the previous node in the linked list
};

// Function prototypes for operations on the volunteer list
struct volunteer *add_to_list(struct volunteer *list);
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
struct volunteer *delete_from_list(struct volunteer *list);

#endif