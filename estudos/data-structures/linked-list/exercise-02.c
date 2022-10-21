#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nElements = 0;

struct node{
    int data;
    struct node *link;
};

struct node* push(struct node *head, int data){
    
    if (nElements == 0) {
        head->data = data;
        head->link = NULL;

        nElements++;

        return head;

    } else {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->link = NULL;

        struct node *temp = head;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        
        temp->link = newNode;

        return head;
    }
}

struct node* push(struct node *head, int data) {

    struct node *ptr;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    int key = data;

    if (head == NULL || key < head->data) {
        temp->link = head;
        head = temp;
    } else {
        ptr = head;
        while (ptr->link != NULL && ptr->link->data < key) {
            ptr = ptr->link;
        }
            
        temp->link = ptr->link;
        ptr->link = temp;
    }

    return head;
}

void printList(struct node *head) {
    if (head == NULL) printf("List is empty!");

    struct node *ptr = head;

    while (ptr != NULL) {
        printf("%d\n", ptr->data);

        ptr = ptr->link;
    }
}

int main(int argc, char const *argv[]) {
    
    struct node *head = (struct node *)malloc(sizeof(struct node));

    push(head, 1);
    push(head, 2);
    push(head, 4);
    head = pushSorted(head, 0);
    push(head, 5);
    head = pushSorted(head, 6);
    push(head, 7);

    printList(head);

    return 0;
}