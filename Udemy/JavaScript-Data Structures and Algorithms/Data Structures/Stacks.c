#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *next;
} node;

node *top = NULL;
int size = 0;

node *CreateNewNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return (newNode);
}

void push(int data){
    node *newnode = CreateNewNode(data);
    newnode->next = top;
    top = newnode;
    size++;
}

node *pop(void){
    if(!top){
        return NULL;
    }
    node *temp = top;
    top = top->next;
    size--;
    return temp;
}

void traverseStack(void){
    if(!top){
        return;
    }
    printf("%d,",pop()->data);
    traverseStack();
}

int empty(){
    if(!top){
        return(1);
    }
    return (0);
}

void main(void){
    push(221);
    push(1);
    push(12);
    push(13);
    push(14);
    push(15);
    push(16);
    printf("%d\n",pop()->data);
    // traverseStack();
    // printf("\n%d",empty());
}