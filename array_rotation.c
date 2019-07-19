//1D array rotation//clock wise
#include<stdio.h>
void rotate(int *arr,int n, int r, int i, int temp, int count)
{//n is array size//r is no of rotations//i is the posn

	int b=n-r+i;
	if (b>=n)
		b=b-n;
	int temp1=arr[b];
	arr[b]=temp;
	count++;
	if (count<n)
		rotate(arr,n,r,b,temp1,count);
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int r;//no of rotations
	scanf("%d",&r);
	r=r%n;//effective number of rotations
	
	rotate(a, n, r , 0, a[0], 0);
	
	printf("\n\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
