#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

void insertAtEnd(struct Node** first, int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->info = val;
    newNode->link = NULL;
    if (*first == NULL) {
        *first = newNode;
        return;
    }
    struct Node* temp = *first;
    while (temp->link != NULL) temp = temp->link;
    temp->link = newNode;
}

void removeDuplicates(struct Node* first) {
    struct Node* current = first;
    while (current && current->link) {
        if (current->info == current->link->info) {
            struct Node* temp = current->link;
            current->link = current->link->link;
            free(temp);
        } else {
            current = current->link;
        }
    }
}

void printList(struct Node* first) {
    while (first) {
        printf("%d ", first->info);
        first = first->link;
    }
    printf("\n");
}

int main() {
    struct Node* first = NULL;
    int values[] = {1, 1, 6, 13, 13, 13, 27, 27};
    for (int i = 0; i < 8; i++) insertAtEnd(&first, values[i]);
    removeDuplicates(first);
    printList(first);
    return 0;
}
