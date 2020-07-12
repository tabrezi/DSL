/*Implementation of Binary search tree*/
#include<stdio.h>
#include<stdlib.h>

struct bstree
{
int data;
struct bstree *left,*right;
};

struct bstree *insert(struct bstree *root,int d)
{
struct bstree *p;
if(root==NULL)
{
p=(struct bstree *)malloc(sizeof(struct bstree));
p->data=d;
p->left=p->right=NULL;
root=p;
}
else
{
if(d<root->data)
root->left=insert(root->left,d);
else
root->right=insert(root->right,d);
}
return root;
}


struct bstree *insertIter(struct bstree *root,int d)
{
struct bstree *p,*curr,*prev;
p=(struct bstree *)malloc(sizeof(struct bstree));
p->data=d;
p->left=p->right=NULL;
if(root==NULL)
root=p;
else
{
curr=prev=root;
while(curr!=NULL)
{
prev=curr;
if(d<curr->data)
curr=curr->left;
else
curr=curr->right;
}
if(d<prev->data)
prev->left=p;
else
prev->right=p;
}
return root;
}

void inorder(struct bstree *r)
{
if(r!=NULL)
{
inorder(r->left);
printf("\n%d",r->data);
inorder(r->right);
}
}

void preorder(struct bstree *r)
{
if(r!=NULL)
{
printf("\n%d",r->data);
preorder(r->left);
preorder(r->right);
}
}

void postorder(struct bstree *r)
{
if(r!=NULL)
{
postorder(r->left);
postorder(r->right);
printf("\n%d",r->data);
}
}


struct bstree *search(struct bstree *root,int key)
{
if(root!=NULL)
{
if(key==root->data)
return root;
else
{
if(key<root->data)
root->left=search(root->left,key);
else
root->right=search(root->right,key);
}
}
else
return NULL;
}



int main()
{
int ch,d;
struct bstree *p,*root=NULL;
while(1)
{
printf("\n\n\t\t\tMENU\n1. Insert.\n2. Inroder. \n3. PreOrder.\n4. PostOrder.\n5. Search.\n6. Exit.");
printf("\n\tEnter your choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter data :: ");
scanf("%d",&d);
root=insert(root,d);
break;
case 2:
printf("\n\tInorder Traversal.");
inorder(root);
break;
case 3:
printf("\n\tPre Order Traversal.");
preorder(root);
break;
case 4:
printf("\n\tPost Order Traversal.");
postorder(root);
break;
case 5:
printf("\nEnter data :: ");
scanf("%d",&d);
p=search(root,d);
if(p==NULL)
printf("\nGiven Key does not exist..");
else
printf("\nGiven Key does exist..");
break;

case 6:
exit(0);
break;
}
}
}
