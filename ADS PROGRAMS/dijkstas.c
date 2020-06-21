#include<stdio.h>
#define INFINITY 9999
#define MAX 10
int G[MAX][MAX],i,j,n; 
void dijkstra();
void create_graph();
 
int main()
{
	create_graph();
	printf("\nGRAPH SUCCESSFULLY CREATED..\n");
	dijkstra();
	return 0;
}

void create_graph()
{
	int e,we,v1,v2,i,j;
	printf("Enter the no. of vertices : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			G[i][j]=0;
	printf("\nEnter the No of Edges : ");
        scanf("%d",&e);
	printf("\nFROM\tTO\tWEIGHT\n");
        for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&v1,&v2,&we);
		G[v1][v2]=we;
                G[v2][v1]=we;
	}
}

void dijkstra()
{
 
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j,startnode;
        printf("\nENter Starting Node : ");
	scanf("%d",&startnode);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}		
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node%d=%d",i,distance[i]);
			printf("\n\tPath=%d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
		}
		printf("\n");
}
