#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int priority;
    struct node *link;
} node;

void CountOfNodes( node *head ) {
    int count = 0;

    if ( head == NULL ) {
        printf("Linked list is empty.\n");
        return;
    }

    node *ptr = NULL;
    ptr = head;

    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }

    printf("Nodes in the list: %d\n", count);
}

void PrintListData( node *head ) {
    if ( head == NULL ) {
        printf("Linked list is empty.\n");
        return;
    }

    node *ptr = NULL;
    ptr = head;

    while (ptr != NULL) {
        printf("Node data: %d\n", ptr->data);
        ptr = ptr->link;
    }
}

void ReverseList ( node **head ) {

    node *prev = NULL, *next = NULL;

    while ( *head != NULL ) {
        next = (*head)->link;
        (*head)->link = prev;
        prev = *head;
        *head = next;
    }

    *head = prev;
}

void Push( node **head, int data, int priority ) {
    node *ptr = *head;

    //Creates the new node
    //Can be a separate function
    node *newNode = (node *) malloc( sizeof(node) );
    newNode->data = data;
    newNode->priority = priority;
    newNode->link = NULL;

    if ( (*head)->priority < priority ) {
        newNode->link = (*head);
        (*head) = newNode;

    } else {
        while ( ptr->link != NULL && ptr->link->priority > priority) {
            ptr = ptr->link;
        }

        newNode->link = ptr->link;
        ptr->link = newNode;
    }
}

void Pop( node** head ) {

    node *ptr = *head;
    (*head) = (*head)->link;
    free(ptr);
}

void DeleteAllList( node **head ) {
    if ( *head == NULL ) {
        printf("Linked list is empty.\n");
        return;
    }

    node *ptr = *head;

    while ( ptr != NULL ) {
        ptr = ptr->link;
        free( *head );
        *head = ptr;
    }
}


int main() {
    node *head = (node *) malloc( sizeof(node) );
    
    head->data = 1;
    head->priority = 1;
    head->link = NULL;

    Push( &head, 2, 2);
    Push( &head, 5, 5);
    Push( &head, 4, 4);
    Push( &head, 3, 3);

    // 5 4 3 2 1

    Pop( &head );
    // 4 3 2 1

    Pop( &head );
    // 3 2 1

    //ReverseList(&head);

    CountOfNodes( head );
    PrintListData( head );

    DeleteAllList( &head );

    return 0;
}
