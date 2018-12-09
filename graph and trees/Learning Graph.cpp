#include<bits/stdc++.h>

using namespace std;
bool sorty(pair<int,int> &a,pair<int,int> &b)
{
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}
void addedge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int n,m,k,x,y;
    int arr[1000003];
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> adj[1000006];
    for(int i=0;i<m;i++){
        int t1,t2;
        cin>>t1>>t2;
        addedge(adj,t1,t2);
    }
    
    for(int i=1;i<=n;i++)
    {
        vector<pair<int,int>> ve;
        for(int j = 0;j<adj[i].size();j++)
        {
            x = adj[i][j];
            y = arr[x-1];
            ve.push_back(make_pair(x,y));
        }
        sort(ve.begin(),ve.end(),sorty);
        if(ve.size()>=k)
            cout<<ve[k-1].first<<"\n";
        else
            cout<<"-1\n";
    }
    
    return 0;
}