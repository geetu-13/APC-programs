#include<iostream>
using namespace std;
void merge(int arr[], int left, int middle, int right){
	int i,j,k;
	
	int n1=middle-left+1;
	int n2=right-middle;
	
	int LEFT[n1],RIGHT[n2];
	
	for(i=0;i<n1;++i)
		LEFT[i]= arr[left+i];
	for(i=0;i<n2;++i)
		RIGHT[i]= arr[middle+1+i];
		
	i=0;
	j=0;
	k=left;
	
	while(i<n1 && j<n2)
	{
		if(LEFT[i]<=RIGHT[j])
		{
			arr[k]=LEFT[i];
			++i;
		}
		else
		{
			arr[k]=RIGHT[j];
			++j;
		}
		++k;
	}
	
	while(i<n1)
	{
		arr[k]=LEFT[i];
		++i;
		++k;
	}
	while(j<n2){
		arr[k]=RIGHT[j];
		++j;
		++k;
	}
}
void mergeSort(int arr[], int left, int right){
	if(left<right)
	{
		int middle=left+(right-left)/2;
		mergeSort(arr, left, middle);
		mergeSort(arr, middle+1, right);
		merge(arr, left, middle, right);
	}
}
int main(){
	int arr[]={8,5,2,3,6,9,1,4,7,0};
	int n=sizeof(arr)/sizeof(int);
	mergeSort(arr,0,n-1);
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
	return 0;
}
