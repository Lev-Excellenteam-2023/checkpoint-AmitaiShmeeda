#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"
#include "file_handler.h"
#include "utils.h"

int main() {
    // Create the school database
    School school;
    initializeSchool(&school);

    // Read student data from the file and build the database
    if (readStudentFromFile("students.txt", &school)) {
        printf("Student data loaded successfully.\n");
    }
    else {
        printf("Error loading student data.\n");
    }

    int choice;
    do {
        printf("\nSchool Management System\n");
        printf("1. Add Student\n");
        printf("2. Search Student\n");
        printf("3. Delete Student\n");
        printf("4. Display All Students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin); // Clear input buffer

        switch (choice) {
        case 1:
            addStudent(&school);
            break;
        case 2:
            searchStudent(&school);
            break;
        case 3:
            deleteStudent(&school);
            break;
        case 4:
            displayAllStudents(&school);
            break;
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
