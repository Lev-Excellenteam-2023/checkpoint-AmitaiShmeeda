#ifndef UTILS_H
#define UTILS_H

// Function prototypes for utils.c
int getIntegerInput(const char* prompt, int min, int max);
float getFloatInput(const char* prompt, float min, float max);
void clearInputBuffer();

#endif  /* UTILS_H */
