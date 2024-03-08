#include "stdio.h"
#include "stdlib.h"

struct CircularQueue{
    int size;
    int front;
    int rear;
    int *Q;
};

void Create(struct CircularQueue *q, int size){
    q->size = size+1;
    q->front=q->rear=0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void Display(struct CircularQueue q){
    int i = q.front;
    do{
        i = (i+1)%q.size;
        printf("%d ", q.Q[i]);
    } while (i!=q.rear);
}

void Enqueue(struct CircularQueue *q, int val){
    if ((q->rear+1)%q->size==q->front)
        printf("Queue is full!\n");
    else{
        q->rear = (q->rear+1)%q->size;
        q->Q[q->rear] = val;
    }
}

int Dequeue(struct CircularQueue *q){
    int x = -1;
    if (q->front==q->rear)
        printf("Queue is empty!\n");
    else{
        q->front = (q->front+1)%q->size;
        x = q->front;
    }
    return x;
}

int main(){
    struct CircularQueue q;
    Create(&q,5);
    Enqueue(&q,1);
    Enqueue(&q,2);
    Enqueue(&q,3);
    Enqueue(&q,4);
    Enqueue(&q,5);
    Dequeue(&q);
    Dequeue(&q);
    Enqueue(&q,6);
    Enqueue(&q,7);
    Dequeue(&q);
    Display(q);
    return 0;
}