#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_structures.h"

// Function to initialize the school
void initializeSchool(School* school) {
    school->numLevels = 0;
}

// Function to create a new student
Student* createStudent(const char* firstName, const char* lastName, const char* phoneNumber, const int grades[]) {
    Student* student = (Student*)malloc(sizeof(Student));
    if (student != NULL) {
        strncpy(student->firstName, firstName, MAX_NAME_LENGTH - 1);
        strncpy(student->lastName, lastName, MAX_NAME_LENGTH - 1);
        strncpy(student->phoneNumber, phoneNumber, MAX_PHONE_LENGTH - 1);
        for (int i = 0; i < NUM_GRADES; i++) {
            student->grades[i] = grades[i];
        }
    }
    return student;
}

// Function to add a student to a class
int addStudentToClass(Class* class, Student* student) {
    if (class->numStudents < MAX_CLASS_SIZE) {
        class->students[class->numStudents] = student;
        class->numStudents++;
        return 1; // Success
    }
    else {
        return 0; // Class is full
    }
}

// Function to add a class to a level
void addClassToLevel(Level* level, Class* class) {
    if (level->numClasses < MAX_NUM_CLASSES) {
        level->classes[level->numClasses] = class;
        level->numClasses++;
    }
}

// Function to add a level to the school
void addLevelToSchool(School* school, Level* level) {
    if (school->numLevels < MAX_NUM_LEVELS) {
        school->levels[school->numLevels] = level;
        school->numLevels++;
    }
}


