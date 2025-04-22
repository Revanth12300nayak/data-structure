#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == value)
            return i;
    return -1;
}

struct Node* buildTreeFromPreIn(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* node = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd) return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);
    node->left = buildTreeFromPreIn(inorder, preorder, inStart, inIndex - 1, preIndex);
    node->right = buildTreeFromPreIn(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return node;
}


struct Node* buildTreeFromPostIn(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* node = createNode(postorder[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) return node;

    int inIndex = search(inorder, inStart, inEnd, node->data);
    node->right = buildTreeFromPostIn(inorder, postorder, inIndex + 1, inEnd, postIndex);
    node->left = buildTreeFromPostIn(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}


void inorderPrint(struct Node* root) {
    if (root != NULL) {
        inorderPrint(root->left);
        printf("%d ", root->data);
        inorderPrint(root->right);
    }
}

int main() {
    // Example: Tree = 1,2,3,4,5,6,7
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(inorder) / sizeof(inorder[0]);

    
    int preIndex = 0;
    struct Node* rootFromPre = buildTreeFromPreIn(inorder, preorder, 0, size - 1, &preIndex);

    printf("Inorder from reconstructed tree (Pre + In): ");
    inorderPrint(rootFromPre);
    printf("\n");

    
    int postIndex = size - 1;
    struct Node* rootFromPost = buildTreeFromPostIn(inorder, postorder, 0, size - 1, &postIndex);

    printf("Inorder from reconstructed tree (Post + In): ");
    inorderPrint(rootFromPost);
    printf("\n");

    return 0;
}
