#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function prototypes
void insert(struct TreeNode **root, int data);
void inOrder(struct TreeNode *root);
void freeTree(struct TreeNode *root);

int main(void) {
    struct TreeNode *root = NULL;
    int list[] = {40,10,30,20,50,60,70};
    for (int i = 0; i < 6; i++) {
        insert(&root, list[i]);
    }
    printf("Key: %d\n",root->data);


    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");


    freeTree(root);

    return 0;
}

void insert(struct TreeNode **root, int data) {
    if (*root == NULL) {

        struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        if (node == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        *root = node;
    } else if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}


void inOrder(struct TreeNode *root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void freeTree(struct TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
