#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Node
{
    char data;
    struct Node *next;
};

struct Node *top = NULL;

void push(char x)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
        printf("Stack overflow!");
    else
    {
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }
}

char pop(){
    struct Node *ptr;
    ptr = top;
    char x;
    if (top==NULL)
        printf("Stack underflow");
    else{
        x = top->data;
        top = top->next;
        free(ptr);
    }
    return x;
}

int isEmpty(){
    return top==NULL;
}

char stackTop(){
    return top->data;
}

int isOperand(char x){
    if (x=='+'||x=='-'||x=='*'||x=='/')
        return 0;
    else
        return 1;
}

int pre(char x){
    if (x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    return 0;
}

char * InfixToPostfix(char *infix){
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len+1)*sizeof(char));
    int i=0,j=0;
    while (infix[i]!='\0'){
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (!top || pre(infix[i])>pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while (top!=NULL)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    char *postfix = InfixToPostfix(infix);
    printf("%s", postfix);
}