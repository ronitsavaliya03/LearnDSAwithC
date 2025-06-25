
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert at end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to count nodes
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to swap Kth node from beginning with Kth from end
void swapKth(struct Node** head, int k) {
    int n = countNodes(*head);
    if (k > n) {
        printf("K is greater than number of nodes.\n");
        return;
    }
    if (2 * k - 1 == n) {
        printf("Kth node from start and end are the same.\n");
        return;
    }

    // Find Kth node from start and its previous
    struct Node *x = *head, *x_prev = NULL;
    for (int i = 1; i < k; i++) {
        x_prev = x;
        x = x->next;
    }

    // Find Kth node from end and its previous
    struct Node *y = *head, *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++) {
        y_prev = y;
        y = y->next;
    }

    // If x_prev exists, point it to y
    if (x_prev)
        x_prev->next = y;
    else
        *head = y;

    // If y_prev exists, point it to x
    if (y_prev)
        y_prev->next = x;
    else
        *head = x;

    // Swap next pointers
    struct Node* temp = x->next;
    x->next = y->next;
    y->next = temp;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Creating the list: 1->2->3->4->5->6->NULL
    for (int i = 1; i <= 6; i++) {
        insertAtEnd(&head, i);
    }

    printf("Original list:\n");
    printList(head);

    int k = 3;
    swapKth(&head, k);

    printf("\nList after swapping %dth node from start and end:\n", k);
    printList(head);

    return 0;
}
