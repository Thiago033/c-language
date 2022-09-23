#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int nElements = 0;

struct node{
    int data;
    struct node *link;
};

struct node* push(struct node *head, int data){
    struct node *newNode;
    struct node *temp;

    if (nElements == 0) {
        head->data = data;
        head->link = NULL;

        nElements++;
        return head;

    } else {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->link = NULL;

        temp = head;

        while (temp->link != NULL) {
            temp = temp->link;
        }

        temp->link = newNode;

        nElements++;
    }
}

void printList(struct node *head) {
    if (head == NULL) printf("List is empty!");

    struct node *ptr = head;

    while (ptr != NULL) {
        printf("%d", ptr->data);

        ptr = ptr->link;
    }
}

int main(int argc, char const *argv[]) {
    
    struct node *head = (struct node *)malloc(sizeof(struct node));

    push(head, 50);
    push(head, 40);
    push(head, 30);

    printList(head);
    

    return 0;
}