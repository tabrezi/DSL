/*
Implementation of DFS and BFS.
*/

#include<stdio.h>
#include<unistd.h>
#define MAX 20

struct stack
{
int data[MAX];
int top;
};

struct Queue
{
int data[MAX];
int front,rear;
};


void push(struct stack *s,int d)
{
if(s->top==MAX-1)
printf("\n\tStack Overflows->");
else
{
s->top++;
s->data[s->top]=d;	
}
}

int pop(struct stack *s)
{
if(s->top==-1)
printf("\n\tStack Underflows->");
else
return s->data[s->top--];
}

void initialize(struct stack *s)
{
s->top=-1;
}


void insert(struct Queue *q,int d)
{
if(q->rear==MAX-1)
printf("\n\tQueue is Full->");
else
{
q->rear++;
q->data[q->rear]=d;
if(q->front==-1)
q->front=0;	
}
}

void initializeQ(struct Queue *q)
{
q->front=q->rear=-1;
}

int delete(struct Queue *q)
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
return d;
}
}

void dfs(int a[][10],int n)
{
struct stack s;
int visited[10];
int i,j,v;
initialize(&s);
for(i=0;i<n;i++)
visited[i]=0; //setting all unvisited.
visited[0]=1; //visit first vertex
printf("\n\t\tDFS Traversal :\n0\t");
push(&s,0);
while(s.top!=-1)      // until stack empty,
{
 v=-1;
        // get an unvisited vertex adjacent to stack top
 for(j=0;j<n;j++)
         if(a[s.data[s.top]][j]==1 && visited[j]==0)
            {
		v=j;
      		break;
	    }
 if(v==-1)                    // if no such vertex,
 v=pop(&s);
 else                           // if it exists,
 {
   visited[v]=1;  // mark it
   printf("%d\t",v);                 // display it
   push(&s,v);                 // push it
 }
}  // end while
}


void bfs(int a[][10],int n)
{
struct Queue q;
int visited[10];
int i,j,v;
initializeQ(&q);
for(i=0;i<n;i++)
visited[i]=0; //setting all unvisited.
visited[0]=1; //visit first vertex
printf("\n\t\tBFS Traversal :\n0\t");
insert(&q,0);
while(q.front!=-1)      // until queue empty,
{
 v=delete(&q);
        // get an unvisited vertex adjacent to stack top
 for(j=0;j<n;j++)
         if(a[v][j]==1 && visited[j]==0)
            {
		visited[j]=1;
		printf("%d\t",j);
		insert(&q,j);
	    }
 
}  // end while
}


int main()
{
int n,i,s,ch,j,a[10][10];
char c,dummy;
while(1)
{    
printf("\n\n\t\tMENU\n1. Make Graph.\n2. DFS.\n3. BFS. \n4. Exit.");
printf("\n\tEnter Your Choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
    printf("\nENTER THE NUMBER OF VERTICES :: " );
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
     for (j=0;j<n;j++)
     {
       printf("\nEnter 1 if %d has a Edge with %d else 0 : ", i+1, j+1);
       scanf( "%d",&a[i][j]);
     }
    }
    printf("\n\nTHE ADJACENCY MATRIX IS\n" );
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
       {
        printf("\t%d",a[i][j]);
       }
      printf("\n");
     }
break;
case 2:
dfs(a,n);
break;
case 3:
bfs(a,n);
break;
case 4:
exit(0);
break;
}
}
}
