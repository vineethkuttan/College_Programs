#include<stdio.h>

int minmax(int i,int j,int *max,int *min)
{
int min1=999,max1=-999;
int a[]={5,4,3,2,1,6};
if(i==j)
	*min=*max=a[i];

else if(j==(i+1))
	{
		if(a[i]<a[j])
		{
			*min=a[i];
			*max=a[j];
		}
		else if(a[i]>a[j])
		{
			*max=a[i];
			*min=a[j];
		}
		else
			*min=*max=a[i];
	}
else
{
	int mid=(i+j)/2;
	minmax(i,mid,max,min);
	minmax(mid+1,j,&max1,&min1);

}	
if(*max<max1)
	*max=max1;
if(*min>min1)
	*min=min1;
	}

int main()
{

	
	int n1=5;
	int m,n;
	minmax(0,n1,&m,&n);
	printf("%d\n",m);

}	
			
