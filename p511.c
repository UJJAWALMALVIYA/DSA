#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<windows.h>
// structure containing a data part and link part

struct node
{
    int data;
    struct node *link;
};

void append (struct node **,int);
void addatbeg(struct node **,int);
void addafter (struct node *,int ,int);
void display (struct node *);
int count (struct node *);
void del (struct node **,int);

int main()
{
    struct node *p;
    p=NULL; /*empty linked list*/
    printf("no of element in linked list=%d\n",count(p));
    append (&p,14);
    append (&p,30);
    append (&p,25);
    append (&p,42);
    append (&p,17);

    system ("cls"); 

    display (p);

    addatbeg (&p,999);
    addatbeg (&p,888);
    addatbeg (&p,777);

    display (p);
    
    addafter(p,7,0);
    addafter(p,2,1);
    addafter(p,5,99);

    diaplay (p);
    printf("no of element in linked list =%d\n",count(p));

    del(&p,99);
    del(&p,1);
    del(&p,10);

    display (p);
    printf("no of element in linked list=%d\n",count(p));
    return 0;

}

/*adds a node at the end of the linked list*/
void append (struct node **q,int num)
{
    struct node *tmp,*r;
    if (*q == NULL) /*if the list is empty,create a first node*/
    {
        tmp=(struct node *)malloc (sizeof (struct node));
        tmp->data=num;
        tmp->link=NULL;
        *q=tmp;    }
    else{           /*when list have some value */
        tmp =*q;
         while (tmp->link != NULL) /*go to last node*/
            tmp=tmp->link;

        r = (struct node *)malloc (sizeof (struct node));   /*add node at the end*/
        r->data =num;
        r->link=NULL;
        tmp->link=r;
    }
    
}
/*adds a new node at the begining of the linked list*/
void addatbeg(struct node **q,int num)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof (struct node));
    tmp->data=num;
    tmp->link=*q;
    *q=tmp;
}
/*adds a new node after the specified number of nodes */
void addafter(struct node *q,int loc,int num)
{
    struct node *tmp,*r;
    int i;
    tmp=q;
    for ( i = 0; i < loc; i++) /*skip to desired position*/
    {
        tmp=tmp->link;
        if (tmp==NULL)  /**if end of list is encountered */
        {
            printf("there is lesser than %d element inlist \n",loc);
            return;
        }
        
    }
    /*insert new code*/
    r=(struct node *)malloc (sizeof(struct node));
    r->data=num;
    r->link=tmp->link;
    tmp->link=r;
    
}

/*display the content of linked list*/
void display(struct node *q)
{
    while (q!=NULL)
    {
        printf("%d, ",q->data);
        q=q->link;
    }
    printf("\n");
    
}
/*counts the number of nodes present in linked list */
int count(struct node *q)
{
    int c=0;
    while (q!=NULL) /*traverse the entire linked list*/
    {
        q=q-> link;
        c++;
    }
    return c;
    
}
/*deletes the specified node from the linked list*/
void del(struct node **q,int num)
{
    struct node *old , *tmp;
    tmp=*q;  
    while (tmp!=NULL)
    {
        if(tmp ->data ==num)
        {
            if (tmp==*q) /*if nodes to be deleted is the first node in the list*/
            {
               *q=tmp->link;
            }
            
            else  /*deletes the intermediate nodes in the list*/
            old->link=tmp->link;

            free(tmp); /*free the memory occupied by the nodes */
            return;
        }
        else
        {
            old=tmp; /*old poiints to the previous node*/
            tmp =tmp->link;  /*go to the next node*/

        }
        
    }
    printf("element %d not found\n",num);
    
}
