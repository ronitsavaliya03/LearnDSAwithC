#include <stdio.h>

int main() {
    int n, smallest, largest, small_pos = 0, large_pos = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    smallest = largest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            small_pos = i;
        }
        if (arr[i] > largest) {
            largest = arr[i];
            large_pos = i;
        }
    }

    printf("Smallest number is %d at position %d\n", smallest, small_pos + 1);
    printf("Largest number is %d at position %d\n", largest, large_pos + 1);

    return 0;
}
