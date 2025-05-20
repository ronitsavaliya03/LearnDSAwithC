#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

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

void insertGCDNodes(struct Node* first) {
    while (first != NULL && first->link != NULL) {
        int g = gcd(first->info, first->link->info);
        struct Node* newNode = malloc(sizeof(struct Node));
        newNode->info = g;
        newNode->link = first->link;
        first->link = newNode;
        first = newNode->link;
    }
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
    insertAtEnd(&first, 12);
    insertAtEnd(&first, 15);
    insertAtEnd(&first, 21);
    insertAtEnd(&first, 30);
    insertGCDNodes(first);
    printList(first);
    return 0;
}
