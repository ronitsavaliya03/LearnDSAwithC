#include <stdio.h>

int longestSubarrayWithSumK(int arr[], int n, int k) {
    int start = 0, end = 0;       
    int sum = 0;                   
    int maxLen = 0;                

    while (end < n) {
        sum += arr[end];  

        while (sum > k && start <= end) {
            sum -= arr[start];  
            start++;            
        }

        int windowLength = end - start + 1;
        if (sum <= k && windowLength > maxLen) {
            maxLen = windowLength;
        }

        end++;  
    }
 
    return maxLen;
}

int main() {
    int arr[] = {1, 2, 1, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int result = longestSubarrayWithSumK(arr, n, k);
    printf("Length of longest subarray with sum <= %d is: %d\n", k, result);

    return 0;
}
