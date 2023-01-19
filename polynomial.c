#include<stdio.h>
#include<stdlib.h>
struct node{
    float coeff;
    int exp;
    struct node *link;
};
void append(struct node **,float,int);
void displax(struct node*);
void add(struct node*,struct node*,struct node **);
int main()
{
    struct node *coeff,*exp;
    int u,p,total;
    p=u=total=NULL;
    append(&p,5,4);
    append(&p,7,3);
    append(&p,8,2);
    append(&p,5,1);

    display(p);
    
    append(&u,7,4);
    append(&u,5,3);
    append(&u,9,2);
    append(&u,5,1);

    display (u);

    add (p,u,&total);
    display(total);

}
void append(struct node **q,float x,int y)
{
    struct node *temp;
    if (*q==NULL)
    {
        *q=(struct node*)malloc(sizeof(struct node));
        temp=*q;
    }
    else{
        while (temp->link != NULL)
        {
            temp=temp->link;
        }
        temp->link=(struct node*)malloc(sizeof(struct node));
        temp=temp->link;
        
    }
    temp->coeff=x;
    temp->exp=y;
    temp->link=NULL;

}
void display(struct node *q)
{
    while ( q != NULL)
    {
        printf("%.1fx^%d + ",q->coeff,q->exp);
        q=q->link;
    }
    printf("\n");
    
}
void add(struct node *x,struct node*y,struct node**s)
{
    struct node *z;
    if (x==NULL && y==NULL)
    {
        return;
    }
    while (x!=NULL && y!= NULL)
    {
        if (*s==NULL)
        {
            *s=(struct node*)malloc(sizeof(struct node));
            z=*s;
        }
        else{
            z->link=malloc(sizeof(struct node));
            z=z->link;
        }
        
        if (x->exp<y->exp)
        {
            z->coeff=y->coeff;
            z->exp=y->exp;
            y=y->link;
        }
        else if(x->exp>y->exp)
        {
            z->coeff=x->coeff;
            z->exp=x->exp;
            x=x->link;

        }
        else if (x->exp==y->exp)
        {
            z->coeff=x->coeff+y->coeff;
            z->exp=x->exp;
            x=x->link;
            y=y->link;
        }
        
        
    }
    
}


// #include<stdio.h>
// main()
// {
//     int t;
//     scanf("%d",&t);
//     while(t--)
// 	{
// 	    int a;
// 	    char str[100],x[100],y[100];
//     	scanf("%d",&a);
//     	scanf("%s",&str);
//     	x = str.substr(0,a/2);
//     	y = str.substr(a/2,a);
    	
//     	if(x==y){
//     	    printf("YES\n");
//     	}
//     	else{
//     	    printf("NO\n");
//     	}
    	
// 	}
// }