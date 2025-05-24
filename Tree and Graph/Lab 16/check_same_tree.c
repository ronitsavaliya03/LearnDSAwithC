#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int info) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->info = info;
    node->left = node->right = NULL;
    return node;
}

int isSameTree(struct Node* root1, struct Node* root2) {
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 && root2)
        return (root1->info == root2->info) &&
               isSameTree(root1->left, root2->left) &&
               isSameTree(root1->right, root2->right);
    return 0;
}

int main() {
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(2);
    root1->left->left = newNode(3);
    root1->right->right = newNode(3);

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->left = newNode(3);
    root2->right->right = newNode(3);

    printf("Same Tree: %s\n", isSameTree(root1, root2) ? "YES" : "NO");

    return 0;
}
