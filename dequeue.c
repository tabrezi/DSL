/*Impln of Double Ended Queue using arrays
*/

#include<stdio.h>
#include<unistd.h>
#define MAX 5

struct Queue
{
int data[MAX];
int front,rear;
};

void insertAtEnd(struct Queue *q,int d)
{
int i;
if(q->rear==MAX-1 && q->front==0)
printf("\n\tQueue is Full->");
else
{
if(q->rear<MAX-1)
q->rear++;
else
{	//making room for new element, left shifting queue by one element
for(i=q->front-1;i<q->rear;i++)
q->data[i]=q->data[i+1];
q->front--;
}
q->data[q->rear]=d;
if(q->front==-1)
q->front=0;	
}
}


void insertAtBeg(struct Queue *q,int d)
{
int i;
if(q->rear==MAX-1 && q->front==0)
printf("\n\tQueue is Full->");
else
{
if(q->front>0)
q->front--;
else
{	//making room for new element, right shifting queue by one element
if(q->front==-1)
q->front=q->rear=0;
else
{
for(i=q->rear+1;i>q->front;i--)
q->data[i]=q->data[i-1];
q->rear++;
}
}
q->data[q->front]=d;
}
}



void display(struct Queue *q)
{
int i;
if(q->rear==-1)
printf("\n\tQueue is Empty->");
else
{
printf("\nQueue Contents ->->\n");
for(i=q->front;i<=q->rear;i++)
{
printf("%d\n",q->data[i]);
}
}
}

void initialize(struct Queue *q)
{
q->front=q->rear=-1;
}

void deleteAtBeg(struct Queue *q)
{
if(q->rear==-1)
printf("\nQueue is empty..");
else
{
int d;
d=q->data[q->front];
q->front++;
if(q->front>q->rear)
q->front=q->rear=-1;
printf("\nElement %d deleted from Queue.",d);
}
}


void deleteAtEnd(struct Queue *q)
{
if(q->rear==-1)
printf("\nQueue is empty..");
else
{
int d;
d=q->data[q->rear];
q->rear--;
if(q->front>q->rear)
q->front=q->rear=-1;
printf("\nElement %d deleted from Queue.",d);
}
}

int main()
{
int ch,d;
struct Queue q;
initialize(&q);
while(1)
{
printf("\n\t\t\tMENU\n1. Insert At End.\n2. Delete At Begining.\n3. Insert At Begining.");
printf("\n4. Delete At End.\n5. Display.\n6. Exit");
printf("\n\tEnter your choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter Data to be Inserted : ");
scanf("%d",&d);
insertAtEnd(&q,d);
break;
case 2:
deleteAtBeg(&q);
break;
case 3:
printf("\nEnter Data to be Inserted : ");
scanf("%d",&d);
insertAtBeg(&q,d);
break;
case 4:
deleteAtEnd(&q);
break;
case 5:
display(&q);
break;
case 6:
exit(0);
default:
printf("\n\tPlease enter correct choice->->->->");
}
}
}

