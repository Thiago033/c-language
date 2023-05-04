#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int data;
    int color;
    struct node* pLeft;
    struct node* pRight;
} node;


int height(struct node *root) {
    if ( root == NULL) return 0;

    int leftHeight = height( root->pLeft );
    int rightHeight = height( root->pRight);

    if ( leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int isAVL(struct node *root) {

    if ( root == NULL) return 1;

    int leftHeight = height(root->pLeft);
    int rightHeight = height(root->pRight);

    int diff = abs(leftHeight - rightHeight);

    if (diff > 1) {
        return 0;
    }

    return isAVL(root->pLeft) && isAVL(root->pRight);
}

/*
===================================
createNode

    create a new node
===================================
*/
node* createNode(int data) {

    node *newNode = malloc( sizeof(node) );

    if (newNode != NULL) {
        newNode->data = data;
        newNode->pRight = NULL;
        newNode->pLeft = NULL;
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

int main(int argc, char const *argv[]) {
    //create root
    node *root = malloc(sizeof(node));

    if (root == NULL) {
        printf("Error!");
        exit(1);
    }

    root = NULL;

    //---------------------------------------------------

    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 6);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 3);


    if (isAVL(root)) {
        printf("The tree is AVL.\n");
    } else {
        printf("The tree is not AVL.\n");
    }


    return 0;
}

