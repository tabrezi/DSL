/*	Implementation of stack using Linked List
		Description of Program.
				Learner:
					 
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct stack		/* Global structure to create a node*/
{
int data;
struct stack *next;
};

struct stack *push(struct stack *h,int d)
{
struct stack *p,*tmp;
p=(struct stack *)malloc(sizeof(struct stack)); //creating a new node
if(p==NULL)
printf("\n\tStack Overflows.");
else
{
p->data=d;	//putting data into new node
p->next=h;	//making new node point to null
h=p;
}
return h;
}


struct stack *pop(struct stack *h)
{
struct stack *tmp;
if(h!=NULL)
{
tmp=h;
h=h->next;
tmp->next=NULL;
printf("\n\tPopped Data is %d",tmp->data);
free(tmp);
}
else
printf("\n\tStack Underflows.");
return h;
}


void display(struct stack *h)
{
struct stack *tmp;
tmp=h;
if(h!=NULL)
{
printf("\n\n\t\tStack Contents..\n");
while(tmp!=NULL)
{
printf("\t%d\n",tmp->data);
tmp=tmp->next;
}
}
else
printf("\nStack is empty.");
}

int main()
{
struct stack *top;
int ch,d;
top=NULL;
while(1)
{
printf("\n\n\n\t\t\tMENU");
printf("\n1. Push.\n2. Pop.\n3. D‬isplay.\n4. Unlimited Push. (Really Unlimited ?) \n5. Exit.");
printf("\n\tEnter Your Choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n\tEnter Data : ");
scanf("%d",&d);
top=push(top,d);
break;
case 2:
top=pop(top);
break;
case 3:
display(top);
break;
case 4:
while(1)
{
top=push(top,10);
}
break;
case 5:
//main();
exit(0);
break;
default:
printf("\n\t\tPlease enter correct choice....");
}
}
return 0;
}

