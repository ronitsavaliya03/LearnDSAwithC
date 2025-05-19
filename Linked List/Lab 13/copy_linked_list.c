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

struct Node* copyList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* copyHead = NULL;
    struct Node* copyTail = NULL;

    while (head != NULL) {
        struct Node* newNode = createNode(head->info);
        if (copyHead == NULL) {
            copyHead = copyTail = newNode;
        } else {
            copyTail->link = newNode;
            copyTail = newNode;
        }
        head = head->link;
    }

    return copyHead;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->info);
        head = head->link;
    }
    printf("NULL\n");
}

int main() {
    struct Node* original = NULL;
    struct Node* tail = NULL;

    for (int i = 1; i <= 5; i++) {
        struct Node* newNode = createNode(i * 10);
        if (original == NULL)
            original = tail = newNode;
        else {
            tail->link = newNode;
            tail = newNode;
        }
    }

    printf("Original List:\n");
    display(original);

    struct Node* copied = copyList(original);
    printf("Copied List:\n");
    display(copied);

    return 0;
}
