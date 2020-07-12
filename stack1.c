/*Impln of stack using arrays
*/

#include<stdio.h>
#include<unistd.h>
#define MAX 5

struct stack
{
int data[MAX];
int top;
};

void initialize(struct stack *s)
{
s->top=-1;
}

int isEmpty(struct stack *s)
{
if(s->top==-1)			// return s->top==-1?1:0;
	return 1;
else
	return 0;
}

int isFull(struct stack *s)
{
if(s->top==MAX-1)
	return 1;
else
	return 0;
}

int push(struct stack *s,int d)
{
if(isFull(s))
	return 0;
else
{
s->top++;
s->data[s->top]=d;
return 1;	
}
}


void pop(struct stack *s)
{
if(s->top==-1)
printf("\n\tStack Underflows->");
else
{
int d;
d=s->data[s->top];
s->top--;		//d=s->data[s->top--];
printf("\nPopped Data is %d",d);
//return s->data[s->top--];
}
}

void peek(struct stack *s)
{
if(s->top==-1)
printf("\n\tStack Underflows->");
else
{
int d;
d=s->data[s->top];
//s->top--;		//d=s->data[s->top--];
printf("\nData at peek is %d",d);
//return s->data[s->top--];
}
}

void display(struct stack *s)
{
int i;
if(s->top==-1)
printf("\n\tStack is Empty->");
else
{
printf("\nStack Contents ->->\n");
for(i=s->top;i>=0;i--)
{
printf("%d\n",s->data[i]);
}
}
}

int main()
{
int ch,d;
struct stack s;
//s->top=-1;
initialize(&s);
while(1)
{
printf("\n\t\t\tMENU\n1. Push.\n2. Pop.\n3. Peek.");
printf("\n4. Display.\n5. Exit.");
printf("\n\tEnter your choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter Data to be Pushed : ");
scanf("%d",&d);
if(push(&s,d))
printf("\nPushed successfully");
else
printf("\nCannot Push..");
break;
case 2:
pop(&s);
break;
case 3:
peek(&s);
break;
case 4:
display(&s);
break;
case 5:
exit(0);
default:
printf("\n\tPlease enter correct choice->->->->");
}
}
}

