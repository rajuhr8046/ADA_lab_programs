#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sort(int [],int [],int,int);
void merge(int a[],int b[],int mid,int low,int high)
{
	int i,j,k;
	i=k=low;
	j=mid+1;
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=high)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(i=0;i<k;i++)
		a[i]=b[i];
	return;
}
int main()
{
	int i,low=0,high,choice,n,j,p,c[60000],d[60000],a[50],b[50];
	FILE *fp;
	clock_t start,end;
	double extime;
	while(1)
	{
		printf("enter your choice\n");
		printf("1:sort the elements using mergesort\n2:time complexity of mergesort\n3:exit()\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the size of the array\n");
					scanf("%d",&n);
					high=n-1;
					printf("enter %d elemennts\n",n);
					for(i=0;i<n;i++)
					{
						a[i]=random()%10000;
						printf("%d\t",a[i]);
					}
					sort(a,b,low,high);
					printf("\nsorted elemennts are\n");	
					for(i=0;i<n;i++)
						printf("%d\t",a[i]);
					printf("\n");
					break;
			case 2:fp=fopen("graph.dat","w");
					for(p=5000;p<50000;p+=5000)
					{
						for(j=0;j<p;j++)
							c[j]=random()%10000;
						start=clock();
						sort(c,d,0,p-1);
						end=clock();
						extime=(double)(end-start)/CLOCKS_PER_SEC;
						fprintf(fp,"%d\t%lf\n",p,extime);
					}
					fclose(fp);
			case 3:exit(0);
		}
	}
	return 0;
}

void sort(int a[],int b[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		sort(a,b,low,mid);
		sort(a,b,mid+1,high);
		merge(a,b,mid,low,high);
	}
	return;
}
