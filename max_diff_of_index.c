#include<stdio.h>
#include<stdlib.h>
struct elem
{
	int val;//value
	int in;//index
};
int compare(const void *a, const void *b)
{
	return (((struct elem *)a)->val -((struct elem *)b)->val);
}
int main()
{
	int i,j,n;
	scanf("%d",&n);//no of elements in array
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	struct elem arr[n];//array of struct elem
	for(i=0;i<n;i++)
	{
		arr[i].val=a[i];//storing the elements of array
		arr[i].in=i;//storing the index of the array
	}
	qsort(arr, n, sizeof(arr[0]), compare);
	//qsort is a already defined function. 
	//we just have to define the compare function.
	int max=0,min=arr[0].in;
	for(i=0;i<n;i++)
	{
		if (arr[i].in-min>max)
			max=arr[i].in-min;
		min=arr[i].in>min?arr[i].in:min;
	}
	printf("max diff is %d \n", max);
	return 0;
}
