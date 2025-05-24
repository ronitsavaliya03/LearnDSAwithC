#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->info)
        root->left = insert(root->left, value);
    else if (value > root->info)
        root->right = insert(root->right, value);
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL)
        return root;
    if (value < root->info)
        root->left = deleteNode(root->left, value);
    else if (value > root->info)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->info = temp->info;
        root->right = deleteNode(root->right, temp->info);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->info == key)
        return root;
    if (key < root->info)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n1.Insert  2.Delete  3.Search  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Node found.\n");
                else
                    printf("Node not found.\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
