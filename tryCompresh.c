#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for each data element
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 12

// Define the structure for a student
typedef struct {
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_LENGTH];
    int level;
    int class;
    int grades[10];
} Student;

// Define the structure for a node in the linked list
typedef struct Node {
    Student student;
    struct Node* next;
} Node;

// Function to create a new node for the linked list
Node* createNode(Student data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->student = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, Student data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        return;
    }

    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to free the allocated memory of the linked list
void freeLinkedList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    FILE* file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error opening the file!\n");
        return 1;
    }

    Node* levels[12] = { NULL }; // Array of pointers to linked lists for each level

    // Read data from the file line by line
    char line[512];
    while (fgets(line, sizeof(line), file) != NULL) {
        Student student;
        sscanf(line, "%s %s %s %d %d %d %d %d %d %d %d %d %d",
            student.first_name, student.last_name, student.phone_number,
            &student.level, &student.class,
            &student.grades[0], &student.grades[1], &student.grades[2],
            &student.grades[3], &student.grades[4], &student.grades[5],
            &student.grades[6], &student.grades[7], &student.grades[8],
            &student.grades[9]);

        // Insert the student into the appropriate level's linked list
        insertAtEnd(&levels[student.level - 1], student);
    }

    fclose(file);

    // Display the list of students for each level
    for (int i = 0; i < 12; i++) {
        printf("Level %d:\n", i + 1);
        Node* current = levels[i];
        while (current != NULL) {
            Student student = current->student;
            printf("%s %s %s Level: %d Class: %d Grades: ",
                student.first_name, student.last_name, student.phone_number,
                student.level, student.class);
            for (int j = 0; j < 10; j++) {
                printf("%d ", student.grades[j]);
            }
            printf("\n");
            current = current->next;
        }
        printf("\n");

        // Free the allocated memory for the linked list of each level
        freeLinkedList(levels[i]);
    }

    

    return 0;
}
