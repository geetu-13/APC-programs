#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		t--;
		int n,i,j;
		cin>>n;
		vector <int> graph;
		for(i=0;i<n;++i)
		{
			cin>>j;
			graph.push_back(j);
		}
		int max_sum=-1;
		for(i=0;i<n;i++)
		{
			int count=0;
			int start=i;
			int x=graph[i];
			int sum=start;
			bool cycle=false;
			while(x<graph.size() && count<n)
			{
				count++;
				if(x!=start)
				{
					sum+=x;
					x=graph[x];
				}
				else if(x==start)
				{
					cycle=true;
					break;
				}
			}
			cout<<sum<<" ";
			if (sum>max_sum && cycle)
				max_sum=sum;
		}
		cout<<"\nmax_sum: "<<max_sum<<"\n\n";
	}
}
