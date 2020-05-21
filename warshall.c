#include<stdio.h>


void warshall(int r[10][10],int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				r[i][j]=r[i][j] || (r[i][k] && r[k][j]);				
	
}

int main()
{
	int i,j,n;
	printf("enter the number of vertices\n");
	scanf("%d",&n);
	int a[10][10],r[10][10]; 
	printf("enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			r[i][j]=a[i][j];
		}
	}
	warshall(r,n);
	printf("transitive closure of the given directed graph\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%d  ",r[i][j]);
		printf("\n");
	}
	return 0;
}
