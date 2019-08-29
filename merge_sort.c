#include<stdio.h>
void MERGE(int a[], int Left, int mid, int Right, int aux[])
{
	int i=Left, j=mid+1, k;
	for(k=Left;k<=Right;k++)
	{
		if (i>mid)
			aux[k]=a[j++];
		else if (j>Right)
			aux[k]=a[i++];
		else if(a[i]>a[j])
			aux[k]=a[j++];
		else
			aux[k]=a[i++];
	}
	for(k=Left;k<=Right;k++)
	{
		a[k]=aux[k];
	}
} 
void MERGE_SORT(int a[], int Left, int Right, int aux[])
{
	if (Right<=Left) 
		return;
	int mid=(Left+Right)/2;
	MERGE_SORT(a,Left,mid,aux);
	MERGE_SORT(a,mid+1,Right,aux);
	MERGE(a,Left,mid,Right,aux);
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int aux[n];
	MERGE_SORT(a, 0, n-1, aux);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}

