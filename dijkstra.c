#include<stdio.h>

void dijkstra(int cost[10][10],int n,int s,int d[])
{
	int visited[10],i,j,u,min;
	for(i=0;i<n;i++)
	{
		d[i]=cost[s][i];
		visited[i]=0;
	}	
	visited[s]=1;
	for(i=0;i<n;i++)
	{
		min=999;
		for(j=0;j<n;j++)
		{
			if(visited[j]==0 && d[j]<min)
			{
				min=d[j];
				u=j;
			}
		}
		visited[u]=1;
		for(j=0;j<n;j++)
		{
			if(visited[j]==0 && d[u]+cost[u][j]<d[j])
				d[j]=d[u]+cost[u][j];
		}
	}
}

int main()
{
	int a[10][10],n,i,j,s,d[10];
	printf("enter the number of vertices:\n");
	scanf("%d",&n);
	printf("enter the cost adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	printf("enter the source vertex:\n");
	scanf("%d",&s);
	for(i=0;i<n;i++)
	{
		d[i]=0;
	}
	dijkstra(a,n,s,d);
	printf("shortest paths to other vertices from source vertex:\n");
	for(i=0;i<n;i++)
		printf("shortest path from %d to %d is %d\n",s,i,d[i]);
	return 0;
	
}
