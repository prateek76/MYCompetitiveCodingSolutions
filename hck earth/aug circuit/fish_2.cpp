#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int s,e;
        vector <pair<int,int>> vec;
        for( int i = 0; i < n; i++ ) {
            cin>>s>>e;
            vec.push_back(make_pair(e,s));
        }
        
        sort(vec.begin(),vec.end());
        int cnt1=0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                    if(vec[j].second <= vec[i].first) {
                        vec[j].first = -1;
                        vec[j].second = 99999999999;
                        cnt1++;
                        break;
                    }
            }
        }
        
        cout<<n-cnt1<<endl;
    }
    return 0;
}