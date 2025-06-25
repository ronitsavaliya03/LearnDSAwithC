#include <stdio.h>
#include <stdlib.h>

// Node structure with int info
struct Node {
    int info;
    struct Node *link;
};

// Global head pointer
struct Node *first = NULL;

// Insert at end
void insertNode() {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data (int): ");
    scanf("%d", &newNode->info);
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
    } else {
        struct Node *temp = first;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = newNode;
    }
}

// Copy the linked list (same as your algorithm)
struct Node* copyList() {
    struct Node *SAVE, *NEW, *PRED, *BEGIN;

    if (first == NULL) {
        return NULL;
    }

    // Copy first node
    NEW = (struct Node*)malloc(sizeof(struct Node));
    if (NEW == NULL) {
        printf("Underflow\n");
        return NULL;
    }
    NEW->info = first->info;
    BEGIN = NEW;

    // Start traversal
    SAVE = first;

    while (SAVE->link != NULL) {
        PRED = NEW;
        SAVE = SAVE->link;

        NEW = (struct Node*)malloc(sizeof(struct Node));
        if (NEW == NULL) {
            printf("Underflow\n");
            return NULL;
        }
        NEW->info = SAVE->info;
        PRED->link = NEW;
    }

    // End the new list
    NEW->link = NULL;
    return BEGIN;
}

// Display a linked list
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (head != NULL) {
        printf("[%d] -> ", head->info);
        head = head->link;
    }
    printf("NULL\n");
}

// Main Menu
int main() {
    int choice;
    struct Node *copiedList = NULL;

    do {
        printf("\n==== Menu ====\n");
        printf("1. Insert Node\n");
        printf("2. Copy List\n");
        printf("3. Display Lists\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertNode(); break;
            case 2: copiedList = copyList(); break;
            case 3:
                printf("\nOriginal List:\n");
                displayList(first);
                printf("Copied List:\n");
                displayList(copiedList);
                break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
