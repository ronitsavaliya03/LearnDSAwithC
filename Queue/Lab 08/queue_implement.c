#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1)
        printf("Queue Overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = val;
        printf("Inserted %d\n", val);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Underflow\n");
    else {
        printf("Deleted %d\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice, val;
    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
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
