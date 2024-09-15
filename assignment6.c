/*
 * Bank Account Management Program
 *
 * This program allows users to manage bank accounts by performing operations such as
 * creating an account, depositing money, withdrawing money, and sorting accounts
 * based on various criteria. The program ensures input validation for account numbers,
 * account types, and date formats.
 *
 * Name: Hasin Shadab Rahman
 * NETID: hasinrahman
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 10  // Maximum number of accounts
#define NAME_LEN 30      // Maximum length for holder's name
#define DATE_LEN 11      // Length for date string (YYYY-MM-DD)

// Structure to store account information
typedef struct {
    int account_number;        // Account number (4 digits)
    char account_type;         // Account type (c for checking, s for savings)
    char holder_name[NAME_LEN]; // Holder's name
    char open_date[DATE_LEN];   // Date account was opened
    float balance;              // Current balance
} Account;

Account accounts[MAX_ACCOUNTS];  // Array to store account information
int num_accounts = 0;  // Counter for the number of accounts created

// Function prototypes
void create_account();
void deposit_money();
void withdraw_money();
void sort_and_print_accounts();
int compare_account_numbers(const void *a, const void *b);
int compare_holder_names(const void *a, const void *b);
int compare_open_dates(const void *a, const void *b);
int compare_balances(const void *a, const void *b);
int is_valid_date(const char *date);

int main() {
    char operation[2];  // Variable to hold user operation input

    // Main loop to handle user operations
    while (1) {
        // Display the main menu
        printf("******* Main menu *******\n");
        printf("c(reate an account)\n");
        printf("d(eposit money)\n");
        printf("w(ithdraw money)\n");
        printf("s(sort and print accounts)\n");
        printf("q(uit program)\n");
        printf("*************************\n");
        printf("Enter operation code (c, d, w, s, q): ");
        scanf("%1s", operation);

        // Convert operation to lowercase
        operation[0] = tolower(operation[0]);


        // Handle the user operation based on input
        if (strcmp(operation, "c") == 0) {
            create_account();
        } else if (strcmp(operation, "d") == 0) {
            deposit_money();
        } else if (strcmp(operation, "w") == 0) {
            withdraw_money();
        } else if (strcmp(operation, "s") == 0) {
            sort_and_print_accounts();
        } else if (strcmp(operation, "q") == 0) {
            break;  // Exit the loop and end the program
        } else {
            printf("Invalid operation code. Please try again.\n");
        }
    }

    return 0;  // End of program
}

// Function to create a new account
void create_account() {
    // Check if the maximum number of accounts is reached
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;  // Exit if maximum accounts reached
    }

    Account new_account;  // Structure to hold the new account information

    // Get account number from user
    printf("Enter account number (4 digits): ");
    while (scanf("%d", &new_account.account_number) != 1 || new_account.account_number < 1000 || new_account.account_number > 9999) {
        printf("Enter a number between 1000 and 9999.\n");
        printf("Enter account number (4 digits): ");
        
    }

    // Check for duplicate account number
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == new_account.account_number) {
            printf("Account number already used. Please enter a different account number.\n");
            return;  // Exit if account number is a duplicate
        }
    }

    // Get account type from user
    printf("Enter account type: c(hecking), s(avings)\nc or s: ");
    while (scanf(" %c", &new_account.account_type) != 1 || (new_account.account_type != 'c' && new_account.account_type != 's')||(new_account.account_type != 'C' && new_account.account_type != 'S')) {
        printf("Wrong account type. Enter c or s.\n");
        printf("Enter account type: c(hecking), s(avings)\nc or s: ");
        
    }

    // Get account holder's name from user
    printf("Enter account holder's name: ");
    
    fgets(new_account.holder_name, NAME_LEN, stdin);
    new_account.holder_name[strcspn(new_account.holder_name, "\n")] = '\0'; // Remove newline character

    // Get account open date from user
    printf("Enter open date (YYYY-MM-DD): ");
    while (scanf("%10s", new_account.open_date) != 1 || !is_valid_date(new_account.open_date)) {
        printf("Wrong date format.\n Enter open date (YYYY-MM-DD): ");
       
    }

    // Get account balance from user
    printf("Enter balance (number only): $ ");
    while (scanf("%f", &new_account.balance) != 1) {
        printf("Enter a valid number.\n");
        printf("Enter balance (number only): $ ");
        
    }

    // Store the new account and increment the account count
    accounts[num_accounts++] = new_account;
    printf("Account %d is created.\n", new_account.account_number);
}

// Function to deposit money into an account
void deposit_money() {
    int account_number;  // Variable to hold account number
    float amount;        // Variable to hold deposit amount

    // Get account number from user
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Find the account and deposit the money
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount (> 0, number only): $ ");
            while (scanf("%f", &amount) != 1 || amount <= 0) {
                printf("Amount must be greater than 0.\n");
                printf("Enter amount (> 0, number only): $ ");
                
            }

            // Update the balance with the deposited amount
            accounts[i].balance += amount;
            printf("Remaining balance: $%-15.2f\n", accounts[i].balance);
            return;  // Exit after successful deposit
        }
    }

    // If account is not found
    printf("Account not found.\n");
}

// Function to withdraw money from an account
void withdraw_money() {
    int account_number;  // Variable to hold account number
    float amount;        // Variable to hold withdrawal amount

    // Get account number from user
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Find the account and withdraw the money
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter amount (> 0, number only): $ ");
            while (scanf("%f", &amount) != 1 || amount <= 0) {
                printf("Amount must be greater than 0.\n");
                printf("Enter amount (> 0, number only): $ ");
                 // Clear input buffer
            }

            // Check for sufficient balance
            if (accounts[i].balance < amount) {
                printf("Insufficient balance.\n");
                return;  // Exit if balance is insufficient
            }

            // Update the balance after withdrawal
            accounts[i].balance -= amount;
            printf("Remaining balance: $%-15.2f\n", accounts[i].balance);
            return;  // Exit after successful withdrawal
        }
    }

    // If account is not found
    printf("Account not found.\n");
}

// Function to sort and print accounts based on a specified field
void sort_and_print_accounts() {
    char field[2];  // Variable to hold sorting field input

    // Get the sorting field from user
    printf("Enter the sorting field: a(ccount number), h(older name), o(pen date), b(alance)\na, h, o or b: ");
    scanf("%1s", field);

    // Sort the accounts based on the chosen field
    if (strcmp(field, "a") == 0) {
        qsort(accounts, num_accounts, sizeof(Account), compare_account_numbers);
    } else if (strcmp(field, "h") == 0) {
        qsort(accounts, num_accounts, sizeof(Account), compare_holder_names);
    } else if (strcmp(field, "o") == 0) {
        qsort(accounts, num_accounts, sizeof(Account), compare_open_dates);
    } else if (strcmp(field, "b") == 0) {
        qsort(accounts, num_accounts, sizeof(Account), compare_balances);
    } else {
        printf("Invalid sorting field.\n");
        return;  // Exit if invalid field is chosen
    }

    // Print the sorted accounts
    printf("#### Type Holder name                     Open date  Balance\n");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%-4d %-4c %-30s %-10s %15.2f\n",
            accounts[i].account_number,
            accounts[i].account_type,
            accounts[i].holder_name,
            accounts[i].open_date,
            accounts[i].balance);
    }
}

// Function to compare account numbers for sorting
int compare_account_numbers(const void *a, const void *b) {
    return ((Account *)a)->account_number - ((Account *)b)->account_number;  // Compare account numbers
}

// Function to compare holder names for sorting
int compare_holder_names(const void *a, const void *b) {
    return strcmp(((Account *)a)->holder_name, ((Account *)b)->holder_name);  // Compare names alphabetically
}

// Function to compare open dates for sorting
int compare_open_dates(const void *a, const void *b) {
    return strcmp(((Account *)a)->open_date, ((Account *)b)->open_date);  // Compare dates lexicographically
}

// Function to compare balances for sorting
int compare_balances(const void *a, const void *b) {
    float balance_a = ((Account *)a)->balance;  // Get balance of first account
    float balance_b = ((Account *)b)->balance;  // Get balance of second account
    return (balance_a > balance_b) - (balance_a < balance_b);  // Compare balances
}

// Function to validate date in YYYY-MM-DD format
int is_valid_date(const char *date) {
    if (strlen(date) != 10) return 0;  // Date length must be 10

    if (date[4] != '-' || date[7] != '-') return 0;  // Hyphen positions must be correct

    int year, month, day;
    if (sscanf(date, "%4d-%2d-%2d", &year, &month, &day) != 3) return 0;  // Check if date components are valid

    if (year < 1900 || year > 2100) return 0;  // Year range
    if (month < 1 || month > 12) return 0;  // Month range
    if (day < 1 || day > 31) return 0;  // Day range

    // Check for days in each month
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return 0;  // April, June, September, November have 30 days
    if (month == 2) {
        int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);  // Leap year check
        if (day > (leap ? 29 : 28)) return 0;  // February has 29 days in leap years and 28 otherwise
    }

    return 1;  // Date is valid
}
