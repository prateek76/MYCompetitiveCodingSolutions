#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    map<int,int> mapy;
    while(t--) {
        mapy.clear();
        int n,a,b;
        cin>>n>>a>>b;
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=n-i;j++) {
                int dk = (i*a)-(j*b);
                //cout<<i<<"*"<<a<<"-"<<j<<"*"<<b<<" = "<<dk<<endl;
                if(mapy[dk] > 0) break;
                mapy[dk]++;
            }
        }
        cout<<mapy.size()<<endl;
    }
    return 0;
}
