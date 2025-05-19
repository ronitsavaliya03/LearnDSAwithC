#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->link;     // store next node
        curr->link = prev;     // reverse current node's pointer
        prev = curr;           // move prev and curr forward
        curr = next;
    }
    return prev; // new head
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->info);
        head = head->link;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 1; i <= 5; i++) {
        struct Node* newNode = createNode(i * 10);
        if (head == NULL)
            head = tail = newNode;
        else {
            tail->link = newNode;
            tail = newNode;
        }
    }

    printf("Original List:\n");
    display(head);

    head = reverseList(head);
    printf("Reversed List:\n");
    display(head);

    return 0;
}