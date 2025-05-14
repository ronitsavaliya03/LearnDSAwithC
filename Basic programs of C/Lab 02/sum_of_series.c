#include <stdio.h>

int main() {
    int n, totalSum = 0;

    printf("Enter value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        totalSum += (i * (i + 1)) / 2; 
    }

    printf("Total sum = %d\n", totalSum);

    return 0;
}
