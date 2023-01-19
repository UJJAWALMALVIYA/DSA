#include <stdio.h>
#include <stdlib.h>
#define MAX 70
struct node
{
    int top;
    int arr[MAX];
};
int top = -1;
int main()
{
    int i;
    struct node *s;
    push(&s, 5);
    push(&s, 4);
    push(&s, 6);
    push(&s, 3);
    push(&s, 9);

    i = pop(&s);
    return 0;
}
void push(struct node *s, int item)
{
    if (s->top == MAX - 1)
    {
        printf("YOUR STACK IS ALREADY FULL\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = item;
        printf("%d\n", item);
    }
}
int pop(struct node *s)
{
    if (s->top == -1)
    {
        printf("YOUR STACK IS EMPTY\n");
    }
    else
    {
        int value;
        value = s->arr[s->top];
        printf("YOUR POPPED VALUE IS %d\n",value);
        s->top--;
        return value;
    }
}
