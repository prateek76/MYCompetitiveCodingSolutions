#include<bits/stdc++.h>
#include<math.h>
using namespace std;

vector<int> adj[100009];
vector<int> ans[100009];
int visited[100009];
void dfs(int s,int ind) {
        visited[s] = true;
        ans[ind].push_back(s);
        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
             dfs(adj[s][i],ind);
        }
    }

    void initialize() {
        for(int i = 0;i < 100009;++i)
         visited[i] = false;
    }

bool isPowerOfTwo(int n)
{
   return (ceil(log2(n)) == floor(log2(n)));
}

bool ispwr2(long long int x)
{
    if(x == 0)
        return 0;
    else
    {
        while(x % 2 == 0) x /= 2;
        return (x == 1);
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[100009];
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    
    set<int> unik;
    
    
    for(int i=1;i<n;i++) {
        int tmp1,tmp2;
        cin>>tmp1>>tmp2;
        unik.insert(tmp1);
        adj[tmp1].push_back(tmp2);
    }
    for(auto it = unik.begin();it!=unik.end();it++) {
        initialize();
        dfs((*it),(*it));
    }
    
    int q;
    cin>>q;
    while(q--) {
        int u,v;
        cin>>u>>v;
        int cnt = 0;
        set<pair<int,int>> sety;
        for(int i=0;i<ans[u].size();i++) {
            for(int j=0;j<ans[v].size();j++) {
                if(isPowerOfTwo(arr[ans[u][i]]^arr[ans[v][j]])) {
                    sety.insert(make_pair(ans[u][i],ans[v][j]));
                    //sety.insert(make_pair(ans[v][i],ans[u][j]));
                    //cout<<ans[u][i]<<" "<<ans[v][j]<<" ";
                }
            }
        }
        cout<<sety.size()<<endl;
    }
    return 0;
}
