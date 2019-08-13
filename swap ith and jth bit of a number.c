#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	printf("i= ");
	scanf("%d",&i);
	printf("j= ");
	scanf("%d",&j);
	i--;j--;
	if ((n>>i)%2==0 && (n>>j)%2==0)//if both are 0
		printf("after flipping ith and jth bit: %d",n);
	else if ((n>>i)%2!=0 && (n>>j)%2!=0)//if both are 1
		printf("after flipping ith and jth bit: %d",n);
	else
	{
		//flip both bits
		n=n^ (1<<i);
		n=n^ (1<<j);
		printf("after flipping ith and jth bit: %d",n);
	}
	return 0;
}
