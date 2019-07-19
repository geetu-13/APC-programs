//array rotation
#include<stdio.h>
int main()
{
	int n;//size of array
	scanf("%d",&n);
	int a[n][n];
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	int r;//no of rotations.
	scanf("%d",&r);
	r=r%4;
	int k;
	for(k=0;k<r;k++)
	{
		for(i=0;i<n/2;i++)//for moving inside the loops
		{
			for(j=i;j<n-1-i;j++)//for outer loop
			{
				int temp=a[i][j];
				a[i][j]=a[n-1-j][i];
				a[n-1-j][i]=a[n-1-i][n-1-j];
				a[n-1-i][n-1-j]=a[j][n-1-i];
				a[j][n-1-i]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
