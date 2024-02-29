#include "stdio.h"
#include "stdlib.h"

struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};

struct Node *head = NULL;

void Create(){
    int n, el;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    struct Node *ptr, *newNode, *last;
    for(int i=0;i<n;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &el);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = el;
        newNode->next = NULL;
        if (head==NULL){
            newNode->prev = NULL;
            head = newNode;
            last = head;
        } else{
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }
}

void Display(){
    struct Node *ptr;
    ptr = head;
    while (ptr){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int Length(struct Node *head){
    struct Node *ptr;
    ptr = head;
    int len = 0;
    while (ptr){
        len += 1;
        ptr = ptr->next;
    }
    return len;
}

void Append(int val){
    struct Node *ptr, *newNode;
    ptr = head;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    while (ptr->next!=NULL)
        ptr = ptr->next;
    newNode->prev = ptr;
    ptr->next = newNode;
}

void Insert(int val, int pos){
    if (pos<0 || pos>(Length(head))){
        return;
    }
    struct Node *newNode, *ptr;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    if (pos==0) {
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        ptr = head;
        for(int i=0;i<pos-1;i++){
            ptr = ptr->next;
        }
        newNode->prev = ptr;
        newNode->next = ptr->next;
        if (newNode->next) newNode->next->prev = newNode;
        ptr->next = newNode;
    }
}

int Delete(int pos){
    if (pos<0 || pos>Length(head))
        return -1;
    struct Node *ptr; 
    int x;
    if (pos==0) {
        ptr = head;
        head = head->next;
        if (head) head->prev = NULL;
        x = ptr->data;
        free(ptr);
    } else {
        ptr = head;
        for (int i=0;i<pos;i++) ptr = ptr->next;
        ptr->prev->next = ptr->next;
        if (ptr->next) ptr->next->prev = ptr->prev;
        x = ptr->data;
        free(ptr);
    }
    return x;
}

void ReverseDisplay(struct Node *ptr){
    if (ptr==NULL)
        return;
    ReverseDisplay(ptr->next);
    printf("%d ", ptr->data);
}

void Reverse(){
    struct Node *ptr, *temp;
    ptr = head;
    while (ptr) {
        temp = ptr->next;
        ptr->next = ptr->prev;
        ptr->prev = temp;
        if (temp==NULL) head = ptr;
        ptr = temp;
    }
}

int main(){
    Create();
    // Insert(4,3);
    // Delete(3);
    Reverse();
    Display();
    // printf("\nLength of the string: %d", Length(head));
    return 0;
}