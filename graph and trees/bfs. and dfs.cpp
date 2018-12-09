#include<bits/stdc++.h>

using namespace std;

//bfs-
	vector <int> v[10];
	bool visited[10];

	void bfs( int s ){//source node
		queue <int> q;
		q.push(s);
		level[s] = 0;
		vis[s] = true;
		while( !q.empty() ){
			int p = q.front();
			q.pop();
			for(int i = 0; i < v[p].size(); i++){
					if(visited[v[p][i]] == false){
						//vis[v[p][i]] = true; //not here
						level[v[p][i]] = level[p]+1;
						q.push(v[p][i]);
						vis[v[p][i]] = true; //here according to process
					}
			}
	}
	
}
//completed bfs


//dfs iterative

dfs-iterative( int s ){
	stack<int> sack;
	s.push( s );
	mark s is visited;
	while( !sack.empty() ){
		int p = sack.top();
		s.pop();
		
		for( int i=0;i < v[p].size(); i++ ){
			if( visited[[p][i]] == false ){
				s.push()
			}
		}
	}
}