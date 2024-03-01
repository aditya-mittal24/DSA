#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Stack{
    int size;
    int top;
    char *s;
};

void push(struct Stack *st, char val){
    st->top++;
    st->s[st->top] = val;
}

int isEmpty(struct Stack st){
    return st.top==-1;
}

void pop(struct Stack *st){
    st->top--;
}

int isBalanced(char *exp){
    struct Stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.s = (char *)malloc(st.size * sizeof(char));
    for (int i=0;exp[i]!='\0';i++){
        if (exp[i]=='(') push(&st, exp[i]);
        else if (exp[i]==')'){
            if (isEmpty(st)) return 0;
            else pop(&st);
        }
    }
    return isEmpty(st);
}

int main(){
    char *exp = "((a+b)*(c-d)))";
    printf("%d",isBalanced(exp));
}