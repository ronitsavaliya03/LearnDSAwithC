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

struct Node* swapConsecutive(struct Node* first) {
    if (!first || !first->link) return first;

    struct Node* newFirst = first->link;
    struct Node* prev = NULL;
    struct Node* curr = first;

    while (curr && curr->link) {
        struct Node* linkPair = curr->link->link;
        struct Node* second = curr->link;
        second->link = curr;
        curr->link = linkPair;

        if (prev){
            prev->link = second;
        }

        prev = curr;
        curr = linkPair;
    }

    return newFirst;
}

void printList(struct Node* first) {
    while (first) {
        printf("%d -> ", first->info);
        first = first->link;
    }
    printf("NULL\n");
}

int main() {
    struct Node* first = NULL;
    for (int i = 1; i <= 8; i++) insertAtEnd(&first, i);

    printList(first);

    first = swapConsecutive(first);
    printList(first);
    
    return 0;
}
