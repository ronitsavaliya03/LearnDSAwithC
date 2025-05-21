#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push() {
    int val;
    if (top == SIZE - 1)
        printf("Stack Overflow!\n");
    else {
        printf("Enter value to push: ");
        scanf("%d", &val);
        stack[++top] = val;
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1)
        printf("Stack is empty.\n");
    else {
        printf("Stack elements: \n\n");
        for (int i = top; i >= 0; i--)
            printf("|  %2d  |\n", stack[i]);
        printf("|______|\n");
    }
}

// PEEP - show element at a specific position from top
void peep() {
    int pos;
    printf("Enter position from top (1 for top element): ");
    scanf("%d", &pos);
    if (pos > top + 1 || pos <= 0)
        printf("Invalid position!\n");
    else
        printf("Element at position %d: %d\n", pos, stack[top - pos + 1]);
}

void change() {
    int pos, val;
    printf("Enter position from top: ");
    scanf("%d", &pos);
    if (pos > top + 1 || pos <= 0)
        printf("Invalid position!\n");
    else {
        printf("Enter new value: ");
        scanf("%d", &val);
        stack[top - pos + 1] = val;
        printf("Value changed successfully.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. PUSH\n2. POP\n3. DISPLAY\n4. PEEP\n5. CHANGE\n6. EXIT\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: peep(); break;
            case 5: change(); break;
            case 6: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
