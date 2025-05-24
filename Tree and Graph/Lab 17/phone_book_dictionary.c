#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

// Node structure
typedef struct Node {
    char name[SIZE];
    char phone[SIZE];
    struct Node *left, *right;
} Node;

// Create new node
Node* createNode(char name[], char phone[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node into BST
Node* insert(Node* root, char name[], char phone[]) {
    if (root == NULL) return createNode(name, phone);

    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, phone);
    else if (strcmp(name, root->name) > 0)
        root->right = insert(root->right, name, phone);
    else
        printf("Name already exists!\n");

    return root;
}

// Find min node (used in deletion)
Node* findMin(Node* root) {
    while (root->left != NULL) root = root->left;
    return root;
}

// Delete node
Node* deleteNode(Node* root, char name[]) {
    if (root == NULL) return NULL;

    if (strcmp(name, root->name) < 0)
        root->left = deleteNode(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = deleteNode(root->right, name);
    else {
        // Node with 0 or 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with 2 children
        Node* temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phone, temp->phone);
        root->right = deleteNode(root->right, temp->name);
    }

    return root;
}

// Search phone number
void search(Node* root, char name[]) {
    if (root == NULL) {
        printf("Name not found.\n");
        return;
    }

    if (strcmp(name, root->name) == 0)
        printf("Phone Number of %s: %s\n", name, root->phone);
    else if (strcmp(name, root->name) < 0)
        search(root->left, name);
    else
        search(root->right, name);
}

// In-order traversal (ascending)
void displayAsc(Node* root) {
    if (root != NULL) {
        displayAsc(root->left);
        printf("%s: %s\n", root->name, root->phone);
        displayAsc(root->right);
    }
}

// Reverse in-order traversal (descending)
void displayDesc(Node* root) {
    if (root != NULL) {
        displayDesc(root->right);
        printf("%s: %s\n", root->name, root->phone);
        displayDesc(root->left);
    }
}

// Main menu
int main() {
    Node* root = NULL;
    int choice;
    char name[SIZE], phone[SIZE];

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add Entry\n");
        printf("2. Delete Entry\n");
        printf("3. Search Phone Number\n");
        printf("4. Display Ascending Order\n");
        printf("5. Display Descending Order\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, SIZE, stdin);
                name[strcspn(name, "\n")] = '\0'; // Remove newline
                printf("Enter phone: ");
                fgets(phone, SIZE, stdin);
                phone[strcspn(phone, "\n")] = '\0';
                root = insert(root, name, phone);
                break;

            case 2:
                printf("Enter name to delete: ");
                fgets(name, SIZE, stdin);
                name[strcspn(name, "\n")] = '\0';
                root = deleteNode(root, name);
                break;

            case 3:
                printf("Enter name to search: ");
                fgets(name, SIZE, stdin);
                name[strcspn(name, "\n")] = '\0';
                search(root, name);
                break;

            case 4:
                printf("Phone Book (A-Z):\n");
                displayAsc(root);
                break;

            case 5:
                printf("Phone Book (Z-A):\n");
                displayDesc(root);
                break;

            case 6:
                printf("Exiting.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}