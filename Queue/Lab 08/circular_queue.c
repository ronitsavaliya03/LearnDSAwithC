#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void insert(int val) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front)
        printf("Queue Overflow\n");
    else {
        if (front == -1)  // First element
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;
        cq[rear] = val;
        printf("Inserted %d\n", val);
    }
}

void delete() {
    if (front == -1)
        printf("Queue Underflow\n");
    else {
        printf("Deleted %d\n", cq[front]);
        if (front == rear)  // Only one element
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1)
        printf("Queue is empty\n");
    else {
        printf("Circular Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", cq[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}