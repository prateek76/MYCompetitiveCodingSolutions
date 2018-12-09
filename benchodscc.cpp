#include<bits/stdc++.h>

using namespace std;

vector<int> adj[1000];
vector<int> transpose[1000];
stack<int> sack;
bool visited[1000];
int flag = 0;
void dfs(int u) {
    visited[u] = true;
    for(int i=0; i<adj[u].size(); i++) {
        if(visited[adj[u][i]] == false) {
            sack.push(u);//push source
            dfs(adj[u][i]);
        }
    }
}

void dfst(int u) {
    visited[u] = true;
        cout<<u<<" ";
    for(int i=0; i<transpose[u].size(); i++) {
        if(visited[transpose[u][i]] == false) {
            sack.push(u);//push source
            dfs(transpose[u][i]);
        }
    }
}

void init(int N) {
    for(int u=0; u<N; u++) {
        if(visited[u] == false) {
            dfs(u);
        }
    }
}

void displayGraph(int v)
    {
        for (int i = 0; i < v; i++) {
            cout << i << "--> ";
            //cout<<transpose[i].size();
            for (int j = 1; j <= transpose[i].size(); j++)
                cout << transpose[i][j] << "  ";
            cout << "\n";
        }
    }

int main() {
    
    int N,M;
    cin>>N>>M;
    while(M--) {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
    }
    
    init(N);
    for(int i=0; i<N; i++) {
        //cout<<adj[i].size();
        for(int j=0; j<adj[i].size(); j++) {
            //cout<<"madarchod"<<adj[i][j]<<endl;
            int y = adj[i][j];
            transpose[y].push_back(i);
            cout<<transpose[adj[i][j]][i];
        }
    }
    for(int i=0;i<=3000;i++) {
        visited[i] = false;
    }
    
    while(sack.empty() == false) {
        int v = sack.top();
        sack.pop();
        
        if(visited[v] = false && v != 0) {
            flag = 1;
            dfst(v);
            cout<<endl;
        }
    }
    cout<<endl;
    displayGraph(N);
    
    
    
    return 0;
}