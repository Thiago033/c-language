#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* pLeft;
    struct node* pRight;
} node;

/*
===================================
freeNode

    free node
===================================
*/
void freeNode(node* node) {
    if (node == NULL) return;

    freeNode(node->pLeft);
    freeNode(node->pRight);
    free(node);

    node = NULL;
}

/*
===================================
freeTree

    free tree
===================================
*/
void freeTree(node** root) {
    if (root == NULL) return;

    freeNode(*root);

    free(root);
}

/*
===================================
isEmpty

    checks if the tree is empty
    return 1 if the tree is empty
    return 0 if not
===================================
*/
int isEmpty(node** root) {
    if (root == NULL) return 1;
    
    if (*root == NULL) return 1;

    return 0;
}

/*
===================================
treeHeight

    tree height
===================================
*/
int treeHeight(node** root) {

    node* rootPtr = *root;

    if (root == NULL) return 0;

    if (rootPtr == NULL) return 0;

    int leftHeight = treeHeight(&rootPtr->pLeft);
    int rightHeight = treeHeight(&rootPtr->pRight);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

/*
===================================
totalNodes

    total nodes
===================================
*/
int totalNodes(node** root) {
    node* rootPtr = *root;

    if (root == NULL) return 0;

    if (rootPtr == NULL) return 0;

    int totalLeft = totalNodes(&rootPtr->pLeft);
    int totalRight = totalNodes(&rootPtr->pRight);

    return (totalLeft + totalRight + 1);
}

/*
=========================================
minValueNode

    find minimum value node and return it
=========================================
*/
struct node* minValueNode(struct node* node) {
    struct node* current = node;
  
    //loop down to find the leftmost leaf
    while (current && current->pLeft != NULL) {
        current = current->pLeft;
    }
        
    return current;
}

/*
===================================
find

    find a node in the tree
===================================
*/
bool find(node *root, int key) {
    if (root == NULL) return false;

    if (root->data == key) return true;

    //greater than the root value
    if (key > root->data) {
        return find(root->pRight, key);
    }

    //less than the root value
    if (key < root->data) {
        return find(root->pLeft, key);
    }
}

/*
===================================
preOrder

    pre order
===================================
*/
void preOrder(node* root) {
    if (root == NULL) return;

    printf("%d, ", root->data);
    preOrder(root->pLeft);
    preOrder(root->pRight);
}

/*
===================================
inOrder

    in order
===================================
*/
void inOrder(node* root) {
    if (root == NULL) return;

    inOrder(root->pLeft);
    printf("%d, ", root->data);
    inOrder(root->pRight);
}

/*
===================================
postOrder

    post order
===================================
*/
void postOrder(node* root) {
    if (root == NULL) return;

    postOrder(root->pLeft);
    postOrder(root->pRight);
    printf("%d, ", root->data);
}

/*
===================================
createNode

    create a new node
===================================
*/
node* createNode(int data) {

    node* newNode = malloc(sizeof(node));

    if (newNode != NULL) {
        newNode->pLeft = NULL;
        newNode->pRight = NULL;
        newNode->data = data;
    }

    return newNode;
}

/*
===================================
insert

    insert a new node into the tree
===================================
*/
bool insert(node** root, int data) {

    node *rootPtr = *root;

    if (rootPtr == NULL) {
        *root = createNode(data);
        return true;
    }
    
    //value already exists in the tree
    if (data == rootPtr->data) {
        return false;
    }

    //less than the root value
    if (data < rootPtr->data) {
        return insert(&(rootPtr->pLeft), data);
    } 

    //greater than the root value
    if (data > rootPtr->data) {
        return insert(&(rootPtr->pRight), data);
    }
}

/*
=========================================
removeNode

    remove a node
=========================================
*/
node* removeNode(node* root, int key) {

    if (root == NULL) {
        return root;
    }
  
    if (key < root->data) {
        root->pLeft = removeNode(root->pLeft, key);
  
    } else if (key > root->data) {
        root->pRight = removeNode(root->pRight, key);
  
    } else {
        if (root->pLeft == NULL) {
            struct node* temp = root->pRight;
            free(root);
            return temp;
        }
        else if (root->pRight == NULL) {
            struct node* temp = root->pLeft;
            free(root);
            return temp;
        }
  
        struct node* temp = minValueNode(root->pRight);

        root->data = temp->data;
  
        root->pRight = removeNode(root->pRight, temp->data);
    }

    return root;
}

int main(int argc, char const *argv[]) {
    
    //create root
    node *root = malloc(sizeof(node));

    if (root == NULL) {
        printf("Error!");
        exit(1);
    }

    root = NULL;

    //---------------------------------------------------

    insert(&root, 10);
    insert(&root, 11);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 9);
    insert(&root, 15);
    insert(&root, 8);

    removeNode(root, 15);
    removeNode(root, 10);

    printf("\nPOST ORDER: \n");
    postOrder(root);
    printf("\nIN ORDER: \n");
    inOrder(root);
    printf("\nPRE ORDER: \n");
    preOrder(root);

    printf("\n\nTREE HEIGHT\n");
    printf("%d\n", treeHeight(&root));

    printf("TOTAL NODES\n");
    printf("%d\n", totalNodes(&root));

    printf("MINIMUM NODE\n");
    node* minimumNode = minValueNode(root);
    printf("%d\n\n", minimumNode->data);

    if (isEmpty(&root)) {
        printf("Tree is empty!\n\n");
    } else {
        printf("Tree isn't empty!\n\n");
    }

    printf("FINDING ON TREE: (0) FALSE | (1) TRUE\n");
    printf("%d (%d)\n", 16, find(root, 16));
    printf("%d (%d)\n", 50, find(root, 50));
    printf("%d (%d)\n", 5, find(root, 5));

    printf("\nDONE IT!");

    return 0;
}