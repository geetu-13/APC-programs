

//intersection of 2 sorted arrays


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,m,j,k;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d",&m);
	int arr1[m];
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr1[i]);
	}
	i=0;
	j=0;
	int q=n<m?n:m;
	int arr2[q];
	k=0;
	while(i<n&&j<m)
	{
		if(arr[i]<arr1[j])
		{
			i++;
		}
		else if(arr[i]>arr1[j])
		{
			j++;
		}
		else
		{
			arr2[k]=arr[i];
			i++;
			j++;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		printf("%d ",arr2[i]);
	}
}
