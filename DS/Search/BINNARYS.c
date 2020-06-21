#include<stdio.h>
int binarysearch(int a[],int low,int high,int key)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(key==a[mid])
			return(1);
		else if(key<a[mid])
			return (binarysearch(a,low,mid-1,key));
		else
			return (binarysearch(a,mid+1,high,key));
	}
	return 0;
}
void main()
{
	int i,key,n,k,a[100];
	printf("Enter the no of elements\t:");
	scanf("%d",&n);
	printf("Enter the elements \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the key element\t:");
	scanf("%d",&key);
	if(binarysearch(a,0,n-1,key))
		printf("key found\n");
	else
		printf("key not found\n");
}