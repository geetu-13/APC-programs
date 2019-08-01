//max continous series of 1's with M flippable zeroes

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(sizeof(int)*n);
// or int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int n1;
	printf("no of flippable zeroes: ");
	scanf("%d",&n1);
	int r=0,l=0, posr=0, max=0, count_zero=0;
	while (r<n)
	{
		if (a[r]==1)
			r++;
		else if (a[r]==0 && count_zero<n1)
		{
			r++;
			count_zero++;
		}
		else
		{
			if(max<r-l)
			{
				max=r-l;
				posr=r;
			}
			while (a[l]!=0)
			{
				l++;
			}
			l++;
			count_zero--;
		}
	}
	if (max<r-l)
	{
		max=r-l;
		posr=r;
	}
	printf("\n\nindexes are: %d, %d", posr-max, posr-1);
	return 0;
}
