#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
	string s1;
	string s2;
	cin>>s1>>s2;	
	string a,b;
	int c=0;
	int i1=0, i2=0, j1=0, j2=0;
	int n1=s1.length();
	int n2=s2.length();
	while(j1<n1 && j2<n2)
	{	
		j1=i1;
		while(s1[j1]!='.')
			j1++;
		j2=i2;
		while(s2[j2]!='.')
			j2++;
		if(c==0)
		{
		a=s1.substr(i1,j1);
		b=s2.substr(i2,j2);}
		else
		{
		a=s1.substr(i1,j1-2);
		b=s2.substr(i2,j2-2);	
		}
		cout<<a<<" "<<b<<"\n";
		int x=atoi(a.c_str());
		int y=atoi(b.c_str());
		if (x>y)
			{
				printf("1");
				break;
			}
		else if(x<y)
			{
				printf("-1");
				break;
			}
		else
			{
				i1=j1+1;
				i2=j2+1;
			}
			c++;
			
	}





}
