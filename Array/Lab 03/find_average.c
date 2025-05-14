#include <stdio.h>

int main() {
    int n, sum = 0;
    float avg;

    printf("Enter value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        sum += i;

    avg = (float)sum / n;

    printf("Average of first %d numbers = %.2f\n", n, avg);
    return 0;
}
