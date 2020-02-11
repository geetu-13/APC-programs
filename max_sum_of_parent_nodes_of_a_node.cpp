#include<iostream>
#include<vector>
#include<map>
#include<iterator>
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
		map<int, int> m;
		for(i=0;i<n;i++)
		{
			if (m[graph[i]])
				m[graph[i]]+=i;
			else 
				m[graph[i]]=i;
		}
		
		int max=0,val;
		for( map<int,int>::iterator ii=m.begin(); ii!=m.end(); ++ii)  
   		{  
   			//print value with sum of parents: 
        	//cout << (*ii).first << ": " << (*ii).second << endl; 
			if (max<(*ii).second)
			{
				max=(*ii).second;
				val=(*ii).first;
			 } 
   		}  
   		cout<<"\n\nnode with max sum of parents is: "<<val<<" and number of parents= "<<max;
	}
}
