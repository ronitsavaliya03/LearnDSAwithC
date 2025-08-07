#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Search for a value in postorder[]
int search(int post[], int key, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (post[i] == key)
            return i;
    }
    return -1;
}

// Build tree from preorder and postorder
struct Node* buildTree(int pre[], int post[], int* preIndex, int postStart, int postEnd, int size) {
    // Base case
    if (*preIndex >= size || postStart > postEnd)
        return NULL;

    // Create root node
    struct Node* root = newNode(pre[*preIndex]);
    (*preIndex)++;

    // If only one node, return it
    if (postStart == postEnd || *preIndex >= size)
        return root;

    // Find next element of preorder in postorder
    int idx = search(post, pre[*preIndex], postStart, postEnd);

    // Construct left and right subtrees
    if (idx != -1) {
        root->left = buildTree(pre, post, preIndex, postStart, idx, size);
        root->right = buildTree(pre, post, preIndex, idx + 1, postEnd - 1, size);
    }

    return root;
}

// Inorder print (to check)
void printInorder(struct Node* root) {
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Main
int main() {
    int pre[] = {1, 2, 4, 5, 3, 6, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);
    int preIndex = 0;

    struct Node* root = buildTree(pre, post, &preIndex, 0, size - 1, size);

    printf("Inorder Traversal:\n");
    printInorder(root);

    return 0;
}
