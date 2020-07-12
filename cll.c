/*	Implementation of CLL
		Description of Program.
				Learner:
					 
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
struct CLL		/* Global structure to create a node*/
{
int data;
struct CLL *next;
};

struct CLL *insertAtEnd(struct CLL *h,int d)
{
struct CLL *p,*tmp;
p=(struct CLL *)malloc(sizeof(struct CLL)); //creating a new node
p->data=d;	//putting data into new node
//p->next=h;	//making new node point to null
if(h==NULL)	// LL is empty
h=p;
else
{	//LL is not empty
tmp=h;
while(tmp->next!=h)	//to traverse to the last node
tmp=tmp->next;
tmp->next=p;
}
p->next=h;
return h;
}

struct CLL *insertAtStart(struct CLL *h,int d)
{
struct CLL *p,*tmp,*p1;
p=(struct CLL *)malloc(sizeof(struct CLL)); //creating a new node
p->data=d;	//putting data into new node
if(h!=NULL)
p->next=h;	//making new node point to null
else
{
p->next=p;
h=p;
}
//
p1=h;
while(p1->next!=h)
p1=p1->next;
p1->next=p;
//
h=p;

return h;
}


struct CLL *removelast(struct CLL *h)
{
struct CLL *tmp,*prev;
tmp=h;
if(h!=NULL)
{
if(h->next!=h)
{
prev=tmp;
while(tmp->next!=h)
{
prev=tmp;
tmp=tmp->next;
}
prev->next=h;
}
else
h=NULL;
free(tmp);
}
else
printf("\nLL is empty.");
return h;
}



void display(struct CLL *h)
{
struct CLL *tmp;
tmp=h;
//modify to empty list
if(h!=NULL)
{
printf("\n\n\t\tLinked List Contents..\n");
do
{
printf("\t%d\n",tmp->data);
tmp=tmp->next;
}while(tmp!=h);
}
else
printf("\nLL is empty.");
}

struct CLL *reverse(struct CLL *h)
{
struct CLL *tmp,*p,*rev,*tmp1;
int cnt,i,j;
rev=NULL;
cnt=0;tmp=h;
do
{
cnt++;
tmp=tmp->next;
}while(tmp!=h);
for(i=cnt;i>0;i--)
{
for(tmp=h,j=0;j!=i-1;tmp=tmp->next,j++);
p=(struct CLL *)malloc(sizeof(struct CLL));
p->data=tmp->data;
if(rev==NULL)
rev=p;
else
{
tmp1=rev;
while(tmp1->next!=rev)
tmp1=tmp1->next;
tmp1->next=p;
}
p->next=rev;
}
return rev;
}

struct CLL *reverse1(struct CLL *h)
{
struct CLL *p,*tmp,*rev=NULL,*tmp1;
tmp=h;
do
{
p=(struct CLL *)malloc(sizeof(struct CLL));
p->data=tmp->data;
if(rev==NULL)
p->next=p;
else
{
p->next=rev;
tmp1=rev;
while(tmp1->next!=rev)
tmp1=tmp1->next;
tmp1->next=p;
}
rev=p;
tmp=tmp->next;
}while(tmp!=h);
return rev;
}

struct CLL *reverse2(struct CLL *h)
{
struct CLL *p,*tmp,*rev=NULL,*tmp1,*addl;
tmp=h;
do
{
p=(struct CLL *)malloc(sizeof(struct CLL));
p->data=tmp->data;
if(rev==NULL)
{
p->next=p;
addl=p;
}
else
p->next=rev;
rev=p;
tmp=tmp->next;
}while(tmp!=h);
addl->next=rev;
return rev;
}

int main()
{
struct CLL *head,*head1;
int ch,d;
head=head1=NULL;
while(1)
{
printf("\n\n\n\t\t\tMENU");
printf("\n1. Insert.\n2. Remove.\n3. Reverse.\n4. Display.\n5. Exit.");
printf("\n\tEnter Your Choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n\tEnter Data : ");
scanf("%d",&d);
head=insertAtStart(head,d);
break;
case 2:
head=removelast(head);
break;
case 3:
//printf("\n\tEnter Key : ");
//scanf("%d",&d);
head1=reverse2(head);
break;
case 4:
display(head);
//display(head1);
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

