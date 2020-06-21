#include<stdio.h>
# include<stdlib.h>
#define MAX 50
int n,G[MAX][MAX];
int front = -1,rear = -1,queue[MAX];
void create_graph();
void enqueue(int i);
int dequeue();
int indegree(int node);
void create_graph()
{
	int e,v1,v2,i,j;
	printf("\nEnter The No Of Vertices : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			G[i][j]=0;
	printf("\nEnter the No of Edges : ");
        scanf("%d",&e);
	printf("Enter The Edges :\n");
	printf("FROM\tTO\n");
        for(i=1;i<=e;i++)
	{
		scanf("%d%d",&v1,&v2);
		G[v1][v2]=1;
	}
}

int indegree(int node)
{
	int i,count=0;
	for(i=1;i<=n;i++)
		if(G[i][node]==1)
			count++;
	return count;
}
void enqueue(int i)
{           
	if(front==-1)
		front++;
	rear++;
	queue[rear]=i;
}
int dequeue()
{       
	int i;
	i=queue[front];
	front++;
	return i;
}

void main()
{
int i,j=1,k;
int topsort[MAX],indeg[MAX];
create_graph();
for(i=1;i<=n;i++)
{
	indeg[i]=indegree(i);
	if(indeg[i]==0)
		enqueue(i);
}
while(front<=rear)
{
	k=dequeue();
	topsort[j++]=k;
	for(i=1;i<=n;i++)
	{
		if(G[k][i]==1)
		{
		G[k][i]=0;
		indeg[i]=indeg[i]-1;
		if(indeg[i]==0)
			enqueue(i);
		}	
 	 }
 }
printf("\nVertices After Topological Sorting : \n");
for(i=1;i<=n;i++)
	printf("V%d - ",topsort[i]);
printf("\n");
}
