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
    struct Node *ptr = front;
    while (ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void pushright(int val){
    struct Node * newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode==NULL)
        printf("Dequeue is full!\n");
    else{
        newNode->data = val;
        newNode->next = NULL;
        if (front==NULL) front = rear = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }
}

void pushleft(int val){
    struct Node * newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode==NULL)
        printf("Dequeue is full!\n");
    else{
        newNode->data = val;
        newNode->next = front;
        front = newNode;
        if (rear==NULL) rear = newNode;
    }
}

int popright(){
    int x = -1;
    if (front==NULL)
        printf("Dequeue is empty!\n");
    else{
        x = rear->data;
        if (front==rear){
            free(rear);
            front=rear=NULL;
        } else{
            struct Node *ptr;
            ptr = front;
            while (ptr && ptr->next!=rear)
                ptr = ptr->next;
            free(rear);
            rear = ptr;
            rear->next = NULL;
        }
    }
    return x;
}

int popleft(){
    int x = -1;
    if (front==NULL)
        printf("Dequeue is empty!\n");
    else{
        struct Node *ptr;
        ptr = front;
        x = front->data;
        front = front->next;
        free(ptr);
    }
    return x;
}


int main(){
    pushright(1);
    pushright(2);
    pushright(3);
    Display();
    popleft();
    popright();
    Display();
    popright();
    popleft();
    Display();
}