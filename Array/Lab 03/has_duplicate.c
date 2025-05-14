#include <stdio.h>

int main() {
    int n, duplicate = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                duplicate = 1;
                break;
            }
        }
        if (duplicate)
            break;
    }

    if (duplicate)
        printf("Array contains duplicate numbers.");
    else
        printf("Array does not contain any duplicates.");

    return 0;
}
