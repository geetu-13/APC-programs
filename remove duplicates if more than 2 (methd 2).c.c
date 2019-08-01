//removing duplicates. if no of count>2 then just keep 2 copies of the number. remove others.
//method 2

#include<stdio.h>
int main()
{
	int n;
	scanf("%d ",&n);
	int a[n];
	int i;
	int j=0;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);//already sorted
	for(i=0;i<n-2;i++)
	{
		if (a[i]==a[i+1] && a[i]==a[i+2])
			continue;
		else
		{
			a[j]=a[i];
			j++;
		}
	}
	a[j]=a[n-2];
	j++;
	a[j]=a[n-1];
	j++;
	for(i=0;i<j;i++)
		printf("%d ",&a[i]);//already sorted
}
