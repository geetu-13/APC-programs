//swap the adjacent bits of a number:
//example n=5 ( 101) after swapping: 011, number= 3
#include<stdio.h>
int swap(int i, int j, int n)
{
	if ((n>>i)%2==0 && (n>>j)%2==0)//if both are 0
		return n;
	else if ((n>>i)%2!=0 && (n>>j)%2!=0)//if both are 1
		return n;
	else
	{
		//flip both bits
		n=n^ (1<<i);
		n=n^ (1<<j);
		return n;
	}
	
}
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
	i=order;
	if (order==-1)
		printf("%d",n);
	else
	{
		while(i>0)
		{
			n=swap(i, i-1, n);
			i=i-2;
		}
		printf("after swapping adjacent bits of a number: %d ",n);
	}
	
}
