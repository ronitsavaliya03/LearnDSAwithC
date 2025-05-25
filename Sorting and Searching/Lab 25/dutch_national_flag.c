#include <stdio.h>

void sortColors(int nums[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                // Swap nums[low] and nums[mid]
                {
                    int temp = nums[low];
                    nums[low] = nums[mid];
                    nums[mid] = temp;
                }
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                // Swap nums[mid] and nums[high]
                {
                    int temp = nums[mid];
                    nums[mid] = nums[high];
                    nums[high] = temp;
                }
                high--;
                break;
        }
    }
}

void display(int arr[], int n) {
    printf("Sorted colors: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int nums[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements (0 for Red, 1 for White, 2 for Blue): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    sortColors(nums, n);
    display(nums, n);
    return 0;
}
