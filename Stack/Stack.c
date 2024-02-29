#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void Display(){
    struct Node *ptr;
    ptr = top;
    while (ptr){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void Push(int x)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
        printf("Stack Overflow!\n");
    else
    {
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }
}

int Pop(){
    struct Node *ptr;
    int x = -1;
    if (top==NULL)
        printf("Stack Underflow!\n");
    else{
        ptr = top;
        x = top->data;
        top = top->next;
        free(ptr);
    }
    return x;
}

int Peek(int pos){
    struct Node *ptr;
    ptr = top;
    for(int i=0;i<pos && ptr;i++){
        ptr = ptr->next;
    }
    if (ptr)
        return ptr->data;
    else
        return -1;
}

int isEmpty(){
    return top==NULL;
}

int isFull(){
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    return t?0:1;
}

int stackTop(){
    if (top)
        return top->data;
    return -1;
}

int main()
{
    printf("%d\n",isEmpty());
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    printf("%d\n",isEmpty());
    printf("%d\n",isFull());
    Display();
}