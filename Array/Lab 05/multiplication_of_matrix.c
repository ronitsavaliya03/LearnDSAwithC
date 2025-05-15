#include <stdio.h>

int main() {
    int A[3][2], B[2][3], C[3][3];

    printf("Enter elements of 3x2 matrix A:\n");
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of 2x3 matrix B:\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 3; j++)
            scanf("%d", &B[i][j]);

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            C[i][j] = 0;

    // Matrix Multiplication: A[3][2] × B[2][3] = C[3][3]
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 2; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("Product of matrices:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
