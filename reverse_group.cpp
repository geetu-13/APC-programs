//reverse_group
#include<stdio.h>
void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n; //size of array= k
	scanf("%d",&n);
	int arr[n];//array
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int k;//size of group
	scanf("%d",&k);
	int j;
	for(i=0;i<n;i=i+k)
	{
		if (i+k<n)
		{
			for(j=0;j<k/2;j++)
			{
				swap(&arr[j+i],&arr[k-j+i-1]);
			}
		}
		else
		{
			for(j=0;j<(n-i)/2;j++)
			{
				swap(&arr[j+i],&arr[n-1-j]);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
