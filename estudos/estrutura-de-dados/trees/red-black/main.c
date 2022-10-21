#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

    change node color
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
rotationLeft

    rotation left
===================================
*/
node* rotationLeft(node* node) {
    struct node* nodePtr = node->pRight;

    node->pRight = nodePtr->pLeft;

    nodePtr->pLeft = node;

    nodePtr->color = node->color;

    node->color = RED;

    return nodePtr;
}

/*
===================================
rotationRight

    rotation right
===================================
*/
node* rotationRight(node* node) {
    struct node* nodePtr = node->pLeft;

    node->pLeft = nodePtr->pRight;

    nodePtr->pRight = node;

    nodePtr->color = node->color;

    node->color = RED;

    return nodePtr;
}

/*
===================================
moveToLeftRed

    move a red node to the left
===================================
*/
node* moveToLeftRed(node* node) {
    changeColor(node);

    if (color(node->pRight->pLeft) == RED) {
        node->pRight = rotationRight(node->pRight);

        node = rotationLeft(node);

        changeColor(node);
    }

    return node;
}

/*
===================================
moveToRightRed

    move a red node to the right
===================================
*/
node* moveToRightRed(node* node) {
    changeColor(node);

    if (color(node->pLeft->pLeft) == RED) {
        node = rotationRight(node);

        changeColor(node);
    }

    return node;
}

/*
===================================
balance

    balance tree
===================================
*/
node* balance(node* node) {

    if (color(node->pRight) == RED) {
        node = rotationLeft(node);
    }

    if (node->pLeft != NULL && color(node->pLeft) == RED && color(node->pLeft->pLeft) == RED) {
        node = rotationRight(node);
    }
    
    if (color(node->pLeft) == RED && color(node->pRight) == RED) {
        changeColor(node);
    }
    
    return node;
}

/*
===================================
createNode

    create a new node
===================================
*/
node* createNode(int data) {

    node *newNode = malloc(sizeof(node));

    if (newNode != NULL) {
        newNode->data = data;
        newNode->color = RED;
        newNode->pLeft = NULL;
        newNode->pRight = NULL;
    }

    return newNode;
}

/*
===================================
insertNode

    insert a new node into the tree
===================================
*/
node* insertNode(node* node, int data, int* res) {

    if (node == NULL) {
        struct node* newNode = createNode(data);

        if (newNode == NULL) {
            *res = 0;
            return NULL;
        }

        *res = 1;
        return newNode;
    }

    if (data == node->data) {
        *res = 0; //duplicated value
    } else {
        if (data < node->data)
        {
            node->pLeft = insertNode(node->pLeft, data, res);
        } else {
            node->pRight = insertNode(node->pRight, data, res);
        }
    }

    if (color(node->pRight) == RED && color(node->pLeft) == BLACK) {
        node = rotationLeft(node);
    }
    
    if (color(node->pLeft) == RED && color(node->pLeft->pLeft) == RED) {
        node = rotationRight(node);
    }

    if (color(node->pLeft) == RED && color(node->pRight) == RED) {
        changeColor(node);
    }
     
    return node;
}

/*
===================================
insert

    insert
===================================
*/
int insert(node** root, int data) {
    int res;

    //node* rootPtr = *root;

    (*root) = insertNode(*root, data, &res);

    if ((*root) != NULL) (*root)->color = BLACK;

    return res;
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
removeMinimum

    removeMinimum
===================================
*/
struct node* removeMinimum(struct node* node){

    if(node->pLeft == NULL){
        free(node);
        return NULL;
    }

    if(color(node->pLeft) == BLACK && color(node->pLeft->pLeft) == BLACK){
        node = moveToLeftRed(node);
    }

    node->pLeft = removeMinimum(node->pLeft);

    return balance(node);
}

/*
===================================
removeNode

    removeNode
===================================
*/
node* removeNode(node* node, int data) {
    if (data < node->data) {
        if (color(node->pLeft) == BLACK && color(node->pLeft->pLeft) == BLACK ) {
            node = moveToLeftRed(node);
        }

        node->pLeft = removeNode(node->pLeft, data);
    } else {
        if (color(node->pLeft) == RED) {
            node = rotationRight(node);
        }

        if (data == node->data && (node->pRight == NULL)) {
            free(node);
            return NULL;
        }

        if (color(node->pRight) == BLACK && color(node->pRight->pLeft) == BLACK) {
            node = moveToRightRed(node);
        }

        if (data == node->data) {
            struct node* nodePtr = minValueNode(node->pRight);
            node->data = nodePtr->data;
            node->pRight = removeMinimum(node->pRight);
        } else {
            node->pRight = removeNode(node->pRight, data);
        }
    }

    return balance(node);
}

/*
===================================
searchNode

    search node
===================================
*/
int searchNode(node** raiz, int valor){
    if(raiz == NULL)
        return 0;

    struct node* atual = *raiz;

    while(atual != NULL){

        if(valor == atual->data){
            return 1;
        }
        if(valor > atual->data)
            atual = atual->pRight;
        else
            atual = atual->pLeft;
    }
    return 0;
}

/*
===================================
remove

    remove
===================================
*/
int removeOnTree(node** root, int data) {
    if(searchNode(root, data)) {
        node* node = *root;

        *root = removeNode(node, data);

        if (*root != NULL) {
            (*root)->color = BLACK;  
        }

        return 1;

    } else {
        return 0;
    }
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

    insert(&root, 50);
    insert(&root, 21);
    insert(&root, 85);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 15);

    removeOnTree(&root, 15);

    printf("\nPOST ORDER: \n");
    postOrder(root);

    printf("\nPRE ORDER: \n");
    preOrder(root);

    printf("\nIN ORDER: \n");
    inOrder(root);
    

    printf("\nDONE IT!");

   return(0);
}