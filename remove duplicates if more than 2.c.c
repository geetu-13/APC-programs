//removing duplicates. if no of count>2 then just keep 2 copies of the number. remove others.
#include<stdio.h>
int main()
{
	int n;
	scanf("%d ",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);//already sorted
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	int count=1;
	int j=0;
	for(i=0;i<n;i++)
	{
		if (a[i]==a[i+1] && a[i]==a[i+2])
			count=count+2;
		else if (a[i]==a[i+1])
			count++;
		if (a[i]!=a[i+1])
			{
				a[j]=a[i];
				j++;
				if (count>1)
				{
					a[j]=a[i];
					j++;
				}
				count=1;
			}
			
	}
	printf("\n\nafter removing duplicates\n\n");
	for(i=0;i<j;i++)
		printf("%d ",a[i]);
}
