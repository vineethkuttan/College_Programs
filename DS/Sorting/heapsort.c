#include<stdio.h>
void heapify(int n,int a[])
{
int i,j,k,t;
for(i=n/2;i>=1;i--)
{
k=i;
while((2*k)<=n)
{
j=2*k;
if(j<n)
{
if(a[j]<a[j+1])
j=j+1;
}
if(a[k]<a[j])
{
t=a[k];
a[k]=a[j];
a[j]=t;
k=j;
}
else
break;
}
}
}
void delmax(int n,int a[])
{
int i,t;
for(i=n;i>1;i--)
{
t=a[1];
a[1]=a[i];
a[i]=t;
heapify(i-1,a);
}
}
int main()
{
int n,i;
printf("Enter the size\n");
scanf("%d",&n);
int arr[n];
printf("Enter the elements\n");
for(i=1;i<=n;i++)
scanf("%d",&arr[i]);
heapify(n,arr);
delmax(n,arr);
for(i=1;i<=n;i++)
printf("%d\t",arr[i]);
return 0;
}
