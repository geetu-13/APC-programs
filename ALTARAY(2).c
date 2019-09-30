//codechef question code: ALTARAY
#include<stdio.h>
void alternate_array(int arr[], int n)
{
	int res[n];
	int i;
		//method 2:
	for(i=0;i<n;i++)
		res[i]=1;
	for(i=n-2;i>=0;i--)
	{
		if (arr[i]*arr[i+1]<0)
			res[i]=res[i]+res[i+1];		
	}
	
	for(i=0;i<n;i++)
		printf("%d ",res[i]);
	printf("\n\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		int n;
		scanf("%d ",&n);
		int arr[n];
		int i;
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		printf("res: ");
		alternate_array(arr,n);
		t--;
	}
}
