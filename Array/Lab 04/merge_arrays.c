#include <stdio.h>

int main() {
    int a[100], b[100], c[200], n1, n2;

    printf("Enter number of elements in first array: ");
    scanf("%d", &n1);
    printf("Enter %d elements:\n", n1);
    for(int i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter number of elements in second array: ");
    scanf("%d", &n2);
    printf("Enter %d elements:\n", n2);
    for(int i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    for(int i = 0; i < n1; i++)
        c[i] = a[i];
    for(int i = 0; i < n2; i++)
        c[n1 + i] = b[i];

    printf("Merged array:\n");
    for(int i = 0; i < n1 + n2; i++)
        printf("%d ", c[i]);

    return 0;
}
