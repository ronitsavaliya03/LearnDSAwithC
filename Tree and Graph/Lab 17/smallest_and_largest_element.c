#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *left, *right;
};

struct Node* newNode(int info) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->info = info;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->info) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

int findMin(struct Node* root) {
    struct Node* curr = root;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr->info;
}

int findMax(struct Node* root) {
    struct Node* curr = root;
    while (curr && curr->right != NULL)
        curr = curr->right;
    return curr->info;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);

    printf("Minimum value = %d\n", findMin(root));
    printf("Maximum value = %d\n", findMax(root));
    return 0;
}
