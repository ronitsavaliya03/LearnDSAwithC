#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int info;
    struct Node* link;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->link = NULL;
    return newNode;
}

bool areSame(struct Node* first1, struct Node* first2) {
    while (first1 != NULL && first2 != NULL) {
        if (first1->info != first2->info)
            return false;
        first1 = first1->link;
        first2 = first2->link;
    }
    return (first1 == NULL && first2 == NULL);
}

int main() {
    struct Node* first1 = createNode(1);
    first1->link = createNode(2);
    first1->link->link = createNode(3);

    struct Node* first2 = createNode(1);
    first2->link = createNode(2);
    first2->link->link = createNode(3);

    if (areSame(first1, first2))
        printf("Both linked lists are SAME.\n");
    else
        printf("Linked lists are DIFFERENT.\n");

    return 0;
}
