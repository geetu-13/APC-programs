//heap sort
#include<stdio.h>
int a[]={5,8,9,1,2,0,3};
int size=7;
int n=7;
void print()
{
	int i=0;
	for(; i<n;i++)
		printf("%d ", a[i]);
	printf("\n\n");
}
void swap(int x,int y)
{
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}

void sink(int i)
{
	if (i>=size)
		return;
	int max=i;
	int L=i*2;//left child
	int R=i*2+1;//right child
	if (L<size && a[L]>a[max])
		max=L;
	if(R<size && a[R]>a[max])
		max=R;
	if(i != max)
	{
		swap(i,max);
		sink(max);
	}
}

void heapify()
{
	int i=n/2;
	for(; i>=0; i--)
		sink(i);
}

void sort()
{
	heapify();
	printf("after heapify:\n");
	print();
	int i=0;
	for(;i<n;i++)
	{
		swap(0, size-1);
		size--;
		sink(0);
	}
}

int main()
{
	printf("before sorting: \n");
	print();
	sort();
	printf("after sorting: \n");
	print();
	return 0;
}
