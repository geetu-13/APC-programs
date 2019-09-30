#include<stdio.h>
int val(char x)
{
	if (x=='i' || x=='I')
		return 1;
	if (x=='X' || x=='x')
		return 10;
	else if (x=='v' || x=='V')
		return 5;
	else if(x=='L' || x=='l')
		return 50;
	else if (x=='C' || x=='c')
		return 100;
	else if(x=='D' || x=='d')
		return 500;
	else if(x=='m' || x=='M')
		return 1000;
}
int main()
{
	char str[100];
	scanf("%s",&str);
	int i=0;
	int sum=0;
	while(i<strlen(str)-1)
	{
		if(val(str[i])>=val(str[i+1]))
			sum+=val(str[i]);
		else
			sum-=val(str[i]);
		i++;	
	}
	sum+=val(str[i]);
	
	printf("\n\n\n%d ",sum);
	return 0;
}
