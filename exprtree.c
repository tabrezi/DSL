/*Implementation of Expression tree using Postfix expression*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct bstree
{
char data;
struct bstree *left,*right;
}BST;

typedef struct stack
{
BST *d[MAX];
int top;
}STK;

void push(STK *s,BST *node)
{
if(s->top==MAX-1)
printf("\nStack Overflow.");
else
{
s->top++;
s->d[s->top]=node;
}
}

BST *pop(STK *s)
{
if(s->top==-1)
return NULL;
else
return s->d[s->top--];
}

BST *createTree(BST *root,char *postfix)
{
BST *p;
STK s;
int i;
char c;
s.top=-1;
for(i=0;postfix[i]!='\0';i++)
{
c=postfix[i];
p=(BST *)malloc(sizeof(BST));
p->data=c;
p->left=p->right=NULL;
switch(c)
{
case '+':
case '-':
case '/':
case '*':
case '%':
case '^':
p->right=pop(&s);
p->left=pop(&s);
push(&s,p);
break;
default:
push(&s,p);
break;
}
}
return pop(&s);
}


void inorder(struct bstree *r)
{
if(r!=NULL)
{
inorder(r->left);
printf("%c",r->data);
inorder(r->right);
}
}


int main()
{
int ch;
char postfix[50];
struct bstree *root=NULL;
while(1)
{
printf("\n\n\t\t\tMENU\n1. Create Expression Tree.\n2. Inroder. \n3. Exit.");
printf("\n\tEnter your choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter Postfix Expression :: ");
scanf("%s",postfix);
root=NULL;
root=createTree(root,postfix);
break;
case 2:
printf("\n\tInorder Traversal giving Infix expression..\n\t\t");
inorder(root);
break;
case 3:
exit(0);
break;
}
}
}
