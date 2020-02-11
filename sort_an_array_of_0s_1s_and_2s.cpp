#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	int zero=0,one=0,two=0;
	for(int i=0;i<n;++i){
		cin>>arr[i];
		if (arr[i]==0)
			zero++;
		else if (arr[i]==1)
			one++;
		else if (arr[i]==2)
			two++;
	}
	for(int i=0;i<n;i++){
		if (zero!=0){
			arr[i]=0;
			zero--;
		}
		else if (one!=0){
			arr[i]=1;
			one--;
		}
		else if(two!=0){
			arr[i]=2;
			two--;
		}
	}
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
		
}
