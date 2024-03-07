#include "stdio.h"
#include "stdlib.h"

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct Queue *q, int size){
    q->size = size;
    q->front =q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void Display(struct Queue q){
    for (int i=q.front+1;i<=q.rear;i++){
        printf("%d ", q.Q[i]);
    }
}

void Enqueue(struct Queue *q, int val){
    if (q->rear==q->size-1)
        printf("Queue is full\n");
    else{
        q->rear++;
        q->Q[q->rear] = val;
    }
}

int Dequeue(struct Queue *q){
    int x = -1;
    if (q->rear==q->front)
        printf("Queue is empty!\n");
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int main(){
    struct Queue q;
    Create(&q, 5);
    Enqueue(&q,1);
    Enqueue(&q,2);
    Enqueue(&q,3);
    Enqueue(&q,4);
    Enqueue(&q,5);
    Dequeue(&q);
    Dequeue(&q);
    Display(q);
    return 0;
}