#include<iostream>
using namespace std;
void swap(int *x, int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;   
        swap(&arr[min_idx], &arr[i]);  
    }  
}

int main()
{
	int arr[]={8,5,2,3,6,9,1,4,7,0};
	int n=sizeof(arr)/sizeof(int);
	selectionSort(arr,n);
	for(int i=0;i<n;++i)
		cout<<arr[i]<<" ";
	return 0;
}
