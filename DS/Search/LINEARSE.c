#include<stdio.h>
int linearsearch(int n,int a[],int key)
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		if(key==a[i])
			return(1);
	}
	return 0;
}
void main()
{
	int i,key,n,k,a[100];
	printf("Enter the no of elements\t:");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the search element\t:");
	scanf("%d",&key);
	if(linearsearch(n,a,key))
		printf("key found\n");
	else
		printf("key not found\n");
}