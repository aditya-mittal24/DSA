#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop(){
    int x = -1;
    if (top==NULL)
        printf("Stack underflow!\n");
    else{
        x = top->data;
        top = top->next;
    }
    return x;
}

int isOperand(char x){
    if (x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;
}

int Evaluate(char *postfix){
    int x,temp;
    for(int i=0;postfix[i]!='\0';i++){
        if (isOperand(postfix[i])){
            push(postfix[i]-'0');
        }
        else {
            if (postfix[i]=='+'){
                x = pop() + pop();}
            else if (postfix[i]=='-'){
                temp = pop();
                x = pop() - temp;
            } else if(postfix[i]=='*'){
                x = pop() * pop();
            } else if(postfix[i]=='/'){
                temp = pop();
                x = pop() / temp;
            }
            push(x);
        }
    }
    return top->data;
}

int main(){
    char *postfix = "234*+82/-";
    printf("%d", Evaluate(postfix));
    return 0;
}