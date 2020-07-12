/*	Implementation of SLL
		Description of Program.
				Learner:
					 
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
struct SLL	/* Global structure to create a node*/
{
int data;
struct SLL *next;
};

struct SLL *insertAtEnd(struct SLL *h,int d)
{
struct SLL *p,*tmp;
p=(struct SLL *)malloc(sizeof(struct SLL)); //creating a new node
if(p==NULL)
{
printf("\nNot enough memory to allocate.");
return h;
}
p->data=d;	//putting data into new node
p->next=NULL;	//making new node point to null
if(h==NULL)	// LL is empty
h=p;
else
{	//LL is not empty
tmp=h;
while(tmp->next!=NULL)	//to traverse to the last node
tmp=tmp->next;
tmp->next=p;
}
return h;
}


struct SLL *insertAtStart(struct SLL *h,int d)
{
struct SLL *p,*tmp;
p=(struct SLL *)malloc(sizeof(struct SLL)); //creating a new node
p->data=d;	//putting data into new node
p->next=h;	//making new node point to null
h=p;
return h;
}

struct SLL *insertAfter(struct SLL *h,int key,int d)
{
struct SLL *p,*tmp;
p=(struct SLL *)malloc(sizeof(struct SLL)); //creating a new node
p->data=d;	//putting data into new node
p->next=NULL;	//making new node point to null
if(h==NULL)
{	// LL is empty
h=p;
}
else
{	//LL is not empty
tmp=h;
while(tmp!=NULL && tmp->data!=key )	//to traverse to the last node
tmp=tmp->next;
if(tmp!=NULL)
{
p->next=tmp->next;
tmp->next=p;
}
else
{
printf("\n\tGiven Node %d does not exist in the Linked List.",key);
free(p);
}
}
return h;
}

struct SLL *removelast(struct SLL *h)
{
struct SLL *tmp,*prev;
tmp=h;
if(h!=NULL)
{
if(h->next!=NULL)
{
while(tmp->next!=NULL)
{
prev=tmp;
tmp=tmp->next;
}
prev->next=NULL;
}
else
h=NULL;
free(tmp);
}
else
printf("\nLL is empty.");
return h;
}


struct SLL *removefirst(struct SLL *h)
{
struct SLL *tmp;
tmp=h;
if(h!=NULL)
{
h=h->next;
free(tmp);
}
else
printf("\nLL is empty.");
return h;
}



struct SLL *removeAfter(struct SLL *h,int key)
{
struct SLL *tmp,*p;
tmp=h;
if(h!=NULL)
{
while(tmp!=NULL && tmp->data!=key)
tmp=tmp->next;
if(tmp!=NULL)
{
if(tmp->next!=NULL)
{
p=tmp->next;
tmp->next=p->next;
p->next=NULL;
free(p);
}
else
printf("\nGiven Node is the last Node.");
}
else
printf("\nGiven key does not exist.");
//printf("\ntmp->data=%d",tmp->dmpata);
//printf("\nprev->data=%d",prev->data);
}
else
printf("\nLL is empty.");
return h;
}




void display(struct SLL *h)
{
struct SLL *tmp;
tmp=h;
//modify to empty list
if(h!=NULL)
{
printf("\n\n\t\tLinked List Contents..\n");
while(tmp!=NULL)
{
printf("\t%d\n",tmp->data);
tmp=tmp->next;
}
}
else
{
printf("\nLL is empty.");
}
}




int main()
{
struct SLL *head;
int ch,d,k;
head=NULL;
while(1)
{
printf("\n\n\n\t\t\tMENU");
printf("\n1. Insert.\n2. Insert After.\n3. Remove.\n4. Remove After.\n5. Display.\n6. Exit.");
printf("\n\tEnter Your Choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n\tEnter Data : ");
scanf("%d",&d);
head=insertAtEnd(head,d);
break;
case 2:
printf("\n\tEnter Data : ");
scanf("%d",&d);
printf("\n\tEnter Key Data : ");
scanf("%d",&k);

head=insertAfter(head,k,d);
break;

case 3:
//head=removelast(head);
head=removefirst(head);
break;
case 4:
printf("\n\tEnter Key : ");
scanf("%d",&d);
head=removeAfter(head,d);
break;
case 5:
display(head);
break;
case 6:
//exit(0);
return 0;
break;
default:
printf("\n\t\tPlease enter correct choice....");
}
}
return 0;
}

