#include <stdio.h>
#include <string.h>

//Color definition
#define RED 1
#define BLACK 0

typedef struct node {
    int data;
    int color;
    struct node* pLeft;
    struct node* pRight;
} node;

/*
===================================
color

    return node color
===================================
*/
int color(node* node) {
    if (node == NULL) {
        return BLACK;
    } else {
        return node->color;
    }
}

/*
===================================
changeColor

    
===================================
*/
void changeColor(node* node) {
    node->color = !node->color;

    if (node->pLeft != NULL) {
        node->pLeft->color = !node->pLeft->color;
    }
    
    if (node->pRight != NULL){
        node->pRight->color = !node->pRight->color;
    }
}

/*
===================================
rotationRight

    rotation right
===================================
*/
node* rotationLeft(node* node) {
    struct node* nodePtr = node->pLeft;

    node->pLeft = nodePtr->pRight;

    nodePtr->pRight = node;

    nodePtr->color = node->color;

    node->color = RED;

    return nodePtr;
}

/*
===================================
rotationLeft

    rotation left
===================================
*/
node* rotationRight(node* node) {
    struct node* nodePtr = node->pRight;

    node->pRight = nodePtr->pLeft;

    nodePtr->pLeft = node;

    nodePtr->color = node->color;

    node->color = RED;

    return nodePtr;
}

int main () {

    //create root
    node *root = malloc(sizeof(node));

    if (root == NULL) {
        printf("Error!");
        exit(1);
    }

    root = NULL;

    //---------------------------------------------------

   return(0);
}