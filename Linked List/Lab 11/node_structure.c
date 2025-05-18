#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

int main() {
    struct Node* first;

    first = (struct Node*) malloc(sizeof(struct Node));

    if (first == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter info for the node: ");
    scanf("%d", &first->info);

    // Set link pointer to NULL (only one node)
    first->link = NULL;

    printf("\ninfo in the node: %d\n", first->info);
    printf("link pointer value: %p\n", first->link);  // Should be NULL (0x0)

    free(first);

    return 0;
}
