#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define NUM_GRADES 10
#define MAX_CLASS_SIZE 1000
#define MAX_NUM_CLASSES 10
#define MAX_NUM_LEVELS 12

typedef struct {
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_LENGTH];
    int grades[NUM_GRADES];
} Student;

typedef struct {
    Student* students[MAX_CLASS_SIZE];
    int numStudents;
} Class;

typedef struct {
    Class* classes[MAX_NUM_CLASSES];
    int numClasses;
} Level;

typedef struct {
    Level* levels[MAX_NUM_LEVELS];
    int numLevels;
} School;

// Function prototypes for data_structures.c
void initializeSchool(School* school);
int addStudent(School* school);
void searchStudent(const School* school);
void deleteStudent(School* school);
void displayAllStudents(const School* school);

#endif  /* DATA_STRUCTURES_H */
