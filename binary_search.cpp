#include<iostream>
using namespace std;
int binary_search(int arr[], int l, int r, int number){
	if(r>=l)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]==number)
			return mid;
		else if (arr[mid]>number)
			return binary_search(arr, l, mid-1, number);
		else
			return binary_search(arr, mid+1, r, number);
	}
	return -1;
}
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9,21};
	//assumption: arr[] is sorted
	int n=sizeof(arr)/sizeof(int);
	int number;
	cin>>number;
	cout<<endl<<binary_search(arr, 0, n-1, number)<<endl;
	return 0;
}
