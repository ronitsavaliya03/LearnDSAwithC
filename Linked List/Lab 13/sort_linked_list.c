#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

void sortList(struct Node* first) {
    struct Node *i, *j;
    int temp;
    for (i = first; i != NULL; i = i->link) {
        for (j = i->link; j != NULL; j = j->link) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
}

void display(struct Node* first) {
    while (first != NULL) {
        printf("%d -> ", first->info);
        first = first->link;
    }
    printf("NULL\n");
}

struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

int main() {
    struct Node* first = createNode(3);
    first->link = createNode(1);
    first->link->link = createNode(5);
    first->link->link->link = createNode(2);
    first->link->link->link->link = createNode(4);


    printf("Original List: ");
    display(first);

    sortList(first);

    printf("Sorted List: ");
    display(first);
    return 0;
}
