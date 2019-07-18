#include<stdio.h>
int main()
{
	int n=3;
	int l[n],r[n];
	int i;
	for (i=0;i<n;i++)
		scanf("%d",&l[i]);
	for(i=0;i<n;i++)
		scanf("%d",&r[i]);
	int max=-999;
	for(i=0;i<n;i++)
	{
		max=max>r[i]?max:r[i];
	}
	int arr[max+1];
	for(i=0;i<max+1;i++)
		arr[i]=0;
	for (i=0;i<n;i++)
	{
		arr[l[i]]++;
		arr[r[i]+1]--;
	}
	int p=0,m=0,count=0;
	for (i=0;i<max+1;i++)
	{
		if (p+arr[i]>m)
		{
			m=p+arr[i];
			p=p+arr[i];
			count=i;
		}
	}
	printf("%d occurs %d times",count,m);
	return 0;
}
