#include <stdio.h>

int main() {
    int A[2][2], B[2][2], C[2][2];

    printf("Enter elements of first 2x2 matrix:\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second 2x2 matrix:\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            C[i][j] = A[i][j] + B[i][j];

    printf("Sum of two matrices:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
