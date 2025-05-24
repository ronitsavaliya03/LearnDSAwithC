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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    return 1 + max(height(node->left), height(node->right));
}

int isBalanced(struct Node* root) {
    if (root == NULL) return 1;

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1 &&
        isBalanced(root->left) &&
        isBalanced(root->right))
        return 1;

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
    root2->right->right = newNode(5);
    root2->right->right->left = newNode(7);
    root2->right->right->right = newNode(11);
    root2->right->right->right->right = newNode(8);


    printf("Balanced Tree: %s\n", isBalanced(root1) ? "YES" : "NO");
    printf("Balanced Tree: %s\n", isBalanced(root2) ? "YES" : "NO");

    return 0;
}
