#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int INT_SIZE=sizeof(int)*8;
	int order=-1;
	int i;
	for(i=0;i<INT_SIZE;i++)
	{
		if ((n>>i)&1)
			order=i;
	}
	int flag=1;
	if (order==-1)
		printf("no");
	else
	{
		while(order>0)
		{
			if ((n>>order)%2==0)
			{
				flag=0;
				break;
			}
			order--;
			if ((n>>order)%2!=0)
			{
				flag=0;
				break;
			}
			order--;
		}
		if (flag)
			printf("yes");
		else
			printf("no");
	}
}
