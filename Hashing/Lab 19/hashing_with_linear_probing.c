#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main() {
    int array[15];
    int hashTable[SIZE];
    int i, x;

    for(i = 0; i < SIZE; i++) {
        hashTable[i] = 0;
    }

    srand(time(0));
    for(i = 0; i < 15; i++) {
        array[i] = (rand() % 900000) + 100000;
    }

    printf("Question Array:\n");
    for(i = 0; i < 15; i++) {
        printf("%d ", array[i]);
    }

    printf("\n\nIndexes Array:\n");
    for(i = 0; i < 15; i++) {
        x = (array[i] % 18) + 2;
        printf("%d ", x);

        while(hashTable[x] != 0) {
            x = (x + 1) % SIZE;
        }
        hashTable[x] = array[i];
    }

    printf("\n\nHash Table:\n");
    for(i = 0; i < SIZE; i++) {
        printf("%d ", hashTable[i]);
    }

    return 0;
}