#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = arr;

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", ptr + i);
    }

    // Bubble sort using pointer
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(*(ptr + j) > *(ptr + j + 1)) {
                temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }

    printf("Sorted Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }
    return 0;
}
