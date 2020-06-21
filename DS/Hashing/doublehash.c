#include<stdio.h>
void double(int tablesize,int hash[])
{
int i,n,x,j,hashkey,r,flag,t;
scanf("%d",&n);
for(r=tablesize-1;r>1;r++)
{
	flag=1;
	for(t=2;t<r;t++)
	{
		if(r%t==0)
		{
			flag=0;
			break;
		}
		if(flag)
			break;
	}
}
for(i=0;i<=n-1;i++)
{
scanf("%d",&x);
j=0;
while(1)
{
hashkey=(((x%tablesize)+(j*(r-(x%r))))%tablesize);
if(hash[hashkey]==-1)
{
hash[hashkey]=x;
break;
}
else
j++;
}
}
for(i=0;i<tablesize-1;i++)
printf("%d->%d",i,hash[i]);
}
void main()
{
int i,tablesize,hash[100];
scanf("%d",&tablesize);
for(i=0;i<tablesize-1;i++)
hash[i]=-1;
double(tablesize,hash);
}
