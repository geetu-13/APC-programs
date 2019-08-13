#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	scanf("%d",&i);
	i--;//position here starts from 0. we want it to be from 1.
	
	if ((n>>i) %2==0)//if the ith bit =0 then no action
		printf("%d",n);
	else//if the ith bit=1, then flip the ith bit.
	{
		n=n^ (1<<i);
		printf("%d",n);
	}
	
	return 0;
}
