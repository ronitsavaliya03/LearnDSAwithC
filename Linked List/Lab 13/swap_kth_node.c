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

int getLength(struct Node* first) {
    int count = 0;
    while (first != NULL) {
        count++;
        first = first->link;
    }
    return count;
}

void swapKthNode(struct Node* first, int k) {
    int n = getLength(first);
    if (k > n) return;
    if (2 * k - 1 == n) return; // Same node

    struct Node* x = first;
    struct Node* y = first;
    for (int i = 1; i < k; i++) x = x->link;
    for (int i = 1; i < n - k + 1; i++) y = y->link;

    int temp = x->info;
    x->info = y->info;
    y->info = temp;
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
    for (int i = 1; i <= 7; i++){
        insertAtEnd(&first, i);
    } 
    int k = 2;

    printList(first);

    swapKthNode(first, k);
    printList(first);
    return 0;
}
