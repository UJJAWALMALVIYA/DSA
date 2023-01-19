#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int size;
    int top;
    char *arr;
};
void push(struct node *sp,char item)
{
    if (isFull(sp))
    {
        printf("YOUR STACK IS OVERFLOW\n");
    }
    else{
        sp->top++;
        sp->arr[sp->top]=item;
    }
    
}
char pop(struct node *sp)
{
    if (isEmpty(sp))
    {
        printf("YOUR STACK IS UNDEFLOW \n");
    }
    else{
        char val;
        val=sp->arr[sp->top];
        sp->top--;
        return val;
    }
    
}
int stackTop(struct node* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct node *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int isFull(struct node *sp)
{
    if (sp->top == sp->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int precedence(char ch)
{
    if (ch=='*' || ch=='/')
    {
        return 2;
    }
     else if (ch=='+' || ch=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int isOperator(char op)
{
    if (op =='*' || op=='/' || op=='+' || op=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
char * infixtopost(char *infix)
{
    struct node *sp;
    sp=(struct node*)malloc(sizeof(struct node));
    sp->size=1000;
    sp->top=-1;
    int i=0;  //track infix traversal
    int j=0;   //track postfix traversal
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    char *postfix=(char *)malloc((strlen(infix)+1)* sizeof(char));
    while (infix[i] != '\0')
    {
        if (infix[i]=='(')
        {
            push(sp,infix[i]);
            i++;
        }
        else if(isOperator(infix[i])==1)
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
            
        }
        else if (infix[i]==')')
        {
            char  x=pop(sp);
            while (x !='(')
            {
                postfix[j]=x;
                j++;
                x=pop(sp);
            }
            i++;
        }
        else
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }

    }
    while (!isEmpty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char * infix;            // THIS IS FOR EVERY EXPRESSION
    printf("ENTER THE INFIX EXPPRESSION : ");   //FOR MEDIUM AND SMALL EXPRESSION
    scanf("%s",&infix);
    printf("YOUR POSTFIX EXPRESSION IS %s",infixtopost(infix));
    return 0;
}

















#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int size;
    int top;
    char *arr;
};
void push(struct node *sp,char item)
{
    sp->top++;
    sp->arr[sp->top]=item;
}
char pop(struct node *sp)
{
    char val;
    val=sp->arr[sp->top];
    sp->top--;
    return val;
    
}
int stackTop(struct node* sp){
    return sp->arr[sp->top];
}

int isEmpty(struct node *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int isFull(struct node *sp)
{
    if (sp->top == sp->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int precedence(char ch)
{
    if (ch=='*' || ch=='/')
    {
        return 2;
    }
     else if (ch=='+' || ch=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int isOperator(char op)
{
    if (op =='*' || op=='/' || op=='+' || op=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
char * infixtopost(char *infix)
{
    struct node *sp;
    sp=(struct node*)malloc(sizeof(struct node));
    sp->size=50;
    sp->top=-1;
    int i=0;  //track infix traversal
    int j=0;   //track postfix traversal
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    char *postfix=malloc((strlen(infix)+1) * sizeof(char));
    while (infix[i] != '\0')
    {
        if(infix[i]=='('){
            push(sp, infix[i]);
            i++;
        }
        else if(isOperator(infix[i])){
            // printf("%c\n", infix[i]);
            if(!isEmpty(sp) && precedence(infix[i])<=precedence(stackTop(sp))){
                
                char c=pop(sp);
                while(precedence(c)>=precedence(infix[i])){
                    postfix[j++]=c;
                    if(isEmpty(sp)) break;
                    c=pop(sp);
                    if(c=='('){
                        push(sp, c);
                        break;
                    }
                }
                push(sp, infix[i]);
                i++;

            }
            else{
                push(sp, infix[i]);
                i++;
            }
        }
        else if(infix[i]==')'){
            char x=pop(sp);
            while(isEmpty(sp)==0 && x!='('){
                postfix[j]=x;
                j++;
                x=pop(sp);
            }
            i++;
        }
        else{
            postfix[j++]=infix[i++];
        }
    }
    while(!isEmpty(sp)){
        postfix[j++]=pop(sp);
    }
    postfix[j]='\0';
    return postfix;
}

int main(){
    char infix[50];     //(a*b+d)/e-f*(g+h/k)
    printf("ENTER THE INFIX EXPPRESSION : ");
    gets(infix);
    printf("YOUR POSTFIX EXPRESSION IS %s",infixtopost(infix));
    return 0;
}