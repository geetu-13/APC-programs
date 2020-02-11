#include<iostream>
using namespace std;
void swap(int *a, int *b){
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[], int low, int high){
	int pivot=arr[high];
	int i=low-1;
	for(int j=low;j<=high-1;++j)
		if(arr[j]<pivot){
			++i;
			swap(&arr[i],&arr[j]);
		}
	swap(&arr[i+1],&arr[high]);
	return i+1;
}
void quicksort(int arr[], int low, int high){
	if(low<high){
		int pivot=partition(arr, low, high);
		quicksort(arr,low,pivot-1);
		quicksort(arr,pivot+1,high);
	}
}
int main()
{
	int arr[]={9,7,8,4,5,6,3,2,1,0};
	int n=sizeof(arr)/sizeof(int);
	quicksort(arr,0,n-1);
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
	return 0;
}
