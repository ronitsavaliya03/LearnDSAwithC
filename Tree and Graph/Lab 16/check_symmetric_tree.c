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

int isMirror(struct Node* t1, struct Node* t2) {
    if (t1 == NULL && t2 == NULL)
        return 1;
    if (t1 && t2)
        return (t1->info == t2->info) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    return 0;
}

int isSymmetric(struct Node* root) {
    return isMirror(root, root);
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
    root2->left->left = newNode(6);
    root2->right->right = newNode(3);

    printf("Symmetric Tree: %s\n", isSymmetric(root1) ? "YES" : "NO");
    printf("Symmetric Tree: %s\n", isSymmetric(root2) ? "YES" : "NO");

    return 0;
}
