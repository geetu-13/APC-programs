#include<stdio.h>
void swap(int *a, int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int num=n;
	int j;int max;int index=0;
	while(n>0)
	{
		i=0;
		max=a[i];
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(max<a[j]){
				max=a[j];
				index=j;
			}
		}
		swap(&a[index],&a[n-1]);
		n--;
	}
	for(i=0;i<num;i++)
	printf("%d ",a[i]);
	
}
