//max sum of a continous sub array
#include<stdio.h>
int main()
{
	int n;//no of elements in the array
	scanf("%d",&n);
	int a[n];//array with n elements
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int sum=a[0];
	int max=-999;
	for(i=0;i<n;i++)
	{
		if (sum<=a[i])
		sum=a[i];
		else
		sum+=a[i];
		max=max>sum?max:sum;
		
	}
	printf("\n%d\n",max);
}
