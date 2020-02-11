#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n1,n2, count=0;
	cin>>n1>>n2;
	int a[n1],b[n2];
	for(int i=0;i<n1;++i)
		cin>>a[i];
	for(int i=0;i<n2;++i)
		cin>>b[i];
	
	cout<<"\npairs: \n";
	for(int i=0;i<n1;++i)
	{
		for(int j=0;j<n2;++j)
		{
			int x=pow(a[i],b[j]);
			int y=pow(b[j],a[i]);
			
			if (x>y)
			{
				cout<<a[i]<<" "<<b[j]<<endl;	
				count++;
			}
				
		}
	}	
	cout<<endl<<"count: "<<count<<endl;
}
