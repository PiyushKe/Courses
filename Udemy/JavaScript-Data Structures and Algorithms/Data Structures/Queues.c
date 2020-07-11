#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *first = NULL;
node *last = NULL;
int size = 0;

node *CreateNewNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return (newNode);
}

void enqueue(int data){
    node *newnode = CreateNewNode(data);
    if(!first){
        first = newnode;
        last = newnode;
    }
    last->next = newnode;
    last = newnode;
    size++;
}

node *dequeue(void){
    if(!first){
        return NULL;
    }
    node *temp = first;
    first = first->next;
    size--;
    return temp;
}

void traverseQueue(void){
    if(!first){
        return;
    }
    printf("%d,",dequeue()->data);
    traverseQueue();
}

int empty(){
    if(!first){
        return(1);
    }
    return (0);
}

void main(void){
    enqueue(221);
    enqueue(1);
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);
    // traverseQueue();
    printf("%d\n",dequeue()->data);
    // printf("%d\n",dequeue()->data);
    // printf("%d\n",dequeue()->data);
    // printf("%d\n",dequeue()->data);
    // printf("%d\n",dequeue()->data);
    // printf("%d\n",dequeue()->data);
    // printf("%d\n",dequeue()->data);
    // printf("%d\n",dequeue()->data);
    // printf("\n%d",empty());
}