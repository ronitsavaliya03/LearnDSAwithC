#include <stdio.h>
#define SIZE 100

int deque[SIZE];
int front = -1, rear = -1;

void insertFront(int val) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) { 
        front = rear = 0;
    } else if (front == 0) {
        front = SIZE - 1;
    } else {
        front--;
    }

    deque[front] = val;
    printf("Inserted %d at front\n", val);
}

void insertRear(int val) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1) {  
        front = rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = val;
    printf("Inserted %d at rear\n", val);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted %d from front\n", deque[front]);

    if (front == rear) { 
        front = rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted %d from rear\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1.Insert Front  2.Insert Rear  3.Delete Front  4.Delete Rear  5.Display  6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
