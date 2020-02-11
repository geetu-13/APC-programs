#include<stdio.h>
//method 1 using for loop to iterate the loop
//method 2 using sum of AP
int main(){
	int t;
	scanf("%d",&t);
	while(t>0){
		int n;
		scanf("%d",&n);
		int a[n-1];
		int i;
		int sum=0;
		for(i=0;i<n-1;++i){
			scanf("%d",&a[i]);
			sum=sum+a[i];
		}
		for(i=0;i<n;i++){
			if(a[i]==i+1)
				continue;
			else 
				break;
		}
		printf("answer by method 1: %d\n",i+1);
		int sum_of_AP=n*(n+1);
		sum_of_AP/=2;
		printf("answer by method 2: %d\n\n", sum_of_AP-sum);
		
		t--;
	}
}
