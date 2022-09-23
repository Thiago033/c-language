#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nElements = 0;

struct node{
    int data;
    struct node *link;
} *top = NULL;

int isEmpty() {
    if (top == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void push(int data){
    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if(newNode == NULL) {
        printf("Stack Overflow!");
        exit(1);
    }

    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
}

int pop() {
    struct node *temp;
    temp = top;

    if (isEmpty()) {
        printf("Stack Overflow!");
        exit(1);
    }
    
    //save the data to val
    int val = temp->data;

    //Updating the top pointer
    top = top->link;

    //Deleting the node
    free(temp);
    temp = NULL;

    return val;
}

void print() {
    print("");
}

int main(int argc, char const *argv[]) {
    
    struct node *top = (struct node *)malloc(sizeof(struct node));

    push(50);
    push(40);
    push(30);



    return 0;
}