#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 5

int stack_arr[MAX];
int top = -1; //"-1" indicates that the stack is empty
int data;

void PUSH(int data) {

    if (top != -1 && top == MAX-1) {
        printf("Stack is full!\n");
        return;
    }

    top++;
    stack_arr[top] = data;
}

int POP() {

    if (top < 0) {
        printf("Stack is empty!\n");
        return 0;
    } else {
        data = stack_arr[top];
        top--;
        return data;
    }
}

void printTopStack() {
    if (top < 0) {
        printf("Stack is empty!\n");
        return 0;
    } else {
        printf("%d", stack_arr[top]);
    }
}

void printStack() {
    for (int i = 0; i < MAX; i++) {
        printf("%d | ", stack_arr[i]);
    } 
}



int main() {
    int choice;

    do{
        
        printf("Digite uma opcao: \n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("PUSH: \n");
            scanf("%d", &data);
            PUSH(data);
            break;
        case 2:
            data = POP();
            printf("Deleted element is %d\n", data);
            break;
        case 3:
            printTopStack();
            break;
        case 4:
            printStack();
            break;
        case 5:
            
            break;
        case 0:
            printf("Saindo do programa.\n");
            exit(1);
            break;
        default:
            printf("Wrong choice!");
            break;
        }
    } while (choice != 0);

    return 0;
}