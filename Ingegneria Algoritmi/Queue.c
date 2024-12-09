#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

typedef struct queue{
    Node *rear, *front;
}Queue;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> value = value;
    newNode -> next = NULL;
    return newNode;
}

Queue* createQueue(){
    Queue* q = (Queue *)malloc(sizeof(Queue));
    q -> front = q -> rear = NULL;
    return q;
}

void enqueue(Queue* q, int value){
    Node* newNode = createNode(value);
    if(q->rear == NULL){
        q -> front = q ->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    return;
}

int isEmpty(Queue* q){
    if(q->front == NULL && q-> rear ==NULL){
        return 1;
    }
    return 0;
}

void dequeue(Queue* q){
    if(isEmpty(q)){printf("Queue is empty\n");}
    Node* tmp = q->front;
    q->front = q->front->next;
    if(q->front == NULL){
        q->rear == NULL;
    }

    free(tmp);
}


void printQueue(Queue* q){
    Node* tmp = q -> front;
    while(tmp != NULL){
        printf("%d -> ", tmp -> value);
        tmp = tmp -> next;
    }
    printf("\n");
}


int main(){
    Queue* q = createQueue();

    enqueue(q, 10);
    printQueue(q);
    enqueue(q, 100);
    printQueue(q);
    enqueue(q, 1);
    printQueue(q);
    enqueue(q, 20);
    printQueue(q);
    dequeue(q);
    printQueue(q);

}


