#include<stdio.h>
#define max 10

int min(int i,int k)
{
	if(i<k)
		return i;
	return k;
}
void binomial(int n,int k,int c[max][max])
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=min(i,k);j++)
		{
			if(j==0 || j==i)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
}
int main()
{
	int n,k,i,j;
	printf("enter the value for n\n");
	scanf("%d",&n);
	printf("enter the value of k\n");
	scanf("%d",&k);
	int c[max][max];
	binomial(n,k,c);
	printf("the binomial matrix is\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			printf("%d  ",c[i][j]);
		}
		printf("\n");
	}
	printf("the value of %dC%d is %d\n",n,k,c[n][k]);
	return 0;
}
