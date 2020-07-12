#include<stdio.h>
#include<stdlib.h>

int linearSer(int a[],int n,int k)
{
int i;
for(i=0;i<n;i++)
if(a[i]==k)
return i;
return -1;
}


int binarySer(int a[],int n,int k)
{
int low,upper,mid;
low=0;
upper=n-1;
for(mid=(low+upper)/2;low<=upper;mid=(low+upper)/2)
{
if(k==a[mid])
return mid;
if(k>a[mid])
low=mid+1;
else
upper=mid-1;
}
return -1;
}

int main()
{
int a[20],n,i,ch,k;
printf("\nEnter Total no. of elements :: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter Element :: ");
scanf("%d",&a[i]);
}
while(1)
{
printf("\n\t\t\tMENU\n1. Key Element. \n2. Linear Search.\n3. Binary Search.\n4. Exit.\n\tEnter your choice :: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n\tEnter Key element to search :: ");
scanf("%d",&k);
break;
case 2:
i=linearSer(a,n,k);
if(i==-1)
printf("\nKey Element does not exist.");
else
printf("\nKey Element exist at location %d.",i);
break;
case 3:
i=binarySer(a,n,k);
if(i==-1)
printf("\nKey Element does not exist.");
else
printf("\nKey Element exist at location %d.",i);
break;
case 4:
exit(0);
break;
}
}
}
