#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;++i)
		cin>>arr[i];
	int count=0;
	for(int i=0;i<n;++i)
	{
		for(int j=i;j<n;++j){
			if (arr[j]<arr[i])
				{
					count++;
					cout<<"("<<arr[i]<<","<<arr[j]<<")\n";
				}
		}
	}
	cout<<endl<<count<<endl;
}
