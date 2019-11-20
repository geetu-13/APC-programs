#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
	int t;
	scanf("%d",&t);
	int res=0;
	while(t>=0)
	{
		char str[100000];
		int check[26];
		int i;
		for(i=0;i<26;i++)
		{
			check[i]=0;
		}
	    gets(str);
	    int n=strlen(str);
		
		bool s=true;
		if (n<26)
		{
			s=false;
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if (str[i]!=' '){
					int p=str[i]-97;
					check[p]=1;	
				}
			}
			for(i=0;i<26;i++)
			{
				if (check[i]==0)
					{
						s=false;
					}
			}
			if (s==false)
			res=res*10+0;
			else
			res=res*10+1;
			
		}
			
			t--;
	}
	printf("\n\n%d ",res);
    //a=97 and z=122
    return 0;
}
