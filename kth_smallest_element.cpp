#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int t=*a;
	*a=*b;
	*b=t;	
}
int partition(int arr[], int l, int r)
{
	int pivot=arr[r];
	int i=l-1;
	for(int j=l;j<=r;++j)
	{
		if(arr[j]<pivot)
		{
			++i;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[r]);
	return i+1;
}
int qsort(int arr[], int l, int r)
{
	if (l<r){
		int pi=partition(arr, l, r);
		qsort(arr, l, pi-1);
		qsort(arr, pi+1, r);
	}
}
int main()
{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		qsort(arr,0,n-1);
		cout<<"sorted array: \n";
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl<<"k: ";
		int k;
		cin>>k;
		cout<<"kth smallest element: "<<arr[k-1];
		return 0;
}
