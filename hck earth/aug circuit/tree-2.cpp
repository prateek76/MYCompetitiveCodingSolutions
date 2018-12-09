#include<bits/stdc++.h>

using namespace std;

vector<int> adj[100006];
vector<int> aa;
vector<int> bb;
int visited[100006];
void dfs1(int s,int ind) {
        visited[s] = true;
        aa.push_back(s);
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs1(adj[s][i],ind);
        }
}
    
void dfs2(int s,int ind) {
        visited[s] = true;
        bb.push_back(s);
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs2(adj[s][i],ind);
        }
}

void initialize() {
    for(int i = 0;i < 100006;++i)
    visited[i] = false;
}

bool isPowerOfTwo (long long int x)
{
  return x && (!(x&(x-1)));
}

int main()
{
    int n;
    cin>>n;
    long long int arr[100006];
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    
    for(int i=1;i<n;i++) {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        adj[tmp1].push_back(tmp2);
    }

    int q;
    cin>>q;
    while(q--) {
        int u,v;
        cin>>u>>v;
        initialize();
        dfs1(u,u);
        initialize();
        dfs2(v,v);
        int cnt = 0;
        set<pair<int,int>> sety;
        for(int i=0;i<aa.size();i++) {
            for(int j=0;j<bb.size();j++) {
                if(isPowerOfTwo(arr[aa[i]]^arr[bb[j]])) {
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        aa.clear();
        bb.clear();
    }
    return 0;
}
