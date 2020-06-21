#include<stdio.h>
void quadraticprobing(int tablesize,int hash[])
{
	int i,n,x,j,hashkey;
	printf("Enter the no of elements\t:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter the element\t:");
		scanf("%d",&x);
		j=0;
		while(1)
		{
			hashkey=(((x%tablesize)+j*j)%tablesize);
			if(hash[hashkey]==-1)
			{
				hash[hashkey]=x;
				break;
			}
			else
				j++;
		}
	}
	for(i=0;i<=tablesize-1;i++)
		printf("%d->%d\n",i,hash[i]);
}
void main()
{
	int i,tablesize;
	printf("Enter the tablesize\t:");
	scanf("%d",&tablesize);
	int hash[tablesize];
	for(i=0;i<=tablesize-1;i++)
		hash[i]=-1;
	quadraticprobing(tablesize,hash);
}
