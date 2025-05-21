#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* prev;
    struct Node* next;
};

struct Node* first = NULL;

void insertAtFront(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->prev = NULL;
    newNode->next = first;

    if (first != NULL)
        first->prev = newNode;

    first = newNode;

    printf("Node inserted at front.\n");
}

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = NULL;

    if (first == NULL) {
        newNode->prev = NULL;
        first = newNode;
        printf("Node inserted at end.\n");
        return;
    }

    struct Node* temp = first;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at end.\n");
}

void deleteAtPosition(int pos) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = first;
    int i;

    if (pos == 1) {
        first = temp->next;
        if (first != NULL)
            first->prev = NULL;
        free(temp);
        printf("Node at position 1 deleted.\n");
        return;
    }

    // Move to (pos-1)th node
    for (i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node at position %d deleted.\n", pos);
}

void display() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = first;
    printf("Doubly Linked List: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 74th Problem: Delete alternate nodes
void deleteAlternateNodes() {
    if (first == NULL || first->next == NULL)
        return;

    struct Node* temp = first->next;
    struct Node* prev = first;

    while (temp != NULL) {
        prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = prev;

        free(temp);
        prev = prev->next;

        if (prev != NULL)
            temp = prev->next;
        else
            break;
    }

    printf("Alternate nodes deleted.\n");
}

int main() {
    int choice, value, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Delete at Position\n");
        printf("4. Display List\n");
        printf("5. Delete Alternate Nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert at front: ");
            scanf("%d", &value);
            insertAtFront(value);
            break;

        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;

        case 3:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;

        case 4:
            display();
            break;

        case 5:
            deleteAlternateNodes();
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
