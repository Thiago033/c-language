#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long keyType;


typedef struct node {
    int value;
    struct node *pLeft;
    struct node *pRight; 
} node;


node *createNode(int value) {

    node *newNode = malloc(sizeof(node));

    if (newNode != NULL) {
        newNode->pLeft = NULL;
        newNode->pRight = NULL;
        newNode->value = value;
    }

    return newNode;
}

/*
===================================
insert

    insert a new node into the tree
===================================
*/
bool insert (node **rootptr, int value) {
    node *root = *rootptr;
    
    //tree is empty
    if (root == NULL) {
        (*rootptr) = createNode(value);

        return true;
    }

    //value already exists in the tree
    if (value == root->value) {
        return false;
    }

    //less than the root value
    if (value < root->value) {
        return insert(&(root->pLeft), value);
    } 

    //greater than the root value
    if (value > root->value) {
        return insert(&(root->pRight), value);
    }
}

/*
===================================
find

    find a node in the tree
===================================
*/
bool find(node *root, int value) {
    if (root == NULL) return false;

    if (root->value == value) return true;

    //greater than the root value
    if (value > root->value) {
        return find(root->pRight, value);
    }

    //less than the root value
    if (value < root->value) {
        return find(root->pLeft, value);
    }
}

/*
===================================
printTree

    prints the tree on the screen
===================================
*/
void printTree(node *root) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }

    printf("Value = %d\n", root->value);

    printf("Left\n");
    printTree(root->pLeft);

    printf("Right\n");
    printTree(root->pRight);

    printf("DONE!!!\n");
}

int main() {

    node *root = NULL;
    
    insert(&root, 15);
    insert(&root, 11);
    insert(&root, 24);
    insert(&root, 5);
    insert(&root, 19);
    insert(&root, 16);
    
    printTree(root);

    printf("%d (%d)\n", 16, find(root, 16));
    printf("%d (%d)\n", 1, find(root, 1));
    printf("%d (%d)\n", 5, find(root, 5));
    printf("%d (%d)\n", 100, find(root, 100));
    printf("%d (%d)\n", 24, find(root, 24));

    return 0;
}