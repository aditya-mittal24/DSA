#include "stdio.h"
#include "stdlib.h"

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void Create() {
    int n,el;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    struct Node *ptr, *newNode, *last;
    for(int i=0;i<n;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &el);
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = el;
        if (head==NULL) {
            head = newNode;
            head->prev = head;
            head->next = head;
            last = head;
        } else {
            last->next = newNode;
            newNode->prev = last;
            newNode->next = head;
            head->prev = newNode;
            last = newNode;
        }
    }
}

void Display(struct Node *start){
    struct Node *ptr;
    ptr = start;
    do {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } while (ptr!=start);
}

int Length(struct Node *start){
    struct Node *ptr;
    int len=0;
    ptr = head;
    do {
        len += 1;
        ptr = ptr->next;
    } while (ptr!=head);
    return len;
}

void Append(int val){
    struct Node *newNode, *ptr;
    ptr = head;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    while (ptr->next != head) ptr = ptr->next;
    ptr->next = newNode;
    newNode->prev = ptr;
    newNode->next = head;
    head->prev = newNode;
}

void Insert(int val, int pos){
    if (pos<0 || pos>Length(head)) return;
    struct Node *newNode, *ptr;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    if (pos==0) {
        head->prev->next = newNode;
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else{
        ptr = head;
        for (int i=0;i<pos-1;i++) ptr = ptr->next;
        newNode->next = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
        if (newNode->next) newNode->next->prev = newNode;
    }
}

int Delete(int pos){
    
}


int main(){
    Create();
    printf("Length of the string: %d\n", Length(head));
    Insert(4,3);
    Display(head);
    return 0;
}