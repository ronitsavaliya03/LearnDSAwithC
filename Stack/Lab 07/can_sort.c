#include <stdio.h>

#define MAX 1000

int stk[MAX];
int top = -1;

void push(int x) {
    stk[++top] = x;
}

int pop() {
    return stk[top--];
}

int peek() {
    return stk[top];
}

int isEmpty() {
    return top == -1;
}

int canSort(int arr[], int n) {
    int b[MAX];        // Array to store final output (virtually)
    int ind = 0;       // Index in b
    int i = 0;
    int last = 0;  // Minimum possible (assuming input values within int range)

    while (i < n) {
        // Find the minimum element from i to n-1
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Push all elements before min into stack
        while (i < min) {
            push(arr[i]);
            i++;
        }

        // Add min directly to result (array B)
        int current = arr[i];
        // if (current < last) return 0; // Not increasing
        last = current;
        b[ind++] = current;
        i++;

        // Pop stack elements if they are in order
        while (!isEmpty() && peek() >= last) {
            int val = pop();
            // if (val < last) return 0;
            last = val;
            b[ind++] = val;
        }
    }

    return isEmpty(); // Should be empty if all were moved in order
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int arr[MAX];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        if (canSort(arr, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
