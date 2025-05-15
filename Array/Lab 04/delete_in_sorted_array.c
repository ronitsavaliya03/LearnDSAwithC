#include <stdio.h>

int main() {
    int arr[100], n, num, found = 0, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements (ascending order):\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to delete: ");
    scanf("%d", &num);

    for(i = 0; i < n; i++) {
        if(arr[i] == num) {
            found = 1;
            break;
        }
    }

    if(found) {
        for(int j = i; j < n - 1; j++)
            arr[j] = arr[j + 1];
        n--;
    } else {
        printf("Number not found.\n");
    }

    printf("Array after deletion:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
