#include <stdio.h>
#include <stdlib.h>

//node structure
typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
} node;

node *root = NULL;

node *newnode(int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return (temp);
}

node *insert(node *current, int x)
{
    if (current == NULL)
    {
        current = newnode(x);
    }
    else if (x < current->data)
    {
        current->left = insert(current->left, x);
    }
    else if (x > current->data)
    {
        current->right = insert(current->right, x);
    }
    return (current);
}

int min_value(node *current)
{
    if (current->left == NULL)
    {
        return (current->data);
    }
    min_value(current->left);
}

int max_value(node *current)
{
    if (current->right == NULL)
    {
        return (current->data);
    }
    max_value(current->right);
}

int max(int x, int y)
{
    return (x < y ? y : x);
}

int height(node *current)
{
    if (current == NULL)
    {
        return (-1);
    }
    return (max(height(current->left), height(current->right)) + 1);
}

typedef struct queue
{
    node *address;
    struct queue *next;
} queue;

queue *first = NULL, *last = NULL;
int k = 0;

void addInQueue(node *address)
{
    if (address == NULL)
    {
        return;
    }
    queue *temp = (queue *)malloc(sizeof(queue));
    temp->address = address;
    temp->next = NULL;
    last->next = temp;
    last = temp;
    k++;
}

void BreadthOrder(void)
{
    first = (queue *)malloc(sizeof(queue));
    first->address = root;
    first->next = NULL;
    last = first;
    while (first != NULL)
    {
        printf("%d,", first->address->data);
        addInQueue(first->address->left);
        addInQueue(first->address->right);
        first = first->next;
    }
}

void preorder(node *current)
{
    if (current == NULL)
    {
        return;
    }
    printf("%d,", current->data);//root
    preorder(current->left);//left
    preorder(current->right);//right
}

void inorder(node *current)
{
    if (current == NULL)
    {
        return;
    }
    inorder(current->left);//left
    printf("%d,", current->data);//root
    inorder(current->right);//right
}

void postorder(node *current)
{
    if (current == NULL)
    {
        return;
    }
    postorder(current->left);//left
    postorder(current->right);//right
    printf("%d,", current->data);//root
}

void main(void)
{
    for (int i = 1; i <= 5; i++)
    {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("\n%d %d\n", min_value(root), max_value(root));
    printf("%d\n", height(root));
    BreadthOrder();
    printf("\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
}
