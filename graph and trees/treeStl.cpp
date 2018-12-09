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

	void DFS(vector<int> adj[], int v) {
		vector<bool> visited(v, false);//intialisation of vector bool with false
	}
	return 0;
}