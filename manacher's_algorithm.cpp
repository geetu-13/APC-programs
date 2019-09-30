#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int min(int x,int y)
{
	int m=x<y?x:y;
	return m;
}
string modify(string s)
{
	int i;
	for(i=0;i<=s.length();i=i+2)
		s.insert(i,"&");
	return s;
}
int main()
{
	string s="abb";
	string str=modify(s);
	cout<<"string: "<<s<<endl<<"modified string: "<<str<<endl;
	int i=0;
	int n=str.length();
	int left=0, right=0;
	int arr[n];
	arr[0]=1;
	for(i=0;i<n;i++)
	{
		left=i;
		right=i;
		while(left>=0 && right<n && str[left-1]==str[right+1])
		{
			left--;
			right++;
		}
		arr[i]=right-left+1;
		int j;
		for(j=i+1;j<=right;j++)
		{
			int x=arr[i-(j-i)];
			arr[j]=min(x,(right-j)*2+1);
			if (x/2+i==right)
				{
					i=j;break;
				}
		}		
	}
	int max=0;
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
		max=max>arr[i]?max:arr[i];
	}
	cout<<endl<<"max length of palindrome: "<<max/2;
}
