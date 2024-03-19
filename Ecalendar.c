#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION_LENGTH 100

// Structure for each day of the week
struct Day {
    char *name;
    int date;
    char *activity;
};

// Function prototypes
void create(struct Day *calendar);
void read(struct Day *calendar);
void display(struct Day *calendar);

int main() {
    struct Day calendar[7]; // Array to store the week's calendar

    // Create the calendar
    create(calendar);

    // Read data for each day
    read(calendar);

    // Display the week's activity details report
    display(calendar);

    // Free dynamically allocated memory
    for (int i = 0; i < 7; i++) {
        free(calendar[i].name);
        free(calendar[i].activity);
    }

    return 0;
}

// Function to create the calendar
void create(struct Day *calendar) {
    for (int i = 0; i < 7; i++) {
        calendar[i].name = (char *)malloc(sizeof(char) * 20); // Allocate memory for the day's name
        calendar[i].activity = (char *)malloc(sizeof(char) * MAX_DESCRIPTION_LENGTH); // Allocate memory for the activity description
    }
}

// Function to read data for each day from the keyboard
void read(struct Day *calendar) {
    for (int i = 0; i < 7; i++) {
        printf("\nEnter the Week Name %d:\n ", i + 1);
        scanf("%s", calendar[i].name);

		printf("\nEnter the Week description %d:\n ", i + 1);
        scanf(" %s", calendar[i].activity);

        printf("\nEnter the Week day %d:\n ", i + 1);
        scanf("%d", &calendar[i].date);

        
    }
}

void display(struct Day *calendar) {
    
  printf("\n Week Name\t\t Day  \t Discription\n"); 
    for (int i = 0; i < 7; i++) {
        printf("\n %s\t\t %d  \t%s", calendar[i].name, calendar[i].date, calendar[i].activity);
    }
}
// Function to display the week's activity details report on the screen

