//remove duplicates
//already sorted
#include<stdio.h>
int main()
{
	int n;
	scanf("%d ",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int j=0;
	for(i=0;i<n-1;i++)
	{
		if (a[i]==a[i+1])
			continue;
		else
			{
				a[j]=a[i];
				j++;
			}
	}
	if (a[n-1]!=a[n-2])//for last element of array
	{
		a[j]=a[n-1];
		j++;
	}
	for(i=0;i<j;i++)
		printf("%d ",a[i]);
}
