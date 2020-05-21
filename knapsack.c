//knapsack problem

#include<stdio.h>

#define max 10

void profittable(int weight[max],int values[max],int v[max][max],int n,int w)
{
	int i,j;
	for(i=0;i<=n;i++)
		v[i][0]=0;

	for(j=0;j<=w;j++)
		v[0][j]=0;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(j-weight[i]<0)
				v[i][j]=v[i-1][j];
			else
			{
				if(v[i-1][j]>values[i]+v[i-1][j-weight[i]])
					v[i][j]=v[i-1][j];
				else
					v[i][j]=values[i]+v[i-1][j-weight[i]];
			}
			
		}
	}
	
}

void selectitems(int weight[max],int loaded[max],int v[max][max],int n,int w)
{
	int i,j;
	i=n;
	j=w;
	while(i>=1 && j>=1)
	{
		if(v[i][j]!=v[i-1][j])
		{
			loaded[i]=1;
			j=j-weight[i];
			i--;
		}
		else
			i--;
	}
}
int main()
{
	int n,w,i,j,totalprofit=0;
	int weight[max],values[max],v[max][max],loaded[max];
	printf("enter the number of items\n");
	scanf("%d",&n);
	printf("enter the knapsack capacity\n");
	scanf("%d",&w);
	printf("enter the weights\n");
	for(i=1;i<=n;i++)
		scanf("%d",&weight[i]);
		
	printf("enter the values\n");
	for(i=1;i<=n;i++)
		scanf("%d",&values[i]);
		
	for(i=1;i<=n;i++)
		loaded[i]=0;
	
	profittable(weight,values,v,n,w);
	selectitems(weight,loaded,v,n,w);
	
	printf("profit matrix\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
			printf("%d  ",v[i][j]);
		printf("\n");
	}
	
	printf("item numbers which are loaded\n{");
	for(i=1;i<=n;i++)
	{
		if(loaded[i])
		{
			printf("%d ",i);
			totalprofit +=values[i];
		}
	}
	printf("}\n");
	printf("total profit is %d\n",totalprofit);
	return 0;		
		
}

//end of the program
