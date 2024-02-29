#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void Display(struct Node *head){
    struct Node *ptr;
    ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main(){
    struct Node *head = NULL;
    int n,el;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&el);
        struct Node *newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = el;
        newNode->next = NULL;
        if(head==NULL){
            head = newNode;
        }
        else {
            struct Node *ptr;
            ptr = head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    Display(head);
    return 0;
}