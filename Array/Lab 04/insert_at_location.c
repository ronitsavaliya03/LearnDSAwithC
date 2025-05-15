#include <stdio.h>

int main() {
    int arr[100], n, pos, num;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the number to insert: ");
    scanf("%d", &num);
    printf("Enter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    for(int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = num;
    n++;

    printf("Array after insertion:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
