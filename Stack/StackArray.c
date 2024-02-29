#include "stdio.h"
#include "stdlib.h"

struct Stack
{
    int size;
    int top;
    int *s;
};

void Create(struct Stack* st){
    printf("Enter the size of the stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st){
    for (int i=st.top;i>=0;i--){
        printf("%d ", st.s[i]);
    }
}

void Push(struct Stack *st, int val)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow!");
    else
    {
        st->top++;
        st->s[st->top] = val;
    }
}

int Pop(struct Stack *st){
    int el = -1;
    if (st->top==-1)
        printf("Stack Underflow!");
    else{
        el = st->s[st->top];
        st->top--;
    }
    return el;
}

int Peak(struct Stack st, int pos){
    int x=-1;
    if (st.top<pos)
        printf("Invalid Position\n");
    else{
        x = st.s[st.top-pos];
    }
    return x;
}

int isFull(struct Stack st){
    if(st.top+1==st.size)
        return 1;
    else
        return 0;
}

int isEmpty(struct Stack st){
    if (st.top==-1)
        return 1;
    else
        return 0;
}

int stackTop(struct Stack st) {
    if (st.top==-1)
        return -1;
    else
        return st.s[st.top];
}

int main()
{
    struct Stack st;
    Create(&st);
    printf("%d\n", isEmpty(st));
    Push(&st, 1);
    Push(&st, 2);
    printf("%d\n", Peak(st,0));
    printf("%d\n", stackTop(st));
    Push(&st, 3);
    Push(&st, 4);
    printf("%d\n", isFull(st));
    Display(st);
}