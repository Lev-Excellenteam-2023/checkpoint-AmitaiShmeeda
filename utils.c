#include <stdio.h>
#include "utils.h"

// Function to get integer input with validation
int getIntegerInput(const char* prompt, int min, int max) {
    int value;
    while (1) {
        printf("%s (%d-%d): ", prompt, min, max);
        int numRead = scanf("%d", &value);
        clearInputBuffer();

        if (numRead == 1 && value >= min && value <= max) {
            return value;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

// Function to get float input with validation
float getFloatInput(const char* prompt, float min, float max) {
    float value;
    while (1) {
        printf("%s (%.2f-%.2f): ", prompt, min, max);
        int numRead = scanf("%f", &value);
        clearInputBuffer();

        if (numRead == 1 && value >= min && value <= max) {
            return value;
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

// Function to clear input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}



