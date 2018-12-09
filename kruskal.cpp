#include<bits/stdc++.h>

using namespace std;

int nodes,edges;
int id[100006]; 
pair<int, pair<int, int>> arr[100006];

void init() {
    for(int i=0; i<100006; i++) {
        id[i] = i;
    }
}

int root(int x) {
    while(id[x] != x) {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1 (int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

int kruskal(pair<int, pair<int, int>> arr[]) {
    int x,y;
    int cost,min_cost = 0;
    for(int i=0; i<edges; i++) {
        x = arr[i].second.first;
        y = arr[i].second.second;
        
        cost = arr[i].first;
        if(root[x] != root[y]) {
            min_cost += cost;
            union1(x,y);
            cout<<root[x]<<" "<<root[y];
        }
    }
    return min_cost;
}

int main()
{
    cin>>nodes>>edges;
    init();
    for(int i=0; i<edges; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        arr[i] = make_pair(c,make_pair(a,b));
    }
    
    sort(arr, arr+edges);
    int ans = kruskal(arr);
    cout<<ans;
    return 0;
}