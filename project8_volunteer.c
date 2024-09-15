//Name:Hasin Shadab Rahman                                  //UID:U87513234
//This program manages a list of high school student volunteers interested in assisting in summer camps for K-8 students. It utilizes a dynamically allocated linked list to store information about each volunteer, including their last name, first name, email, and grade level.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMAIL_LEN 100
#define NAME_LEN 30

struct volunteer {
    char first[NAME_LEN + 1];
    char last[NAME_LEN + 1];
    char email[EMAIL_LEN + 1];
    int grade_level;
    struct volunteer *next;
};

// Function prototypes
struct volunteer *add_to_list(struct volunteer *list);
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
int read_line(char str[], int n);

int main(void) {
    char code;
    struct volunteer *volunteer_list = NULL;

    printf("Operation Code: a for adding to the list, s for searching, p for printing the list; q for quit.\n");

    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') /* skips to end of line */
            ;

        switch (code) {
            case 'a':
                volunteer_list = add_to_list(volunteer_list);
                break;
            case 's':
                search_list(volunteer_list);
                break;
            case 'p':
                print_list(volunteer_list);
                break;
            case 'q':
                clear_list(volunteer_list);
                return 0;
            default:
                printf("Illegal code\n");
        }
        printf("\n");
    }
}

// Function to add a new volunteer to the list
struct volunteer *add_to_list(struct volunteer *list) {
    struct volunteer *current = list;
    struct volunteer *new_volunteer = malloc(sizeof(struct volunteer));
    
    if (new_volunteer == NULL) {
        printf("Memory allocation failed.\n");
        return list; // Return the original list without adding the new volunteer
    }

    printf("Enter last name: ");
    read_line(new_volunteer->last, NAME_LEN);
    printf("Enter first name: ");
    read_line(new_volunteer->first, NAME_LEN);
    printf("Enter email address: ");
    read_line(new_volunteer->email, EMAIL_LEN);
    printf("Enter grade level: ");
    scanf("%d", &new_volunteer->grade_level);

    while (current != NULL) {
        if (strcmp(current->email, new_volunteer->email) == 0 && strcmp(current->last, new_volunteer->last) == 0) {
            printf("volunteer already exists.\n");
            free(new_volunteer);
            return list;
        }
        current = current->next;
    }

    new_volunteer->next = NULL;

    if (list == NULL)
        return new_volunteer;

    current = list;
    while (current->next != NULL)
        current = current->next;

    current->next = new_volunteer;

    return list;
}

// Function to search volunteers by grade level
void search_list(struct volunteer *list) {
    int grade;
    printf("Enter grade level: ");
    scanf("%d", &grade);

    struct volunteer *current = list;
    int found = 0;

    while (current != NULL) {
        if (current->grade_level == grade) {
            printf("%-12s%-12s%-30s\n", current->last, current->first, current->email);
            found = 1;
        }
        current = current->next;
    }

    if (!found)
        printf("not found\n");
}

// Function to print the list of volunteers
void print_list(struct volunteer *list) {
    struct volunteer *current = list;

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
        free(temp);
    }
}

// Function to read a line of input
int read_line(char str[], int n) {
    int ch, i = 0;
    while (isspace(ch = getchar()))
        ;

    str[i++] = ch;

    while ((ch = getchar()) != '\n') {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}
