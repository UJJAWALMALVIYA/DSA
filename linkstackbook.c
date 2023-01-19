#include<stdio.h>
#include<stdlib.h>

#define MAX 10
struct node{
    int arr[MAX];
    int top;
};
void add(struct node *);
int pop(struct node *);
void push(struct node *,int);

int main(){
    struct node s;
    int i;

    add(&s);

    push(&s,7);
    push(&s,9);
    push(&s,2);
    push(&s,3);
    push(&s,8);


    i=pop(&s);
    if (i != -1)
    {
        printf("YOUR %d NUMBER IS STACKED OUT\n");
    }
    return 0;

}
void push(struct node *s,int item)
{
    if(s->top==MAX-1)
    {
        printf("STACK IS FULL\n");
        return ;
    }
    else{
        s->top++;
        s->arr[s->top]=item;
        printf("YOUR STACK IS %d\n",item);
    }
}

int pop(struct node *s)
{
    if (s->top==-1)
    {
        printf("stack is under flow\n");
        return NULL ;
    }
    else
    {
        int data;
        data =s->arr[s->top];
        s->top--;
        return data;
        
    }
    
}
void add(struct node *s)
{
    s->top=-1;
}