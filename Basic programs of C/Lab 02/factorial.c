#include <stdio.h>

// Recursive function
long long factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorialRecursive(n - 1);
}

// Iterative (loop-based) function
long long factorialLoop(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial using loop: %lld\n", factorialLoop(number));
        printf("Factorial using recursion: %lld\n", factorialRecursive(number));
    }

    return 0;
}
