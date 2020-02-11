#include<iostream>
#include<list>
#include<vector>
using namespace std;
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}
void BFS(vector<int>adj[], int V, int start_point)
{
	bool visited[V];
	for(int i=0;i<V;++i)
		visited[i]=false;
	list<int> queue;
	
	visited[start_point]=true;
	queue.push_back(start_point);
	
	vector<int>::iterator i; 
	
	while(!queue.empty())
	{
		start_point = queue.front(); 
        cout << start_point << " "; 
        queue.pop_front(); 

        for (i = adj[start_point].begin(); i != adj[start_point].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        }
	}
}
int main()
{
	int V=4;
	vector<int>adj[V];
	addEdge(adj, 0, 1);
    addEdge(adj, 0, 2); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 2, 0); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 3); 
    BFS(adj, V, 2);
    return 0;
}
