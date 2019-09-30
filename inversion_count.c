//inversion count
#include<stdio.h>
int sort(int a[], int L, int R, int aux[])
{
	if(R<=L) return 0;
	int count=0;
	int mid=(R+L)/2;
	count=sort(a,L,mid,aux);
	count+=sort(a,mid+1,R,aux);
	count+=merge(a,L,mid,R,aux);
	return count;
}
int merge(int a[], int L, int mid, int R, int aux[])
{

	int i=L;
	int j=mid+1;
	int count=0;
	int k=L;
	while(k<=R)
	{
		if(i>mid)
			aux[k++]=a[j++];
		else if(j>R)
			aux[k++]=a[i++];
		else if(a[i]>a[j])
		{
			int x;
			count+=mid-i+1;
			/**printing the pairs **/
			for(x=i;x<=mid;x++)
				printf("[%d,%d]\n",a[x],a[j]);
			aux[k++]=a[j++];
		}
		else
			aux[k++]=a[i++];		
	}
	for(k=L;k<=R;k++)
		a[k]=aux[k];
	return count;
}
int main()
{
	int n=5;
	int a[]={4,2,1,3,6};
	int aux[n];
	printf("pairs:\n");
	printf("inversion count: %d \narray: \n",sort(a,0,4,aux));
	int i=0;
	for(i=0;i<5;i++)
		{
			printf("%d ",a[i]);
		}
	return 0;
}
