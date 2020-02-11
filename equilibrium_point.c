//c
#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int i;
	int sum=0;
	for(i=0;i<n;++i){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	int left=0;
	int right=sum;
	int res=-1;
	for(i=0;i<n;++i){
		int center=arr[i];
		if(left==right-center)
			{
				if (i!=0 && i!=n-1)
				res=center;
				break;
			}
		else{
			left=left+center;
			right=right-center;
		}
	}
	printf("res= %d \n",res);
	
}
