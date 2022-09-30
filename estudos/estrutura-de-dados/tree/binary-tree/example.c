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

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
  
    /* loop down to find the leftmost leaf */
    while (current && current->pLeft != NULL)
        current = current->pLeft;
  
    return current;
}

/*
===================================
insert

    insert a new node into the tree
===================================
*/
bool insert (node **root, int value) {
    node *rootPtr = *root;
    
    //tree is empty
    if (rootPtr == NULL) {
        (*root) = createNode(value);
        return true;
    }

    //value already exists in the tree
    if (value == rootPtr->value) {
        return false;
    }

    //less than the root value
    if (value < rootPtr->value) {
        return insert(&(rootPtr->pLeft), value);
    } 

    //greater than the root value
    if (value > rootPtr->value) {
        return insert(&(rootPtr->pRight), value);
    }
}

/*
===================================
remove

    remove
===================================
*/
struct node* removeNode(struct node* root, int key)
{
    // base case
    if (root == NULL) {
        return root;
    }
  
    if (key < root->value) {
        root->pLeft = removeNode(root->pLeft, key);
  
    } else if (key > root->value) {
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

        root->value = temp->value;
  
        root->pRight = removeNode(root->pRight, temp->value);
    }
    return root;
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
    
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    root = removeNode(root, 20);
    root = removeNode(root, 30);
    root = removeNode(root, 50);
    
    printTree(root);

    printf("%d (%d)\n", 16, find(root, 16));
    printf("%d (%d)\n", 50, find(root, 50));
    printf("%d (%d)\n", 5, find(root, 5));
    printf("%d (%d)\n", 70, find(root, 70));
    printf("%d (%d)\n", 20, find(root, 20));

    return 0;
}