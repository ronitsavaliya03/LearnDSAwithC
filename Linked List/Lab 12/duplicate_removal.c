#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};
struct Node* first = NULL;

void insert(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->link = NULL;
    if (first == NULL)
        first = newNode;
    else {
        struct Node* temp = first;
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = newNode;
    }
}

void removeDuplicates() {
    struct Node *ptr1 = first, *ptr2, *dup;
    while (ptr1 != NULL && ptr1->link != NULL) {
        ptr2 = ptr1;
        while (ptr2->link != NULL) {
            if (ptr1->info == ptr2->link->info) {
                dup = ptr2->link;
                ptr2->link = ptr2->link->link;
                free(dup);
            } else {
                ptr2 = ptr2->link;
            }
        }
        ptr1 = ptr1->link;
    }
    printf("Duplicates removed.\n");
}

void display() {
    struct Node* temp = first;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("\nList Menu:\n1.Insert\n2.Display\n3.Remove Duplicates\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display();
                break;
            case 3:
                removeDuplicates();
                break;
            case 4:
                printf("Exiting Duplicate Removal Program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
