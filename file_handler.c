#include <stdio.h>
#include <stdlib.h>
#include "file_handler.h"

// Function to read student data from the file and build the database
int readStudentFromFile(const char* filename, School* school) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 0; // Error opening file
    }

    char line[200];
    while (fgets(line, sizeof(line), file) != NULL) {
        char firstName[MAX_NAME_LENGTH];
        char lastName[MAX_NAME_LENGTH];
        char phoneNumber[MAX_PHONE_LENGTH];
        int numLevel, numClass;
        int grades[NUM_GRADES];

        if (sscanf(line, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            firstName, lastName, phoneNumber, &numLevel, &numClass,
            &grades[0], &grades[1], &grades[2], &grades[3], &grades[4],
            &grades[5], &grades[6], &grades[7], &grades[8], &grades[9])) {
            // Create the student object
            Student* student = createStudent(firstName, lastName, phoneNumber, grades);
            if (student == NULL) {
                fclose(file);
                return 0; // Memory allocation error
            }

            // Find or create the level and class
            Level* level = school->levels[numLevel - 1];
            if (level == NULL) {
                level = (Level*)malloc(sizeof(Level));
                if (level == NULL) {
                    fclose(file);
                    return 0; // Memory allocation error
                }
                level->numClasses = 0;
                addLevelToSchool(school, level);
            }

            Class* class = level->classes[numClass - 1];
            if (class == NULL) {
                class = (Class*)malloc(sizeof(Class));
                if (class == NULL) {
                    fclose(file);
                    return 0; // Memory allocation error
                }
                class->numStudents = 0;
                addClassToLevel(level, class);
            }

            // Add the student to the class
            if (!addStudentToClass(class, student)) {
                // Handle class full error
            }
        }
        else {
            // Invalid line format, skip to the next line
        }
    }

    fclose(file);
    return 1; // Data loaded successfully
}

// Rest of the functions in file_handler.c

