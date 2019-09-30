//length of last word of string
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char str[]="hell world  koala     ";
	printf("\n%s\n",str);

	int n=strlen(str);
	int count=0;
	int i=n-1;
	while(str[i]==' ')//trim function substitute
		i--;
	while(str[n]=='\0' && i>=0 && str[i]!=' ')
	{
		count++;
		printf("%c ",str[i]);
		i--;
	}
	printf("\ncount= %d",count);
}
