#include <stdio.h>

void countingSort(int arr[], int n) {
    int output[100], count[1000] = {0};
    int max = arr[0];

    // Find maximum value
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    // Count occurrences
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Cumulative count
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void display(int arr[], int n) {
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements (non-negative integers only): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);
    display(arr, n);
    return 0;
}
