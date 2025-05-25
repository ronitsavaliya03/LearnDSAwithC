#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;       
    int left = 2 * i + 1;   
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) 
        largest = left;

    if (right < n && arr[right] > arr[largest]) 
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest); 
    }
}

void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
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
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);
    display(arr, n);
    return 0;
}
