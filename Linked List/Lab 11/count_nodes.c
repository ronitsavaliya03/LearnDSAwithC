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
    if (first == NULL) {
        first = newNode;
        newNode->link = first;  // circular link
    } else {
        struct Node* temp = first;
        while (temp->link != first)
            temp = temp->link;
        temp->link = newNode;
        newNode->link = first;
    }
}

int countNodes() {
    if (first == NULL)
        return 0;

    int count = 1;
    struct Node* temp = first->link;
    while (temp != first) {
        count++;
        temp = temp->link;
    }
    return count;
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    printf("Total nodes in circular linked list: %d\n", countNodes());
    return 0;
}
