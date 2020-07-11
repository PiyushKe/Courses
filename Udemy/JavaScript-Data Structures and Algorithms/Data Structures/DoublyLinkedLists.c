#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *previous;
    int data;
    struct node *next;
} node;

node *head = NULL;
node *CurrentNode = NULL;
node *tail=NULL;

int length = 0;

node *CreateNewNode(int data){
    node *newNode = (node *)malloc(sizeof(node));
    newNode->previous = NULL;
    newNode->data = data;
    newNode->next = NULL;
    return (newNode);
}

void push(int data){
    node *newnode = CreateNewNode(data);
    
    if(!head){
        head = newnode;
        CurrentNode = head;
        tail = CurrentNode;
    }
    else{
        CurrentNode = newnode;
        CurrentNode->previous = tail;
        tail->next = CurrentNode;
        tail = CurrentNode;
    }
    length++;
}

node *pop(void){
    if(length==0){
        return NULL;
    }
    else if(length==1){
        head = NULL;
        tail = NULL;
    }
    else{
        CurrentNode = tail;
        tail = CurrentNode->previous;
        CurrentNode->previous = NULL;
        tail->next = NULL;
    }
    length--;
    return CurrentNode;
}

node *shift(void){
    CurrentNode = head;
    if(length==0){
        return NULL;
    }
    else if(length==1)
    {
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
    }
    length--;
    return CurrentNode;
}

void unshift(int data){
    node *newnode = CreateNewNode(data);
    newnode->previous = NULL;
    newnode->data = data;
    newnode->next = head;
    head->previous = newnode;
    head = newnode;
    length++;
}

node *delete(int index){
    if(index==0){
        return shift();
    }
    else if(index==length-1){
        return pop();
    }
    CurrentNode = head;
    for (int i = 1; i <= index;i++){
        CurrentNode = CurrentNode->next;
    }
    CurrentNode->previous->next = CurrentNode->next;
    CurrentNode->next->previous = CurrentNode->previous;
    CurrentNode->next = NULL;
    CurrentNode->previous = NULL;
    return (CurrentNode);
}

void insert(int data,int index){
    if(index==0){
        unshift(data);
    }
    else if(index==length-1){
        push(data);
    }
    else{
        node *newNode = CreateNewNode(data);
        CurrentNode = head;
        for (int i = 1; i <= index;i++){
            CurrentNode = CurrentNode->next;
        }
        CurrentNode->previous->next = newNode;
        newNode->previous = CurrentNode->previous;
        newNode->next = CurrentNode;
        CurrentNode->previous = newNode;
        length++;
    }
}

void reverse(node *CurrentNode){
    if(!CurrentNode->next){
        node *temp = CurrentNode->next;
        CurrentNode->next = CurrentNode->previous;
        CurrentNode->previous = temp;
        tail = head;
        head = CurrentNode;
        return;
    }
    reverse(CurrentNode->next);
    node *temp = CurrentNode->next;
    CurrentNode->next = CurrentNode->previous;
    CurrentNode->previous = temp;
}

void set(int data,int index){
    CurrentNode = head;
    for (int i = 1; i <= index;i++){
        CurrentNode = CurrentNode->next;
    }
    CurrentNode->data = data;
}

int get(int index){
    CurrentNode = head;
    for (int i = 1; i <= index;i++){
        CurrentNode = CurrentNode->next;
    }
    return (CurrentNode->data);
}

void print(node *CurrentNode){
    if(!CurrentNode){
        return;
    }
    printf("%d,",CurrentNode->data);
    print(CurrentNode->next);
}

void main(void){
    push(221);
    push(1);
    push(2);
    push(10);
    push(55);
    push(69);
    push(38);
    push(49);
    push(7);
    push(1000);
    push(1258);
    push(17);
    unshift(5);
    // unshift(-8);
    // printf("%d\n",pop()->data);
    // printf("%d\n",shift()->data);
    // printf("%d\n",delete(2)->data);
    // insert(100,3);
    print(head);
    printf("\n%d %d\n",head->data,tail->data);
    printf("\n");
    reverse(head);
    // print(head);
    // printf("\n%d\n",get(7));
    // set(-5,7);
    // printf("%d\n",get(7));
    print(head);
    printf("\n%d %d\n",head->data,tail->data);
}