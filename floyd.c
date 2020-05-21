#include<stdio.h>


void floyd(int d[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				if(d[i][j]<d[i][k]+d[k][j])
					d[i][j]=d[i][j];
				else
					d[i][j]=d[i][k]+d[k][j];
			}	
	
}

int main()
{
	int i,j,n;
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	int d[10][10]; 
	printf("enter the cost adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&d[i][j]);
			
	}
	floyd(d,n);
	printf("all pair shortest paths\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d  ",d[i][j]);
		printf("\n");
	}
	return 0;
}
