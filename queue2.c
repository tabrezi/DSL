/*Impln of Queue using LL
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct SLL
{
int data;
struct SLL *next;
};

struct Queue
{
struct SLL *front;
struct SLL *rear;
};


struct Queue *insert(struct Queue *q,int d)
{
struct SLL *p;
p=(struct SLL *)malloc(sizeof(struct SLL));
if(p==NULL)
printf("\n\tQueue is Full->");
else
{
p->data=d;
p->next=NULL;
if(q->front==NULL)
q->front=p;
if(q->rear!=NULL)
q->rear->next=p;
q->rear=p;
return q;
}
}

void display(struct Queue *q)
{
if(q->rear==NULL || q->front==NULL)
printf("\n\tQueue is Empty->");
else
{
struct SLL *tmp;
printf("\nQueue Contents ->->\n");
for(tmp=q->front;tmp!=NULL;tmp=tmp->next)
{
printf("%d\n",tmp->data);
}
}
}

struct Queue *delete(struct Queue *q)
{
struct SLL *tmp;
if(q->rear==NULL || q->front==NULL)
printf("\n\tQueue is Empty->");
else
{
printf("\nDeleted Element is %d",q->front->data);
tmp=q->front;
q->front=q->front->next;
if(q->front==NULL)
q->rear=NULL;
tmp->next=NULL;
free(tmp);
}
return q;
}


struct SLL *search(struct Queue *q,int key)
{
struct SLL *tmp;
if(q->rear==NULL || q->front==NULL)
printf("\n\tQueue is Empty->");
else
{
tmp=q->front;
while(tmp!=NULL && tmp->data!=key)
tmp=tmp->next;
return tmp;
}
}


int main()
{
int ch,d;
struct Queue *q;
struct SLL *k;
//initialize(&q);
q=(struct Queue *)malloc(sizeof(struct Queue));
q->front=q->rear=NULL;
while(1)
{
printf("\n\t\t\tMENU\n1. Insert.\n2. Delete.\n3. Search.");
printf("\n4. Display.\n5. Exit.");
printf("\n\tEnter your choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter Data to be Inserted : ");
scanf("%d",&d);
q=insert(q,d);
break;
case 2:
q=delete(q);
break;
case 3:
printf("\nEnter Data to be Searched : ");
scanf("%d",&d);
k=search(q,d);
if(k==NULL)
printf("\nKey is not found..");
else
printf("\nKey is found having value %d..",k->data);
break;
case 4:
display(q);
break;
case 5:
exit(0);
default:
printf("\n\tPlease enter correct choice->->->->");
}
}
}

