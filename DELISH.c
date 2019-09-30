//codechef question code: DELISH (dessert wizard)
#include<stdio.h>

int max(int a,int b)
{
	if(a>b) 
		return a; 
	return b;
}
int min(int a,int b)
{
	if(a<b) 
		return a; 
	return b;
}
int main() 
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n, i;
		scanf("%d",&n);
		int a[n];
	 	for(i=0;i<n;i++)
	 		scanf("%lld",&a[i]);
	 	int minl[n],maxl[n],minr[n],maxr[n];
	 	minl[0]=a[0]; 
		maxl[0]=a[0];
	 
	 	maxr[n-1]=a[n-1];
		minr[n-1]=a[n-1];
		for(i=1;i<n;i++)
		{
			minl[i]=min(a[i],minl[i-1]+a[i]);
			maxl[i]=max(a[i],maxl[i-1]+a[i]);
		}
		for(i=n-2;i>=0;i--)
		{
			minr[i]=min(a[i],minr[i+1]+a[i]);
			maxr[i]=max(a[i],maxr[i+1]+a[i]);
		}
		int max_diff=0;
		for(i=0;i<n-1;i++)
		{
			if(max_diff<(maxr[i+1]-minl[i]))
	 			max_diff=maxr[i+1]-minl[i];
	 		if(max_diff<(maxl[i]-minr[i+1]))
	 			max_diff=maxl[i]-minr[i+1];
		}
		printf("%d\n",max_diff);
	}
	return 0;
}
