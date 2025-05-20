#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

void insertAtEnd(struct Node** last, int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    if (*last == NULL) {
        newNode->link = newNode;
        *last = newNode;
    } else {
        newNode->link = (*last)->link;
        (*last)->link = newNode;
        *last = newNode;
    }
}

void display(struct Node* last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = last->link;
    do {
        printf("%d -> ", temp->info);
        temp = temp->link;
    } while (temp != last->link);
    printf("(First Node)%d\n", last->link->info);
}

void splitList(struct Node* last, struct Node** last1, struct Node** last2) {
    if (last == NULL || last->link == last) {
        *last1 = last;
        *last2 = NULL;
        return;
    }

    struct Node* slow = last->link;
    struct Node* fast = last->link;

    while (fast->link != last->link && fast->link->link != last->link) {
        fast = fast->link->link;
        slow = slow->link;
    }

    *last1 = slow;
    struct Node* head1 = last->link;
    struct Node* head2 = slow->link;

    slow->link = head1;

    struct Node* temp = head2;
    while (temp->link != head1) {
        temp = temp->link;
    }
    temp->link = head2;
    *last2 = temp;
}

int main() {
    struct Node* last = NULL;
    struct Node* last1 = NULL;
    struct Node* last2 = NULL;

    for (int i = 1; i <= 8; i++) {
        insertAtEnd(&last, i);
    }

    printf("Original Circular Linked List:\n");
    display(last);

    splitList(last, &last1, &last2);

    printf("\nFirst Half:\n");
    display(last1);

    printf("Second Half:\n");
    display(last2);

    return 0;
}
