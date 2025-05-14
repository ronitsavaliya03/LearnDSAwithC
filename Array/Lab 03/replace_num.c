#include <stdio.h>

int main() {
    int n, i, oldNum, newNum;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the number to replace (old number): ");
    scanf("%d", &oldNum);
    printf("Enter the new number: ");
    scanf("%d", &newNum);

    printf("Replaced indices:\n");
    for (i = 0; i < n; i++) {
        if (arr[i] == oldNum) {
            arr[i] = newNum;
            printf("Index: %d\n", i);
        }
    }

    printf("Final array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
