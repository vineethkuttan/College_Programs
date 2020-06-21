#include <stdio.h>
#include <math.h>
void selectionSort(int a[], int n)
{
int i,j,min,temp;
for(i=0;i<=n-2;i++)
{
min=i;
for(j=i+1;j<=n-1;j++)
{
if(a[j]<a[min])
min=j;
}
if(a[i]!=a[min])
{
temp=a[i];
a[i]=a[min];
a[min]=temp;
}
}
}
void printArray(int arr[], int n)
{
int i;
for (i=0; i < n; i++)
printf("%d ", arr[i]);
printf("\n");
}
int main()
{
int i,m;
printf("Enter the no of element \n");
scanf("%d",&m);
int arr[m];
printf("Enter the elements\n");
for(i=0;i<m;i++)
scanf("%d",&arr[i]);
int n = sizeof(arr)/sizeof(arr[0]);
selectionSort(arr, n);
printArray(arr, n);
return 0;
}
