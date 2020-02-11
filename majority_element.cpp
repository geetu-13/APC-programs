//c++
#include<iostream>
//boyer moore majority-voting algorithm
using namespace std;
int boyer_moore(int arr[], int n){
	int m;
	int i=0;
	for(int j=0;j<n;++j){
		if(i==0)
			m=arr[j],i=1;
		else if (m==arr[j])
			i++;
		else
			i--;
	}
	return m;
}
int count(int arr[], int n, int m){
	int count=0;
	for(int i=0;i<n;i++){
		if (arr[i]==m)
			count++;
	}
	return count;
}
int main(){
	int t;
	cin>>t;
	while(t>0){
		int n;
		cin>>n;
		int arr[n];
		int i;
		for(i=0;i<n;++i)
			cin>>arr[i];
		int ans=boyer_moore(arr,i);//finding majority in array
		if (count(arr, n, ans)>n/2) //checking if the number found occurs more than n/2 times
			ans=ans;
		else
			 ans=-1;
		cout<<"answer: "<<ans<<endl<<endl;
		--t;
	}
}
