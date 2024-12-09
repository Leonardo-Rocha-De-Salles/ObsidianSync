#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef struct stack{
    Node* top;
}Stack;

Stack* createStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> top = NULL;
    return stack;
}

Node* createNode(Stack* stack, int value){
    Node* newNode = (Node *)malloc(sizeof(newNode));
    newNode ->value = value;
    newNode -> next = NULL;
    return newNode;
}

void push(Stack* stack, int value){
    Node* newNode = createNode(stack, value);
    if(!newNode){
        printf("Memory Allocation Fail.\n");
    }
    newNode -> next = stack -> top;
    stack -> top = newNode;
}

void printStack(Stack* stack){
    Node* tmp = stack -> top;
    while(tmp!=NULL){
        printf("%d -> ", tmp ->value);
        tmp = tmp -> next;
    }
    printf("\n");
    free(tmp);
}


void pop(Stack* stack){
    Node* tmp = stack -> top;
    stack -> top = stack -> top -> next;
    free(tmp);
}


int main(int argc, char **argv){
    Stack* stack = createStack();
    push(stack, 10);
    printStack(stack);
    push(stack, 20);
    printStack(stack);
    push(stack, 5);
    printStack(stack);
    pop(stack);
    printStack(stack);
}