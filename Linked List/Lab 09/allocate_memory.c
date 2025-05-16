#include <stdio.h>
#include <stdlib.h> 

int main() {
    int *pInt;
    char *pChar;
    float *pFloat;

    // Allocate memory
    pInt = (int *)malloc(sizeof(int));
    pChar = (char *)malloc(sizeof(char));
    pFloat = (float *)malloc(sizeof(float));

    // Check if memory allocation was successful
    if (pInt == NULL || pChar == NULL || pFloat == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign values
    *pInt = 25;
    *pChar = 'A';
    *pFloat = 3.14;

    printf("Integer value: %d\n", *pInt);
    printf("Character value: %c\n", *pChar);
    printf("Float value: %.2f\n", *pFloat);

    // De-allocate memory
    free(pInt);
    free(pChar);
    free(pFloat);

    printf("Memory has been deallocated.\n");

    return 0;
}
