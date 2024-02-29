#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* Create(struct Node *start){
    struct Node *last;
    int n, el;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &el);
        struct Node *new_node;
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = el;
        if (start==NULL){
            start = new_node;
            new_node->next = new_node;
            last = new_node;
        } else{
            last->next = new_node;
            new_node->next = start;
            last = new_node;
        }
    }
    return start;
}

void Display(struct Node *start){
    struct Node *ptr;
    ptr = start;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr!=start);
}

void Append(struct Node *head, int val){
    struct Node *ptr, *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    ptr = head;
    while (ptr->next!=head){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
}

int Length(struct Node *head){
    int cnt = 0;
    struct Node *ptr = head;
    do {
        cnt += 1;
        ptr = ptr->next;
    } while (ptr!=head);
    return cnt;
}

void Insert(int val, int pos){
    if (pos<0 || pos>Length(head)){
        return;
    }
    struct Node *newNode, *ptr;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    if(pos==0){
        if (head==NULL){
            head = newNode;
            head->next = head;
        } else{
            ptr = head;
            while (ptr->next!=head)
                ptr = ptr->next;
            ptr->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    } else {
        ptr = head;
        for (int i=0;i<pos-1;i++){
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void Delete(int pos){
    struct Node *ptr,*ptr2;
    if (pos==0){
        ptr = head;
        while (ptr->next!=head) ptr=ptr->next;
        ptr->next =head->next;
        free(head);
        head = ptr->next;
    } else{
        ptr = head;
        for(int i=0;i<pos-1;i++){
            ptr = ptr->next;
        }
        ptr2 = ptr->next;
        ptr->next = ptr2->next;
        free(ptr2);
    }
}

int main(){
    head = Create(head);
    // Append(head,4);
    // Insert(0,0);
    Delete(2);
    Display(head);
}