#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Display(){
    struct Node *ptr;
    ptr = front;
    while (ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
        printf("Queue is full!\n");
    else
    {
        newNode->data = val;
        newNode->next = NULL;
        if (front == NULL)
            front = rear = newNode;
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
}

int dequeue()
{
    int x = -1;
    if (front == NULL)
        printf("Queue is empty!");
    else{
        x = front->data;
        struct Node *ptr = front;
        front = front->next;
        free(ptr);
    }
    return x;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    dequeue();
    dequeue();
    Display();
}