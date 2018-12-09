#include<bits/stdc++.h>

using namespace std;

int main()
{
	void addEdge(vector<int> adj[], int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void DFSutil(int u, vector<int> adj[], vector<bool> &visited)
	{
		visited[u] = true;
		//cout<<u<<" ";

	}

	void DFS(vector<int> adj[], int V) 
	{
		vector<bool> visited(vis, false);//intialisation of vector bool with false
		for (int u = 0;u < vis;u++) {
			if (visited[u] == false) {
				DFSutil(u, adj, visited);
			}
		}
	}

	int main() 
	{
		int vis = 5;
		vector<int> adj[vis];
		addedge(adj, 0, 1);
		add
	}
	return 0;
}