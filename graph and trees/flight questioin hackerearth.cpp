#include<bits/stdc++.h>

using namespace std;

int N,T;
int igi = 0;
int graph[5009][5009],n,dist[100006];
vector <int> path[1000];
int minD(int sptset[]){
    int min=999999999,min_index;
    for(int i=1;i<=n;i++){
        if(!sptset[i] && dist[i]<min){
            min = dist[i],min_index=i;
        }
    }
    
    return min_index;
}

void near(int s){
    int sptset[100006];
    for(int i=1;i<100006;i++){
        dist[i] = 999999999;
        sptset[i] = 0;
    }
    
    dist[s] = 0;
    
    for(int i=1;i<=n;i++){
        int u = minD(sptset);
        sptset[i] = 1;
        for(int j=1;j<=n;j++){
            if(!sptset[j] && graph[u][j] && dist[u] != 999999999 && dist[u]+graph[u][j]<dist[j]){
                dist[j] = dist[u] + graph[u][j];
                path[j].push_back(u);
                for(int i=0;i<path[u].size();i++){
                    path[j].push_back(path[u][i]);
                }
            }
        }
    }
}

int main()
{
    for(int i=0;i<5009;i++){
        for(int j=0;j<5009;j++){
            graph[i][j] = 0;
        }
    }
    int M,C;
    cin>>n>>M>>T>>C;
    while(M--) {
        int u,v;
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int x,y;
    cin>>x>>y;
    near(x);
    
    cout<<dist[y]+1<<endl;
    sort(path[y].begin(),path[y].end());
    path[y].push_back(y);
    for(int i=0;i<path[y].size();i++){
        cout<<path[y][i]<<" ";
    }
    return 0;
}

//lexiographical error