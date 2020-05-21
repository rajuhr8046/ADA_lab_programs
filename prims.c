#include<stdio.h>
int a[10][10];

void prims(int n)
{
	int i,j,min=999,mincost,k,l,z;
	int t[n][2],near[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
				k=i;l=j;
			}
		}
		mincost=a[k][l];
		t[0][0]=k;t[0][1]=1;
		for(i=0;i<n;i++)
		{
			if(a[i][l]<a[i][k])
				near[i]=l;
			else
				near[i]=k;
		}
		near[k]=near[l]=-1;
		
		for(int i=1;i<n-1;i++)
		{
			min=999;
			for(z=0;z<n;z++)
			{
				if(near[z]!=-1)
				{
					if(a[z][near[z]]<min)
					{
						j=z;
						min=a[z][near[z]];
					}
					t[i][0]=j;
					t[i][1]=near[j];
					mincost+=a[j][near[j]];
					near[j]=-1;
					for(z=0;z<n;z++)
						if((near[z]!=-1) && (a[z][near[z]]>a[z][j]))
							near[z]=j;
			}	}	
		}
	}
		printf("\nMinimum cost=%d\n",mincost);
		printf("\nvertices :\n");
		for(i=0;i<n-1;i++)
		{
			printf("%d->%d\n",t[i][0]+1,t[i][1]+1);
		}
	
}

int main()
{
	int i,j,n;
	printf("enter the number of vertices:");
	scanf("%d",&n);
	printf("enter the weighted adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
	prims(n);
	printf("\n");
	return 0;
}
