#include<iostream>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;++i)
		cin>>arr[i];
	
	int mid=n/2;
	
	int f[mid], s[n-mid];
	
	for(i=0;i<mid;++i)
	{
		f[i]=arr[i];
	}

	for(i=0;i<n-mid;++i)
	{
		s[n-mid-1-i]=arr[mid+i];	
	}
	
	int q=0,r=0;
	for(i=0;i<n;i++){
		if (i%2==0)
		{
			arr[i]=s[q];
			q++;	
		}
		else 
		{
			arr[i]=f[r];
			r++;
		}
		cout<<arr[i]<<" ";
	}
	
}
