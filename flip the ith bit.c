#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	scanf("%d",&i);//position here starts from 0. we want it to be from 1.
	i--;
	n=n^ (1<<i);
	printf("after flipping: %d",n);
	return 0;
}
