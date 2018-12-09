#include<bits/stdc++.h>

using namespace std;

#define pb push_back

vector<bool> v;
vector<vector<int>> g;

void edge(int a,int b){
	g[a].pb(b);
	
	//if undirected graph d0
	//g[b].pb(a);
}

void bfs(int u){
	queue<int> q;
	q.push(u);
	v[u] = true;
	
	while(!q.empty()){
		
		int f = q.front();
		q.pop();
		
		cout<<f<<" ";
		
		//enqueue all the adjecent of f and mark them visited
		for(auto i = g[f].begin();i!=g[f].end();i++){
			if(!v[*i]){
				q.push(*i);
				v[*i] = true;
			}
		}
	}
}

int main(){
	
	//code ...
	return 0;
	
}