#include<stdio.h>
#define MAX 15
int n,adj[MAX][MAX],visit[MAX],dfsorder[MAX];
int i,j,v1,v2,count=1;
void create_graph();
void display();
void dfs(int v);
void create_graph()
{
	int ch=1;
	printf("Enter the no. of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			adj[i][j]=0;
do
	{
		printf("\nEnter the edges(v1 to v2):");
		scanf("%d%d",&v1,&v2);
		adj[v1][v2]=1;
		printf("1 to add more edges:");
		scanf("%d",&ch);
	}while(ch==1);
}
void display()
{
	printf("\nAdjacacency Matrix");
	printf("\nVERTEX");
	for(i=1;i<=n;i++)
		printf("\tV%d",i);
	for(i=1;i<=n;i++)
	{
		printf("\nV%d",i);
		for(j=1;j<=n;j++)
		{
			printf("\t%d",adj[i][j]);
		}
	}
}
void dfs(int v)
{
	int w;
	printf("V%d-",v);
	visit[v]=1;
	
	for(w=1;w<=n;w++)
	{
		if(adj[v][w]==1)
		{
			if(visit[w]==0)
				dfs(w);
		}
	}
}	
void main()
{
	
	create_graph();
	printf("\nGRAPH SUCCESSFULLY CREATED..\n");
	display();
	for(i=1;i<=n;i++)
	{
		visit[i]=0;
		
	}
	printf("\nDFS TRAVERSAL..\n");
	for(i=1;i<=n;i++)
	{
		if(visit[i]==0)
			dfs(i);
	
	}
}
