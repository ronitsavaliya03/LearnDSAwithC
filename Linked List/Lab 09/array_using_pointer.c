#include <stdio.h>

int main() {
    int arr[100], n, i;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = arr;  // ptr points to the first element of the array

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }

    printf("Array elements are:\n");
    for(i = 0; i < n; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    return 0;
}
