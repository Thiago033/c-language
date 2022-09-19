#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

int nodesCounter(struct node *head) {
    int count = 0;

    if (head == NULL) printf("Linked list is empty!");

    struct node *ptr = NULL;
    ptr = head;

    while (ptr != NULL) {
        count++;
        ptr = ptr->link;
    }

    return count;
}

void printList(struct node *head) {
    if (head == NULL) printf("Linked list is empty!");

    struct node *ptr = NULL;
    ptr = head;

    while (ptr != NULL) {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

// //1st version
// void addAtEnd(struct node *head, int data){
//     struct node *ptr, *temp;

//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;

//     ptr = head;

//     while (ptr->link != NULL){
//         ptr = ptr->link;
//     }

//     ptr->link = temp;
// }

//2nd version
struct node* addAtEnd(struct node *ptr, int data){
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}

//1st version
// struct node* addAtBeginning(struct node *head, int data) {
//     struct node *temp;

//     temp = (struct node *)malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = head;
//     head = temp;
//     return head;
// }

//2nd version
void addAtBeginning(struct node **head, int data) {
    struct node *temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = *head;
    *head = temp;
}

void addAtCertainPosition(struct node *head, int data, int pos) {

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    struct node *ptr = head;
    pos--;

    while (pos != 1) {
        ptr = ptr->link;
        pos--;
    }

    temp->link = ptr->link;
    ptr->link = temp;

}

struct node* del_first(struct node *head){
    if (head == NULL) printf("Linked list is empty!");
    else {
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
    }
    
    return head;
}

//1st version
// struct node* del_last(struct node *head) {
//     if (head == NULL) printf("Linked list is empty!");
//     else if (head->link == NULL){
//         free(head)
//         head = NULL;
//     } else {
//         struct node *temp = head;
//         struct node *temp2 = head;

//         while (temp->link != NULL) {
//             temp2 = temp;
//             temp = temp->link;
//         }

//         temp2->link = NULL;
//         free(temp);
//         temp = NULL;
//     }

//     return head;
// }

//2nd version
struct node* del_last(struct node *head) {
    if (head == NULL) printf("Linked list is empty!");
    else if (head->link == NULL){
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;

        while (temp->link->link != NULL) {
            temp = temp->link;
        }

        free(temp->link);
        temp->link = NULL;
    }

    return head;
}

struct node* del_pos(struct node **head, int position) {

    struct node *current = *head;
    struct node *previous = *head;

    if (*head == NULL) printf("Linked list is empty!");
    else if (position == 1){
        *head = current->link;
        free(current);
        current = NULL;
    } else {
        while (position != 1)
        {
            previous = current;
            current = current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}

struct node* del_list(struct node *head) {
    struct node *temp = head;

    while (temp != NULL) {
        temp = temp->link;
        free(head);
        head = temp;
    }
    
}

struct node* reverse_list(struct node *head) {
    struct node *prev = NULL;
    struct node *next = NULL;

    while (head != NULL) {

        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }

    head = prev;
    return head;

}

int main(int argc, char const *argv[]) {
    struct node *head = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->link = NULL;

    struct node *ptr = head;
    // struct node *current = (struct node *)malloc(sizeof(struct node));
    // current->data = 2;
    // current->link = NULL;
    // head->link = current;

    // current = (struct node *)malloc(sizeof(struct node));
    // current->data = 3;
    // current->link = NULL;
    // head->link->link = current;

    ptr = addAtEnd(ptr, 2);
    ptr = addAtEnd(ptr, 3);
    ptr = addAtEnd(ptr, 4);

    //head = addAtBeginning(head, 5);
    addAtBeginning(&head, 5);

    addAtCertainPosition(head, 10, 4);
    addAtCertainPosition(head, 11, 5);
    addAtCertainPosition(head, 12, 2);

    addAtBeginning(&head, 89);

    head = del_first(head);

    del_pos(&head, 5);

    del_last(head);
    
    printf("==========================================\n");
    printf("Nodes counter: %d\n", nodesCounter(head));
    printList(head);
    printf("head: %d\n", head->data);
    printf("==========================================\n");


    head = reverse_list(head);
    printf("AFTER REVERSE_LIST\n");
    printf("==========================================\n");
    printf("Nodes counter: %d\n", nodesCounter(head));
    printList(head);
    printf("head: %d\n", head->data);
    printf("==========================================\n");


    printf("AFTER DEL_LIST\n");
    head = del_list(head);
    printf("==========================================\n");
    printf("Nodes counter: %d\n", nodesCounter(head));
    printList(head);
    printf("head: %d\n", head->data);
    printf("==========================================\n");
    return 0;
}