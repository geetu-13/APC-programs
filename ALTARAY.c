//codechef question code: ALTARAY
#include<stdio.h>
void alternate_array(int arr[], int n)
{
	int res[n];
	int i;
	//method 1:
		for(i=0;i<n;i++)
		{
			if (res[i-1]>=2)
				res[i]=res[i-1]-1;
			else if (i==n-1)
				res[i]=1;
			else
			{
				res[i]=1;
				int j=i;
				while (arr[j]*arr[j+1]<0 && j<n)
				{
					res[i]++;
					j++;
				}
			}
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
