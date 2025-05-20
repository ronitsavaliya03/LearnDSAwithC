#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

// NOTE:
// If we use first (head pointer):
// To insert at end: we must traverse the whole list to find the last node every time.

// More steps required for end insertions or circular handling.

struct Node* last = NULL;

void insertAtFront(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->info = val;
    if (last == NULL) {
        newNode->link = newNode;
        last = newNode;
    } else {
        newNode->link = last->link;
        last->link = newNode;
    }
}

void insertAtEnd(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->info = val;
    if (last == NULL) {
        newNode->link = newNode;
        last = newNode;
    } else {
        newNode->link = last->link;
        last->link = newNode;
        last = newNode;
    }
}

void deleteFromPosition(int pos) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = last->link;
    if (pos == 1) {
        if (last == last->link) {
            free(last);
            last = NULL;
        } else {
            last->link = temp->link;
            free(temp);
        }
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->link;
        if (temp == last->link) {
            printf("Position out of range.\n");
            return;
        }
    }

    prev->link = temp->link;
    if (temp == last) last = prev;
    free(temp);
}

void display() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->link;
    do {
        printf("%d -> ", temp->info);
        temp = temp->link;
    } while (temp != last->link);
    printf("(First Node)%d\n", last->link->info);
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\n1.Insert at front\n2.Insert at end\n3.Delete from position\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
