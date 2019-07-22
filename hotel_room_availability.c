//hotel booking system
#include<stdio.h>
#include<stdlib.h>
struct elem
{
	int s;
	int e;
};
int compare(const void *a, const void *b)
{
	int x=((struct elem *)a)->s;
	int y=((struct elem *)b)->s;
	if (x-y!=0)
		return x-y;
	else
	{
		int p=((struct elem *)a)->e;
		int q=((struct elem*)b)->e;
		return p-q;
	}
}
int main()
{
	int n;//no of pairs
	scanf("%d",&n);
	struct elem a[n];//array of struct elem
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a[i].s,&a[i].e);//scanning the pairs
	}
	
/**	printf("\n BEFORE SORTING \n");
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",a[i].s,a[i].e);
	}**/
	qsort(a, n, sizeof(a[0]), compare);//sorting the pairs on basis of starting index
	printf("\n AFTER SORTING \n");
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",a[i].s,a[i].e);
	}	
	i=0;
	int room;
	printf("enter the no rooms available:");
	scanf("%d",&room);
	
//	printf("\n AFTER MERGING \n");
	while (i<n)
	{
		if (a[i+1].s<=a[i].e)//successfully merging
		{
			a[i+1].s=a[i].s;
			a[i+1].e=a[i+1].e>a[i].e?a[i+1].e:a[i].e;
					}			
		else//merge not possible
			{//printf("%d, %d \n",a[i].s,a[i].e);
			room--;
			}
		i++;
	}
	if (room<0)
		printf("NO");
	else
		printf("YES");
	return 0;
}
