#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int rows;

    printf("Enter number of rows for Pascal Triangle: ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++) {
        // Print spaces
        for (int space = 1; space <= rows - i; space++)
            printf("  ");

        for (int j = 0; j <= i; j++)
            printf("%4d", combination(i, j));

        printf("\n");
    }

    return 0;
}
