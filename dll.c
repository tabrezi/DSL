/*	Implementation of DLL
		Description of Program.
				Learner:
					 
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

struct DLL		/* Global structure to create a node*/
{
int data;
struct DLL *next,*prev;
};

struct DLL *insertAtEnd(struct DLL *h,int d)
{
struct DLL *p,*tmp;
p=(struct DLL *)malloc(sizeof(struct DLL)); //creating a new node
p->data=d;	//putting data into new node
p->next=NULL;	//making new node point to null
p->prev=NULL;	//Added for DLL
if(h==NULL)
{	// LL is empty
h=p;

}
else
{	//LL is not empty
tmp=h;
while(tmp->next!=NULL)	//to traverse to the last node
tmp=tmp->next;
tmp->next=p;
p->prev=tmp;	//Added for DLL
}
return h;
}


struct DLL *insertAtStart(struct DLL *h,int d)
{
struct DLL *p,*tmp;
p=(struct DLL *)malloc(sizeof(struct DLL)); //creating a new node
p->data=d;	//putting data into new node
p->next=h;
p->prev=NULL;
if(h!=NULL)
h->prev=p;

h=p;
return h;
}


struct DLL *insertAfter(struct DLL *h,int key,int d)
{
struct DLL *p,*tmp;
p=(struct DLL *)malloc(sizeof(struct DLL)); //creating a new node
p->data=d;	//putting data into new node
p->next=NULL;	//making new node point to null
p->prev=NULL;	//newly added statement
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
//tmp1=tmp->next;
p->next=tmp->next;
p->prev=tmp;		//Additional
if(tmp->next!=NULL)	//Additional
(tmp->next)->prev=p;	//Additional
tmp->next=p;
}
else
printf("\n\tGiven Node %d does not exist in the Linked List.",key);
}
return h;
}

struct DLL *removelast(struct DLL *h)
{
struct DLL *tmp;
tmp=h;
if(h!=NULL)
{
if(h->next!=NULL)
{
while(tmp->next!=NULL)
	tmp=tmp->next;	
//after while loop, tmp will point to last node.
(tmp->prev)->next=NULL;
}
else
h=NULL;
free(tmp);
}
else
printf("\nLL is empty.");
return h;
}


struct DLL *removeAfter(struct DLL *h,int key)
{
struct DLL *tmp,*p;
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
if(p->next!=NULL)	//Additional
(p->next)->prev=tmp;	//Additional
tmp->next=p->next;
p->next=NULL;
p->prev=NULL;		//Additional
free(p);
}
else
printf("\nGiven Node is the last Node.");
}
else
printf("\nGiven key does not exist.");
}
else
printf("\nLL is empty.");
return h;
}




void display(struct DLL *h)
{
struct DLL *tmp;
tmp=h;
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
printf("\nLL is empty.");
}


void displayRev(struct DLL *h)
{
struct DLL *tmp;
tmp=h;
if(h!=NULL)
{
printf("\n\n\t\tLinked List Contents in Reverse Order..\n");
while(tmp->next!=NULL)
tmp=tmp->next;
do
{
printf("\t%d\n",tmp->data);
tmp=tmp->prev;
}while(tmp!=NULL);
}
else
printf("\nLL is empty.");
}


int main()
{
struct DLL *head;
int ch,d,k;
head=NULL;
while(1)
{
printf("\n\n\n\t\t\tMENU");
printf("\n1. Insert.\n2. Remove.\n3. Remove After.\n4. Display.\n5. Exit.");
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
head=removelast(head);
break;
case 3:
printf("\n\tEnter Key : ");
scanf("%d",&k);
//printf("\n\tEnter Data : ");
//scanf("%d",&d);

head=removeAfter(head,k);
break;
case 4:
display(head);
displayRev(head);
break;
case 5:
//exit(0);
return 0;
break;
default:
printf("\n\t\tPlease enter correct choice....");
}
}
return 0;
}

