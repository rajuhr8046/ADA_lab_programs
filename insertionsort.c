#include<stdio.h>
#include<stdlib.h>


int main()
{
	int n,i,j,c;
	printf("enter the size of the array\n");
	scanf("%d",&n);
	int a[n];
	printf("enter %d elements\n",n);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%100;
		printf("%d\t",a[i]);
	}
	for(i=1;i<n;i++)
	{
		c=a[i];
		j=i-1;
		while(j>=0 && c<a[j])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=c;
		
	}
	
	printf("\nsorted elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;
	
	
}
